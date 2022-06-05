#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QKeyEvent>
#include <QRectF>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QDebug>
#include <QTimer>
#include <QTime>

namespace Ui {
class Snake;
}

class Snake : public QWidget
{
    Q_OBJECT

public:
    explicit Snake(QWidget *parent = 0);
    ~Snake();

protected:
    void paintEvent(QPaintEvent *);   //重写绘图事件
    void keyPressEvent(QKeyEvent *);  //重写键盘事件

//私有函数
private:
    void addTopRectF();   //向上移动
    void addDownRectF();   //向下移动
    void addLeftRectF();   //向左移动
    void addRightRectF();  //向右移动
    void deleteLastRectF();  //删除蛇的最后结点
    bool snakeStrike();     //蛇撞到自身的函数
    enum Move{Left,Right,Up,Down};   //枚举值

protected slots:
    void timeOut();   //时间的槽函数
    void rewardTimeOut();   //奖励的时间槽函数

//私有属性
private:
    Ui::Snake *ui;

    QList<QRectF> snake;//贪吃蛇本体
    int snakeNodeWidth = 10;   //蛇的宽度
    int snakeNodeHeight = 10;   //蛇的高度
    QTimer *timer;
    QTimer *rewardTimer;
    int time = 100;  //100ms
    int moveFlage = Up;
    bool gameOver = false;
    bool gameStart = false;
    QList<QRectF> rewardNode;//奖励节点

};

#endif // SNAKE_H
