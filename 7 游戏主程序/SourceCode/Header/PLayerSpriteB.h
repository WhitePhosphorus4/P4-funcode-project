#pragma once
#include "player.h"
class CPLayerSpriteB :
	public CPlayer
{
public:
	CPLayerSpriteB( const char *szName );
	~CPLayerSpriteB(void);
	//玩家功能函数==========================================================================================================================================
	virtual	void		OnMove(int iKey, bool bPress);			//玩家角色移动函数具体实现
	virtual void		OnJump();
};

