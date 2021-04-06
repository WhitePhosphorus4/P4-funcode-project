/////////////////////////////////////////////////////////////////////////////////
//
//第二关
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonClass.h"
#include "LessonY.h"
////////////////////////////////////////////////////////////////////////////////
//
//
DGameMain		e_GameMain;	

//============================================================================================
//
// 大体的程序流程为：GameMainLoop函数为主循环函数，在引擎每帧刷新屏幕图像之后，都会被调用一次。

//============================================================================================
//
// 构造函数
DGameMain::DGameMain()
{

	m_iGameState		=	0;
	m_iIfAlive			=	1;
	//========================================================================================
	m_pGameStart		=	new CSprite("gamestart");
	m_pPlayerSpriteA	=	new CPlayerSpriteA("testA");
	m_pPlayerSpriteB	=	new CPLayerSpriteB("testB");
	m_pPortalA			=	new CPortal("portalA");
	m_pPortalB			=	new CPortal("portalB");
	//射手精灵================================================================================
	m_pShooter1			=	new CSprite("shooter1");
	//预设传送门精灵==========================================================================
	m_pPrePortalA1		=	new CPortal("preportalA1");
	m_pPrePortalB1		=	new CPortal("preportalB1");
	m_pPrePortalA2		=	new CPortal("preportalA2");
	m_pPrePortalB2		=	new CPortal("preportalB2");
	//门精灵==================================================================================
	m_pDoor1			=	new CSprite("door1");
	m_pDoor2			=	new CSprite("door2");
	m_pDoor3			=	new CSprite("door3");
	//触发器精灵==============================================================================
	m_pTrigger1			=	new CTrigger("trigger1");
	m_pTrigger2			=	new CTrigger("trigger2");
	m_pJetSmoke			=	new CSprite("jetsmoke");
	m_pBulletTrigger1	=	new CTrigger("bullettrigger1");

	m_pLevelGate		=	
	//==========================================================================================
	m_PausePhoto		=	new CSprite("Pausephoto");
	m_DeadPhoto			=	new CSprite("DeadPhoto");
	m_ConPhoto1			=	new CSprite("Congratulations1");
	m_ConPhoto2			=	new CSprite("Congratulations2");

	m_SoundMenu			=	new CSound("menu.wav", 0, 1);
	m_SoundRunning1		=	new CSound("runing.wav", 0, 1);
	m_SoundRunning2		=	new CSound("runing.wav", 0, 1);
	m_SoundFire			=	new CSound("fire.wav", 0, 1);
	m_SoundPortal		=	new CSound("portal.wav", 0, 1);
	m_SoundOpenDoor		=	new CSound("door open.wav", 0, 1);
	m_Soundtaping		=	new CSound("taping.wav", 0, 1);
	m_SoundManDead		=	new CSound("man dead.wav", 0, 1);
	m_SoundWomanDead	=	new CSound("woman dead.wav", 0, 1);
	m_SoundTrig			=	new CSound("trig.wav", 0, 1);
	m_SoundTrans		=	new CSound("trans.wav", 0, 1);
	m_SoundWarning		=	new CSound("warning.wav", 0, 1);
	m_BgmC				=	new CSound("d.wav", 1, 1);

	m_pBlack				=	new CSprite("iBlack1");
}
//============================================================================================
//
// 析构函数
DGameMain::~DGameMain()
{
}

