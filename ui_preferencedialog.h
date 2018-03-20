/********************************************************************************
** Form generated from reading UI file 'preferencedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCEDIALOG_H
#define UI_PREFERENCEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_PreferenceDialog
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QLineEdit *lineEditWireshark;
    QLabel *label;

    void setupUi(QDialog *PreferenceDialog)
    {
        if (PreferenceDialog->objectName().isEmpty())
            PreferenceDialog->setObjectName(QStringLiteral("PreferenceDialog"));
        PreferenceDialog->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/decoder.png"), QSize(), QIcon::Normal, QIcon::Off);
        PreferenceDialog->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(PreferenceDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(PreferenceDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 381, 221));
        lineEditWireshark = new QLineEdit(groupBox);
        lineEditWireshark->setObjectName(QStringLiteral("lineEditWireshark"));
        lineEditWireshark->setGeometry(QRect(10, 100, 351, 20));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 80, 191, 16));

        retranslateUi(PreferenceDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PreferenceDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PreferenceDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PreferenceDialog);
    } // setupUi

    void retranslateUi(QDialog *PreferenceDialog)
    {
        PreferenceDialog->setWindowTitle(QApplication::translate("PreferenceDialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("PreferenceDialog", "Preferences", 0));
        lineEditWireshark->setPlaceholderText(QApplication::translate("PreferenceDialog", "Enter wireshark path", 0));
        label->setText(QApplication::translate("PreferenceDialog", "Wireshark Location", 0));
    } // retranslateUi

};

namespace Ui {
    class PreferenceDialog: public Ui_PreferenceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCEDIALOG_H
