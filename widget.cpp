#include "widget.h"
#include "ui_widget.h"
#include "qmessagebox.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbcoffee->setEnabled(false);
    ui->pbtea->setEnabled(false);
    ui->pbmilk->setEnabled(false);
    //button click-> enabled!
}


Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    changeMoney(10);
    checkMoney(money);
}


void Widget::on_pushButton_2_clicked()
{
    changeMoney(50);
    checkMoney(money);
}

void Widget::on_pushButton_3_clicked()
{
    changeMoney(100);
    checkMoney(money);
}

void Widget::on_pushButton_4_clicked()
{
    changeMoney(500);
    checkMoney(money);
}

void Widget::on_pbcoffee_clicked()
{
   changeMoney(-100);
   checkMoney(money);
}


void Widget::on_pbtea_clicked()
{
    changeMoney(-150);
    checkMoney(money);
}

void Widget::on_pbmilk_clicked()
{
    changeMoney(-200);
    checkMoney(money);
}


void Widget::on_pbreset_clicked()
{
    QMessageBox m;
    checkCharge(money);
    m.information(nullptr,"잔돈이 남았습니다.", QString("잔돈은 %1원입니다.\n 500원 : %2개\n "
                                                "100원 : %3개\n 50원 : %4개\n 10원 : %5개입니다. ")
                  .arg(money).arg(n_500).arg(n_100).arg(n_50).arg(n_10)); //잔돈출력
}


