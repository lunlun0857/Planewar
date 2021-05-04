#ifndef EXPLODE_H
#define EXPLODE_H

#include "config.h"
#include <qpixmap.h>
#include <qvector.h>

class explode
{
public:
	explode();

	void updateInfo();

	QVector<QPixmap> m_pixArr;

	int m_X;
	int m_Y;

	bool m_Free;

	int m_recorder;
	
	int m_index;
};

#endif //EXPLODE_H