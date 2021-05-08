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

void Myplane::shootb() {

	//�ۼӕr�g�g��
	m_brecorder++;

	//����o䛵Ĕ��֞��_���l���ӏ��ĕr�g�g��
	if (m_brecorder < BULLET_INTERVAL) {
		return;
	}

	//�_���l��r�g
	m_brecorder = 0;

	//�l���ӏ�
	for (int i = 0; i < BULLET_NUM; i++) {
		//����ӏ����f�t�l��
		if (m_bullets[i].m_Free) {
			//���f��B׃���
			m_bullets[i].m_Free = false;

			//�O���ӏ�����
			m_bullets[i].m_X = m_X + 45;
			m_bullets[i].m_Y = m_Y;
			break;
		}
	}
}

void Myplane::shootr1() {

	//�ۼӕr�g�g��
	m_rrecorder++;

	//����o䛵Ĕ��֞��_���l���ӏ��ĕr�g�g��
	if (m_rrecorder < ROC_INTERVAL) {
		return;
	}

	//�_���l��r�g
	m_rrecorder = 0;

	//�l���ӏ�
	for (int i = 0; i < ROC_NUM; i++) {
		//����ӏ����f�t�l��
		if (m_rocs[i].m_Free) {
			//���f��B׃���
			m_rocs[i].m_Free = false;

			//�O���ӏ�����
			m_rocs[i].m_X = m_X + 10;
			m_rocs[i].m_Y = m_Y;
			break;
		}
	}
}

void Myplane::shootr2() {

	//�ۼӕr�g�g��
	m_r2recorder++;

	//����o䛵Ĕ��֞��_���l���ӏ��ĕr�g�g��
	if (m_r2recorder < ROC_INTERVAL) {
		return;
	}

	//�_���l��r�g
	m_r2recorder = 0;

	//�l���ӏ�
	for (int i = 0; i < ROC_NUM; i++) {
		//����ӏ����f�t�l��
		if (m_rocs[i].m_Free) {
			//���f��B׃���
			m_rocs[i].m_Free = false;

			//�O���ӏ�����
			m_rocs[i].m_X = m_X + 80;
			m_rocs[i].m_Y = m_Y;
			break;
		}
	}
}

void Myplane::setPosition(int x, int y)
{
	m_X = x;
	m_Y = y;
	m_Rect.moveTo(m_X, m_Y);
}
