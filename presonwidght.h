#ifndef PRESONWIDGHT_H
#define PRESONWIDGHT_H

#include <QWidget>

namespace Ui {
class presonWidght;
}

class presonWidght : public QWidget
{
    Q_OBJECT

public:
    explicit presonWidght(QWidget *parent = 0);
    ~presonWidght();
    void init(QString sno,QString sname);

private:
    Ui::presonWidght *ui;
};

#endif // PRESONWIDGHT_H
