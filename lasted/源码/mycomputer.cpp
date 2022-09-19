/*
 * 本计算器是利用输入的数据分析数的性质来进行运算
 * 这个只支持简单的加减乘除的运算
 * 并且不支持多个运算符的计算
 * 但支持小数之间的运算
 * 使用说明
 * 支持键盘输入  其中需要注意的是
 * “delete”键 是清除键  “Alt”键 相当于“=”  “Esc”键 是退出本窗口
*/
#include "mycomputer.h"
#include "ui_mycomputer.h"
#include "snake.h"
#include "painter.h"

#include <QDebug>
#include <QtMath>
#include <QPushButton>

//MyComputer 继承 QWidget
MyComputer::MyComputer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyComputer)
{
    ui->setupUi(this);

    //初始化窗口
    this->setFixedSize(600,600);
    this->setWindowTitle("Computer");
    this->setWindowIcon(QIcon(":/Image/11.jpg"));

    //按钮btn_snake 触发信号  即计算器中的 “贪吃蛇”  按钮
    connect(ui->btn_snake, &QPushButton::clicked, this, [=](){
        //关闭本窗口
        this->close();
        //给新窗口分配空间
        Snake * w2 = new Snake;
        w2->show();
    });

    //按钮btn_painter 触发信号  即计算器中的 “绘图”  按钮
    connect(ui->btn_painter, &QPushButton::clicked, this, [=](){
        this->close();
        Painter * w3 = new Painter;
        w3->show();
    });
}

//析构函数
MyComputer::~MyComputer()
{
    delete ui;
}

//数字0
void MyComputer::on_btn_0_clicked()
{
    m = 0;
    Send(m);
}

//数字1
void MyComputer::on_btn_1_clicked()
{
    m = 1;
    Send(m);
}

//“+”按钮  加法
void MyComputer::on_btn_add_clicked()
{
    ch = 0;
    Attack(QString("+"));
    b = 0;
}

//“=”按钮
void MyComputer::on_btn_equal_clicked()
{
    ch = 11;
    Attack(QString("="));
    //在textEdit_2中输出结果
    ui->textEdit_2->append(QString("%1").arg(sum));
    //按过“=”后 置sum = 0
    sum = 0;
}

//输入运算符时  向textEdit追加运算符  textEdit_2是保存所有的输入数据
 void MyComputer::Attack(QString s)
 {
     if(Is){
         num = 10 * (num1+num2);
         //qDebug()<<num;
         Is = false;
         j = 1;
     }

     //捕捉光标
     ui->textEdit->moveCursor(QTextCursor::End);
     //插入运算符
     ui->textEdit->insertPlainText(s);
     str += ui->textEdit->toPlainText();
     ui->textEdit->clear();
     ui->textEdit_2->clear();
     //把输入的所有数据显示在textEdit_2
     ui->textEdit_2->append(str);

     //运算
     switch (ch) {
     case 0:  //加法
         sum += num;
         //qDebug()<<sum/10;
         break;
     case 1:  //减法
         if(sum == 0){
           sum = num;
         }else {
           sum -= num;
         }
         break;
     case 2:  //乘法
         if(sum == 0){
          sum = 1.0 * num;
         }else {
             sum *= num;
         }
         break;
     case 3:  //除法
         if(sum == 0){
             sum = num;
         }else {
             if(num == 0) {
                 ui->textEdit_2->append("0不能做除数");
             }else {
                 sum = sum/num;
             }
         }
         break;
     case 11:  //“=”
         if(b == 0){//最后一个运算符为加
             sum = (sum + num)/10;
         }
         if(b == 1){//最后一个运算符为减
             sum = (sum - num)/10;
         }
         if(b == 2){//最后一个运算符为乘
             sum = (sum * num)/100;
         }
         if(b == 3){//最后一个运算符为除
             sum = (sum / num);
         }
         break;
     default:
         break;
     }
     //qDebug()<<"sum= "<<sum;
     //qDebug()<<"num= "<<num;
     //输入运算符后num置零
     num = 0;
 }

 //向textEdit中追加数据
 void MyComputer::MyAppend(int m)
 {
     //定位光标
     ui->textEdit->moveCursor(QTextCursor::End);
     //插入刚输入的数据     int类型转化为qstring类型
     ui->textEdit->insertPlainText(QString::number(m));
 }

