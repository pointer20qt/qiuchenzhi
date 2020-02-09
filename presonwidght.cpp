#include "presonwidght.h"
#include "ui_presonwidght.h"
#include <QSqlQuery>
#include <QTextCharFormat>
#include <QProgressBar>
presonWidght::presonWidght(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::presonWidght)
{
    ui->setupUi(this);
}

void presonWidght::init(QString sno,QString sname)
{
    ui->label->setText("学号："+sno);
    ui->label_2->setText("姓名："+sname);
    QSqlQuery q;
    q.exec(QString("select signtime from 20_signinfo "
           "where sno = %1 and date_format(signtime,'%Y-%m')"
           " = date_format(curdate(),'%Y-%m')").arg(sno));
    ui->label_3->setText("次数: "+QString::number(q.size()));
    ui->progressBar->setRange(0,q.value(1).toInt());
    ui->progressBar->setValue(q.value(0).toInt());
    QTextCharFormat f;
    f.setBackground(Qt::yellow);
    f.setForeground(Qt::blue);
    while(q.next())
    {
        ui->calendarWidget->setDateTextFormat(q.value(0).toDate(),f);
    }
    this->setWindowTitle("签到次数及日期");
}
presonWidght::~presonWidght()
{
    delete ui;
}
