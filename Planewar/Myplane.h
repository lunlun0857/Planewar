#include <qpixmap.h>
#include <qrect.h>
#include "bullet.h"
#include "config.h"
#include "roc.h"
#include "roc2.h"

class Myplane
{
public:
	Myplane();

	//發射子彈
	void shootb();
	void shootr1();
	void shootr2();

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
	roc m_rocs[ROC_NUM];
	roc2 m_rocs2[ROC_NUM];

	//發射間隔
	int m_brecorder;
	int m_rrecorder;
	int m_r2recorder;
};



