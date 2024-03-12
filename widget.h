#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int money{0};
    void changeMoney(int diff);
    void refresh();

private slots:
    void on_pb10Coin_clicked();

    void on_pb50Coin_clicked();

    void on_pb50Coin_3_clicked();

    void on_pbJuice_clicked();

    void on_pbCoffee_clicked();

    void on_pb100Coin_clicked();

    void on_pbCola_clicked();

    void on_Reset_clicked();

    void on_pb100Coin_2_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
