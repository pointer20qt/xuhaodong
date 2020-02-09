#ifndef PERSONMESSAGE_H
#define PERSONMESSAGE_H

#include <QWidget>

namespace Ui {
class PersonMessage;
}

class PersonMessage : public QWidget
{
    Q_OBJECT

public:
    explicit PersonMessage(QWidget *parent = 0);
    ~PersonMessage();
    void init(QString sno, QString name, QString _class);

private:
    Ui::PersonMessage *ui;
};

#endif // PERSONMESSAGE_H
