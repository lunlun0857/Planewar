#include <qpixmap.h>
#include <qrect.h>
#include "bullet.h"
#include "config.h"

class Myplane
{
public:
	Myplane();

	//發射子彈
	void shoot();

	//設置飛機位置
	void setPosition(int x, int y);

	QPixmap m_Plane;

	//飛機座標
	int m_X;
	int m_Y;

	//飛機的矩形邊框
	QRect m_Rect;

	//彈匣
	Bullet m_bullets[BULLET_NUM];

	//發射間隔
	int m_recorder;
};



