#pragma once
#include "player.h"
class CPLayerSpriteB :
	public CPlayer
{
public:
	CPLayerSpriteB( const char *szName );
	~CPLayerSpriteB(void);
	//��ҹ��ܺ���==========================================================================================================================================
	virtual	void		OnMove(int iKey, bool bPress);			//��ҽ�ɫ�ƶ���������ʵ��
	virtual void		OnJump();
};

