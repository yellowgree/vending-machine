#include "widget.h"
#include "ui_widget.h"
#include "qmessagebox.h"

int money(0);

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void changeMoney(int diff);
void Widget::changeMoney(int diff)
{
        money += diff;
    ui->lcdNumber->display(money);
    changeEnable();


}

void Widget::changeEnable()
{

    ui->pbcoffie->setEnabled(money>=100);
    ui->pbtang->setEnabled(money>=300);
    ui->pbTea->setEnabled(money>=200);



}

void Widget::on_pushButton_clicked()
{


}

void Widget::on_pbcoin10_clicked()
{
    changeMoney(10);

}


void Widget::on_pbcoin50_clicked()
{
    changeMoney(50);
}



void Widget::on_pbcoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbcoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbcoffie_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbtang_clicked()
{
    changeMoney(-300);
}


void Widget::on_pbreset_clicked()
{
    QMessageBox nb;
    int c100=0, c10=0, c500=0;

    c10 =  ((money%500)%100)/10;
    c100 = (money%500)/100;
    c500 = money/500;



    nb.information(nullptr, "coin reset", QString("coin10:%1\n coin100:%2\n coin500:%3\n").arg(c10).arg(c100).arg(c500));

    changeMoney(-money);


}

