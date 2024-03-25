#include <QMessageBox>
#include "loginform.h"
#include "ui_loginform.h"

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::setDatabase(std::shared_ptr<Database> dbPtr)
{
     m_dbPtr = dbPtr;
}

void LoginForm::on_buttonBox_accepted()
{
     auto userId = m_dbPtr->checkPassword(ui->loginEdit->text().toStdString(),
                                          ui->passwordEdit->text().toStdString());
     if(userId == -1){
         QMessageBox::critical(this, tr("Error"),
                               tr("Passwords IS wrong"));
         return;
     }

    emit accepted(userId,ui->loginEdit->text());
}


void LoginForm::on_buttonBox_rejected()
{
    emit rejected();
}


void LoginForm::on_registrationPushButton_clicked()
{
    emit registerRequested();
}