//对输入的数字转化为十进制数字
void MyComputer::Send(int m)
{
    //int te = m;
    num += m;
    //qDebug()<<"+="<<num;
    MyAppend(m);
    num *= 10;
    //qDebug()<<"*="<<num;
    if(Is){//获取num的小数部分num2
        j++;
        num2 = num/qPow(10,j);
        //qDebug()<<num2;
    }
    //qDebug()<<j;
    //qDebug()<<num/10;
}

//数字2
void MyComputer::on_btn_2_clicked()
{
    m = 2;
    Send(m);
}

//数字3
void MyComputer::on_btn_3_clicked()
{
    m = 3;
    Send(m);
}

//数字4
void MyComputer::on_btn_4_clicked()
{
    m = 4;
    Send(m);
}

//数字5
void MyComputer::on_btn_5_clicked()
{
    m = 5;
    Send(m);
}

//数字6
void MyComputer::on_btn_6_clicked()
{
    m = 6;
    Send(m);
}

//数字7
void MyComputer::on_btn_7_clicked()
{
    m = 7;
    Send(m);
}

//数字8
void MyComputer::on_btn_8_clicked()
{
    m = 8;
    Send(m);
}

//数字9
void MyComputer::on_btn_9_clicked()
{
    m = 9;
    Send(m);
}

//“-”按钮  减法
void MyComputer::on_btn_subtract_clicked()
{
    ch = 1;
    Attack(QString("-"));
    b = 1;
}

//“*”按钮  乘法
void MyComputer::on_btn_multiply_clicked()
{
    ch = 2;
    Attack(QString("*"));
    b = 2;
}

//“/”按钮  除法
void MyComputer::on_btn_divide_clicked()
{
    ch = 3;
    Attack(QString("/"));
    b = 3;
}

//“CE”按钮  清除两个编辑区的内容
void MyComputer::on_btn_clear_clicked()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    //重置所有值
    str = "";
    num = 0;
    Is = false;
    j = 1;
    sum = 0;
    ch = 100;  //非运算符的值即可
    b = 100;
}

// //“Back”按钮   清除最近输入的一个数据
//void MyComputer::on_btn_back_clicked()
//{
//    QTextCursor cursor = ui->textEdit->textCursor();
//    cursor.deletePreviousChar();

//}

void MyComputer::on_btn_pi_clicked()
{
    float n = M_PI;  //M_PI自带的宏值  pi
    num = 10*n;   //与前面叠加时扩大十倍保持一致
    ui->textEdit->moveCursor(QTextCursor::End);
    //float类型转化为QString类型
    ui->textEdit->insertPlainText(QString("%1").arg(n));
}

//获取键盘输入的 值
void MyComputer::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Alt:   //“Alt”  相当于“=” (由于在调试时“Enter”键不能正常反应 更改为“Alt”)
        on_btn_equal_clicked();
        //qDebug()<<"按下";
        break;
    case Qt::Key_0:
        on_btn_0_clicked();
        break;
    case Qt::Key_1:
        on_btn_1_clicked();
        break;
    case Qt::Key_2:
        on_btn_2_clicked();
        break;
    case Qt::Key_3:
        on_btn_3_clicked();
        break;
    case Qt::Key_4:
        on_btn_4_clicked();
        break;
    case Qt::Key_5:
        on_btn_5_clicked();
        break;
    case Qt::Key_6:
        on_btn_6_clicked();
        break;
    case Qt::Key_7:
        on_btn_7_clicked();
        break;
    case Qt::Key_8:
        on_btn_8_clicked();
        break;
    case Qt::Key_9:
        on_btn_9_clicked();
        break;
    case Qt::Key_Plus: //“+”
        on_btn_add_clicked();
        break;
    case Qt::Key_Minus: //“-”
        on_btn_subtract_clicked();
        break;
    case Qt::Key_Asterisk: //“*”
        on_btn_multiply_clicked();
        break;
    case Qt::Key_Slash:  //“/”
        on_btn_divide_clicked();
        break;
    case Qt::Key_Escape:  //“Esc”  退出窗口
        this->close();
        break;
    case Qt::Key_Delete:  //“Delete”  清屏 相当于 “EC”键
        on_btn_clear_clicked();
        break;
    case Qt::Key_Period:   //“.”
        on_btn_point_clicked();
        break;
    default:
        break;
    }

}

void MyComputer::on_btn_point_clicked()
{
    num1 = num/10;
    //qDebug()<<"num1="<<num1;
    ui->textEdit->moveCursor(QTextCursor::End);
    ui->textEdit->insertPlainText(QString("."));
    Is = true;
    num = 0;
}
