#include "painter.h"
#include "ui_painter.h"

#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <QPen>
#include <QMenuBar>
#include <QFile>
#include <QFileDialog>
#include <QBuffer>
#include <QMessageBox>


Painter::Painter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Painter)
{
    ui->setupUi(this);

    //设置窗口
    this->resize(1200,1200);
    this->setWindowTitle("画板");
    this->setWindowIcon(QIcon(":/Image/14.jpg"));
    //设置字体大小编辑框
    //ui->lineEditFont->resize(this->width()/3,this->height()/40);
    ui->lineEditFont->resize(100,50);
    //移到左下角
    ui->lineEditFont->move(0,this->height() - ui->lineEditFont->height());

    //把窗口的全局设置为画纸
    pix = QPixmap(this->width(),this->height());
    pix.fill(Qt::white);   //画板的背景颜色

    //comboBoxBrush为 画笔颜色的选择框  初始化
    ui->comboBoxBrush->resize(115,65);
    ui->comboBoxBrush->move(0, 0);
    creatColorComboBox(ui->comboBoxBrush);

    //save按钮  保存所画图像
    ui->btn_savePix->resize(100, 100);
    ui->btn_savePix->move(this->width() - ui->btn_savePix->width(), 0);

    //back按钮  移到右下角
    ui->btnBack->resize(200, 100);
    ui->btnBack->move(this->width() - ui->btnBack->width(), this->height() - ui->btnBack->height());

}

Painter::~Painter()
{
    delete ui;
}

//鼠标按下事件的重写

//鼠标按下事件
void Painter::mousePressEvent(QMouseEvent * ev)
{
    if(ev->button() == Qt::LeftButton){
        //确定鼠标的位置
        lastPoint = ev->pos();
        endPoint = lastPoint;
        //qDebug()<<"鼠标按下";
  }
    //按下右键清空之前画的东西
    if(ev->button() == Qt::RightButton){
        QPixmap clearPix = QPixmap();
        pix = clearPix;
        pix = QPixmap(this->width(),this->height());
        pix.fill(Qt::white);
        //移动lineEditFont   comboBoxBackground 保持与界面协调
        ui->lineEditFont->move(0,this->height() - ui->lineEditFont->height());
        ui->btn_savePix->move(this->width() - ui->btn_savePix->width(), 0);
        ui->btnBack->move(this->width() - ui->btnBack->width(), this->height() - ui->btnBack->height());
        update();
    }
}

//鼠标移动事件
void Painter::mouseMoveEvent(QMouseEvent * ev)
{
    if(ev->buttons() & Qt::LeftButton){
        //结束的点为鼠标移动到的位置
        endPoint = ev->pos();
        //qDebug()<<"鼠标移动";
        update();
    }
}

//鼠标释放事件
void Painter::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton){
        //qDebug()<<"鼠标左键释放了";
        //最后一个点为鼠标释放时的位置
        endPoint = ev->pos();
        update();
    }

}


//绘图事件
void Painter::paintEvent(QPaintEvent *)
{
    QPainter pp(&pix);  //保存的绘图
    QPainter painter(this);
    //设置画笔
    QPen pen;
    pen.setColor(penColor);
    fontSeize = ui->lineEditFont->text().toInt();
    pen.setWidth(fontSeize);
    pp.setPen(pen);
    //把瞬时的两个点连起来
    pp.drawLine(lastPoint,endPoint);
    lastPoint = endPoint;
    painter.drawPixmap(0,0,pix);
}

//设置画笔可选颜色
void Painter::creatColorComboBox(QComboBox *comboBox)
{
    QPixmap pix2(16,16);
    QPainter painter(&pix2);
    //设置改颜色的图标  大小为16*16
    painter.fillRect(0,0,16,16,Qt::red);
    comboBox->addItem(QIcon(pix2),tr("红色"),QColor(Qt::red));
    painter.fillRect(0,0,16,16,Qt::black);
    comboBox->addItem(QIcon(pix2),tr("黑色"),QColor(Qt::black));
    painter.fillRect(0,0,16,16,Qt::green);
    comboBox->addItem(QIcon(pix2),tr("绿色"),QColor(Qt::green));
    painter.fillRect(0,0,16,16,Qt::blue);
    comboBox->addItem(QIcon(pix2),tr("蓝色"),QColor(Qt::blue));
    painter.fillRect(0,0,16,16,Qt::yellow);
    comboBox->addItem(QIcon(pix2),tr("黄色"),QColor(Qt::yellow));
    painter.fillRect(0,0,16,16,Qt::cyan);
    comboBox->addItem(QIcon(pix2),tr("青色"),QColor(Qt::cyan));
    painter.fillRect(0,0,16,16,Qt::magenta);
    comboBox->addItem(QIcon(pix2),tr("洋红"),QColor(Qt::magenta));
    comboBox->addItem(tr("不选"),QColor(Qt::transparent));
}

void Painter::on_comboBoxBrush_currentIndexChanged(int index)
{
    //返回复选框选择的颜色
     QColor color = ui->comboBoxBrush->itemData(index,Qt::UserRole).value<QColor>();
     // qDebug()<<color;
     penColor = color;
     //setPenColor(color);

}

void Painter::on_btn_savePix_clicked()
{
    QString filePath;
    //记录保存文件的路径  getSaveFileName()的第四个参数  为保存文件类型的可选项
    filePath = QFileDialog::getSaveFileName(this,"open","../",tr("Images(*.png);;Images(*.jpg)"));
    pix.save(filePath);
}

//窗口关闭事件
void Painter::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton btn;
    btn = QMessageBox::question(this,tr("是否保存"),QString(tr("确认保存")),QMessageBox::Yes|QMessageBox::No);
    if(btn == QMessageBox::Yes){
        //忽略信号
        event->ignore();
        on_btn_savePix_clicked();
    } if(btn == QMessageBox::No) {
        //接收信号
        event->accept();
    }

}


//返回计算器
void Painter::on_btnBack_clicked()
{
    //关闭本窗口  返回计算器窗口
    this->close();
    w->show();
}
