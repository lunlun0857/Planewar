#include "Myplane.h"
#include "config.h"

Myplane::Myplane()
{
	//��ʼ�����d�w�C�DƬ�YԴ
	m_Plane.load(MYPLANE_PATH);

	//��ʼ���w�C����
	m_X = (GAME_WIDTH  - m_Plane.width()) * 0.5;
	m_Y =  GAME_HEIGHT - m_Plane.height();

	//��ʼ������߅��
	m_Rect.setWidth(m_Plane.width());
	m_Rect.setHeight(m_Plane.height());
	m_Rect.moveTo(m_X, m_Y);
}

void Myplane::shoot()
{

}

void Myplane::setPosition(int x, int y)
{
	m_X = x;
	m_Y = y;
	m_Rect.moveTo(m_X, m_Y);
}
