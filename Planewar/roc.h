#ifndef ROC_H
#define ROC_H
#include "config.h"
#include <QPixmap>

class roc
{
public:
    roc();

    //�����ӏ�����
    void updatePosition();

    //�ӏ��YԴ����
    QPixmap m_roc;

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

#endif // ROC_H
