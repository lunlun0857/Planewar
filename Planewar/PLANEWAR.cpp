#include "PLANEWAR.h"
#include "config.h"
#include <qicon.h>
#include <qpainter.h>
#include <QMouseEvent>
#include <ctime>

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

    //���C�����r�g�� ��ʼ��
    m_recorder = 0;

    //�S�C���N��
    srand((unsigned int)time(NULL));

}

void PLANEWAR::playgame()
{
    //���Ӷ��r��
    m_Timer.start();

    //�O ���r���l�͵���̖
    connect(&m_Timer, &QTimer::timeout, [=]() {

        //���C����
        enemyToScene();

        //�����[����Ԫ�ص�����
        updatePosition();

        //�L�u����Ļ��
        update();

        //��ײ�z�y
        collisionDetection();
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

    //���C����
    for (int i = 0; i < ENEMY_NUM; i++) {
        if (m_enemys[i].m_Free == false) {
            m_enemys[i].updatePosition();
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

    //�L�u���C
    for (int i = 0; i < ENEMY_NUM; i++) {
        if (m_enemys[i].m_Free == false) {
            painter.drawPixmap(m_enemys[i].m_X, m_enemys[i].m_Y, m_enemys[i].m_enemy);
        }
    }
}

void PLANEWAR::mouseMoveEvent(QMouseEvent* event)
{
    int x = event->x();
    int y = event->y();

    m_plane.setPosition(x - 60, y - 45);
}

void PLANEWAR::enemyToScene()
{
    m_recorder++;

    if (m_recorder < ENEMY_INTERVAL) {
        return;
    }

    m_recorder = 0;

    for (int i = 0; i < ENEMY_NUM; i++) {
        //�����f�t����
        if (m_enemys[i].m_Free) {
            m_enemys[i].m_Free = false;

            //����
            m_enemys[i].m_X = rand() % (GAME_WIDTH - m_enemys[i].m_Rect.width());
            m_enemys[i].m_Y = -m_enemys[i].m_Rect.height();
            break;
        }
    }
}

void PLANEWAR::collisionDetection()
{
    
    for (int i = 0; i < ENEMY_NUM; i++) {
        if (m_enemys[i].m_Free) {
            continue;
        }

        for (int j = 0; j < BULLET_NUM; j++) {
            if (m_plane.m_bullets[j].m_Free) {
                continue;
            }

            if (m_enemys[i].m_Rect.intersects(m_plane.m_bullets[j].m_Rect)) {
                m_enemys[i].m_Free = true;
                m_plane.m_bullets[j].m_Free = true;
            }
        }
    }

    //�w�C�ӏ��Էǿ��f


}
