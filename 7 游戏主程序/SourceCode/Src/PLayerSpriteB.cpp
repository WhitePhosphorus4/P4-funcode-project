#include "..\Header\PLayerSpriteB.h"
//================================================================================================================================================================
CPLayerSpriteB::CPLayerSpriteB( const char *szName ):CPlayer( szName )
{
}
//================================================================================================================================================================
CPLayerSpriteB::~CPLayerSpriteB(void)
{
}
//================================================================================================================================================================
void CPLayerSpriteB::OnMove(int iKey, bool bPress)
{
	if(bPress){									//按下AD按键时各方向速度设置
		switch(iKey){
			case KEY_A:
				SetSpeedLeft(-200);	
				break;
			case KEY_D:
				SetSpeedRight(200) ;
				break;
		}
	}	
	else{										//抬起AD按键时各方向速度归零
		if(iKey == KEY_A ||iKey == KEY_D){
				SetSpeedLeft(0);
				SetSpeedRight(0);
		}
	}
	if((GetSpeedLeft() + GetSpeedRight()) > 0){
		SetSpriteFlipX( false);					//根据合速度方向 判断人物行走朝向：动画初始方向向右 合速度向右 动画不反转
	}
	else if((GetSpeedLeft() + GetSpeedRight()) < 0){
		SetSpriteFlipX( true);					//根据合速度方向 判断人物想走朝向：动画初始方向向左 合速度向左 动画反转
	}
	SetSpriteLinearVelocityX( GetSpeedLeft() + GetSpeedRight() );
	if(GetSpeedLeft() + GetSpeedRight() == 0){	//根据速度方向选择人物动画 正面或侧面
		AnimateSpritePlayAnimation( "PlayerPic04Animation1", 0 );
	}
	else{
		AnimateSpritePlayAnimation( "PlayerPic04Animation3", 0 );
	}
}
//================================================================================================================================================================
void CPLayerSpriteB::OnJump()
{	//玩家二阶跳跃函数定义 不涉及按键操作 因此无需定义为虚函数
	if( GetJumpState() == 0 ){					//起跳之前状态0 表示第一次起跳前人物站在地面上
		SetJumpState(1);						//起跳后状态变为1 表示第一次起跳后的腾空状态
		SetSpriteImpulseForcePolar(-90,500,0);	//设置起跳的瞬时力大小
	}
	else if( GetJumpState() == 1 ){				//起跳之前状态为1 表示已经处于提一次起跳后的腾空状态
		SetJumpState(2);						//第二次起跳后状态变为1 表示第二次起跳后的腾空状态
		SetSpriteLinearVelocityY(0);			//设置当前速度为零，。排除瞬时速度对跳跃高度的影响
		SetSpriteImpulseForcePolar(-90,500,0);	//设置起跳的瞬时力大小
	}
}
//================================================================================================================================================================