//============================================================================================
//
// 游戏主循环，此函数将被不停的调用，引擎每刷新一次屏幕，此函数即被调用一次
// 用以处理游戏的开始、进行中、结束等各种状态. 
// 函数参数fDeltaTime : 上次调用本函数到此次调用本函数的时间间隔，单位：秒
void DGameMain::GameMainLoop( float	fDeltaTime )
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
		}
		break;
	case 4:
		{
			if(m_AlpahState	== 1&&ColorAlphaMaking(0,255,1)==1)
			{
				LevelState = 4;
				MapLoadingState = 1;
			}
		}
		break;
		// 游戏结束/等待按空格键开始
	case 0:
		{
			m_pBlack->SetSpritePosition(0,0);
		}
	default:
		break;
	};
}
//============================================================================================
//
// 每局开始前进行初始化，清空上一局相关数据
void DGameMain::GameInit()
{
	ColorAlpha				=	255;
	m_AlpahState			=	0;
	//========================================================================================
	m_fTime = 0;
	//========================================================================================
	m_iIfAlive = 1;
	m_iPlayerAState = 0;
	m_iPlayerBState = 0;
	//========================================================================================
	m_pPlayerSpriteA->PlayerSpriteInit(1);
	m_pPlayerSpriteB->PlayerSpriteInit(1);
	//========================================================================================
	m_pMap.SetMapInfo(40, 40);
	//========================================================================================
	m_pTrigger1->SetTriggerResult(0);
	m_pTrigger2->SetTriggerResult(0);
	m_pBulletTrigger1->SetTriggerResult(0);
	//========================================================================================
	m_iBulletNum_1 = 0;
	m_iBulletNum_2 = 0;
	m_iBulletNum_3 = 0;
	//========================================================================================
	m_pPortalA->PortalInit(40, 600, 1);
	m_pPortalB->PortalInit(-40, 600, 1);
	m_pPrePortalA1->SetDir(2);
	m_pPrePortalB1->SetDir(0);
	m_pPrePortalA2->SetDir(2);
	m_pPrePortalB2->SetDir(0);
	//========================================================================================
	fDoor1PosX = m_pDoor1->GetSpritePositionX();
	fDoor1PosY = m_pDoor1->GetSpritePositionY();
	fDoor2PosX = m_pDoor2->GetSpritePositionX();
	fDoor2PosY = m_pDoor2->GetSpritePositionY();
	fDoor3PosX = m_pDoor3->GetSpritePositionX();
	fDoor3PosY = m_pDoor3->GetSpritePositionY();
	m_SoundMenu->StopAllSound();
	m_BgmC->PlaySoundA();
	m_iRunningFlag1 = 0;
	m_iRunningFlag2 = 0;
	m_pBlack->SetSpritePosition(0,0);
}
//============================================================================================
//
// 每局游戏进行中
void DGameMain::GameRun( float fDeltaTime )
{
	//开场渐变效果
	ColorAlphaMaking(255,0,1);

	m_fTime +=	fDeltaTime;
	if(m_fTime > 0.25){
		AddBulletC();
		m_fTime = 0;
	}
	//玩家触发机关============================================================================
	if(m_pTrigger1->GetTriggerResult() == 1){
		m_pDoor2->SpriteMoveTo(fDoor2PosX, fDoor2PosY + 100, 50, 1);
	}
	if(m_pTrigger2->GetTriggerResult() == 1){
		m_pDoor1->SpriteMoveTo(fDoor1PosX - 120, fDoor1PosY , 50, 1);
	}
	//子弹触发机关===========================================================================
	if(m_pBulletTrigger1->GetTriggerResult() == 1){
		m_pDoor3->SpriteMoveTo(fDoor3PosX, fDoor3PosY + 120, 50, 1);
	}
	//玩家死亡============================================================================
	if(m_iIfAlive == 0){
		m_DeadPhoto->SpriteMoveTo(0,0,1500,1);
		m_pPlayerSpriteA->DeleteSprite();
		m_pPlayerSpriteB->DeleteSprite();
		SetGameState(3);
	}
	//玩家通过游戏============================================================================
	switch(PatternState)
	{
		//闯关模式切关
		case 1:
			if(m_iPlayerAState == 1 && m_iPlayerBState == 1){
				m_ConPhoto1->SpriteMoveTo(0,0,1500,1);
				m_pPlayerSpriteA->DeleteSprite();
				m_pPlayerSpriteB->DeleteSprite();
				SetGameState(4);
			}
			break;
		//剧情模式切关
		case 2:
			if(m_iPlayerAState == 1 && m_iPlayerBState == 1){
				m_ConPhoto2->SpriteMoveTo(0,0,1500,1);
				m_pPlayerSpriteA->DeleteSprite();
				m_pPlayerSpriteB->DeleteSprite();
				SetGameState(4);
			}
			break;
	}
}
//============================================================================================
//
// 本局游戏结束
void DGameMain::GameEnd()
{
}
//============================================================================================
//
// 鼠标移动
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void DGameMain::OnMouseMove( const float fMouseX, const float fMouseY )
{
	m_fMousePosX = fMouseX;
	m_fMousePosY = fMouseY;
}
//============================================================================================
//
// 鼠标点击
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void DGameMain::OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
	if(m_iGameState == 2){
		if(iMouseType == 0){
			AddBulletA();
			m_SoundFire->PlaySoundA();
		}
		if(iMouseType == 1){
			AddBulletB();
			m_SoundFire->PlaySoundA();
		}
	}
}
//============================================================================================
//
// 鼠标弹起
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void DGameMain::OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
	
}
//============================================================================================
//
// 键盘按下
// 参数 iKey：被按下的键，值见 enum KeyCodes 宏定义
// 参数 iAltPress, iShiftPress，iCtrlPress：键盘上的功能键Alt，Ctrl，Shift当前是否也处于按下状态(0未按下，1按下)
void DGameMain::OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{	
	//================================================================
	//暂停界面选择操作： 按键1或空格：继续当前游戏；按键2：重新开始；按键3：返回开始菜单
	if(GetGameState() == 3){
		if( iKey == KEY_1 || iKey == KEY_SPACE ){
			m_PausePhoto->SpriteMoveTo(0,-2000,1700,1);
			SetGameState(2);
			m_SoundMenu->PlaySoundA();
		}
		if(iKey == KEY_2 ){
			MapLoadingState = 1;
			m_SoundMenu->PlaySoundA();
		}
		if(iKey == KEY_3 ){
			LevelState =5;
			MapLoadingState = 1;
			m_SoundMenu->PlaySoundA();
		}
	}
	//==============================================================
	if(GetGameState() == 0){
		if(iKey == KEY_SPACE){
			SetGameState(1);
			m_pGameStart->SetSpriteVisible(0);
			m_SoundMenu->PlaySoundA();
		}
	}
	if(GetGameState() == 2){
		if(iKey == KEY_A || iKey == KEY_D){
			m_pPlayerSpriteB->OnMove(iKey, true);
			if(m_iRunningFlag1 == 0){
				m_iRunningFlag1 = 1;
				m_SoundRunning1->PlaySoundA();
			}
		}
		if(iKey == KEY_W){
			m_pPlayerSpriteB->OnJump();
		}
		if(iKey == KEY_LEFT || iKey == KEY_RIGHT){
			m_pPlayerSpriteA->OnMove(iKey, true);
			if(m_iRunningFlag2 == 0){
				m_iRunningFlag2 = 1;
				m_SoundRunning2->PlaySoundA();
			}
		}
		if(iKey == KEY_UP){
			m_pPlayerSpriteA->OnJump();
		}
		if(iKey == KEY_ENTER && m_pTrigger1->GetTriggerState() == 1){
			m_pTrigger1->SetTriggerResult(1);
		}
		//ESC触发游戏暂停界面====================================================================================
		if(iKey == KEY_ESCAPE){
			m_PausePhoto->SpriteMoveTo(0,0,1500,1);
			SetGameState(3);
			m_SoundMenu->PlaySoundA();
		}
	}
	//通关后继续操作的选择==========================================
	//闯关模式
	if(GetGameState() == 4 && PatternState == 1){
		if( iKey == KEY_1 || iKey == KEY_SPACE ){
			m_ConPhoto1->SpriteMoveTo(0,-1220,1700,1);
			LevelState = 2;
			MapLoadingState = 1;
			m_SoundMenu->PlaySoundA();
		}
		if(iKey == KEY_2 ){
			m_ConPhoto1->SpriteMoveTo(0,-1220,1700,1);
			SetGameState(3);
			LevelState = 5;
			MapLoadingState = 1;
			m_SoundMenu->PlaySoundA();
		}
	}
	//剧情模式
	if(GetGameState() == 4 && PatternState == 2){
		if( iKey == KEY_1 || iKey == KEY_SPACE ){
			m_AlpahState	= 1;
			m_SoundMenu->PlaySoundA();
		}
		if(iKey == KEY_2 ){
			m_ConPhoto1->SpriteMoveTo(0,-1220,1700,1);
			SetGameState(3);
			LevelState = 5;
			MapLoadingState = 1;
			m_SoundMenu->PlaySoundA();
		}
	}
}
//============================================================================================
//
// 键盘弹起
// 参数 iKey：弹起的键，值见 enum KeyCodes 宏定义
void DGameMain::OnKeyUp( const int iKey )
{
	if(GetGameState() == 2){
	
		if(iKey == KEY_A || iKey == KEY_D){
			m_pPlayerSpriteB->OnMove(iKey, false);
			m_SoundRunning1->StopSound();
			m_iRunningFlag1 = 0;
		}
		if(iKey == KEY_LEFT || iKey == KEY_RIGHT){
			m_pPlayerSpriteA->OnMove(iKey, false);
			m_SoundRunning2->StopSound();
			m_iRunningFlag2 = 0;
		}
	}
}
//============================================================================================
//
// 精灵与精灵碰撞
// 参数 szSrcName：发起碰撞的精灵名字
// 参数 szTarName：被碰撞的精灵名字
void DGameMain::OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
	//========================================================================================
	if(strcmp(szSrcName, "testA") == 0 && strstr(szTarName, "Block_L") != NULL){
		m_pPlayerSpriteA->SetSpriteLinearVelocityY(0);
		m_pPlayerSpriteA->SetJumpState(0);
	}
	if(strcmp(szSrcName, "testA") == 0 && strstr(szTarName, "Block_V") != NULL){
		m_pPlayerSpriteA->SetSpriteLinearVelocityX(0);
	}
	if(strcmp(szSrcName, "testB") == 0 && strstr(szTarName, "Block_L") != NULL){
		m_pPlayerSpriteB->SetSpriteLinearVelocityY(0);
		m_pPlayerSpriteB->SetJumpState(0);
	}
	if(strcmp(szSrcName, "testB") == 0 && strstr(szTarName, "Block_V") != NULL){
		m_pPlayerSpriteB->SetSpriteLinearVelocityX(0);
	}
	//========================================================================================
	if(strstr(szSrcName, "bulletA") != NULL && strstr(szTarName, "Block") != NULL ){
		OnBulletHitA(szSrcName, szTarName);
	}
	if(strstr(szSrcName, "bulletB") != NULL && strstr(szTarName, "Block") != NULL  ){
		OnBulletHitB(szSrcName, szTarName);
	}
	//========================================================================================
	if(strstr(szSrcName, "bulletA") != NULL && strstr(szTarName, "door1") != NULL ){
		m_pPortalA->SetSpriteRotation(90);
		if(FindBulletA(szSrcName)->GetSpritePositionX()  > fDoor1PosX){
			m_pPortalA->PortalInit(FindBulletA(szSrcName)->GetSpritePositionX(),  FindBulletA(szSrcName)->GetSpritePositionY(), 1);
			m_pPortalA->SetDir(1);
			m_SoundPortal->PlaySoundA();
		}
		else if(FindBulletA(szSrcName)->GetSpritePositionX()  < fDoor1PosX){
			m_pPortalA->PortalInit(FindBulletA(szSrcName)->GetSpritePositionX(),  FindBulletA(szSrcName)->GetSpritePositionY(), 1);
			m_pPortalA->SetDir(3);
			m_SoundPortal->PlaySoundA();
		}
		FindBulletA(szSrcName)->DeleteSprite();
	}
	if(strstr(szSrcName, "bulletB") != NULL && strstr(szTarName, "door1") != NULL  ){
		m_pPortalB->SetSpriteRotation(90);
		if(FindBulletB(szSrcName)->GetSpritePositionX()  > fDoor1PosX){
			m_pPortalB->PortalInit(FindBulletB(szSrcName)->GetSpritePositionX(),  FindBulletB(szSrcName)->GetSpritePositionY(), 1);
			m_pPortalB->SetDir(1);
			m_SoundPortal->PlaySoundA();
		}
		else if(FindBulletB(szSrcName)->GetSpritePositionX()  < fDoor1PosX){
			m_pPortalB->PortalInit(FindBulletB(szSrcName)->GetSpritePositionX(),  FindBulletB(szSrcName)->GetSpritePositionY(), 1);
			m_pPortalB->SetDir(3);
			m_SoundPortal->PlaySoundA();
		}
		FindBulletB(szSrcName)->DeleteSprite();
	}
	//========================================================================================
	if(strstr(szSrcName, "bulletA") != NULL && strstr(szTarName, "door2") != NULL ){
		m_pPortalA->SetSpriteRotation(0);
		if(FindBulletA(szSrcName)->GetSpritePositionX()  > fDoor2PosX){
			m_pPortalA->PortalInit(FindBulletA(szSrcName)->GetSpritePositionX(),  FindBulletA(szSrcName)->GetSpritePositionY(), 1);
			m_pPortalA->SetDir(2);
			m_SoundPortal->PlaySoundA();
		}
		else if(FindBulletA(szSrcName)->GetSpritePositionX()  < fDoor2PosX){
			m_pPortalA->PortalInit(FindBulletA(szSrcName)->GetSpritePositionX(),  FindBulletA(szSrcName)->GetSpritePositionY(), 1);
			m_pPortalA->SetDir(0);
			m_SoundPortal->PlaySoundA();
		}
		FindBulletA(szSrcName)->DeleteSprite();
	}
	if(strstr(szSrcName, "bulletB") != NULL && strstr(szTarName, "door2") != NULL  ){
		m_pPortalB->SetSpriteRotation(0);
		if(FindBulletB(szSrcName)->GetSpritePositionX()  > fDoor2PosX){
			m_pPortalB->PortalInit(FindBulletB(szSrcName)->GetSpritePositionX(),  FindBulletB(szSrcName)->GetSpritePositionY(), 1);
			m_pPortalB->SetDir(2);
			m_SoundPortal->PlaySoundA();
		}
		else if(FindBulletB(szSrcName)->GetSpritePositionX()  < fDoor2PosX){
			m_pPortalB->PortalInit(FindBulletB(szSrcName)->GetSpritePositionX(),  FindBulletB(szSrcName)->GetSpritePositionY(), 1);
			m_pPortalB->SetDir(0);
			m_SoundPortal->PlaySoundA();
		}
		FindBulletB(szSrcName)->DeleteSprite();
	}
	//========================================================================================
	if(strstr(szSrcName, "bulletA") != NULL && strstr(szTarName, "door3") != NULL ){
		m_pPortalA->SetSpriteRotation(0);
		if(FindBulletA(szSrcName)->GetSpritePositionX()  > fDoor3PosX){
			m_pPortalA->PortalInit(FindBulletA(szSrcName)->GetSpritePositionX(),  FindBulletA(szSrcName)->GetSpritePositionY(), 1);
			m_pPortalA->SetDir(2);
			m_SoundPortal->PlaySoundA();
		}
		else if(FindBulletA(szSrcName)->GetSpritePositionX()  < fDoor3PosX){
			m_pPortalA->PortalInit(FindBulletA(szSrcName)->GetSpritePositionX(),  FindBulletA(szSrcName)->GetSpritePositionY(), 1);
			m_pPortalA->SetDir(0);
			m_SoundPortal->PlaySoundA();
		}
		FindBulletA(szSrcName)->DeleteSprite();
	}
	if(strstr(szSrcName, "bulletB") != NULL && strstr(szTarName, "door3") != NULL  ){
		m_pPortalB->SetSpriteRotation(0);
		if(FindBulletB(szSrcName)->GetSpritePositionX()  > fDoor3PosX){
			m_pPortalB->PortalInit(FindBulletB(szSrcName)->GetSpritePositionX(),  FindBulletB(szSrcName)->GetSpritePositionY(), 1);
			m_pPortalB->SetDir(2);
			m_SoundPortal->PlaySoundA();
		}
		else if(FindBulletB(szSrcName)->GetSpritePositionX()  < fDoor3PosX){
			m_pPortalB->PortalInit(FindBulletB(szSrcName)->GetSpritePositionX(),  FindBulletB(szSrcName)->GetSpritePositionY(), 1);
			m_pPortalB->SetDir(0);
			m_SoundPortal->PlaySoundA();
		}
		FindBulletB(szSrcName)->DeleteSprite();
	}
	//========================================================================================
	if(strcmp(szSrcName, "testA") == 0 && strstr(szTarName, "portal") != NULL){
		if(strcmp(szTarName, "portalA") == 0){
			Transmission(m_pPortalB, m_pPlayerSpriteA);
		}
		if(strcmp(szTarName, "portalB") == 0){
			Transmission(m_pPortalA, m_pPlayerSpriteA);
		}
	}
	if(strcmp(szSrcName, "testB") == 0 && strstr(szTarName, "portal") != NULL){
		if(strcmp(szTarName, "portalA") == 0){
			Transmission(m_pPortalB, m_pPlayerSpriteB);
		}
		if(strcmp(szTarName, "portalB") == 0){
			Transmission(m_pPortalA, m_pPlayerSpriteB);
		}
	}
