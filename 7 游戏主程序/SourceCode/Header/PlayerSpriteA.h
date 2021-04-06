#pragma once
#include "Player.h"
class CPlayerSpriteA:
	public CPlayer
{
public:
	CPlayerSpriteA( const char *szName );
	~CPlayerSpriteA(void);						
	//玩家功能函数==========================================================================================================================================
	virtual	void		OnMove(int iKey, bool bPress);			//玩家角色移动函数具体实现								//玩家左右横移设置函数
	virtual void		OnJump();
};

