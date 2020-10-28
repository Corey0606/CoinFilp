#include "mycoin.h"
#include "QDebug"
#include "QTimer"

MyCoin::MyCoin(QWidget *parent) : QPushButton(parent)
{

}

MyCoin::MyCoin(QString butImg)
{

    QPixmap pixmap;
    bool ret = pixmap.load(butImg);
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    if(!ret)
    {
        qDebug() << butImg << "加载图片失败!";
    }

    this->setFixedSize( pixmap.width(), pixmap.height() );
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
    connect(timer2, &QTimer::timeout,[=](){
        QPixmap pixmap;
        QString str= QString(":/res/Coin000%1.png").arg((this->max)-- );
        pixmap.load(str);
        this->setFixedSize(pixmap.width(),pixmap.height() );
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));
        if(this->max < this->min) //如果小于最小值，重置最大值，并停止定时器
        {
            this->max = 8;
            timer2->stop();
        }

    });
}

void MyCoin::changeFlag()
{
    if(this->flag)  //如果是正面
    {
     timer1->start(30);
     this->flag = false;
    }else       //反面
        {
    timer2->start(30);
    this->flag = true;

    }
}
