#pragma once
//===========================================================================================
#include "commonclass.h"

//===========================================================================================
class CPortal :
	public CSprite
{
private:
//set函数====================================================================================
	int				m_iPortalState;		//传送门状态
	int				m_iDir;				//传送门方向 0朝左 1朝上 2朝右 3朝下 
public:
	CPortal(const char *szName);
	~CPortal(void);
	//set函数====================================================================================
	void			SetPortalState(int iPortalState)	{m_iPortalState = iPortalState;}	//设置
	void			SetDir(int iDir)					{m_iDir = iDir;}					//设置
	//get函数====================================================================================
	int				GetPortalState()					{return m_iPortalState;}
	int				GetDir()							{return m_iDir;}
	//Portal基本功能函数=========================================================================
	void			PortalInit(float fPortalPosX, float fPortalPosY, int iPortalState );
	void			SetPortal(float fBulletPosX, float fBulletPosY, float fBlockPosX, float fBlockPosY, const char* szTarName);
};

