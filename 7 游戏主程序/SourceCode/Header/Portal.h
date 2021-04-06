#pragma once
//===========================================================================================
#include "commonclass.h"

//===========================================================================================
class CPortal :
	public CSprite
{
private:
//set����====================================================================================
	int				m_iPortalState;		//������״̬
	int				m_iDir;				//�����ŷ��� 0���� 1���� 2���� 3���� 
public:
	CPortal(const char *szName);
	~CPortal(void);
	//set����====================================================================================
	void			SetPortalState(int iPortalState)	{m_iPortalState = iPortalState;}	//����
	void			SetDir(int iDir)					{m_iDir = iDir;}					//����
	//get����====================================================================================
	int				GetPortalState()					{return m_iPortalState;}
	int				GetDir()							{return m_iDir;}
	//Portal�������ܺ���=========================================================================
	void			PortalInit(float fPortalPosX, float fPortalPosY, int iPortalState );
	void			SetPortal(float fBulletPosX, float fBulletPosY, float fBlockPosX, float fBlockPosY, const char* szTarName);
};

