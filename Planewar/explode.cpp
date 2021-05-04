#include "explode.h"

explode::explode() {

	//�����б�ըPIXMAP���M���M
	for (int i = 1; i <= EXPLODE_MAX; i++) {
		QString str = QString(EXPLODE_PATH).arg(i);
		m_pixArr.push_back(QPixmap(str));
	}

	m_X = 0;
	m_Y = 0;

	m_Free = true;

	m_index = 0;

	m_recorder = 0;
}

void explode::updateInfo()
{
	//���f��B�µı�ըЧ��ֱ��return
	if (m_Free) {
		return;
	}

	m_recorder++;

	if (m_recorder < EXPLODE_INTERVAL) {
		return;
	}

	//�����g��
	m_recorder = 0;

	//�ГQ��ը���ňDƬ��
	m_index++;


	//���M��0�_ʼӋ��
	if (m_index > EXPLODE_MAX - 1) {
		m_index = 0;
		m_Free = true;
	}

}





