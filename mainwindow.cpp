#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    chargerLesRayons();
    chargerComboBoxUniteMesureProduit();
    chargerTableauProduits();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::chargerLesRayons()
{
    QString maRequeteTexte = "select rayonLibelle,rayonId from Rayon order by rayonLibelle";
    QSqlQuery maRequete(maRequeteTexte);

    //Suppression des valeurs existantes (pratique en cas de modifs ou d'ajout)
    ui->comboBoxRayon->clear();

    while(maRequete.next())
    {
        QString unRayonLibelle = maRequete.value(0).toString();
        QString unRayonId = maRequete.value(1).toString();

        //Aller chercher dans la base de données
        QIcon icon(maRequete.value(2).toString());

        //insertion des rayons dans la combo box de la page d'ajout
        ui->comboBoxRayon->addItem(icon,unRayonLibelle,unRayonId);
    }
}

void MainWindow::chargerComboBoxUniteMesureProduit()
{
    QString maRequeteTexte = "select uniteId, uniteLibelle from Unite";
    QSqlQuery maRequete(maRequeteTexte);

    while(maRequete.next())
    {
        QString uneUniteLibelle = maRequete.value(1).toString();
        QString uneUniteId = maRequete.value(0).toString();

        //insertion des unite dans la combo box de la page d'ajout
        ui->comboBoxUniteMesureProduit->addItem(uneUniteLibelle,uneUniteId);
    }
}

void MainWindow::chargerTableauProduits()
{
    //Reinitialiser le tableau en cas de modifications
    ui->tableWidgetProduit->setRowCount(0);


    QString maRequeteTexte = "select produitId, produitLibelle, produitDescription, produitPrixUnitaire, uniteLibelle, produitImage, rayonLibelle "
                             "from Produit natural join Rayon natural join Unite";

    QSqlQuery maRequete(maRequeteTexte);

    int nombreDeColonnes = 7 ; //3 colonnes + id (caché) :

    ui->tableWidgetProduit->setColumnCount(nombreDeColonnes);

    int compteurDeLignes=0;

    //Ajouter des lignes à mon tableau
    while(maRequete.next())
    {
        //Ajout de lignes
        ui->tableWidgetProduit->insertRow(compteurDeLignes);

        //Ajout d'élément à mon tableau
        for(int i = 0 ; i<=nombreDeColonnes ; i++)
        {
            //Creer un nouvelle élément pour mon tableau
            QTableWidgetItem *elementDuTableau = new QTableWidgetItem;

            //Inserer le texte dans l'element
            elementDuTableau->setText(maRequete.value(i).toString());

            //Inserer l'élément au bon endroit
            ui->tableWidgetProduit->setItem(compteurDeLignes,i,elementDuTableau);
        }
        compteurDeLignes++;
    }

    //Cacher la colonne des ids
    ui->tableWidgetProduit->hideColumn(0);

    //Apparence du tableau
    QStringList mesEntetes= {tr("Id"),tr("Label"),tr("Description"),tr("Price"),tr("Unit"),tr("Picture"),tr("Section")};
    ui->tableWidgetProduit->setHorizontalHeaderLabels(mesEntetes);
    ui->tableWidgetProduit->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetProduit->verticalHeader()->setVisible(false);
}

void MainWindow::on_pushButtonValiderProduit_clicked()
{
    QString noRayon=ui->comboBoxRayon->currentData().toString();
    QString monLibelle = ui->lineEditLibelleProduit->text();
    QString maDescription = ui->textEditDescriptionProduit->toPlainText();
    QString monPrixUnitaire = ui->doubleSpinBoxPrixUnitaire->text().replace(",",".");
    QString monUniteDeMesure = ui->comboBoxUniteMesureProduit->currentData().toString();

    if(monLibelle.length()>3 && ui->doubleSpinBoxPrixUnitaire->value()>0)
    {
        //Ma requete
        QString maRequeteTexte = "insert into Produit (produitLibelle, produitDescription, produitPrixUnitaire, uniteId, produitImage, rayonId)"
        " values ('"+monLibelle+"','"+maDescription+"',"+monPrixUnitaire+",'"+monUniteDeMesure+"','"+cheminImageProduit+"',"+noRayon+")";

        qDebug()<<maRequeteTexte;

        //Envoie de la requete
        QSqlQuery maRequete(maRequeteTexte);


        //Supprimer le text des line edits
        ui->lineEditLibelleProduit->setText("");
        ui->doubleSpinBoxPrixUnitaire->setValue(0.00);
        ui->comboBoxUniteMesureProduit->setCurrentIndex(0);
        ui->textEditDescriptionProduit->setText("");
        ui->comboBoxRayon->setCurrentIndex(0);

        //Charger les modification
        chargerTableauProduits();

        //Enlever message erreur de saisie (au cas où)
        ui->labelErrorMessage->setText("");

    }
    else
    {
        ui->labelErrorMessage->setText(tr("Fields are incorrect"));
        //QTimer::singleShot(5000,this,SLOT(chargerLesRayons()));
    }
}

