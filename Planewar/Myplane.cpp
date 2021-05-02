#include "Myplane.h"
#include "config.h"

Myplane::Myplane()
{
	//初始化加載飛機圖片資源
	m_Plane.load(MYPLANE_PATH);

	//初始化飛機坐標
	m_X = (GAME_WIDTH  - m_Plane.width()) * 0.5;
	m_Y =  GAME_HEIGHT - m_Plane.height();

	//初始化矩形邊框
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
