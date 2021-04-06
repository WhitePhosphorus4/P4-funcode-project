/////////////////////////////////////////////////////////////////////////////////
//
//游戏的开始界面
//(有一个隐藏的载入接口，初始界面按1进入关卡4）
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonClass.h"
#include "LessonS.h"
////////////////////////////////////////////////////////////////////////////////
//
//
AGameMain		a_GameMain;	

//==============================================================================
//
// 大体的程序流程为：GameMainLoop函数为主循环函数，在引擎每帧刷新屏幕图像之后，都会被调用一次。

//==============================================================================
//
// 构造函数
AGameMain::AGameMain()
{
	m_iGameState			=	1;
	m_pCampaign1			=	new CSprite("Campaign1");
	m_pCampaign2			=	new CSprite("Campaign2");
	m_pFight				=	new CSprite("Fight");
	m_pIntroduce			=	new CSprite("Introduce");
	m_pFirstLevel			=	new CSprite("FirstLevel");
	m_pSecondLevel			=	new CSprite("SecondLevel");
	m_pThirdLevel			=	new CSprite("ThirdLevel");
	m_pBack1				=	new CSprite("Back1");
	m_pBack2				=	new CSprite("Back2");
	m_pYes					=	new CSprite("YES");
	m_pOther1				=	new CSprite("Other1");
	m_pOther2				=	new CSprite("Other2");
	m_pIntroduce1			=	new CSprite("Introduce1");
	m_pIntroduce2			=	new CSprite("Introduce2");
	m_pLetter				=	new CSprite("Letter");
	m_pKuang11				=	new CSprite("Kuang11");
	m_pKuang12				=	new CSprite("Kuang12");
	m_pKuang13				=	new CSprite("Kuang13");
	m_pKuang21				=	new CSprite("Kuang21");
	m_pKuang22				=	new CSprite("Kuang22");
	m_pKuang23				=	new CSprite("Kuang23");
	m_pKuang31				=	new CSprite("Kuang31");
	m_pKuang32				=	new CSprite("Kuang32");
	m_pKuang33				=	new CSprite("Kuang33");
	m_pBlack				=	new CSprite("iBlack1");
	

	m_SoundMenu				=	new CSound("menu.wav", 0, 1);
	m_BgmA					=	new CSound("a.wav", 1, 1);
}
//==============================================================================
//
// 析构函数
AGameMain::~AGameMain()
{
}

