#include <QtWidgets/QWidget>
#include "ui_PLANEWAR.h"
#include<qtimer.h>
#include "Map.h"
#include "Myplane.h"
#include "enemy.h"


class PLANEWAR : public QWidget
{
    Q_OBJECT

public:
    PLANEWAR(QWidget *parent = Q_NULLPTR);
    void initScene();

    //�����[��
    void playgame();
     
    //���������[����Ԫ�ص�����
    void updatePosition();

    //�L�u����Ļ�� 
    void paintEvent(QPaintEvent*);

    //����Ƅ�
    void mouseMoveEvent(QMouseEvent*);

    //���C����
    void enemyToScene();

    //��ײ�z�y
    void collisionDetection();

    //���C���M
    Enemy m_enemys[ENEMY_NUM];

    //���C�����g���o�
    int m_recorder;

    //�؈D����
    Map m_map;

    //�w�C����
    Myplane m_plane;

    //���r��
    QTimer m_Timer;
private:
    Ui::PLANEWARClass ui;
};
