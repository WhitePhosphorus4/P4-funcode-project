#include "..\Header\Bullet.h"


CBullet::CBullet(const char *szName):CSprite( szName )
{
}


CBullet::~CBullet(void)
{
}

void CBullet::OnMove(float fPosX, float fPosY, float fMousePosX, float fMousePosY)
{
	SetSpritePosition(fPosX, fPosY);
	SetSpriteRotation(180/3.14*atan2(fMousePosY-fPosY, fMousePosX-fPosY) - 90);
	SpriteMoveTo(fMousePosX, fMousePosY, 400, 0);
}
