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

	//�l���ӏ�
	void shootb();
	void shootr1();
	void shootr2();

	//�O���w�Cλ��
	void setPosition(int x, int y);

	QPixmap m_Plane;

	//�w�C����
	int m_X;
	int m_Y;

	//�w�C�ľ���߅��
	QRect m_Rect;

	//��ϻ
	Bullet m_bullets[BULLET_NUM];
	roc m_rocs[ROC_NUM];
	roc2 m_rocs2[ROC_NUM];

	//�l���g��
	int m_brecorder;
	int m_rrecorder;
	int m_r2recorder;
};



