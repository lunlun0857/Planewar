#include "roc2.h"

roc2::roc2()
{
    //���d�Ԅ��YԴ
    m_roc2.load(ROC_PATH);

    //�ӏ����˳�ʼ��
    m_X = (GAME_WIDTH * 0.5 - m_roc2.width() * 0.5);
    m_Y = GAME_HEIGHT;

    //�ӏ����f��B
    m_Free = true;

    //�ӏ��ٶ�
    m_Speed = BULLET_SPEED;

    //�ӏ�����߅�� ����ײ�z�y��
    m_Rect.setWidth(m_roc2.width());
    m_Rect.setHeight(m_roc2.height());
    m_Rect.moveTo(m_X, m_Y);
}

void roc2::updatePosition()
{
    //����ӏ��ǿ��f��B������ҪӋ������
    if (m_Free)
    {
        return;
    }

    //�ӏ������Ƅ�
    m_Y -= m_Speed;
    m_Rect.moveTo(m_X, m_Y);

    if (m_Y <= -m_Rect.height())
    {
        m_Free = true;
    }

}
