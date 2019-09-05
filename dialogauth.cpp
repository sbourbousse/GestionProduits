#include "dialogauth.h"
#include "ui_dialogauth.h"
#include <QtSql>


DialogAuth::DialogAuth(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAuth)
{
    ui->setupUi(this);
}

DialogAuth::~DialogAuth()
{
    delete ui;
}

void DialogAuth::on_pushButton_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    QString queryUserText = "select userUsername,userPassword from User where userUsername='"+username+"' and userPassword='"+password+"'";
    QSqlQuery queryUser(queryUserText);


    if (queryUser.first()==true)
    {
        accept();
    }
    else
    {
        //ui->labelErrorMessage->setText("Nom d'utilisateur ou mot de passe incorrect.");
    }
}
