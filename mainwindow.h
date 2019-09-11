#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_listeButtonPageAjout_clicked();

    void on_ajoutButtonPageListe_clicked();

    void loadProductList();

    void loadRayonList();

    void on_pushButtonAddRayon_clicked();

    void on_pushButtonBrowsePicture_clicked();

    void on_pushButtonAddProduit_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
