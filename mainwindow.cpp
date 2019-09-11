#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadRayonList();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_listeButtonPageAjout_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_ajoutButtonPageListe_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::loadProductList()
{
    /*QString queryTextProductList = "select produitLibelle,produitDescription,produitPrixUnitaire,produitUnite,produitImage,rayonLibelle from Produit natural join Rayon";
    QSqlQuery queryProductList(queryTextProductList);

    while(queryProductList.next())
    {

        QString unProduit = queryProductList.value('produitLibelle');
    }*/
}

void MainWindow::loadRayonList()
{
    QString queryTextRayonList = "select rayonLibelle,rayonId from Rayon order by rayonLibelle";
    QSqlQuery queryRayonList(queryTextRayonList);

    //Suppression des valeurs existantes (pratique en cas de modifs ou d'ajout)
    ui->comboBoxRayon->clear();
    ui->comboBoxRayonListe->clear();

    while(queryRayonList.next())
    {


        QString unRayonLibelle = queryRayonList.value(0).toString();
        QString unRayonId = queryRayonList.value(1).toString();


        QIcon icon("/home/sbourbousse/Images/"+unRayonId+".png");




        //insertion des rayons dans la combo box de la page d'ajout
        ui->comboBoxRayon->addItem(icon,unRayonLibelle,unRayonId);
        //insertion des rayons dans la combo box de la page liste
        ui->comboBoxRayonListe->addItem(icon,unRayonLibelle,unRayonId);
    }
}


void MainWindow::on_pushButtonAddRayon_clicked()
{
    //Recuperation du libelle
    QString libelleRayon = ui->lineEditRayonLibelle->text();

    //Envoie de l'ajout
    QString queryTextRayonAdd = "insert into Rayon (rayonLibelle) values ('"+libelleRayon+"')";
    QSqlQuery queryRayonAdd(queryTextRayonAdd);

    //Reinitialiser le lineEdit
    ui->lineEditRayonLibelle->clear();

    //Charger les ajouts
    loadRayonList();



}

void MainWindow::on_pushButtonBrowsePicture_clicked()
{
    //Ouverture de la fenêtre de parcour de fichiers
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"),"~" ,tr("Png Files (*.png)"));

    //Affichage de l'url du fichier sous le bouton parcourir
    ui->labelImagePath->setText(filePath);
}

void MainWindow::on_pushButtonAddProduit_clicked()
{
    QString noRayon=ui->comboBoxRayon->currentData().toString();
    QString queryTextProduitAdd = "insert into Produit (produitLibelle, produitDescription, produitPrixUnitaire, produitUnite, produitImage, rayonId)"
    " values ('"+ui->lineEditLibelle->text()+"','"+ui->textEditDescription->toPlainText()+"',"+ui->lineEditPrixUnitaire->text()+
    ",'"+ui->lineEditUnite->text()+"','"+ui->labelImagePath->text()+"',"+ui->comboBoxRayon->itemData(ui->comboBoxRayon->currentIndex()).toString()+")";

    //ui->debug->setText(queryTextProduitAdd);
    qDebug()<<ui->comboBoxRayon->itemData(ui->);
}