//预设传送门==================================================================================
//游戏地图上的预设传送门 分为正常传送门和不稳定传送门
//不稳定传送门只能传送角色A
	//预设传送门1=============================================================================
	if(strcmp(szSrcName, "testA") == 0 && strstr(szTarName, "preportal") != NULL){
		if(strstr(szTarName, "preportalA1") != NULL){
			Transmission(m_pPrePortalB1, m_pPlayerSpriteA);
		}
		if(strstr(szTarName, "preportalB1") != NULL){
			Transmission(m_pPrePortalA1, m_pPlayerSpriteA);
		}
	}									//预设传送门传送角色A
	if(strcmp(szSrcName, "testB") == 0 && strstr(szTarName, "preportal") != NULL){
		if(strstr(szTarName, "preportalA1") != NULL){
			Transmission(m_pPrePortalB1, m_pPlayerSpriteB);
		}
		if(strstr(szTarName, "preportalB1") != NULL){
			Transmission(m_pPrePortalA1, m_pPlayerSpriteB);
		}
	}									//预设传送门传送角色B
	//预设传送门2=============================================================================
	if(strcmp(szSrcName, "testA") == 0 && strstr(szTarName, "preportal") != NULL){
		
		if(strstr(szTarName, "preportalA2") != NULL){
			Transmission(m_pPrePortalB2, m_pPlayerSpriteA);
		}
		if(strstr(szTarName, "preportalB2") != NULL){
			Transmission(m_pPrePortalA2, m_pPlayerSpriteA);
		}
	}									//预设传送门传送角色A
	if(strcmp(szSrcName, "testB") == 0 && strstr(szTarName, "preportal") != NULL){
		if(strstr(szTarName, "preportalA2") != NULL){
			Transmission(m_pPrePortalB2, m_pPlayerSpriteB);
		}
		if(strstr(szTarName, "preportalB2") != NULL){
			Transmission(m_pPrePortalA2, m_pPlayerSpriteB);
		}
	}									//预设传送门传送角色B
