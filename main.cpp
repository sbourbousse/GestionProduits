#include "mainwindow.h"
#include "dialogauth.h"
#include <QApplication>
#include <QtSql>
#include <QTranslator>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*
     * CHARGER LE LANGAGE DE L'APPLICATION
     */
    QString locale = QLocale::system().name().section('_', 0, 0);
    QTranslator translator;
    translator.load(":/Traductions/ressources/gestionProduits_"+ locale);
    a.installTranslator(&translator);
    /*
     * CONNEXION A LA BASE DE DONNEE
     */
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("GestionProduit");
    db.setUserName("AppliGestion");
    db.setPassword("motdepasse");
    bool ok = db.open();


    /*
     * AUTHENTIFICATION
     */
    MainWindow w;
    DialogAuth 	authWindow;
    authWindow.show();


    if(authWindow.exec()==QDialog::Accepted)
    {
        w.show();
    }

    return a.exec();
}
