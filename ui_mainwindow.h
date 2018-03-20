/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Exit;
    QAction *action_Copy;
    QAction *action_Paste;
    QAction *action_Cut;
    QAction *action_About_Decoder;
    QAction *action_Support;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLineEdit *lineEditData;
    QGroupBox *groupBox_2;
    QComboBox *comboBoxProtocol;
    QPushButton *pushButtonDecode;
    QPushButton *pushButtonClear;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButtonGsm;
    QRadioButton *radioButtonUmts;
    QRadioButton *radioButtonLte;
    QGroupBox *groupBox_3;
    QTextEdit *textEditDecoded;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Edit;
    QMenu *menu_Help;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(712, 726);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/decoder.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        action_Copy = new QAction(MainWindow);
        action_Copy->setObjectName(QStringLiteral("action_Copy"));
        action_Paste = new QAction(MainWindow);
        action_Paste->setObjectName(QStringLiteral("action_Paste"));
        action_Cut = new QAction(MainWindow);
        action_Cut->setObjectName(QStringLiteral("action_Cut"));
        action_About_Decoder = new QAction(MainWindow);
        action_About_Decoder->setObjectName(QStringLiteral("action_About_Decoder"));
        action_Support = new QAction(MainWindow);
        action_Support->setObjectName(QStringLiteral("action_Support"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 691, 80));
        lineEditData = new QLineEdit(groupBox);
        lineEditData->setObjectName(QStringLiteral("lineEditData"));
        lineEditData->setGeometry(QRect(10, 30, 671, 31));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 100, 691, 80));
        comboBoxProtocol = new QComboBox(groupBox_2);
        comboBoxProtocol->setObjectName(QStringLiteral("comboBoxProtocol"));
        comboBoxProtocol->setGeometry(QRect(10, 50, 181, 22));
        pushButtonDecode = new QPushButton(groupBox_2);
        pushButtonDecode->setObjectName(QStringLiteral("pushButtonDecode"));
        pushButtonDecode->setGeometry(QRect(490, 50, 75, 23));
        pushButtonClear = new QPushButton(groupBox_2);
        pushButtonClear->setObjectName(QStringLiteral("pushButtonClear"));
        pushButtonClear->setGeometry(QRect(580, 50, 75, 23));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 174, 23));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButtonGsm = new QRadioButton(layoutWidget);
        radioButtonGsm->setObjectName(QStringLiteral("radioButtonGsm"));

        horizontalLayout->addWidget(radioButtonGsm);

        radioButtonUmts = new QRadioButton(layoutWidget);
        radioButtonUmts->setObjectName(QStringLiteral("radioButtonUmts"));

        horizontalLayout->addWidget(radioButtonUmts);

        radioButtonLte = new QRadioButton(layoutWidget);
        radioButtonLte->setObjectName(QStringLiteral("radioButtonLte"));
        radioButtonLte->setChecked(true);

        horizontalLayout->addWidget(radioButtonLte);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 200, 691, 471));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        textEditDecoded = new QTextEdit(groupBox_3);
        textEditDecoded->setObjectName(QStringLiteral("textEditDecoded"));
        textEditDecoded->setGeometry(QRect(10, 20, 671, 441));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 712, 20));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_Edit = new QMenu(menuBar);
        menu_Edit->setObjectName(QStringLiteral("menu_Edit"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setMovable(false);
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setEnabled(false);
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Edit->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_File->addAction(action_Exit);
        menu_Edit->addAction(action_Copy);
        menu_Edit->addAction(action_Cut);
        menu_Edit->addAction(action_Paste);
        menu_Help->addAction(action_About_Decoder);
        menu_Help->addAction(action_Support);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "3GPP Decoder Linux", 0));
        action_Exit->setText(QApplication::translate("MainWindow", "&Exit", 0));
        action_Copy->setText(QApplication::translate("MainWindow", "&Copy", 0));
        action_Paste->setText(QApplication::translate("MainWindow", "&Paste", 0));
        action_Cut->setText(QApplication::translate("MainWindow", "&Cut", 0));
        action_About_Decoder->setText(QApplication::translate("MainWindow", "&About Decoder", 0));
        action_Support->setText(QApplication::translate("MainWindow", "&Support", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Enter Hex data to be decoded", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Protocol options", 0));
        comboBoxProtocol->setCurrentText(QString());
        pushButtonDecode->setText(QApplication::translate("MainWindow", "Decode", 0));
        pushButtonClear->setText(QApplication::translate("MainWindow", "Clear all", 0));
        radioButtonGsm->setText(QApplication::translate("MainWindow", "GSM", 0));
        radioButtonUmts->setText(QApplication::translate("MainWindow", "UMTS", 0));
        radioButtonLte->setText(QApplication::translate("MainWindow", "LTE", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Decoded data", 0));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0));
        menu_Edit->setTitle(QApplication::translate("MainWindow", "&Edit", 0));
        menu_Help->setTitle(QApplication::translate("MainWindow", "&Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
