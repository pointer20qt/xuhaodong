#include "personmessage.h"
#include "ui_personmessage.h"
#include <QSqlQuery>
#include <QTextCharFormat>

PersonMessage::PersonMessage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonMessage)
{
    ui->setupUi(this);

    //界面美化
    this->setWindowIcon(QIcon(":/back/style/)NY3HDB6G_{N60CEK%_094A.png"));
    this->setWindowTitle("个人信息");

}
void PersonMessage::init(QString sno,QString name,QString _class )
{
    ui->label->setText("学号："+sno);
    ui->label_2->setText("姓名："+name);
    ui->label_3->setText("班级: "+_class);

    QSqlQuery q;
    q.next();
    q.exec(QString("select *from signer where sno='%1' and date_format(sign_date,'%Y-%m')="
           "date_format(curdate(),'%Y-%m')").arg(sno));
    ui->label_4->setText("签到次数: "+QString::number(q.size()));


    QTextCharFormat f;
    f.setBackground(Qt::green);
    f.setBackground(Qt::red);

    ui->calendarWidget->setDateTextFormat(q.value(0).toDate(),f);
}

PersonMessage::~PersonMessage()
{
    delete ui;
}