//玩家触发机关================================================================================
//玩家通过传接触触发机关
//只能通过角色B触发
	if(strcmp(szSrcName, "testB") == 0 && strstr(szTarName, "trigger1") != NULL){
		m_pTrigger1->SetTriggerResult(1);
		m_pTrigger1->SetSpriteVisible(0);
		m_SoundOpenDoor->PlaySoundA();
		m_pTrigger1->DeleteSprite();
	}									//玩家B触碰机关
	if(strcmp(szSrcName, "testB") == 0 && strstr(szTarName, "trigger2") != NULL){
		m_pTrigger2->SetTriggerResult(1);
		m_pTrigger2->SetSpriteVisible(0);
		m_pJetSmoke->SetSpriteVisible(0);
		m_SoundOpenDoor->PlaySoundA();
		m_pTrigger2->DeleteSprite();
	}									//玩家B触碰机关					
//C型子弹功能=================================================================================
//C类型子弹由枪手发射
//可以被传送门传送
	if(strstr(szSrcName, "bulletC") != NULL && strstr(szTarName, "Block") != NULL  ){
		OnBulletHitC(szSrcName, szTarName);
	}
	if(strstr(szSrcName, "bulletC") != NULL && strstr(szTarName, "door") != NULL  ){
		OnBulletHitC(szSrcName, szTarName);
	}									//子弹触碰墙壁消失
	if(strstr(szSrcName, "bulletC") != NULL && strstr(szTarName, "portal") != NULL){
		if(strcmp(szTarName, "portalA") == 0){
			TransmissionBullet(m_pPortalB, FindBulletC(szSrcName));
		}
		if(strcmp(szTarName, "portalB") == 0){
			TransmissionBullet(m_pPortalA, FindBulletC(szSrcName));
		}
	}									//子弹被玩家传送门传送
	if(strstr(szSrcName, "bulletC") != NULL && strcmp(szTarName, "bullettrigger1") == 0){
		m_pBulletTrigger1->SetTriggerResult(1);
		m_pBulletTrigger1->SetSpriteVisible(0);
		m_SoundWarning->PlaySoundA();
		m_pBulletTrigger1->DeleteSprite();
	}									//子弹触碰机关
