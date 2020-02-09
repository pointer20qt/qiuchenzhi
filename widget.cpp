#include "widget.h"
#include "ui_widget.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QTableWidgetItem>
#include <QCheckBox>
#include <QDateTime>
#include <QMessageBox>
#include "presonWidght.h"
Widget::Widget(QWidget *parent,QString sname) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->sname =sname;
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
    dataToTable("select *from 20_student");
    displayClass();
    displaySno();
    signinDate();
}
void Widget::signinDate()
{
    //在日历中显示签到日期
    connect(ui->tableWidget,QTableWidget::cellDoubleClicked,[=](int r,int c){
        presonWidght* p = new presonWidght();
        p->init(ui->tableWidget->item(r,0)->text(),ui->tableWidget->item(r,1)->text());
        p->show();
    });

}
void  Widget::displaySno()
{
    connect(ui->pushButton,QPushButton::clicked,[=](){
        if(ui->lineEdit->text().isEmpty())
        {
            QMessageBox::warning(this,"warn","输入为空");
        }
        else
        {
            dataToTable(QString("select * from 20_student where sno like '%1'").arg(ui->lineEdit->text()));
        }
    });

}
void Widget::displayClass()
{
    QSqlQuery q4;
    q4.exec("select distinct class from 20_student");
    ui->comboBox->addItem("全部班级");
    while(q4.next())
    {
        ui->comboBox->addItem(q4.value(0).toString());
    }

    connect(ui->comboBox,QComboBox::currentTextChanged,[=](QString text){
        if(text=="全部班级")
        {
            dataToTable("select *from 20_student");
        }
        else
        {
            dataToTable(QString("select * from 20_student where class = '%1'").arg(text));
        }

    });
}
void Widget::dataToTable(QString sql)
{


    QSqlQuery q;
    q.exec(QString("select sno from 20_student where sname ='%1'").arg(this->sname));
    qDebug()<< this->sname;
    q.next();
    QString cursno = q.value(0).toString();
    qDebug()<<q.value(0).toString();
    if(q.exec(sql))
    {
       ui->tableWidget->setRowCount(q.size());
       int i =0;
       while(q.next())
       {
           QCheckBox *c = new QCheckBox("未签到");
           QString sno = q.value(0).toString();
           QSqlQuery q3;
           q3.exec(QString("select signtime from 20_signinfo "
                           "where sno =%1 and date(signtime) = curdate()"
                           "order by signtime desc;").arg(sno));
           q3.next();
           if(sno!=cursno)
           {
               c->setDisabled(true);
           }
           if(q3.size())
           {
               c->setText("已签到");
               c->setDisabled(true);
               c->setChecked(true);
               ui->tableWidget->setItem(i,4,new QTableWidgetItem(q3.value(0).toString()));
           }
           ui->tableWidget->setItem(i,0,new QTableWidgetItem(sno));
           ui->tableWidget->setItem(i,1,new QTableWidgetItem(q.value(1).toString()));
           ui->tableWidget->setItem(i,2,new QTableWidgetItem(q.value(2).toString()));
           ui->tableWidget->setCellWidget(i,3,c);
           connect(c,QCheckBox::clicked,[=](){
               //修改控件本身状态
               c->setText("已签到");
               c->setDisabled(true);
               // 向表格中添加签到时间
               ui->tableWidget->setItem(i,4,new QTableWidgetItem(QDateTime::currentDateTime().toString()));

               QSqlQuery q1;
               q1.exec(QString("insert into 20_signinfo values(%1,now())").arg(sno));
           });
           i++;
       }

    this->setWindowTitle("签到");

    }
}
Widget::~Widget()
{
    delete ui;
}
