#include "startpushbutton.h"
#include "QDebug"
#include "QPropertyAnimation"



startPushButton::startPushButton(QString noralImg, QString pressImg){
    normalImgPath= noralImg;
    pressedImgPath = pressImg;
    QPixmap pixmap;
    bool ret = pixmap.load(normalImgPath);
    if(!ret)
    {
        qDebug()<<"加载图片失败";
    }
    this->setFixedSize(pixmap.width(), pixmap.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
};

void startPushButton::zoom_down(){
    QPropertyAnimation * pa_down = new QPropertyAnimation(this, "geometry");
    pa_down->setDuration(200);
    pa_down->setStartValue(QRect(this->x(),this->y(),this->width(), this->height()));
    pa_down->setEndValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
    pa_down->setEasingCurve(QEasingCurve::OutBounce);
    pa_down->start();
}

void startPushButton::zoom_up(){
    QPropertyAnimation * pa_down = new QPropertyAnimation(this, "geometry");
    pa_down->setDuration(200);
    pa_down->setStartValue(QRect(this->x(),this->y()+10,this->width(), this->height()));
    pa_down->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    pa_down->setEasingCurve(QEasingCurve::OutBounce);
    pa_down->start();
}

void startPushButton::mousePressEvent(QMouseEvent *e){
    if(pressedImgPath !="")
    {
        QPixmap pixmap;
        bool ret = pixmap.load(pressedImgPath);
        if(!ret){
          qDebug()<<pressedImgPath<<"加载图片失败";
        };
        this->setFixedSize(pixmap.width(),pixmap.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));

    }
    return QPushButton::mousePressEvent(e);

};

void startPushButton::mouseReleaseEvent(QMouseEvent *e){
    if(normalImgPath !="")
    {
        QPixmap pixmap;
        bool ret = pixmap.load(normalImgPath);
        if(!ret){
          qDebug()<<pressedImgPath<<"加载图片失败";
        };
        this->setFixedSize(pixmap.width(),pixmap.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));

    }
    return QPushButton::mouseReleaseEvent(e);

};
