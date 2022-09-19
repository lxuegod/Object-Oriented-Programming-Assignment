/*
 * 使用说明
 * 本贪吃蛇游戏 双击空格即可开始
 * 蛇可以穿墙 只有撞到自身 游戏才会结束
 * 蛇的控制由 上下左右 键控制
 * 空格 键 也可以游戏暂停
 * 按下“Enter”键后 重新开始  按下“Esc”键 退出
*/
#include "snake.h"
#include "ui_snake.h"
#include "mycomputer.h"

#include <QWidget>
#include <QKeyEvent>
#include <QRectF>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QDebug>
#include <QTimer>
#include <QTime>

Snake::Snake(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Snake)
{
    ui->setupUi(this);

    //初始化窗口
    this->setFixedSize(750,600);
    this->setWindowTitle("贪吃蛇");
    this->setWindowIcon(QIcon(":/Image/6.png"));
    //设置窗体背景色为黑色
    this->setStyleSheet("QWidget{background:black}");
    this->setWindowOpacity(0.8);//设置窗口的透明度

    //蛇初始化
    snake.append(QRectF(200, 500, snakeNodeWidth, snakeNodeHeight));
    addTopRectF();
    addTopRectF();
    //首先生成一个奖励节点
    rewardNode.append(QRectF(100, 100, snakeNodeWidth, snakeNodeWidth));

    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(timeOut()));
    //timer->start(time);

    rewardTimer = new QTimer;
    connect(rewardTimer, SIGNAL(timeout()), this, SLOT(rewardTimeOut()));
    //rewardTimer->start(time*30);
}

Snake::~Snake()
{
    delete ui;
}

//界面刷新
void Snake::timeOut()
{
    int flage = 1;  //flage为分数
    for(int i = 0; i < rewardNode.length(); i++){
        if(rewardNode.at(i).contains(snake.at(0).topLeft()+QPointF(snakeNodeWidth/2,snakeNodeHeight/2))){
        //if(snake.at(0).contains(rewardNode.at(i).x()+rewardNode.at(i).width()/2,rewardNode.at(i).y()+rewardNode.at(i).height()/2)){
            if(rewardNode.at(i).width()>snakeNodeWidth){
                //奖励所在位置的宽度大于蛇的宽度   额外奖励
                flage += 2;
            }
            flage++;//正常奖励
            rewardNode.removeAt(i);
            break;
        }
    }
    while(flage--){
        switch (moveFlage) {
        case Up:
            addTopRectF();
            break;
        case Down:
            addDownRectF();
            break;
        case Right:
            addRightRectF();
            break;
        case Left:
            addLeftRectF();
            break;
        default:
            break;
        }
    }
    deleteLastRectF();

    update();
}

//随机生成奖励
void Snake::rewardTimeOut()
{
    //以当前时间为种子  生成随机点
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    if(rewardNode.length() > 5){
        //保证生成点的长度 小于5
        rewardNode.removeAt(qrand()%5);
    }
    //追加到随机位置
    rewardNode.append(QRectF(qrand()%(this->width()/20)*20,qrand()%(this->height()/20)*20,snakeNodeWidth,snakeNodeWidth));
    if(qrand()%5 == 3){
        //额外奖励把点扩大两倍
        rewardNode.append(QRectF(qrand()%(this->width()/20)*20-5,qrand()%(this->height()/20)*20-5,snakeNodeWidth*2,snakeNodeWidth*2));
    }
}

//向上移动
void Snake::addTopRectF()
{
    if(snake.at(0).y()-snakeNodeHeight < 0){//向左右移动时
        snake.insert(0,QRectF(QPointF(snake.at(0).x(),this->height()-snakeNodeHeight),
                              QPointF(snake.at(0).x()+snakeNodeWidth,this->height())));
    }else{
        snake.insert(0,QRectF(snake.at(0).topLeft()+QPointF(0,-snakeNodeHeight),snake.at(0).topRight()));
    }
}

//向下移动
void Snake::addDownRectF()
{
    if(snake.at(0).y()+snakeNodeHeight*2 > this->height()){//向左右移动时
        snake.insert(0,QRectF(QPointF(snake.at(0).x(),snakeNodeHeight),
                              QPointF(snake.at(0).x()+snakeNodeWidth,0)));
    }else{
        snake.insert(0,QRectF(snake.at(0).bottomLeft(),snake.at(0).bottomRight()+QPointF(0,snakeNodeHeight)));
    }
}

