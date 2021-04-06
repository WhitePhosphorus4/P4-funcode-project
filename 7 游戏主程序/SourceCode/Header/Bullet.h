#pragma once
//==============================================================================
#include "commonclass.h"
#include "cmath"
#include "vector"
using namespace std;
//==============================================================================
class CBullet :
	public CSprite									//继承类型：CSprite
{
private:
	//子弹特征变量===============================================================
	float			m_fBulletSpeedTop;				//子弹上升速度
	float			m_fBulletSpeedLeft;				//子弹左移速度
	float			m_fBulletSpeedBottom;			//子弹下降速度
	float			m_fBulletSpeedRight;			//子弹右移速度
public:
	//===========================================================================
	CBullet(const char *szName);
	~CBullet(void);
	//子弹功能函数===============================================================
	void			OnMove(float fPosX, float fPosY, float fMousePosX, float fMousePosY);
													//设置子弹飞行速度及方向函数
};

