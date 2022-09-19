#ifndef PAINTER_H
#define PAINTER_H

#include <QWidget>
#include <QMouseEvent>  //鼠标事件
#include <QPainter>  //画家事件
#include <QComboBox>
#include <QCloseEvent>
#include "mycomputer.h"

namespace Ui {
class Painter;
}

class Painter : public QWidget
{
    Q_OBJECT

public:
    explicit Painter(QWidget *parent = 0);
    ~Painter();

    void creatColorComboBox(QComboBox *comboBox);

private:
    Ui::Painter *ui;

    QPixmap pix;  //全局变量保存绘图
    QPoint lastPoint;  //保存鼠标上的最后一个值
    QPoint endPoint;  //保存鼠标最后一个值
    int fontSeize;  //字体大小
    QColor penColor;  //画笔的颜色

    //分配空间  返回计算器的窗口
    MyComputer * w = new MyComputer;

protected:
    void mousePressEvent(QMouseEvent * ev);   //鼠标按下事件
    void paintEvent(QPaintEvent *);  //绘画事件
    void mouseMoveEvent(QMouseEvent *ev);  //鼠标移动事件
    void mouseReleaseEvent(QMouseEvent *ev);  //鼠标释放事件
    void closeEvent(QCloseEvent *event);  //窗口关闭事件

private slots:
    //自定义的信号 改变颜色发出信号
    void on_comboBoxBrush_currentIndexChanged(int index);
    void on_btn_savePix_clicked();
    void on_btnBack_clicked();
};

#endif // PAINTER_H
