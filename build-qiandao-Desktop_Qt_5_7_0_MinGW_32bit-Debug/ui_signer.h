/********************************************************************************
** Form generated from reading UI file 'signer.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNER_H
#define UI_SIGNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signer
{
public:
    QLabel *label_2;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButton;
    QLineEdit *lineEdit2;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QWidget *tab_2;
    QLabel *label_7;
    QPushButton *pushButton_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_8;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;

    void setupUi(QWidget *signer)
    {
        if (signer->objectName().isEmpty())
            signer->setObjectName(QStringLiteral("signer"));
        signer->resize(803, 515);
        signer->setStyleSheet(QStringLiteral("\"border:2px groove gray;border-radius:10px;padding:2px 4px;\""));
        label_2 = new QLabel(signer);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(370, 100, 151, 61));
        label_2->setStyleSheet(QLatin1String("font: 75 14pt \"Arial\";\n"
"color: rgb(14, 6, 255);"));
        label = new QLabel(signer);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 801, 521));
        label->setStyleSheet(QStringLiteral("border-image: url(:/back/style/first.png);"));
        tabWidget = new QTabWidget(signer);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(370, 160, 421, 251));
        tabWidget->setStyleSheet(QString::fromUtf8("\342\200\234venus\342\200\223TitleBar {\"background-color:rgba(244,244,244,2)\";border:none;}\342\200\235"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 130, 231, 51));
        pushButton->setStyleSheet(QStringLiteral(""));
        lineEdit2 = new QLineEdit(tab);
        lineEdit2->setObjectName(QStringLiteral("lineEdit2"));
        lineEdit2->setGeometry(QRect(100, 80, 261, 41));
        lineEdit2->setStyleSheet(QStringLiteral("font: 18pt \"Arial\";"));
        lineEdit2->setEchoMode(QLineEdit::Password);
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(9, 16, 61, 41));
        label_4->setStyleSheet(QLatin1String("color: rgb(255, 39, 42);\n"
"font: 75 9pt \"Arial\";"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 80, 71, 41));
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 39, 42);"));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(100, 20, 261, 41));
        lineEdit->setStyleSheet(QStringLiteral("font: 18pt \"Arial\";"));
        tabWidget->addTab(tab, QString());
        lineEdit->raise();
        label_3->raise();
        label_4->raise();
        lineEdit2->raise();
        pushButton->raise();
        label->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_2->setEnabled(true);
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 10, 111, 16));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 180, 93, 28));
        widget = new QWidget(tab_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(89, 26, 62, 151));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 83, 114);"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QStringLiteral("color: rgb(255, 70, 82);"));

        verticalLayout->addWidget(label_6);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setStyleSheet(QStringLiteral("color: rgb(255, 83, 114);"));

        verticalLayout->addWidget(label_9);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QStringLiteral("color: rgb(255, 70, 82);"));

        verticalLayout->addWidget(label_8);

        widget1 = new QWidget(tab_2);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(170, 20, 173, 161));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_2 = new QLineEdit(widget1);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(widget1);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        verticalLayout_2->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(widget1);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        verticalLayout_2->addWidget(lineEdit_4);

        lineEdit_5 = new QLineEdit(widget1);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(lineEdit_5);

        tabWidget->addTab(tab_2, QString());
        label->raise();
        label_2->raise();
        tabWidget->raise();

        retranslateUi(signer);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(signer);
    } // setupUi

    void retranslateUi(QWidget *signer)
    {
        signer->setWindowTitle(QApplication::translate("signer", "Form", 0));
        label_2->setText(QApplication::translate("signer", "\346\214\207\351\222\210\347\255\276\345\210\260\347\263\273\347\273\237", 0));
        label->setText(QString());
        pushButton->setText(QApplication::translate("signer", "sign_in", 0));
        lineEdit2->setText(QApplication::translate("signer", "123456", 0));
        label_4->setText(QApplication::translate("signer", "\350\264\246\346\210\267\345\220\215\357\274\232", 0));
        label_3->setText(QApplication::translate("signer", "\345\257\206\347\240\201\357\274\232", 0));
        lineEdit->setText(QApplication::translate("signer", "2559926", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("signer", "\347\231\273\345\275\225", 0));
        label_7->setText(QApplication::translate("signer", "*\350\241\250\347\244\272\344\270\215\345\217\257\344\270\272\347\251\272", 0));
        pushButton_2->setText(QApplication::translate("signer", "\346\263\250\345\206\214", 0));
        label_5->setText(QApplication::translate("signer", "\350\264\246\346\210\267\345\220\215\357\274\232", 0));
        label_6->setText(QApplication::translate("signer", "\345\247\223\345\220\215\357\274\232", 0));
        label_9->setText(QApplication::translate("signer", "\347\217\255\347\272\247\357\274\232", 0));
        label_8->setText(QApplication::translate("signer", "\345\257\206\347\240\201\357\274\232", 0));
        lineEdit_2->setText(QApplication::translate("signer", "*", 0));
        lineEdit_3->setText(QApplication::translate("signer", "*", 0));
        lineEdit_4->setText(QApplication::translate("signer", "*", 0));
        lineEdit_5->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("signer", "\346\263\250\345\206\214", 0));
    } // retranslateUi

};

namespace Ui {
    class signer: public Ui_signer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNER_H
