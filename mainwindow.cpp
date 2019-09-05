#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>

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
    QString queryTextRayonList = "select rayonLibelle,rayonId from Rayon";
    QSqlQuery queryRayonList(queryTextRayonList);

    while(queryRayonList.next())
    {


        QString unRayonLibelle = queryRayonList.value(0).toString();
        QString unRayonId = queryRayonList.value(1).toString();


        QIcon icon("/home/sbourbousse/Images/"+unRayonId+".png");

        ui->comboBoxRayon->addItem(icon,unRayonLibelle,unRayonId);
        ui->comboBoxRayonListe->addItem(icon,unRayonLibelle,unRayonId);
    }
}

void MainWindow::on_comboBoxRayonListe_currentIndexChanged(const QString &arg1)
{

}