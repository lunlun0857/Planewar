#include "Planewar.h"
#include "config.h"
#include <qicon.h>
#include <qpainter.h>
#include <QMouseEvent>
#include <ctime>
#include <qsound.h>
#include <qpen.h>
#include <qbrush.h>


PLANEWAR::PLANEWAR(QWidget *parent)
    : QWidget(parent)
{
    //�{�ó�ʼ������
    initScene();

    //�����[��
    playgame();

    score = 0.3;
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
    //���ӱ�������
    QSound::play(SOUND_BG);


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
    m_plane.shootb();
    m_plane.shootr1();
    m_plane.shootr2();

    //Ӌ�����зǿ��f�ӏ���ǰ����
    for (int i = 0; i < BULLET_NUM; i++) {
        //����ǿ��f
        if (m_plane.m_bullets[i].m_Free == false) {
            m_plane.m_bullets[i].updatePosition();
        }
    }

    for (int i = 0; i < ROC_NUM; i++) {
        //����ǿ��f
        if (m_plane.m_rocs[i].m_Free == false) {
            m_plane.m_rocs[i].updatePosition();
        }
    }

    for (int i = 0; i < ROC_NUM; i++) {
        //����ǿ��f
        if (m_plane.m_rocs2[i].m_Free == false) {
            m_plane.m_rocs2[i].updatePosition();
        }
    }

    //���C����
    for (int i = 0; i < ENEMY_NUM; i++) {
        if (m_enemys[i].m_Free == false) {
            m_enemys[i].updatePosition();
        }
    }

    //Ӌ�㱬ը�Ĳ��ňD
    for (int i = 0; i < EXPLODE_NUM; i++) {
        if (m_bombs[i].m_Free == false) {
            m_bombs[i].updateInfo();
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

    painter.drawPixmap(m_map.s_sco_X, m_map.s_sco_Y, m_map.s_sco);

    QFont font1("Courier", 30, QFont::Bold, true);
    painter.setFont(font1);
    painter.setPen(QPen(Qt::yellow, 5, Qt::DashDotLine, Qt::RoundCap));
    painter.drawText(400, 50, QString::number(score));


    //�L�u�ӏ�
    for (int i = 0; i < BULLET_NUM; i++) {
        //����ǿ��f���L�u
        if (m_plane.m_bullets[i].m_Free == false) {
            painter.drawPixmap(m_plane.m_bullets[i].m_X, m_plane.m_bullets[i].m_Y, m_plane.m_bullets[i].m_Bullet);
        }
    }

    for (int i = 0; i < ROC_NUM; i++) {
        //����ǿ��f���L�u
        if (m_plane.m_rocs[i].m_Free == false) {
            painter.drawPixmap(m_plane.m_rocs[i].m_X, m_plane.m_rocs[i].m_Y, m_plane.m_rocs[i].m_roc);
        }
    }

    for (int i = 0; i < ROC_NUM; i++) {
        //����ǿ��f���L�u
        if (m_plane.m_rocs2[i].m_Free == false) {
            painter.drawPixmap(m_plane.m_rocs2[i].m_X, m_plane.m_rocs2[i].m_Y, m_plane.m_rocs2[i].m_roc2);
        }
    }

    //�L�u���C
    for (int i = 0; i < ENEMY_NUM; i++) {
        if (m_enemys[i].m_Free == false) {
            painter.drawPixmap(m_enemys[i].m_X, m_enemys[i].m_Y, m_enemys[i].m_enemy);
        }
    }

    //�L�u��ը
    for (int i = 0; i < EXPLODE_NUM; i++) {
        if (m_bombs[i].m_Free == false) {
            painter.drawPixmap(m_bombs[i].m_X, m_bombs[i].m_Y, m_bombs[i].m_pixArr[m_bombs[i].m_index]);
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

        for (int j = 0; j < ROC_NUM; j++) {
            if (m_plane.m_rocs[j].m_Free) {
                continue;
            }
            //�w�C�ӏ��Էǿ��f
            if (m_enemys[i].m_Rect.intersects(m_plane.m_rocs[j].m_Rect)) {
                m_enemys[i].m_Free = true;
                m_plane.m_rocs[j].m_Free = true;
                score += 7.8;

                //���ű�ըЧ��
                for (int k = 0; k < EXPLODE_NUM; k++) {
                    if (m_bombs[k].m_Free) {

                        QSound::play(SOUND_BOMB);

                        m_bombs[k].m_Free = false;

                        m_bombs[k].m_X = m_enemys[i].m_X;
                        m_bombs[k].m_Y = m_enemys[i].m_Y;
                        break;
                    }
                }
            }
        }

        for (int j = 0; j < ROC_NUM; j++) {
            if (m_plane.m_rocs2[j].m_Free) {
                continue;
            }
            //�w�C�ӏ��Էǿ��f
            if (m_enemys[i].m_Rect.intersects(m_plane.m_rocs2[j].m_Rect)) {
                m_enemys[i].m_Free = true;
                m_plane.m_rocs2[j].m_Free = true;
                score += 7.8;

                //���ű�ըЧ��
                for (int k = 0; k < EXPLODE_NUM; k++) {
                    if (m_bombs[k].m_Free) {

                        QSound::play(SOUND_BOMB);

                        m_bombs[k].m_Free = false;

                        m_bombs[k].m_X = m_enemys[i].m_X;
                        m_bombs[k].m_Y = m_enemys[i].m_Y;
                        break;
                    }
                }
            }
        }

        for (int j = 0; j < BULLET_NUM; j++) {
            if (m_plane.m_bullets[j].m_Free) {
                continue;
            }
            //�w�C�ӏ��Էǿ��f
            if (m_enemys[i].m_Rect.intersects(m_plane.m_bullets[j].m_Rect)) {
                m_enemys[i].m_Free = true;
                m_plane.m_bullets[j].m_Free = true;
                score += 6.8;

                //���ű�ըЧ��
                for (int k = 0; k < EXPLODE_NUM; k++) {
                    if (m_bombs[k].m_Free) {

                        QSound::play(SOUND_BOMB);

                        m_bombs[k].m_Free = false;

                        m_bombs[k].m_X = m_enemys[i].m_X;
                        m_bombs[k].m_Y = m_enemys[i].m_Y;
                        break;
                    }
                }
            }
        }
    }
}
