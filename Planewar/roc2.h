#ifndef ROC2_H
#define ROC2_H
#include "config.h"
#include <QPixmap>

class roc2
{
public:
    roc2();

    //�����ӏ�����
    void updatePosition();

    //�ӏ��YԴ����
    QPixmap m_roc2;

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

#endif // ROC2_H
