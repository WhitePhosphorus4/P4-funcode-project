#pragma once
#include "Player.h"
class CPlayerSpriteA:
	public CPlayer
{
public:
	CPlayerSpriteA( const char *szName );
	~CPlayerSpriteA(void);						
	//��ҹ��ܺ���==========================================================================================================================================
	virtual	void		OnMove(int iKey, bool bPress);			//��ҽ�ɫ�ƶ���������ʵ��								//������Һ������ú���
	virtual void		OnJump();
};

