#ifndef DIALOGRAYON_H
#define DIALOGRAYON_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class DialogRayon;
}

class DialogRayon : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRayon(QWidget *parent = 0);
    ~DialogRayon();

private slots:
    void on_pushButtonImageRayon_clicked();

    void on_pushButtonValiderRayon_clicked();

    void chargerTableauRayons();

    void on_pushButtonSupprimer_clicked();

    void on_pushButtonModifier_clicked();

    void on_pushButtonAbandonRayon_clicked();

    void on_pushButtonModifRayon_clicked();

    void on_pushButtonImageRayonModif_clicked();

private:
    QString cheminImageRayon;
    QString idAModif;
    Ui::DialogRayon *ui;
};

#endif // DIALOGRAYON_H