//人物与子弹的碰撞============================================================================
	if(strstr(szSrcName, "bulletC") != NULL && strstr(szTarName, "testA") != NULL){
		m_iIfAlive = 0;
		m_SoundManDead->PlaySoundA();
	}
	if(strstr(szSrcName, "bulletC") != NULL && strstr(szTarName, "testB") != NULL){
		m_iIfAlive = 0;
		m_SoundWomanDead->PlaySoundA();
	}
//人物与陷阱的碰撞============================================================================
	if(strcmp(szSrcName, "testA") ==0 && strstr(szTarName, "trap") != NULL){
		m_iIfAlive = 0;
		m_SoundWomanDead->PlaySoundA();
	}
	if(strcmp(szSrcName, "testB") ==0 && strstr(szTarName, "trap") != NULL){
		m_iIfAlive = 0;
		m_SoundManDead->PlaySoundA();
	}
//人物与门的碰撞==============================================================================
//门会组织角色闯过
//可由机关出发打开
	if(strstr(szSrcName, "test") != NULL && strstr(szTarName, "door1") != NULL){
		m_pPlayerSpriteA->SetSpriteLinearVelocityY(0);
		m_pPlayerSpriteB->SetSpriteLinearVelocityY(0);
		m_pPlayerSpriteA->SetJumpState(0);
		m_pPlayerSpriteB->SetJumpState(0);
	}
	else if(strstr(szSrcName, "test") != NULL && strstr(szTarName, "door") != NULL){
		m_pPlayerSpriteA->SetSpriteLinearVelocityX(0);
		m_pPlayerSpriteB->SetSpriteLinearVelocityX(0);
	}
