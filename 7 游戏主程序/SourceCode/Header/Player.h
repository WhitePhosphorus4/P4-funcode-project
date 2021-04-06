#pragma once
#include "commonclass.h"
class CPlayer :
	public CAnimateSprite
{
private:
	//玩家特征变量定义======================================================================================================================================
	float			m_fPlayerMass;					//人物质量
	int				m_iJumpState;					//跳跃状态变量 实现二连跳 判断腾空状态 0为站在地面 1为腾空一阶条状态 2为腾空二阶跳状态
	float			m_fSpeedTop;					//上升速度
	float			m_fSpeedLeft;					//玩家左移速度
	float			m_fSpeedBottom;					//玩家下降速度
	float			m_fSpeedRight;					//玩家右移速度
public:
	CPlayer(const char* szName);
	~CPlayer(void);									//继承类型：CAnimateSprite
	//set函数===============================================================================================================================================
	//设置玩家类型特征变量
	void			SetPlayerMass(float fPlayerMass)	{fPlayerMass = m_fPlayerMass;}		//设置玩家质量
	void			SetJumpState(int iJumpState)		{m_iJumpState = iJumpState;}		//设置跳跃状态 0为站在地面 1为腾空一阶条状态 2为腾空二阶跳状态
	void			SetSpeedTop(float fSpeedTop)		{m_fSpeedTop = fSpeedTop;}			//设置玩家上升速度
	void			SetSpeedLeft(float fSpeedLeft)		{m_fSpeedLeft = fSpeedLeft;}		//设置玩家左移速度
	void			SetSpeedBottom(float fSpeedBottom)	{m_fSpeedBottom = fSpeedBottom;}	//设置玩家下降速度
	void			SetSpeedRight(float fSpeedRight)	{m_fSpeedRight = fSpeedRight;}		//设置玩家右移速度
	//get函数===============================================================================================================================================
	//获取玩家类型特征变量
	float			GetPlayerMass()						{return m_fPlayerMass;}				//获取玩家质量
	int				GetJumpState()						{return m_iJumpState;}				//获取跳跃状态 0为站在地面 1为腾空一阶条状态 2为腾空二阶跳状态
	float			GetSpeedTop()						{return m_fSpeedTop;}				//获取玩家上升速度
	float			GetSpeedLeft()						{return m_fSpeedLeft;}				//获取玩家左移速度
	float			GetSpeedBottom()					{return m_fSpeedBottom;}			//获取玩家下降速度
	float			GetSpeedRight()						{return m_fSpeedRight;}				//获取玩家右移速度
	//玩家功能函数==========================================================================================================================================
	void			PlayerSpriteInit(float fPlayerMass);									//玩家精灵初始化函数
	virtual	void	OnMove(int iKey, bool bPress) = 0;										//玩家左右横移设置函数 纯虚函数 具体定义分别在CPlayerSpriteA和CPlayerSpriteB中实现
	virtual void	OnJump() = 0;															//玩家二连跳动作实现函数 不涉及按键操作 因此无需定义为虚函数
};

