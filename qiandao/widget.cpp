#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QSqlDatabase>
#include <qDebug>
#include <QSqlQuery>
#include <QCheckBox>
#include <QComboBox>
#include <QDateTime>
#include <QMessageBox>
#include "personmessage.h"

Widget::Widget(QWidget *parent, QString sname) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->sname=sname;
    DataToTable("select * from stu");
    displayClass();
    displaySno();

    //界面美化
    this->setWindowTitle("签到统计");
    this->setWindowIcon(QIcon(":/back/style/)NY3HDB6G_{N60CEK%_094A.png"));
    ui->tableWidget->setFrameShape(QFrame::NoFrame);

    ui->tableWidget->setStyleSheet("alternate-background-color:rgb(48,51,55);selection-background-color:qlineargradient(x1:0,y1:0, x2:0, y2:1, stop:0 rgb(56,56,56),stop:1 rgb(76,76,76));");
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

//班级查询 下拉框
void Widget::displayClass()
{
    QSqlQuery q4;
    q4.exec("select distinct class from stu");
    ui->comboBox->addItem("全部班级");
    while(q4.next())
    {
        ui->comboBox->addItem(q4.value(0).toString());
    }
    connect(ui->comboBox,QComboBox::currentTextChanged,[=](QString text){
        if(text=="全部班级")
        {
            DataToTable("select *from stu");
        }
        else
        {
            DataToTable(QString("select * from stu where class='%1'").arg(text));
        }
    });
}
//学号查询
void Widget::displaySno()
{
    connect(ui->pushButton,QPushButton::clicked,[=](){
        if(ui->lineEdit->text().isEmpty())
        {
            QMessageBox::warning(this,"warn","你输入为空！");
        }
        else
        {
            DataToTable(QString("select *from stu where sno like '%%1%'").arg(ui->lineEdit->text()));
        }
    });
}
//填充数据到控件
void Widget::DataToTable(QString sql)
{
    QSqlQuery q;
    q.exec(sql);
    ui->tableWidget->setRowCount(q.size());
    qDebug()<<q.size();
    int i=0;//；列的编号
    while(q.next())
    {
        QCheckBox *c=new QCheckBox("未签到");
        QString sno=q.value(0).toString();
        //数据库内签到更新
        QSqlQuery q2;
        q2.exec(QString("select sign_date from signer where sno='%1' and date(sign_date)=curdate() order by sign_date desc").arg(sno));
        q2.next();
        qDebug()<<q2.value(0);
        if(sno!=sname)
        {
            c->setDisabled(true);
        }
        if(q2.size())
        {
            c->setText("已签到");
            c->setDisabled(true);
            c->setChecked(true);
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(q2.value(0).toString()));
        }
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(q.value(0).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(q.value(1).toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(q.value(2).toString()));
        ui->tableWidget->setCellWidget(i,3,c);



        connect(c,QCheckBox::clicked,[=](){
            //表格内修改与填充
            c->setText("已签到");
            c->setDisabled(true);
            c->setChecked(true);
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(QDateTime::currentDateTime().toString()));
            //数据库修改
            QSqlQuery q1;
            q1.exec(QString("insert into signer values('%1',now())").arg(sno));
        });
        i++;
    }
    connect(ui->tableWidget,QTableWidget::cellDoubleClicked,[=](int r,int c){
        PersonMessage *p=new PersonMessage();
        p->init(ui->tableWidget->item(r,0)->text(),ui->tableWidget->item(r,1)->text(),ui->tableWidget->item(r,2)->text());
        p->show();
    });
}


Widget::~Widget()
{
    delete ui;
}
