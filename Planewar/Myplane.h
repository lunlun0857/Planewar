#include <qpixmap.h>
#include <qrect.h>

class Myplane
{
public:
	Myplane();

	//�l���ӏ�
	void shoot();

	//�O���w�Cλ��
	void setPosition(int x, int y);

	QPixmap m_Plane;

	//�w�C����
	int m_X;
	int m_Y;

	//�w�C�ľ���߅��
	QRect m_Rect;
};

