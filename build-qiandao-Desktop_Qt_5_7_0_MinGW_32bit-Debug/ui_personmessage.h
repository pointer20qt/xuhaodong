/********************************************************************************
** Form generated from reading UI file 'personmessage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONMESSAGE_H
#define UI_PERSONMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonMessage
{
public:
    QCalendarWidget *calendarWidget;
    QLabel *label_6;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_4;
    QLabel *label_5;
    QProgressBar *progressBar;

    void setupUi(QWidget *PersonMessage)
    {
        if (PersonMessage->objectName().isEmpty())
            PersonMessage->setObjectName(QStringLiteral("PersonMessage"));
        PersonMessage->resize(452, 670);
        calendarWidget = new QCalendarWidget(PersonMessage);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(0, 200, 451, 281));
        label_6 = new QLabel(PersonMessage);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 20, 151, 151));
        label_6->setStyleSheet(QLatin1String("font: 75 12pt \"Arial\";\n"
"border-image: url(:/back/style/user.png);"));
        layoutWidget = new QWidget(PersonMessage);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(270, 10, 171, 181));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_7 = new QLabel(PersonMessage);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, -20, 461, 701));
        label_7->setStyleSheet(QStringLiteral("border-image: url(:/back/style/third.png);"));
        label_8 = new QLabel(PersonMessage);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(0, 484, 451, 191));
        label_8->setStyleSheet(QStringLiteral("background-color: rgb(215, 255, 243);"));
        label_4 = new QLabel(PersonMessage);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 520, 83, 16));
        label_5 = new QLabel(PersonMessage);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(31, 564, 84, 16));
        progressBar = new QProgressBar(PersonMessage);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(30, 610, 411, 23));
        progressBar->setValue(24);
        label_8->raise();
        label_7->raise();
        calendarWidget->raise();
        label_6->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        label_4->raise();
        label_5->raise();
        progressBar->raise();

        retranslateUi(PersonMessage);

        QMetaObject::connectSlotsByName(PersonMessage);
    } // setupUi

    void retranslateUi(QWidget *PersonMessage)
    {
        PersonMessage->setWindowTitle(QApplication::translate("PersonMessage", "Form", 0));
        label_6->setText(QString());
        label->setText(QApplication::translate("PersonMessage", "\345\255\246\345\217\267:2559926", 0));
        label_2->setText(QApplication::translate("PersonMessage", "\345\247\223\345\220\215:\345\206\257\346\235\274\346\273\250", 0));
        label_3->setText(QApplication::translate("PersonMessage", "\347\217\255\347\272\247\357\274\2323-108", 0));
        label_7->setText(QString());
        label_8->setText(QString());
        label_4->setText(QApplication::translate("PersonMessage", "\347\255\276\345\210\260\346\254\241\346\225\260\357\274\2321", 0));
        label_5->setText(QApplication::translate("PersonMessage", "\345\207\272\345\213\244\347\216\207\357\274\23224%", 0));
    } // retranslateUi

};

namespace Ui {
    class PersonMessage: public Ui_PersonMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONMESSAGE_H
