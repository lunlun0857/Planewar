#ifndef BULLET_H
#define BULLET_H
#include "config.h"
#include <QPixmap>

class Bullet
{
public:
    Bullet();

    //�����ӏ�����
    void updatePosition();

    //�ӏ��YԴ����
    QPixmap m_Bullet;

    //�ӵ�����
    int m_X;
    int m_Y;

    //�ӏ��Ƅ��ٶ�
    int m_Speed;

    //�ӏ��Ƿ��f��
    bool m_Free;

    //�ӏ��ľ���߅�������ײ�z�y��
    QRect m_Rect;

};

#endif // BULLET_H
