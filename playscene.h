#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int index);
    void paintEvent(QPaintEvent *);
    int levalIndex;
    int gameArray[4][4];

signals:
    void chooseSceneBack();

};

#endif // PLAYSCENE_H
