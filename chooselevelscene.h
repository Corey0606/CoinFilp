#ifndef CHOOSELEVELSCANS_H
#define CHOOSELEVELSCANS_H

#include <QMainWindow>
#include "playscene.h"

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    PlayScene * pScene = NULL;
signals:
    void ChooseSceneBack();

};

#endif // CHOOSELEVELSCANS_H
