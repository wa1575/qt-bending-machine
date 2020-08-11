#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "ui_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int money {0}; 
    int n_500{0};
    int n_100{0};
    int n_50{0};
    int n_10{0};
    void changeMoney(int diff){
        money += diff;  
    } 
    void checkMoney(int money){
        ui->lcdNumber->display(money);
        if(money>=100) ui->pbcoffee->setEnabled(true);
        if(money>=150) ui->pbtea->setEnabled(true);
        if(money>=200) ui->pbmilk->setEnabled(true);
    }
    void checkCharge(int charge){
        n_500 = charge/500;
        n_100 = (charge % 500)/100;
        n_50 = (charge % 100)/50;
        n_10 = (charge % 50)/10;
    }


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pbcoffee_clicked();

    void on_pbtea_clicked();

    void on_pbmilk_clicked();

    void on_pbreset_clicked();

private:
    Ui::Widget *ui;
};



#endif // WIDGET_H
