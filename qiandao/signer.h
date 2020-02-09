#ifndef SIGNER_H
#define SIGNER_H

#include <QWidget>

namespace Ui {
class signer;
}

class signer : public QWidget
{
    Q_OBJECT

public:
    explicit signer(QWidget *parent = 0);
    void SignTodatabase(QString sql);
    void LogTodatabase(QString sql);

    QString sno,sname,classs,pwd;
    ~signer();

private:
    Ui::signer *ui;
};

#endif // SIGNER_H
