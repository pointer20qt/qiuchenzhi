#include "registration.h"
#include "ui_registration.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>
Registration::Registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("20_sql");
    db.setUserName("root");
    db.setPassword("123456");
    if(db.open())
    {
        qDebug() << "数据库打开成功";
    }
    else
    {
         qDebug() << "数据库打开失败";
    }

}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_pushButton_clicked()
{
    QString userSno = ui->lineEdit->text();
    QString userName = ui->lineEdit_2->text();
    QString userClass = ui->lineEdit_3->text();
    QString userPwd = ui->lineEdit_4->text();
    QSqlQuery q;
    QString i =QString("insert  into 20_student values('%1','%2','%3','%4') ").arg(userSno).arg(userName).arg(userClass).arg(userPwd);
    if(q.exec(i))
    {
        QMessageBox::information(this,"注册成功","注册成功");
    }
    else
    {
        QMessageBox::warning(this,"warn","注册失败");
    }
    this->setWindowTitle("注册");
    this->close();
}
