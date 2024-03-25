/********************************************************************************
** Form generated from reading UI file 'startscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#pragma once

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include "sources/registrationform.h"
#include "sources/loginform.h"
QT_BEGIN_NAMESPACE

class Ui_StartScreen
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    LoginForm *loginWidget;
    QVBoxLayout *verticalLayout_2;
    RegistrationForm *registerWidget;

    void setupUi(QDialog *StartScreen)
    {
        if (StartScreen->objectName().isEmpty())
            StartScreen->setObjectName(QString::fromUtf8("StartScreen"));
        StartScreen->resize(351, 332);
        verticalLayout = new QVBoxLayout(StartScreen);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(StartScreen);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        loginWidget = new LoginForm();
        loginWidget->setObjectName(QString::fromUtf8("loginWidget"));
        verticalLayout_2 = new QVBoxLayout(loginWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        stackedWidget->addWidget(loginWidget);
        registerWidget = new RegistrationForm();
        registerWidget->setObjectName(QString::fromUtf8("registerWidget"));
        stackedWidget->addWidget(registerWidget);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(StartScreen);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(StartScreen);
    } // setupUi

    void retranslateUi(QDialog *StartScreen)
    {
        StartScreen->setWindowTitle(QApplication::translate("StartScreen", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartScreen: public Ui_StartScreen {};
} // namespace Ui

QT_END_NAMESPACE
