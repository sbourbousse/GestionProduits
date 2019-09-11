/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *pageAjout;
    QPushButton *ajoutButtonPageAjout;
    QPushButton *listeButtonPageAjout;
    QTabWidget *tabWidget;
    QWidget *tabProduit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelLibelle;
    QLineEdit *lineEditLibelle;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *labelDescription;
    QTextEdit *textEditDescription;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelRayon;
    QComboBox *comboBoxRayon;
    QLabel *labelTitleTabProduit;
    QLabel *labelImagePath;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonAddProduit;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelPrixUnitaire;
    QLineEdit *lineEditPrixUnitaire;
    QVBoxLayout *verticalLayout_5;
    QLabel *labelUnite;
    QLineEdit *lineEditUnite;
    QVBoxLayout *verticalLayout_6;
    QLabel *labelImage;
    QPushButton *pushButtonBrowsePicture;
    QWidget *tabRayon;
    QLabel *labelTitleTabRayon;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonAddRayon;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_7;
    QLabel *label;
    QLineEdit *lineEditRayonLibelle;
    QWidget *pageListe;
    QPushButton *ajoutButtonPageListe;
    QPushButton *listeButtonPageListe;
    QTableWidget *tableWidget;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBoxRayonListe;
    QMenuBar *menuBar;
    QMenu *menuGestion_des_produits;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(819, 544);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 20, 811, 461));
        pageAjout = new QWidget();
        pageAjout->setObjectName(QStringLiteral("pageAjout"));
        ajoutButtonPageAjout = new QPushButton(pageAjout);
        ajoutButtonPageAjout->setObjectName(QStringLiteral("ajoutButtonPageAjout"));
        ajoutButtonPageAjout->setGeometry(QRect(0, 0, 101, 231));
        ajoutButtonPageAjout->setStyleSheet(QStringLiteral("gridline-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        listeButtonPageAjout = new QPushButton(pageAjout);
        listeButtonPageAjout->setObjectName(QStringLiteral("listeButtonPageAjout"));
        listeButtonPageAjout->setGeometry(QRect(0, 230, 101, 221));
        tabWidget = new QTabWidget(pageAjout);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(100, 0, 691, 451));
        tabProduit = new QWidget();
        tabProduit->setObjectName(QStringLiteral("tabProduit"));
        layoutWidget = new QWidget(tabProduit);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(42, 62, 291, 56));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelLibelle = new QLabel(layoutWidget);
        labelLibelle->setObjectName(QStringLiteral("labelLibelle"));

        verticalLayout_2->addWidget(labelLibelle);

        lineEditLibelle = new QLineEdit(layoutWidget);
        lineEditLibelle->setObjectName(QStringLiteral("lineEditLibelle"));

        verticalLayout_2->addWidget(lineEditLibelle);

        layoutWidget1 = new QWidget(tabProduit);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(40, 250, 631, 98));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelDescription = new QLabel(layoutWidget1);
        labelDescription->setObjectName(QStringLiteral("labelDescription"));

        verticalLayout->addWidget(labelDescription);

        textEditDescription = new QTextEdit(layoutWidget1);
        textEditDescription->setObjectName(QStringLiteral("textEditDescription"));

        verticalLayout->addWidget(textEditDescription);

        layoutWidget2 = new QWidget(tabProduit);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(370, 60, 301, 56));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        labelRayon = new QLabel(layoutWidget2);
        labelRayon->setObjectName(QStringLiteral("labelRayon"));

        verticalLayout_3->addWidget(labelRayon);

        comboBoxRayon = new QComboBox(layoutWidget2);
        comboBoxRayon->setObjectName(QStringLiteral("comboBoxRayon"));

        verticalLayout_3->addWidget(comboBoxRayon);

        labelTitleTabProduit = new QLabel(tabProduit);
        labelTitleTabProduit->setObjectName(QStringLiteral("labelTitleTabProduit"));
        labelTitleTabProduit->setGeometry(QRect(180, 10, 361, 31));
        QFont font;
        font.setFamily(QStringLiteral("TeXGyreHeros"));
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        labelTitleTabProduit->setFont(font);
        labelImagePath = new QLabel(tabProduit);
        labelImagePath->setObjectName(QStringLiteral("labelImagePath"));
        labelImagePath->setGeometry(QRect(320, 220, 341, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Cantarell"));
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(50);
        labelImagePath->setFont(font1);
        labelImagePath->setLayoutDirection(Qt::LeftToRight);
        labelImagePath->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        widget = new QWidget(tabProduit);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 370, 681, 30));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButtonAddProduit = new QPushButton(widget);
        pushButtonAddProduit->setObjectName(QStringLiteral("pushButtonAddProduit"));

        horizontalLayout_3->addWidget(pushButtonAddProduit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        widget1 = new QWidget(tabProduit);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(42, 151, 621, 61));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        labelPrixUnitaire = new QLabel(widget1);
        labelPrixUnitaire->setObjectName(QStringLiteral("labelPrixUnitaire"));

        verticalLayout_4->addWidget(labelPrixUnitaire);

        lineEditPrixUnitaire = new QLineEdit(widget1);
        lineEditPrixUnitaire->setObjectName(QStringLiteral("lineEditPrixUnitaire"));

        verticalLayout_4->addWidget(lineEditPrixUnitaire);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        labelUnite = new QLabel(widget1);
        labelUnite->setObjectName(QStringLiteral("labelUnite"));

        verticalLayout_5->addWidget(labelUnite);

        lineEditUnite = new QLineEdit(widget1);
        lineEditUnite->setObjectName(QStringLiteral("lineEditUnite"));

        verticalLayout_5->addWidget(lineEditUnite);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        labelImage = new QLabel(widget1);
        labelImage->setObjectName(QStringLiteral("labelImage"));

        verticalLayout_6->addWidget(labelImage);

        pushButtonBrowsePicture = new QPushButton(widget1);
        pushButtonBrowsePicture->setObjectName(QStringLiteral("pushButtonBrowsePicture"));

        verticalLayout_6->addWidget(pushButtonBrowsePicture);


        horizontalLayout->addLayout(verticalLayout_6);

        tabWidget->addTab(tabProduit, QString());
        layoutWidget->raise();
        layoutWidget->raise();
        pushButtonAddProduit->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        labelTitleTabProduit->raise();
        labelImagePath->raise();
        tabRayon = new QWidget();
        tabRayon->setObjectName(QStringLiteral("tabRayon"));
        labelTitleTabRayon = new QLabel(tabRayon);
        labelTitleTabRayon->setObjectName(QStringLiteral("labelTitleTabRayon"));
        labelTitleTabRayon->setGeometry(QRect(180, 10, 361, 31));
        labelTitleTabRayon->setFont(font);
        widget2 = new QWidget(tabRayon);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(3, 370, 681, 30));
        horizontalLayout_4 = new QHBoxLayout(widget2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pushButtonAddRayon = new QPushButton(widget2);
        pushButtonAddRayon->setObjectName(QStringLiteral("pushButtonAddRayon"));

        horizontalLayout_4->addWidget(pushButtonAddRayon);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        widget3 = new QWidget(tabRayon);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(40, 60, 231, 56));
        verticalLayout_7 = new QVBoxLayout(widget3);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget3);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_7->addWidget(label);

        lineEditRayonLibelle = new QLineEdit(widget3);
        lineEditRayonLibelle->setObjectName(QStringLiteral("lineEditRayonLibelle"));

        verticalLayout_7->addWidget(lineEditRayonLibelle);

        tabWidget->addTab(tabRayon, QString());
        stackedWidget->addWidget(pageAjout);
        pageListe = new QWidget();
        pageListe->setObjectName(QStringLiteral("pageListe"));
        ajoutButtonPageListe = new QPushButton(pageListe);
        ajoutButtonPageListe->setObjectName(QStringLiteral("ajoutButtonPageListe"));
        ajoutButtonPageListe->setGeometry(QRect(0, 0, 101, 231));
        listeButtonPageListe = new QPushButton(pageListe);
        listeButtonPageListe->setObjectName(QStringLiteral("listeButtonPageListe"));
        listeButtonPageListe->setGeometry(QRect(0, 230, 101, 221));
        tableWidget = new QTableWidget(pageListe);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(200, 90, 401, 281));
        layoutWidget3 = new QWidget(pageListe);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(200, 50, 401, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBoxRayonListe = new QComboBox(layoutWidget3);
        comboBoxRayonListe->setObjectName(QStringLiteral("comboBoxRayonListe"));

        horizontalLayout_2->addWidget(comboBoxRayonListe);

        stackedWidget->addWidget(pageListe);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 819, 25));
        menuGestion_des_produits = new QMenu(menuBar);
        menuGestion_des_produits->setObjectName(QStringLiteral("menuGestion_des_produits"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuGestion_des_produits->menuAction());

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des produits", Q_NULLPTR));
        ajoutButtonPageAjout->setText(QApplication::translate("MainWindow", "Gestion", Q_NULLPTR));
        listeButtonPageAjout->setText(QApplication::translate("MainWindow", "Liste", Q_NULLPTR));
        labelLibelle->setText(QApplication::translate("MainWindow", "Libelle", Q_NULLPTR));
        labelDescription->setText(QApplication::translate("MainWindow", "Description", Q_NULLPTR));
        labelRayon->setText(QApplication::translate("MainWindow", "Rayon", Q_NULLPTR));
        labelTitleTabProduit->setText(QApplication::translate("MainWindow", "AJOUTER UN PRODUIT", Q_NULLPTR));
        labelImagePath->setText(QApplication::translate("MainWindow", "Aucune image selectionn\303\251e", Q_NULLPTR));
        pushButtonAddProduit->setText(QApplication::translate("MainWindow", "Valider", Q_NULLPTR));
        labelPrixUnitaire->setText(QApplication::translate("MainWindow", "Prix Unitaire", Q_NULLPTR));
        labelUnite->setText(QApplication::translate("MainWindow", "Unit\303\251", Q_NULLPTR));
        labelImage->setText(QApplication::translate("MainWindow", "Image", Q_NULLPTR));
        pushButtonBrowsePicture->setText(QApplication::translate("MainWindow", "Parcourir les fichiers...", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabProduit), QApplication::translate("MainWindow", "Produit", Q_NULLPTR));
        labelTitleTabRayon->setText(QApplication::translate("MainWindow", "AJOUTER UN RAYON", Q_NULLPTR));
        pushButtonAddRayon->setText(QApplication::translate("MainWindow", "Valider", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Libelle", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabRayon), QApplication::translate("MainWindow", "Rayon", Q_NULLPTR));
        ajoutButtonPageListe->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        listeButtonPageListe->setText(QApplication::translate("MainWindow", "Liste", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Libelle", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Description", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Prix Unitaire", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Quantite", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Rayon", Q_NULLPTR));
        menuGestion_des_produits->setTitle(QApplication::translate("MainWindow", "Gestion des produits", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