//向左移动
void Snake::addLeftRectF()
{
    if(snake.at(0).x()-snakeNodeWidth < 0){//向上下移动时
        snake.insert(0,QRectF(QPointF(this->width()-snakeNodeWidth,snake.at(0).y()),
                              QPointF(this->width(),snake.at(0).y()+snakeNodeHeight)));
    }else{
        snake.insert(0,QRectF(snake.at(0).topLeft()+QPointF(-snakeNodeWidth,0),snake.at(0).bottomLeft()));
    }
}

//向右移动
void Snake::addRightRectF()
{
    if(snake.at(0).x()+snakeNodeWidth*2 > this->width()){//向上下移动时
        snake.insert(0,QRectF(QPointF(0,snake.at(0).y()),
                              QPointF(snakeNodeWidth,snake.at(0).y()+snakeNodeHeight)));
    }else{
        snake.insert(0,QRectF(snake.at(0).topRight(),snake.at(0).bottomRight()+QPointF(snakeNodeWidth,0)));
    }
}

//删除结尾数据
void Snake::deleteLastRectF()
{
    snake.removeLast();
}

//绘图
void Snake::paintEvent(QPaintEvent *event)
{
    //指定父类 为本窗口 即this
    QPainter painter(this);
    QPen pen; //画笔
    QBrush brush; //画刷
    QFont font("方正舒体",12,QFont::ExtraLight,false);

    //反锯齿型
    painter.setRenderHint(QPainter::Antialiasing);

    pen.setColor(Qt::black);
    brush.setColor(Qt::green);
    brush.setStyle(Qt::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);

    for(int i=0; i<snake.length(); i++){
        painter.drawRect(snake.at(i));
    }
    brush.setColor(Qt::red);
    painter.setBrush(brush);
    for(int i=0; i<rewardNode.length(); i++){
        //把奖励点画成红色的圆
        painter.drawEllipse(rewardNode.at(i));
    }
    pen.setColor(Qt::white);
    painter.setPen(pen);
    painter.setFont(font);
    //显示得分
    painter.drawText(20,20,QString("当前得分：")+QString("%1").arg(snake.length()));

    if(snakeStrike()){//蛇自身相撞
        QFont font("方正舒体",30,QFont::ExtraLight,false);
        painter.setFont(font);
        painter.drawText((this->width()-300)/2,(this->height()-30)/2,QString("GAME OVER!"));

        //计时器停止
        timer->stop();
        rewardTimer->stop();
        gameOver = true;
    }

    QWidget::paintEvent(event);
}

//通过键盘操作
void Snake::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Up:
        if(moveFlage != Down){//向下运动时没有反应
            moveFlage = Up;
        }
        break;
    case Qt::Key_Down:
        if(moveFlage != Up){//向上运动时没有反应
            moveFlage = Down;
        }
        break;
    case Qt::Key_Right:
        if(moveFlage != Left){//向左运动时没有反应
            moveFlage = Right;
        }
        break;
    case Qt::Key_Left:
        if(moveFlage != Right){//向右运动时没有反应
            moveFlage = Left;
        }
        break;
        //按下Enter键后 重新开始
    case Qt::Key_Enter:
    case Qt::Key_Return:
        if(gameOver){
            snake.clear();
            rewardNode.clear();
            moveFlage = Up;
            snake.append(QRectF(200,500,snakeNodeWidth,snakeNodeHeight));
            addTopRectF();
            addTopRectF();
            //首先生成一个奖励节点
            rewardNode.append(QRectF(100,100,snakeNodeWidth,snakeNodeWidth));
            timer->start(time);
            rewardTimer->start(time*30);
            gameOver = false;
        }
        break;
    case Qt::Key_Space:
        if(gameStart && !gameOver){//开始
            timer->start(time);
            rewardTimer->start(time*30);
            gameStart = false;
        }else if(!gameStart && !gameOver){//暂停
            timer->stop();
            rewardTimer->stop();
            gameStart = true;
        }
        break;
    case Qt::Key_Escape:  //“Esc”键退出
        this->close();
        break;
    default:
        break;
    }
}

//判断蛇头是否和蛇身相撞
bool Snake::snakeStrike()
{
    for(int i=0; i<snake.length(); i++){
        for(int j=i+1; j<snake.length(); j++){
            if(snake.at(i) == snake.at(j)){
                return true;
            }
        }
    }
    return false;

}
