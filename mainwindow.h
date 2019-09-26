#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QIcon>
#include <QFileDialog>
#include <QCloseEvent>
#include <QDebug>
#include "dialograyon.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void closeEvent(QCloseEvent *event);

    void chargerLesRayons();

    void chargerComboBoxUniteMesureProduit();

    void chargerTableauProduits();

    void on_pushButtonValiderProduit_clicked();

    void on_pushButtonImageProduit_clicked();

    void on_pushButtonAjoutRayon_clicked();    


private slots:
    void on_pushButtonSupprimerProduit_clicked();

    void on_pushButtonModifierProduit_clicked();

    void on_pushButtonAnnulerProduitModif_clicked();

    void on_pushButtonValiderProduitModif_clicked();

private:
    QString idAModifier;
    QString cheminImageProduit;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
