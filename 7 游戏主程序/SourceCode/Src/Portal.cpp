#include "..\Header\Portal.h"


CPortal::CPortal(const char *szName):CSprite(szName)
{
	m_iPortalState = 1;
	m_iDir = 1;
}


CPortal::~CPortal(void)
{
}


void CPortal::PortalInit(float fPortalPosX, float fPortalPosY, int iPortalState )
{
	SetSpritePositionX(fPortalPosX);
	SetSpritePositionY(fPortalPosY);
	m_iPortalState = iPortalState;
	SetSpriteCollisionActive(0, 1);
}

void CPortal::SetPortal(float fBulletPosX, float fBulletPosY, float fBlockPosX, float fBlockPosY, const char* szTarName)
{
	if(strstr(szTarName, "Block_L") != NULL){
		SetSpriteRotation(90);
		if(fBulletPosY  > fBlockPosY){
			PortalInit(fBulletPosX, fBulletPosY, 1);
			SetDir(3);
		}
		else if(fBulletPosY  < fBlockPosY){
			PortalInit(fBulletPosX, fBulletPosY, 1);
			SetDir(1);
		}
	}
	else if(strstr(szTarName, "Block_V") != NULL){
		SetSpriteRotation(0);
		if(fBulletPosX  > fBlockPosX){
			PortalInit(fBulletPosX, fBulletPosY, 1);
			SetDir(2);
		}
		else if(fBulletPosX  < fBlockPosX){
			PortalInit(fBulletPosX, fBulletPosY, 1);
			SetDir(0);
		}
	}
}
