#include "signer.h"
#include "ui_signer.h"
#include <Qlabel>
#include <QSqlQuery>
#include <QMessageBox>
#include "widget.h"
#include <QPalette>
#include <QBitmap>

signer::signer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signer)
{
    ui->setupUi(this);
    this->setWindowTitle("pointer_sign System");
    this->setWindowIcon(QIcon(":/back/style/)NY3HDB6G_{N60CEK%_094A.png"));
//    QPalette pal = palette();
//    pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
//    this->setPalette(pal);

    connect(ui->pushButton,QPushButton::clicked,[=](){
        if(ui->lineEdit->text().isEmpty()||ui->lineEdit2->text().isEmpty())
        {
            QMessageBox::warning(this,"warn","你输入账户名或密码为空！");
        }
        else
        {
            SignTodatabase(QString("select sno,pwd from stu where sno = '%1'").arg(ui->lineEdit->text()));
        }
    });
    connect(ui->pushButton_2,QPushButton::clicked,[=](){
       sno=ui->lineEdit_2->text();
       sname=ui->lineEdit_3->text();
       classs=ui->lineEdit_4->text();
       pwd=ui->lineEdit_5->text();

       if(sno==NULL||sname==NULL||classs==NULL||pwd==NULL)
       {
           QMessageBox::warning(this,"warn","您还有未填写项！");
       }
       else
       {

           LogTodatabase(QString("insert into stu values('%1','%2','%3','%4')").arg(sno).arg(sname).arg(classs).arg(pwd));
       }
    });
    //界面美化
    ui->tabWidget->setStyleSheet("QTabWidget::tab-bar{alignment:left;}QTabBar::tab{background:transparent;color:white;min-width:30ex;min-height:10ex;}QTabBar::tab:selected{border-color: white;background:white;color:green;}QTabWidget:pane{border: none; top: -1px;background: transparent;}");
}
//登录
void signer::SignTodatabase(QString sql)
{

    QSqlQuery q1;
    q1.exec(sql);
    q1.next();
    if(q1.size()==0)
    {
        QMessageBox::warning(this,"warn","该账户名不存在！");
    }
    else
    {
        if(q1.value(1).toString()==ui->lineEdit2->text())
        {
            Widget *c=new Widget(NULL,ui->lineEdit->text());
            c->show();
            this->close();
            c->displayClass();
            c->displaySno();
            c->sname=ui->lineEdit->text();
        }
        else
        {
            QMessageBox::warning(this,"warn","密码错误！");
        }
    }
}
//注册
void signer::LogTodatabase(QString sql)
{
    QSqlQuery q2;
    if(q2.exec(sql)==true)
    {
        QMessageBox::information(this,"log is ok!","注册成功！请前往登录！");
    }
    else
    {
        QMessageBox::warning(this,"warn","该账户名已存在！");
    }
}

signer::~signer()
{
    delete ui;
}
