#include "..\Header\Player.h"
//================================================================================================================================================================
CPlayer::CPlayer(const char* szName):CAnimateSprite(szName)
{
}
//================================================================================================================================================================
CPlayer::~CPlayer(void)
{
}
//================================================================================================================================================================
void CPlayer::PlayerSpriteInit(float fPlayerMass)
{	//CPlayer父类类型初始化函数定义
	//玩家特征变量初始化
	m_fPlayerMass		=	fPlayerMass;
	m_iJumpState		=	0;
	m_fSpeedTop			=	0;
	m_fSpeedLeft		=	0;
	m_fSpeedBottom		=	0;
	m_fSpeedRight		=	0;
	//玩家角色初始特征设置
	SetSpriteMass(fPlayerMass);					//设置玩家角色的质量
	SetSpriteConstantForce(0,1800,1);			//设置玩家收到的引力
	SetSpriteWorldLimit(WORLD_LIMIT_NULL, CSystem::GetScreenLeft(), CSystem::GetScreenTop(), CSystem::GetScreenRight(), CSystem::GetScreenBottom());
												//设置玩家角色的世界边界
	SetSpriteCollisionActive(1,1);				//设置玩家角色的碰撞发送与接收
	SetSpriteVisible(true);						//设置玩家角色的可见性
}
//================================================================================================================================================================
//玩家左右横移设置函数 纯虚函数 具体定义分别在CPlayerSpriteA和CPlayerSpriteB中实现
//================================================================================================================================================================