//玩家与关卡出口碰撞==========================================================================
	if(strcmp(szSrcName, "testA") == 0 && strcmp(szTarName, "levelgate") == 0){
		m_iPlayerAState = 1;
	}
	if(strcmp(szSrcName, "testB") == 0 && strcmp(szTarName, "levelgate") == 0){
		m_iPlayerBState = 1;
	}
}
//============================================================================================
//
// 精灵与世界边界碰撞
// 参数 szName：碰撞到边界的精灵名字
// 参数 iColSide：碰撞到的边界 0 左边，1 右边，2 上边，3 下边
void DGameMain::OnSpriteColWorldLimit( const char *szName, const int iColSide )
{

}
//============================================================================================
void DGameMain::AddBulletA()
{	
	char* szName = CSystem::MakeSpriteName("bulletA",m_iBulletNum_1);	//创建子弹名字
	CBullet* tmpBullet = new CBullet(szName);							//创建临时变量存储子弹副本的信息
	tmpBullet->CloneSprite("bulletA");									//将子弹的信息复制到临时变量之中
	tmpBullet->SetSpriteCollisionSend(true);							//设置接收碰撞
	m_vBulletA.push_back(tmpBullet);
	tmpBullet->OnMove(m_pPlayerSpriteA->GetSpritePositionX(), m_pPlayerSpriteA->GetSpritePositionY(), m_fMousePosX, m_fMousePosY);
																		//调用OnMove() 设置子弹的初始位置 子弹的方向 子弹的速度
	m_iBulletNum_1++;													//子弹个数加1
}
void DGameMain::AddBulletB()
{	
	char* szName = CSystem::MakeSpriteName("bulletB",m_iBulletNum_2);	//创建子弹名字
	CBullet* tmpBullet = new CBullet(szName);							//创建临时变量存储子弹副本的信息
	tmpBullet->CloneSprite("bulletB");									//将子弹的信息复制到临时变量之中
	tmpBullet->SetSpriteCollisionSend(true);							//设置接收碰撞
	m_vBulletB.push_back(tmpBullet);
	tmpBullet->OnMove(m_pPlayerSpriteA->GetSpritePositionX(), m_pPlayerSpriteA->GetSpritePositionY(), m_fMousePosX, m_fMousePosY);
																		//调用OnMove() 设置子弹的初始位置 子弹的方向 子弹的速度
	m_iBulletNum_2++;													//子弹个数加1
}
void DGameMain::AddBulletC()
{	
	char* szName = CSystem::MakeSpriteName("bulletC",m_iBulletNum_3);	//创建子弹名字
	CBullet* tmpBullet = new CBullet(szName);							//创建临时变量存储子弹副本的信息
	tmpBullet->CloneSprite("bulletC");									//将子弹的信息复制到临时变量之中
	tmpBullet->SetSpriteCollisionSend(true);							//设置接收碰撞
	m_vBulletC.push_back(tmpBullet);
	tmpBullet->OnMove(m_pShooter1->GetSpritePositionX(), m_pShooter1->GetSpritePositionY(), m_pShooter1->GetSpritePositionX() - 1, m_pShooter1->GetSpritePositionY());
																		//调用OnMove() 设置子弹的初始位置 子弹的方向 子弹的速度
	m_iBulletNum_3++;													//子弹个数加1
}
//============================================================================================
CSprite* DGameMain::FindBulletA(const char* szName)
{
	for(int i = 0;i < m_vBulletA.size();i++){
		if(strcmp(szName, m_vBulletA[i]->GetName()) == 0){
			return m_vBulletA[i];
		}
	}
}
CSprite* DGameMain::FindBulletB(const char* szName)
{
	for(int i = 0;i < m_vBulletB.size();i++){
		if(strcmp(szName, m_vBulletB[i]->GetName()) == 0){
			return m_vBulletB[i];
		}
	}
}
CSprite* DGameMain::FindBulletC(const char* szName)
{
	for(int i = 0;i < m_vBulletC.size();i++){
		if(strcmp(szName, m_vBulletC[i]->GetName()) == 0){
			return m_vBulletC[i];
		}
	}
}
//============================================================================================
void DGameMain::OnBulletHitA(const char* szSrcName, const char*szTarName)
{
	m_SoundPortal->PlaySoundA();
	float fBulletPosX, fBulletPosY, fBlockPosX, fBlockPosY;
	fBulletPosX = FindBulletA(szSrcName)->GetSpritePositionX();
	fBulletPosY = FindBulletA(szSrcName)->GetSpritePositionY();
	fBlockPosX = m_pMap.FindMapSprite(szTarName)->GetSpritePositionX();
	fBlockPosY = m_pMap.FindMapSprite(szTarName)->GetSpritePositionY();
	m_pPortalA->SetPortal(fBulletPosX, fBulletPosY, fBlockPosX, fBlockPosY, szTarName);
	FindBulletA(szSrcName)->DeleteSprite();
}
void DGameMain::OnBulletHitB(const char* szSrcName, const char*szTarName)
{
	m_SoundPortal->PlaySoundA();
	float fBulletPosX, fBulletPosY, fBlockPosX, fBlockPosY;
	fBulletPosX = FindBulletB(szSrcName)->GetSpritePositionX();
	fBulletPosY = FindBulletB(szSrcName)->GetSpritePositionY();
	fBlockPosX = m_pMap.FindMapSprite(szTarName)->GetSpritePositionX();
	fBlockPosY = m_pMap.FindMapSprite(szTarName)->GetSpritePositionY();
	m_pPortalB->SetPortal(fBulletPosX, fBulletPosY, fBlockPosX, fBlockPosY, szTarName);
	FindBulletB(szSrcName)->DeleteSprite();
}
void DGameMain::OnBulletHitC(const char* szSrcName, const char*szTarName)
{
	FindBulletC(szSrcName)->DeleteSprite();
}
//============================================================================================
void DGameMain::Transmission(CPortal* pPortal, CPlayer* pPlayerSprite){
	float fPortalPosX, fPortalPosY;
	m_SoundTrans->PlaySoundA();
	fPortalPosX = pPortal->GetSpritePositionX();
	fPortalPosY = pPortal->GetSpritePositionY();
	switch(pPortal->GetDir()){
		case 0:
			pPlayerSprite->SetSpritePosition(fPortalPosX - 20, fPortalPosY);
			break;
		case 1:
			pPlayerSprite->SetSpritePosition(fPortalPosX, fPortalPosY - 25);
			pPlayerSprite->SetSpriteImpulseForcePolar(-90,500,0);
			break;
		case 2:
			pPlayerSprite->SetSpritePosition(fPortalPosX + 20, fPortalPosY);
			break;
		case 3:
			pPlayerSprite->SetSpritePosition(fPortalPosX, fPortalPosY + 25);
			pPlayerSprite->SetSpriteLinearVelocityY(0);
			break;
	}
}
void DGameMain::TransmissionBullet(CPortal* pPortal, CSprite* pBulletSprite){
	float fPortalPosX, fPortalPosY;
	fPortalPosX = pPortal->GetSpritePositionX();
	fPortalPosY = pPortal->GetSpritePositionY();
	switch(pPortal->GetDir()){
		case 0:
			pBulletSprite->SetSpritePosition(fPortalPosX - 20, fPortalPosY);
			pBulletSprite->SetSpriteLinearVelocity(-400, 0);
			break;
		case 1:
			pBulletSprite->SetSpritePosition(fPortalPosX, fPortalPosY - 25);
			pBulletSprite->SetSpriteLinearVelocity(0, -400);
			break;
		case 2:
			pBulletSprite->SetSpritePosition(fPortalPosX + 20, fPortalPosY);
			pBulletSprite->SetSpriteLinearVelocity(400, 0);
			break;
		case 3:
			pBulletSprite->SetSpritePosition(fPortalPosX, fPortalPosY + 25);
			pBulletSprite->SetSpriteLinearVelocity(0, 400);
			break;
	}
}
//============================================================================================
//===========================================================================
//
// 设置渐变块的渐变效果
// 参数 AlphaStart：初始渐变块透明度
// 参数 AlphaEnd：结束渐变块透明度
// 参数 Accuracy：变化精度
int DGameMain::ColorAlphaMaking(const double AlphaStart,const double AlphaEnd,const double Accuracy)
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