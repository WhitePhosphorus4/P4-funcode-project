#pragma once
//==============================================================================
#include "commonclass.h"
#include "cmath"
#include "vector"
using namespace std;
//==============================================================================
class CBullet :
	public CSprite									//�̳����ͣ�CSprite
{
private:
	//�ӵ���������===============================================================
	float			m_fBulletSpeedTop;				//�ӵ������ٶ�
	float			m_fBulletSpeedLeft;				//�ӵ������ٶ�
	float			m_fBulletSpeedBottom;			//�ӵ��½��ٶ�
	float			m_fBulletSpeedRight;			//�ӵ������ٶ�
public:
	//===========================================================================
	CBullet(const char *szName);
	~CBullet(void);
	//�ӵ����ܺ���===============================================================
	void			OnMove(float fPosX, float fPosY, float fMousePosX, float fMousePosY);
													//�����ӵ������ٶȼ�������
};

