/********************************************************************************
** Form generated from reading UI file 'dialogauth.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGAUTH_H
#define UI_DIALOGAUTH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogAuth
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelUsername;
    QLineEdit *lineEditUsername;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelPassword;
    QLineEdit *lineEditPassword;
    QPushButton *pushButton;
    QLabel *labelErrorMessage;

    void setupUi(QDialog *DialogAuth)
    {
        if (DialogAuth->objectName().isEmpty())
            DialogAuth->setObjectName(QStringLiteral("DialogAuth"));
        DialogAuth->resize(400, 300);
        groupBox = new QGroupBox(DialogAuth);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 30, 311, 221));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 271, 181));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelUsername = new QLabel(layoutWidget);
        labelUsername->setObjectName(QStringLiteral("labelUsername"));

        horizontalLayout->addWidget(labelUsername);

        lineEditUsername = new QLineEdit(layoutWidget);
        lineEditUsername->setObjectName(QStringLiteral("lineEditUsername"));

        horizontalLayout->addWidget(lineEditUsername);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelPassword = new QLabel(layoutWidget);
        labelPassword->setObjectName(QStringLiteral("labelPassword"));

        horizontalLayout_2->addWidget(labelPassword);

        lineEditPassword = new QLineEdit(layoutWidget);
        lineEditPassword->setObjectName(QStringLiteral("lineEditPassword"));
        lineEditPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEditPassword);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        labelErrorMessage = new QLabel(DialogAuth);
        labelErrorMessage->setObjectName(QStringLiteral("labelErrorMessage"));
        labelErrorMessage->setGeometry(QRect(40, 260, 311, 41));

        retranslateUi(DialogAuth);

        QMetaObject::connectSlotsByName(DialogAuth);
    } // setupUi

    void retranslateUi(QDialog *DialogAuth)
    {
        DialogAuth->setWindowTitle(QApplication::translate("DialogAuth", "Connexion", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("DialogAuth", "Authentification", Q_NULLPTR));
        labelUsername->setText(QApplication::translate("DialogAuth", "Nom d'utilisateur", Q_NULLPTR));
        labelPassword->setText(QApplication::translate("DialogAuth", "Mot de passe", Q_NULLPTR));
        pushButton->setText(QApplication::translate("DialogAuth", "Connexion", Q_NULLPTR));
        labelErrorMessage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogAuth: public Ui_DialogAuth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGAUTH_H
