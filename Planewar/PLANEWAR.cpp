#include "PLANEWAR.h"
#include "config.h"
#include <qicon.h>
#include <qpainter.h>
#include <QMouseEvent>

PLANEWAR::PLANEWAR(QWidget *parent)
    : QWidget(parent)
{
    //�{�ó�ʼ������
    initScene();

    //�����[��
    playgame();
}

void PLANEWAR::initScene()
{
    //�O�ô��ڹ̶��ߴ�
    setFixedSize(GAME_WIDTH, GAME_HEIGHT);

    //�O�Ø��}
    setWindowTitle(GAME_TITLE);

    //���d�D��
    setWindowIcon(QIcon(GAME_ICON));

    //���r���O��
    m_Timer.setInterval(GAME_RATE);
}

void PLANEWAR::playgame()
{
    //���Ӷ��r��
    m_Timer.start();

    //�O ���r���l�͵���̖
    connect(&m_Timer, &QTimer::timeout, [=]() {
        //�����[����Ԫ�ص�����
        updatePosition();
        //�L�u����Ļ��
        update();
    });
}

void PLANEWAR::updatePosition()
{
    //���µ؈D����
    m_map.mapPosition();

    //�l���ӏ�
    m_plane.shoot();

    //Ӌ�����зǿ��f�ӏ���ǰ����
    for (int i = 0; i < BULLET_NUM; i++) {
        //����ǿ��f
        if (m_plane.m_bullets[i].m_Free == false) {
            m_plane.m_bullets[i].updatePosition();
        }
    }


}

void PLANEWAR::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    //�L�u�؈D
    painter.drawPixmap(0, m_map.m_map1_posY, m_map.m_map1);
    painter.drawPixmap(0, m_map.m_map2_posY, m_map.m_map2);

    //�L�uӢ���w�C
    painter.drawPixmap(m_plane.m_X, m_plane.m_Y, m_plane.m_Plane);

    //�L�u�ӏ�
    for (int i = 0; i < BULLET_NUM; i++) {
        //����ǿ��f���L�u
        if (m_plane.m_bullets[i].m_Free == false) {
            painter.drawPixmap(m_plane.m_bullets[i].m_X, m_plane.m_bullets[i].m_Y, m_plane.m_bullets[i].m_Bullet);
        }
    }
}

void PLANEWAR::mouseMoveEvent(QMouseEvent* event)
{
    int x = event->x();
    int y = event->y();

    m_plane.setPosition(x - 60, y - 45);
}