void MainWindow::on_pushButtonImageProduit_clicked()
{
    //Ouverture de la fenêtre de parcour de fichiers
    QString cheminFichier = QFileDialog::getOpenFileName(this, tr("Open File"),"~" ,tr("Png Files (*.png)"));

    //Affichage de l'url du fichier sous le bouton parcourir
    ui->labelImageProduit->setText(cheminFichier);
    cheminImageProduit = cheminFichier;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    int reponse = QMessageBox::warning(this,tr("Leave the application?"),tr("Are you sur you want to leave?"),QMessageBox::Yes|QMessageBox::No,QMessageBox::No);

    switch (reponse)
    {
    case QMessageBox::Yes:

        event->accept();
        break;
    case QMessageBox::No:
        event->ignore();
        break;
    }
}

void MainWindow::on_pushButtonAjoutRayon_clicked()
{
    DialogRayon *maFenetreRayon = new DialogRayon(this);
    maFenetreRayon->show();
}

void MainWindow::on_pushButtonSupprimerProduit_clicked()
{
    //Je récupere le numero de la ligne selectionné
    int maLigneASupprimer = ui->tableWidgetProduit->currentRow();
    //Je recupere l'identifiant à supprimer dans la colonne caché de mon tableau
    auto itemId = ui->tableWidgetProduit->item(maLigneASupprimer, 0)->text();

    QString maRequeteTexte = "delete from Produit where produitId="+itemId;
    QSqlQuery maRequete(maRequeteTexte);


    //Recharger le tableau
    chargerTableauProduits();

    //Transition page ajout
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButtonModifierProduit_clicked()
{
    //Je recupere et stock l'id à modifier
    idAModifier = ui->tableWidgetProduit->item(ui->tableWidgetProduit->currentRow(),0)->text();

    //Transition page modification
    ui->stackedWidget->setCurrentIndex(1);

    //Requete pour recuperer les informations du produits
    QSqlQuery maRequete("select produitLibelle, produitDescription, produitPrixUnitaire, uniteId, produitImage, rayonId "
                        "from Produit where produitId="+idAModifier);
    //Prendre le premier résultat de la requete
    maRequete.first();

    //Memoriser l'image
    cheminImageProduit=maRequete.value(4).toString();


    //Remplir les champs d'information du produit
    ui->lineEditLibelleProduit->setText(maRequete.value(0).toString());
    ui->comboBoxRayon->setCurrentIndex(ui->comboBoxRayon->findData(maRequete.value(5)));
    ui->doubleSpinBoxPrixUnitaire->setValue(maRequete.value(2).toDouble());
    ui->comboBoxUniteMesureProduit->setCurrentIndex(ui->comboBoxUniteMesureProduit->findData(maRequete.value(3)));
    ui->textEditDescriptionProduit->setText(maRequete.value(1).toString());
    if (maRequete.value(4).toString().length()>0)
        ui->labelImageProduit->setText(maRequete.value(4).toString());


}

void MainWindow::on_pushButtonAnnulerProduitModif_clicked()
{
    //Transition page ajout
    ui->stackedWidget->setCurrentIndex(0);

    //Vider les inputs
    ui->lineEditLibelleProduit->setText("");
    ui->comboBoxRayon->setCurrentIndex(0);
    ui->doubleSpinBoxPrixUnitaire->setValue(0);
    ui->comboBoxUniteMesureProduit->setCurrentIndex(0);
    ui->textEditDescriptionProduit->setText("");
    ui->labelImageProduit->setText(tr("No picture"));

    //Vider variable temporaire
    cheminImageProduit="";
    idAModifier="";
}

void MainWindow::on_pushButtonValiderProduitModif_clicked()
{
    QString noRayon=ui->comboBoxRayon->currentData().toString();
    QString monLibelle = ui->lineEditLibelleProduit->text();
    QString maDescription = ui->textEditDescriptionProduit->toPlainText();
    QString monPrixUnitaire = ui->doubleSpinBoxPrixUnitaire->text().replace(",",".");
    QString monUniteDeMesure = ui->comboBoxUniteMesureProduit->currentData().toString();

    if(monLibelle.length()>3 && ui->doubleSpinBoxPrixUnitaire->value()>0)
    {
        //Ma requete
        QSqlQuery maRequete("update Produit set produitLibelle=\""+monLibelle+"\", rayonId=\""+noRayon+"\", produitDescription=\""+maDescription+"\","
                            " produitPrixUnitaire="+monPrixUnitaire+", uniteId="+monUniteDeMesure+", produitImage=\""+cheminImageProduit+"\""
                            " where produitId="+idAModifier);

        qDebug()<<"update Produit set produitLibelle=\""+monLibelle+"\", rayonId=\""+noRayon+"\", produitDescription=\""+maDescription+"\","
               " produitPrixUnitaire="+monPrixUnitaire+", uniteId="+monUniteDeMesure+", produitImage=\""+cheminImageProduit+"\""
               " where produitId="+idAModifier;


        //Transition page ajout
        ui->stackedWidget->setCurrentIndex(0);

        //Vider les inputs
        ui->lineEditLibelleProduit->setText("");
        ui->comboBoxRayon->setCurrentIndex(0);
        ui->doubleSpinBoxPrixUnitaire->setValue(0);
        ui->comboBoxUniteMesureProduit->setCurrentIndex(0);
        ui->textEditDescriptionProduit->setText("");
        ui->labelImageProduit->setText(tr("No picture"));

        //Vider variable temporaire
        cheminImageProduit="";
        idAModifier="";

        //Recharger le tableau
        chargerTableauProduits();
    }
    else
        ui->labelErrorMessage->setText(tr("Fiels are incorrect"));
}