//==============================================================================
//
// 游戏主循环，此函数将被不停的调用，引擎每刷新一次屏幕，此函数即被调用一次
// 用以处理游戏的开始、进行中、结束等各种状态. 
// 函数参数fDeltaTime : 上次调用本函数到此次调用本函数的时间间隔，单位：秒
void AGameMain::GameMainLoop( float	fDeltaTime )
{
	switch( GetGameState() )
	{
		// 初始化游戏，清空上一局相关数据
	case 1:
		{
			GameInit();
			SetGameState(2); // 初始化之后，将游戏状态设置为进行中
		}
		break;

		// 游戏进行中，处理各种游戏逻辑
	case 2:
		{
			// TODO 修改此处游戏循环条件，完成正确游戏逻辑
			if( true )
			{
				GameRun( fDeltaTime );
			}
			else // 游戏结束。调用游戏结算函数，并把游戏状态修改为结束状态
			{				
				SetGameState(0);
				GameEnd();
			}
		}
		break;
	case 3:
		{
			// TODO 修改此处游戏循环条件，完成正确游戏逻辑
			if( true )
			{
				GameRun3( fDeltaTime );
			}
			else // 游戏结束。调用游戏结算函数，并把游戏状态修改为结束状态
			{				
				SetGameState(0);
				GameEnd();
			}
		}
		break;
	case 4:
		{
			// TODO 修改此处游戏循环条件，完成正确游戏逻辑
			if( true )
			{
				GameRun4( fDeltaTime );
			}
			else // 游戏结束。调用游戏结算函数，并把游戏状态修改为结束状态
			{				
				SetGameState(0);
				GameEnd();
			}
		}
		break;
	case 5:
		{
			// TODO 修改此处游戏循环条件，完成正确游戏逻辑
			if( true )
			{
				GameRun5( fDeltaTime );
			}
			else // 游戏结束。调用游戏结算函数，并把游戏状态修改为结束状态
			{				
				SetGameState(0);
				GameEnd();
			}
		}
		break;
	case 6:
		{
			// TODO 修改此处游戏循环条件，完成正确游戏逻辑
			if( true )
			{
				GameRun6( fDeltaTime );
			}
			else // 游戏结束。调用游戏结算函数，并把游戏状态修改为结束状态
			{				
				SetGameState(0);
				GameEnd();
			}
		}
		break;
		// 游戏结束/等待按空格键开始
	case 0:
	default:
		break;
	};
}
//=============================================================================
//
// 每局开始前进行初始化，清空上一局相关数据
void AGameMain::GameInit()
{
	//渐变效果参数初始化===============================================
	m_AlpahState			=	0;
	ColorAlpha				=	255;
	//设置初始位置====================================================
	m_pCampaign1->SetSpritePosition(-993.614,-55.400);
	m_pCampaign2->SetSpritePosition(1347.600,27.903);
	m_pFight->SetSpritePosition(-993.614,43.987);
	m_pIntroduce->SetSpritePosition(-993.614,132.400);
	m_pFirstLevel->SetSpritePosition(1028.080,-95.671);
	m_pSecondLevel->SetSpritePosition(1031.070,-3.394);
	m_pThirdLevel->SetSpritePosition(1029.830,90.316);
	m_pBack1->SetSpritePosition(987.063,171.823);
	m_pBack2->SetSpritePosition(1415.550,120.651);
	m_pYes->SetSpritePosition(1301.520,120.965);
	m_pOther1->SetSpritePosition(1350.440,-48.404);
	m_pOther2->SetSpritePosition(1594.500,12.330);
	m_pIntroduce1->SetSpritePosition(0,-1085.320);
	m_pIntroduce2->SetSpritePosition(0,-1085.320);
	m_pLetter->SetSpritePosition(0,1125.640);
	m_pBlack->SetSpritePosition(0,0);
	//设置框框初始不可见
	m_pKuang11->SetSpriteVisible(0);
	m_pKuang12->SetSpriteVisible(0);
	m_pKuang13->SetSpriteVisible(0);
	m_pKuang21->SetSpriteVisible(0);
	m_pKuang22->SetSpriteVisible(0);
	m_pKuang23->SetSpriteVisible(0);
	m_pKuang31->SetSpriteVisible(0);
	m_pKuang32->SetSpriteVisible(0);
	m_pKuang33->SetSpriteVisible(0);
	//左边开始菜单的移动===============================================
	m_pCampaign1->SpriteMoveTo(-456.615,-64.146,1200,1);
	m_pFight->SpriteMoveTo(-456.615,32.243,1200,1);
	m_pIntroduce->SpriteMoveTo(-456.615,128.632,1200,1);
	m_SoundMenu->StopAllSound();
	m_BgmA->PlaySoundA();
}
//=============================================================================
//
// 在初始菜单界面等待玩家选择
void AGameMain::GameRun( float fDeltaTime )
{
	//开场渐变效果
	ColorAlphaMaking(255,0,1);
}
//=============================================================================
//
// 选择了剧情模式
void AGameMain::GameRun3( float fDeltaTime )
{
}
//=============================================================================
//
// 选择了闯关模式
void AGameMain::GameRun4( float fDeltaTime )
{
	switch(m_AlpahState)
	{
	case 0:
		break;
	case 1:
		if(ColorAlphaMaking(0,255,1)==1)
		{
			LevelState =1;
			MapLoadingState = 1;
			PatternState=1;
		}
		break;
	case 2:
		if(ColorAlphaMaking(0,255,1)==1)
		{
			LevelState =2;
			MapLoadingState = 1;
			PatternState=1;
		}
		break;
	case 3:
		if(ColorAlphaMaking(0,255,1)==1)
		{
			LevelState =3;
			MapLoadingState = 1;
			PatternState=1;
		}
		break;
	}
}
//=============================================================================
//
// 选择了游戏介绍
void AGameMain::GameRun5( float fDeltaTime )
{
}
//=============================================================================
//
// 剧情模式等待开始
void AGameMain::GameRun6( float fDeltaTime )
{
	switch(m_AlpahState)
	{
		//从透明变不透明
	case 0:
		{
			if(ColorAlphaMaking(0,255,1)==1)
			{
				m_AlpahState=1;
			}
		}
		break;
		//从不透明变透明
	case 1:
		{
			m_pLetter->SetSpritePosition(0,0);
			if(ColorAlphaMaking(255,0,1)==1)
			{
				m_AlpahState=3;
			}
		}
		break;
		//从透明变不透明
	case 2:
		{
			if(ColorAlphaMaking(0,255,1)==1)
			{
				LevelState =1;
				MapLoadingState = 1;
				PatternState=2;
			}
			
		}
		break;
	}
}
//=============================================================================
//
// 本局游戏结束
void AGameMain::GameEnd()
{
}
//==========================================================================
//
// 鼠标移动
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void AGameMain::OnMouseMove( const float fMouseX, const float fMouseY )
{
	switch( GetGameState() )
	{
	case 2:
		{
			if(m_pKuang11->IsPointInSprite(fMouseX,fMouseY))
			{
				m_pKuang11->SetSpriteVisible(1);
			}
			else if(m_pKuang12->IsPointInSprite(fMouseX,fMouseY))
			{
				m_pKuang12->SetSpriteVisible(1);
			}
			else if(m_pKuang13->IsPointInSprite(fMouseX,fMouseY))
			{
				m_pKuang13->SetSpriteVisible(1);
			}
			else
			{
				m_pKuang11->SetSpriteVisible(0);
				m_pKuang12->SetSpriteVisible(0);
				m_pKuang13->SetSpriteVisible(0);
			}
		}
		break;
	case 3:
		{
			if(m_pKuang33->IsPointInSprite(fMouseX,fMouseY))
			{
				m_pKuang33->SetSpriteVisible(1);
			}
			else if(m_pKuang32->IsPointInSprite(fMouseX,fMouseY))
			{
				m_pKuang32->SetSpriteVisible(1);
			}
			else
			{
				m_pKuang32->SetSpriteVisible(0);
				m_pKuang33->SetSpriteVisible(0);
			}
		}
		break;
	case 4:
		{
			if(m_pKuang21->IsPointInSprite(fMouseX,fMouseY))
			{
				m_pKuang21->SetSpriteVisible(1);
			}
			else if(m_pKuang22->IsPointInSprite(fMouseX,fMouseY))
			{
				m_pKuang22->SetSpriteVisible(1);
			}
			else if(m_pKuang23->IsPointInSprite(fMouseX,fMouseY))
			{
				m_pKuang23->SetSpriteVisible(1);
			}
			else if(m_pKuang31->IsPointInSprite(fMouseX,fMouseY))
			{
				m_pKuang31->SetSpriteVisible(1);
			}
			else
			{
				m_pKuang21->SetSpriteVisible(0);
				m_pKuang22->SetSpriteVisible(0);
				m_pKuang23->SetSpriteVisible(0);
				m_pKuang31->SetSpriteVisible(0);
			}
		}
	case 5:
		{
			
		}
	case 6:
		{
			
		}
	}
}
//==========================================================================
//
// 鼠标点击
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void AGameMain::OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
	switch( GetGameState() )
	{
	case 2:
		{
			if(m_pCampaign1->IsPointInSprite(fMouseX,fMouseY))
			{
				SetGameState(3);
				m_pOther1->SpriteMoveTo(450.444,-30.334,1500,1);
				m_pCampaign2->SpriteMoveTo(447.603,45.972,1500,1);
				m_pOther2->SpriteMoveTo(694.501,30.400,1500,1);
				m_pYes->SpriteMoveTo(401.521,139.035,1500,1);
				m_pBack2->SpriteMoveTo(515.554,138.721,1500,1);
				m_SoundMenu->PlaySoundA();
			}
			if(m_pFight->IsPointInSprite(fMouseX,fMouseY))
			{
				SetGameState(4);
				m_pFirstLevel->SpriteMoveTo(463.078,-90.671,1500,1);
				m_pSecondLevel->SpriteMoveTo(466.074,1.606,1500,1);
				m_pThirdLevel->SpriteMoveTo(464.828,95.316,1500,1);
				m_pBack1->SpriteMoveTo(422.063,176.823,1500,1);
				m_SoundMenu->PlaySoundA();
			}
			if(m_pIntroduce->IsPointInSprite(fMouseX,fMouseY))
			{
				m_pIntroduce1->SpriteMoveTo(0,0,1400,1);
				m_pIntroduce2->SetSpritePosition(0,-1085.320);
				SetGameState(5);
				m_SoundMenu->PlaySoundA();
			}
		}
		break;
	case 3:
		{
			if(m_pYes->IsPointInSprite(fMouseX,fMouseY))
			{
				SetGameState(6);
				m_SoundMenu->PlaySoundA();
			}
			if(m_pBack2->IsPointInSprite(fMouseX,fMouseY))
			{
				SetGameState(2);
				m_pOther1->SpriteMoveTo(1350.440,-48.404,1500,1);
				m_pCampaign2->SpriteMoveTo(1347.600,27.903,1500,1);
				m_pOther2->SpriteMoveTo(1594.500,12.330,1500,1);
				m_pYes->SpriteMoveTo(1301.520,120.965,1500,1);
				m_pBack2->SpriteMoveTo(1415.550,120.651,1500,1);
				m_SoundMenu->PlaySoundA();
			}
		}
		break;
	case 4:
		{
			if(m_pFirstLevel->IsPointInSprite(fMouseX,fMouseY))
			{
				m_AlpahState=1;
				m_SoundMenu->PlaySoundA();
			}
			if(m_pSecondLevel->IsPointInSprite(fMouseX,fMouseY))
			{
				m_AlpahState=2;
				m_SoundMenu->PlaySoundA();
			}
			if(m_pThirdLevel->IsPointInSprite(fMouseX,fMouseY))
			{
				m_AlpahState=3;
				m_SoundMenu->PlaySoundA();
			}
			if(m_pBack1->IsPointInSprite(fMouseX,fMouseY))
			{
				SetGameState(2);
				m_pFirstLevel->SpriteMoveTo(1028.080,-95.671,1500,1);
				m_pSecondLevel->SpriteMoveTo(1031.070,-3.394,1500,1);
				m_pThirdLevel->SpriteMoveTo(1029.830,90.316,1500,1);
				m_pBack1->SpriteMoveTo(987.063,171.823,1500,1);
				m_SoundMenu->PlaySoundA();
			}
		}
	case 5:
		{
			if(m_pIntroduce1->IsPointInSprite(fMouseX,fMouseY))
			{
				m_pIntroduce1->SpriteMoveTo(0,1085.320,1700,1);
				m_pIntroduce2->SpriteMoveTo(0,0,1400,1);
				m_SoundMenu->PlaySoundA();
			}
			if(m_pIntroduce2->IsPointInSprite(fMouseX,fMouseY))
			{
				m_pIntroduce2->SpriteMoveTo(0,1085.320,1700,1);
				m_SoundMenu->PlaySoundA();
				SetGameState(2);
				m_pIntroduce1->SetSpritePosition(0,-1085.320);
			}
		}
	case 6:
		{
			if(m_pLetter->IsPointInSprite(fMouseX,fMouseY))
			{
				m_AlpahState=2;
				m_SoundMenu->PlaySoundA();
			}
		}
	}

}
//==========================================================================
//
// 鼠标弹起
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void AGameMain::OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
	
}
//==========================================================================
//
// 键盘按下
// 参数 iKey：被按下的键，值见 enum KeyCodes 宏定义
// 参数 iAltPress, iShiftPress，iCtrlPress：键盘上的功能键Alt，Ctrl，Shift当前是否也处于按下状态(0未按下，1按下)
void AGameMain::OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{	
}
//==========================================================================
//
// 键盘弹起
// 参数 iKey：弹起的键，值见 enum KeyCodes 宏定义
void AGameMain::OnKeyUp( const int iKey )
{
	
}
//===========================================================================
//
// 精灵与精灵碰撞
// 参数 szSrcName：发起碰撞的精灵名字
// 参数 szTarName：被碰撞的精灵名字
void AGameMain::OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
	
}
//===========================================================================
//
// 精灵与世界边界碰撞
// 参数 szName：碰撞到边界的精灵名字
// 参数 iColSide：碰撞到的边界 0 左边，1 右边，2 上边，3 下边
void AGameMain::OnSpriteColWorldLimit( const char *szName, const int iColSide )
{
	
}

//===========================================================================
//
// 设置渐变块的渐变效果
// 参数 AlphaStart：初始渐变块透明度
// 参数 AlphaEnd：结束渐变块透明度
// 参数 Accuracy：变化精度
int AGameMain::ColorAlphaMaking(const double AlphaStart,const double AlphaEnd,const double Accuracy)
{
	static int LoadingState	=	1;
	if(LoadingState==1)
	{
		ColorAlpha	=	AlphaStart;
		m_pBlack->SetSpriteColorAlpha(ColorAlpha);
		LoadingState	=	0;
	}
	if(ColorAlpha	>	AlphaEnd)
	{
		ColorAlpha-=Accuracy;
		m_pBlack->SetSpriteColorAlpha(ColorAlpha);
		return 0;
	}
	else if(ColorAlpha	<	AlphaEnd)
	{
		ColorAlpha+=Accuracy;
		m_pBlack->SetSpriteColorAlpha(ColorAlpha);
		return 0;
	}
	else
	{
		return 1;
	}
}