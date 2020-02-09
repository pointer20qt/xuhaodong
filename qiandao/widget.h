#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlQuery>
#include <QCheckBox>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0,QString sname=NULL);


    void DataToTable(QString sql);
    void displayClass();
    void displaySno();
    void init(QString sno);

    QString text,sname;
    ~Widget();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
