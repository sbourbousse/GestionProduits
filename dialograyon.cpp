#include "dialograyon.h"
#include "ui_dialograyon.h"
#include <QSqlQuery>
#include <QFileDialog>
#include <QDebug>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>

DialogRayon::DialogRayon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRayon)
{
    idAModif="";
    cheminImageRayon="";
    ui->setupUi(this);
    chargerTableauRayons();
    ui->stackedWidget->setCurrentIndex(0);
}

DialogRayon::~DialogRayon()
{
    delete ui;
}

void DialogRayon::on_pushButtonImageRayon_clicked()
{
    //Ouverture de la fenêtre de parcour de fichiers
    QString cheminFichier = QFileDialog::getOpenFileName(this, tr("Open File"),"~" ,tr("Png Files (*.png)"));

    cheminImageRayon = cheminFichier;
}

void DialogRayon::on_pushButtonValiderRayon_clicked()
{
    //Ma requete
    QString maRequeteTexte = "insert into Rayon (rayonLibelle,RayonImage) values ('"+ui->lineEditLibelleRayon->text()+"','"+cheminImageRayon+"')";

    qDebug()<<maRequeteTexte;

    //Envoie de la requete
    QSqlQuery maRequete(maRequeteTexte);

    //Charger les modifications apportées
    chargerTableauRayons();
    ((MainWindow*)parent())->chargerLesRayons();
    ((MainWindow*)parent())->chargerTableauProduits();

    //Supprimer le text des line edits
    ui->lineEditLibelleRayon->setText("");

}

void DialogRayon::chargerTableauRayons()
{
    //Reinitialiser le tableau en cas de modifications
    ui->tableWidgetRayon->setRowCount(0);


    QString maRequeteTexte = "select Rayon.rayonId,rayonLibelle,rayonImage,count(Produit.produitId) from Rayon left outer join Produit on Rayon.rayonId=Produit.rayonId group by Rayon.rayonId";

    QSqlQuery maRequete(maRequeteTexte);

    int nombreDeColonnes = 4 ; //3 colonnes + id (caché) :

    ui->tableWidgetRayon->setColumnCount(nombreDeColonnes);

    int compteurDeLignes=0;

    //Ajouter des lignes à mon tableau
    while(maRequete.next())
    {
        //Ajout de lignes
        ui->tableWidgetRayon->insertRow(compteurDeLignes);

        //Ajout d'élément à mon tableau
        for(int i = 0 ; i<=nombreDeColonnes ; i++)
        {
            //Creer un nouvelle élément pour mon tableau
            QTableWidgetItem *elementDuTableau = new QTableWidgetItem;

            //Inserer le texte dans l'element
            elementDuTableau->setText(maRequete.value(i).toString());

            //Inserer l'élément au bon endroit
            ui->tableWidgetRayon->setItem(compteurDeLignes,i,elementDuTableau);
        }
        compteurDeLignes++;
    }

    //Cacher la colonne des ids
    ui->tableWidgetRayon->hideColumn(0);

    //Apparence du tableau
    QStringList mesEntetes= {"Identifiant","Libelle","Image","Nombre de produits"};
    ui->tableWidgetRayon->setHorizontalHeaderLabels(mesEntetes);
    ui->tableWidgetRayon->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetRayon->verticalHeader()->setVisible(false);
}

void DialogRayon::on_pushButtonSupprimer_clicked()
{

    //Je récupere le numero de la ligne selectionné
    int maLigneASupprimer = ui->tableWidgetRayon->currentRow();
    //Je recupere l'identifiant à supprimer dans la colonne caché de mon tableau
    auto itemId = ui->tableWidgetRayon->item(maLigneASupprimer, 0)->text();
    QString libelleRayon = ui->tableWidgetRayon->item(maLigneASupprimer, 1)->text();


    //Message d'alerte si il y a des produits dans ce rayon
    QString maRequeteTexte = "select count(*) from Rayon natural join Produit where Rayon.rayonId="+itemId;
    QSqlQuery maRequete(maRequeteTexte);

    maRequete.first();
    if(maRequete.value(0).toInt()>0)
    {
        QString produitOuProduits = " produits";
        //Accorder produits au singulier ou au pluriel
        if (maRequete.value(0).toInt()>1)
            produitOuProduits = " produits";
        else
            produitOuProduits = " produit";

        int reponse = QMessageBox::warning(this,"Suppression du Rayon "+libelleRayon,"Etes vous sur de vouloir supprimer "+libelleRayon+"\nCe rayon comporte "+maRequete.value(0).toString()+produitOuProduits,QMessageBox::Yes|QMessageBox::No,QMessageBox::No);

        if(reponse==QMessageBox::Yes)
        {
            qDebug()<<"Supprimer tout";
            maRequeteTexte = "delete from Produit where rayonId="+itemId;
            QSqlQuery maRequete(maRequeteTexte);
            maRequeteTexte = "delete from Rayon where rayonId="+itemId;
            QSqlQuery maRequete2(maRequeteTexte);
        }
    }
    else
    {
        maRequeteTexte = "delete from Rayon where rayonId="+itemId;
        QSqlQuery maRequete(maRequeteTexte);
    }


    //Recharger le tableau
    chargerTableauRayons();
    ((MainWindow*)parent())->chargerLesRayons();
    ((MainWindow*)parent())->chargerTableauProduits();
    //qDebug()<<maRequeteTexte;

    //Transition interface d'ajout
    ui->stackedWidget->setCurrentIndex(0);
}

void DialogRayon::on_pushButtonModifier_clicked()
{
    //Remplir l'input libelle
    ui->lineEditLibelleRayonModif->setText(ui->tableWidgetRayon->item(ui->tableWidgetRayon->currentRow(),1)->text());
    //Transition pour faire apparaitre l'interface de modification
    ui->stackedWidget->setCurrentIndex(1);
    //Vider la variable du chemin
    cheminImageRayon = "";
    //Memoriser l'identifiant à modifier
    idAModif = ui->tableWidgetRayon->item(ui->tableWidgetRayon->currentRow(),0)->text();
}

void DialogRayon::on_pushButtonAbandonRayon_clicked()
{
    //Transition interface d'ajout
    ui->stackedWidget->setCurrentIndex(0);
    //Vider les variables temporaires
    cheminImageRayon = "";
    idAModif = "";
}

void DialogRayon::on_pushButtonModifRayon_clicked()
{
    QString rayonLibelleModifie = ui->lineEditLibelleRayonModif->text();
    QString rayonImageModifie = cheminImageRayon;

    //Si l'input n'est pas vide
    if(rayonLibelleModifie.length()>1)
    {
        QSqlQuery maRequete("update Rayon set rayonLibelle=\""+rayonLibelleModifie+"\", rayonImage=\""+rayonImageModifie+"\" where rayonId="+idAModif);
    }
    else
        ui->labelErrorMessageModif->setText("Veuillez remplir les champs correctement.");

    //Charger les modifications apportées
    chargerTableauRayons();
    ((MainWindow*)parent())->chargerLesRayons();
    ((MainWindow*)parent())->chargerTableauProduits();

    //Transition interface d'ajout
    ui->stackedWidget->setCurrentIndex(0);

    //Vider les variables temporaires
    cheminImageRayon = "";
    idAModif = "";

}

void DialogRayon::on_pushButtonImageRayonModif_clicked()
{
    //Ouverture de la fenêtre de parcour de fichiers
    QString cheminFichier = QFileDialog::getOpenFileName(this, tr("Open File"),"~" ,tr("Png Files (*.png)"));

    cheminImageRayon = cheminFichier;
}


