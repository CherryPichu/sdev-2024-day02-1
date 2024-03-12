#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <String>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    refresh();
}

void changeMoney(int diff);

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int coin){
    money += coin;
    ui->lcdNumber->display(money);
}

void Widget::refresh(){


    ui->pbCoffee->setEnabled( money >= 100 );
    ui->pbJuice->setEnabled( money >= 200 );
    ui->pbCola->setEnabled( money >= 300 );

    // if(money < 100){ // coofe
    //     ui->pbCoffee->setEnabled(false);
    // }else{
    //     ui->pbCoffee->setEnabled(true);
    // }
    // if(money < 200){
    //     ui->pbJuice->setEnabled(false);
    // }else{
    //     ui->pbJuice->setEnabled(true);
    // }
    // if(money < 300){
    //     ui->pbCola->setEnabled(false);
    // }else{
    //     ui->pbCola->setEnabled(true);
    // }
}

void Widget::on_pb10Coin_clicked()
{
    changeMoney(10);
    refresh();
}


void Widget::on_pb50Coin_clicked()
{
    changeMoney(50);
    refresh();
}


void Widget::on_pb100Coin_clicked()
{
    changeMoney(100);
    refresh();
}


void Widget::on_pbJuice_clicked()
{
    changeMoney(-200);
    refresh();
}

void Widget::on_pbCola_clicked()
{
    changeMoney(-300);
    refresh();
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
    refresh();
}


void Widget::on_Reset_clicked()
{
    QMessageBox box;

    QString str = "100원 금액 : " + QString::number( money / 100 ) +
        "\n50원 금액 : " + QString::number( money % 100 / 50 ) +
        "\n10원 금액 : " + QString::number( money % 100 % 50 / 10 );

    changeMoney(-money);

    box.information(nullptr, "나머지 금액", str);
    box.show();
    refresh();
}

