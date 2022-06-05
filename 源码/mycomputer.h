#ifndef MYCOMPUTER_H
#define MYCOMPUTER_H

#include <QWidget>
#include <QKeyEvent>

namespace Ui {
class MyComputer;
}

class MyComputer : public QWidget
{
    Q_OBJECT

public:
    explicit MyComputer(QWidget *parent = 0);
    ~MyComputer();

    void Attack(QString s);
    void MyAppend(int m);
    void Send(int m);

private slots:
    void on_btn_0_clicked();

    void on_btn_1_clicked();

    void on_btn_add_clicked();

    void on_btn_equal_clicked();

    void on_btn_2_clicked();

    void on_btn_3_clicked();

    void on_btn_4_clicked();

    void on_btn_5_clicked();

    void on_btn_6_clicked();

    void on_btn_7_clicked();

    void on_btn_8_clicked();

    void on_btn_9_clicked();

    void on_btn_subtract_clicked();

    void on_btn_multiply_clicked();

    void on_btn_divide_clicked();

    void on_btn_clear_clicked();

    //void on_btn_back_clicked();

    void on_btn_pi_clicked();

    void on_btn_point_clicked();

protected:
    //重写画家事件  即获取键盘的输入值
    void keyPressEvent(QKeyEvent *);

private:
    Ui::MyComputer *ui;

    float num = 0;  //输入的数字
    float sum = 0;      //计算结果
    int b;   //判断最后一个运算符
    int ch;  //代表符号的特征值
    int m;    //判断输入的数字
    QString str;  //输入的数据  包括运算符
    float num1;   //小数的整数部分
    float num2;   //小数的小数部分
    int j = 1;  //判断Send()函数调用的次数
    bool IsBack = false;

    bool Is = false;   //判断是否为小数
};

#endif // MYCOMPUTER_H
