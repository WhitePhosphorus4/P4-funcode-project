/////////////////////////////////////////////////////////////////////////////////
//
//������
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonClass.h"
#include "LessonZ.h"
////////////////////////////////////////////////////////////////////////////////
//
//
CGameMain		g_GameMain;	

//============================================================================================
//
// ����ĳ�������Ϊ��GameMainLoop����Ϊ��ѭ��������������ÿ֡ˢ����Ļͼ��֮�󣬶��ᱻ����һ�Ρ�

//============================================================================================
//
// ���캯��
CGameMain::CGameMain()
{

	m_iGameState		=	0;
	m_iIfAlive			=	1;
	//========================================================================================
	m_pLevelGate1		=	new CSprite("levelgate1");
	m_pLevelGate2		=	new CSprite("levelgate2");
	//========================================================================================
	m_pGameStart		=	new CSprite("gamestart");
	m_pPlayerSpriteA	=	new CPlayerSpriteA("testA");
	m_pPlayerSpriteB	=	new CPLayerSpriteB("testB");
	m_pPortalA			=	new CPortal("portalA");
	m_pPortalB			=	new CPortal("portalB");
	//���־���================================================================================
	m_pShooter1			=	new CSprite("shooter1");
	m_pShooter2			=	new CSprite("shooter2");
	//Ԥ�贫���ž���==========================================================================
	m_pPrePortalA1		=	new CPortal("preportalA1");
	m_pPrePortalB1		=	new CPortal("preportalB1");
	m_pPrePortalA2		=	new CPortal("preportalA2");
	m_pPrePortalB2		=	new CPortal("preportalB2");
	m_pPrePortalA3		=	new CPortal("preportalA3");
	m_pPrePortalB3		=	new CPortal("preportalB3");
	m_pPrePortalA4		=	new CPortal("preportalA4");
	m_pPrePortalB4		=	new CPortal("preportalB4");
	m_pPrePortalA5		=	new	CPortal("preportalA5");
	m_pPrePortalB5		=	new	CPortal("preportalB5");
	//�ž���==================================================================================
	m_pDoor1			=	new CSprite("door1");
	m_pDoor2			=	new CSprite("door2");
	m_pDoor3			=	new CSprite("door3");
	//���徫��================================================================================
	m_pTrap1			=	new CSprite("trap1");
	m_pTrap2			=	new CSprite("trap2");
	m_pTrap3			=	new CSprite("trap3");
	//����������==============================================================================
	m_pTrigger1			=	new CTrigger("trigger1");
	m_pTrigger2			=	new CTrigger("trigger2");
	m_pTrigger3			=	new CTrigger("trigger3");
	m_pTrigger4			=	new CTrigger("trigger4");
	m_pTrigger5			=	new CTrigger("trigger5");
	m_pJetSmoke1		=	new CSprite("jetsmoke1");
	m_pJetSmoke2		=	new CSprite("jetsmoke2");
	m_pJetSmoke3		=	new CSprite("jetsmoke3");
	m_pJetSmoke4		=	new CSprite("jetsmoke4");

	m_pTrigger6			=	new CTrigger("trigger6");
	m_pTrigger7			=	new CTrigger("trigger7");
	m_pBulletTrigger1	=	new CTrigger("bullettrigger1");
	m_pTriggerBroken1	=	new	CSprite("bullettriggerbroken1");
	m_pBulletTrigger2	=	new CTrigger("bullettrigger2");
	//========================================================================================
	m_pTest1			=	new CPlayerSpriteA("testC1");
	m_pTest2			=	new CPlayerSpriteA("testC2");
	//========================================================================================
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
	m_SoundWarning		=	new CSound("warning.wav", 0, 1);
	m_SoundTrans		=	new CSound("trans.wav", 0, 1);
	m_BgmD				=	new CSound("c.wav", 1, 1);

	m_pBlack				=	new CSprite("iBlack1");
}
//============================================================================================
//
// ��������
CGameMain::~CGameMain()
{
}

//============================================================================================
//
// ��Ϸ��ѭ�����˺���������ͣ�ĵ��ã�����ÿˢ��һ����Ļ���˺�����������һ��
// ���Դ�����Ϸ�Ŀ�ʼ�������С������ȸ���״̬. 
// ��������fDeltaTime : �ϴε��ñ��������˴ε��ñ�������ʱ��������λ����
void CGameMain::GameMainLoop( float	fDeltaTime )
{
	switch( GetGameState() )
	{
		// ��ʼ����Ϸ�������һ���������
	case 1:
		{
			GameInit();
			SetGameState(2); // ��ʼ��֮�󣬽���Ϸ״̬����Ϊ������
		}
		break;

		// ��Ϸ�����У����������Ϸ�߼�
	case 2:
		{
			// TODO �޸Ĵ˴���Ϸѭ�������������ȷ��Ϸ�߼�
			if( true )
			{
				GameRun( fDeltaTime );
			}
			else // ��Ϸ������������Ϸ���㺯����������Ϸ״̬�޸�Ϊ����״̬
			{				
				SetGameState(0);
				GameEnd();
			}
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
		// ��Ϸ����/�ȴ����ո����ʼ
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
// ÿ�ֿ�ʼǰ���г�ʼ���������һ���������
void CGameMain::GameInit()
{
	ColorAlpha				=	255;
	m_AlpahState			=	0;
	//========================================================================================
	m_fTime = 0;
	m_iIfAlive = 1;
	m_iPlayerAState = 0;
	m_iPlayerBState = 0;
	//========================================================================================
	m_pPlayerSpriteA->PlayerSpriteInit(1);
	m_pPlayerSpriteB->PlayerSpriteInit(1);
	m_pTest1->PlayerSpriteInit(1);
	m_pTest2->PlayerSpriteInit(1);
	//========================================================================================
	m_pMap.SetMapInfo(14, 12);
	//========================================================================================
	m_pTrigger1->SetTriggerResult(0);
	m_pTrigger2->SetTriggerResult(0);
	m_pTrigger3->SetTriggerResult(0);
	m_pTrigger4->SetTriggerResult(0);
	m_pTrigger5->SetTriggerResult(0);
	m_pTrigger6->SetTriggerResult(0);
	m_pTrigger7->SetTriggerResult(0);
	m_pBulletTrigger1->SetTriggerResult(0);
	m_pBulletTrigger2->SetTriggerResult(0);
	//========================================================================================
	m_iBulletNum_1 = 0;
	m_iBulletNum_2 = 0;
	m_iBulletNum_3 = 0;
	m_iBulletNum_4 = 0;
	//========================================================================================
	m_pPortalA->PortalInit(40, 600, 1);
	m_pPortalB->PortalInit(-40, 600, 1);
	m_pPrePortalA1->SetDir(0);
	m_pPrePortalB1->SetDir(2);
	m_pPrePortalA2->SetDir(2);
	m_pPrePortalB2->SetDir(0);
	m_pPrePortalA3->SetDir(2);
	m_pPrePortalB3->SetDir(3);
	m_pPrePortalA4->SetDir(0);
	m_pPrePortalB4->SetDir(3);
	m_pPrePortalA5->SetDir(2);
	m_pPrePortalB5->SetDir(0);
	//========================================================================================
	fDoor1PosX = m_pDoor1->GetSpritePositionX();
	fDoor1PosY = m_pDoor1->GetSpritePositionY();
	fDoor2PosX = m_pDoor2->GetSpritePositionX();
	fDoor2PosY = m_pDoor2->GetSpritePositionY();
	m_fJetSmoke3PosX = m_pJetSmoke3->GetSpritePositionX();
	m_fJetSmoke3PosY = m_pJetSmoke3->GetSpritePositionY();
	m_fJetSmoke4PosX = m_pJetSmoke4->GetSpritePositionX();
	m_fJetSmoke4PosY = m_pJetSmoke4->GetSpritePositionY();
	fBulletTrigger1PosX = m_pBulletTrigger1->GetSpritePositionX();
	fBulletTrigger1PosY = m_pBulletTrigger1->GetSpritePositionY();
	fDoor3PosX = m_pDoor3->GetSpritePositionX();
	fDoor3PosY = m_pDoor3->GetSpritePositionY();
	m_SoundMenu->StopAllSound();
	m_BgmD->PlaySoundA();
	m_iRunningFlag1 = 0;
	m_iRunningFlag2 = 0;
	m_pBlack->SetSpritePosition(0,0);
}
//============================================================================================
//
// ÿ����Ϸ������
void CGameMain::GameRun( float fDeltaTime )
{
	//��������Ч��
	ColorAlphaMaking(255,0,1);

	m_fTime +=	fDeltaTime;
	if(m_fTime > 0.25){
		AddBulletC();
		AddBulletD();
		m_fTime = 0;
	}
	//������������============================================================================
	if(m_pTrigger1->GetTriggerResult() == 1){
		m_pDoor1->SpriteMoveTo(fDoor1PosX, fDoor1PosY + 150, 50, 1);

	}
	if(m_pTrigger2->GetTriggerResult() == 1){
		m_pDoor2->SpriteMoveTo(fDoor2PosX - 240, fDoor2PosY, 50, 1);
		m_pBulletTrigger1->SpriteMoveTo(fBulletTrigger1PosX - 240, fBulletTrigger1PosY, 50, 1);
		m_pTriggerBroken1->SpriteMoveTo(fBulletTrigger1PosX - 240, fBulletTrigger1PosY, 50, 1);
		m_pJetSmoke3->SpriteMoveTo(m_fJetSmoke3PosX - 240, m_fJetSmoke3PosY, 50, 1);
		m_pJetSmoke4->SpriteMoveTo(m_fJetSmoke4PosX - 240, m_fJetSmoke4PosY, 50, 1);
	}
	if(m_pTrigger3->GetTriggerResult() == 1){
		m_pPrePortalA4->SetSpritePosition(210, -205);
		m_pPrePortalB4->SetSpritePosition(-425, 240);
	}
	//��Ҵ�������============================================================================
	if(m_pTrigger4->GetTriggerResult() == 1){
		m_pPrePortalA1->SetSpritePosition(-210, -95);
		m_pPrePortalB1->SetSpritePosition(-600, 175);
	}
	if(m_pTrigger5->GetTriggerResult() == 1){
		m_pPrePortalA2->SetSpritePosition(270, 50);
		m_pPrePortalB2->SetSpritePosition(-385, 170);
	}
	if(m_pTrigger6->GetTriggerResult() == 1){
		m_pPrePortalA3->SetSpritePosition(270, 170);
		m_pPrePortalB3->SetSpritePosition(-285, 125);
	}
	if(m_pTrigger7->GetTriggerResult() == 1){
		m_pDoor1->SpriteMoveTo(fDoor3PosX, fDoor3PosY, 40, 1);
	}
	//�ӵ���������===========================================================================
	if(m_pBulletTrigger1->GetTriggerResult() == 1){
		m_pDoor3->SpriteMoveTo(fDoor3PosX, fDoor3PosY - 280, 50, 1);
	}
	if(m_pBulletTrigger2->GetTriggerResult() == 1){
		m_pPrePortalA5->SetSpritePosition(-325, 170);
		m_pPrePortalB5->SetSpritePosition(-380, 45);
	}
	//�������============================================================================
	if(m_iIfAlive == 0){
		m_DeadPhoto->SpriteMoveTo(0,0,1500,1);
		m_pPlayerSpriteA->DeleteSprite();
		m_pPlayerSpriteB->DeleteSprite();
		SetGameState(3);
	}
	//���ͨ����Ϸ============================================================================
	switch(PatternState)
	{
		//����ģʽ�й�
		case 1:
			if(m_iPlayerAState == 1 && m_iPlayerBState == 1){
				m_ConPhoto1->SpriteMoveTo(0,0,1500,1);
				m_pPlayerSpriteA->DeleteSprite();
				m_pPlayerSpriteB->DeleteSprite();
				SetGameState(4);
			}
			break;
		//����ģʽ�й�
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
// ������Ϸ����
void CGameMain::GameEnd()
{
}
//============================================================================================
//
// ����ƶ�
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void CGameMain::OnMouseMove( const float fMouseX, const float fMouseY )
{
	m_fMousePosX = fMouseX;
	m_fMousePosY = fMouseY;
}
//============================================================================================
//
// �����
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void CGameMain::OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
	if(m_iGameState == 2){
		if(iMouseType == 0){
			AddBulletA();

		}
		if(iMouseType == 1){
			AddBulletB();
		}
	}
}
//============================================================================================
//
// ��굯��
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void CGameMain::OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
	
}
//============================================================================================
//
// ���̰���
// ���� iKey�������µļ���ֵ�� enum KeyCodes �궨��
// ���� iAltPress, iShiftPress��iCtrlPress�������ϵĹ��ܼ�Alt��Ctrl��Shift��ǰ�Ƿ�Ҳ���ڰ���״̬(0δ���£�1����)
void CGameMain::OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{	
	//================================================================
	//��ͣ����ѡ������� ����1��ո񣺼�����ǰ��Ϸ������2�����¿�ʼ������3�����ؿ�ʼ�˵�
	if(GetGameState() == 3){
		if( iKey == KEY_1 || iKey == KEY_SPACE ){
			m_PausePhoto->SpriteMoveTo(0,-890,1700,1);
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
		//ESC������Ϸ��ͣ����====================================================================================
		if(iKey == KEY_ESCAPE){
			m_PausePhoto->SpriteMoveTo(0,0,1500,1);
			SetGameState(3);
			m_SoundMenu->PlaySoundA();
		}
	}
	//ͨ�غ����������ѡ��==========================================
	//����ģʽ
	if(GetGameState() == 4 && PatternState == 1){
		if( iKey == KEY_1 || iKey == KEY_SPACE ){
			m_ConPhoto1->SpriteMoveTo(0,-1220,1700,1);
			LevelState = 3;
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
	//����ģʽ
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
// ���̵���
// ���� iKey������ļ���ֵ�� enum KeyCodes �궨��
void CGameMain::OnKeyUp( const int iKey )
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
// �����뾫����ײ
// ���� szSrcName��������ײ�ľ�������
// ���� szTarName������ײ�ľ�������
void CGameMain::OnSpriteColSprite( const char *szSrcName, const char *szTarName )
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
		m_pPortalA->SetSpriteRotation(0);
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
		m_pPortalB->SetSpriteRotation(0);
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
		m_pPortalA->SetSpriteRotation(90);
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
		m_pPortalB->SetSpriteRotation(90);
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
//��������====================================================================================
//������ش�����
//CPlayer����
	//����1����===============================================================================
	if(strstr(szSrcName, "testC1") != NULL && strstr(szTarName, "Block_L") != NULL){
		m_pTest1->SetSpriteLinearVelocityY(0);
	}									//����������ͼ
	if(strstr(szSrcName, "testC1") != NULL && strstr(szTarName, "portal") != NULL){
		if(strcmp(szTarName, "portalA") == 0){
			Transmission(m_pPortalB, m_pTest1);
		}
		if(strcmp(szTarName, "portalB") == 0){
			Transmission(m_pPortalA, m_pTest1);
		}
	}									//�������Ŵ���
	if(strcmp(szSrcName, "testC1") == 0 && strcmp(szTarName, "trigger1") == 0){
		m_pTrigger1->SetTriggerResult(1);
		m_SoundOpenDoor->PlaySoundA();
		m_pTrigger1->DeleteSprite();
	}									//������������1
	if(strcmp(szSrcName, "testC1") == 0 && strcmp(szTarName, "trigger3") == 0){
		m_pTrigger3->SetTriggerResult(1);
		m_SoundTrig->PlaySoundA();
		m_pTrigger3->DeleteSprite();
	}									//������������3
	if(strstr(szSrcName, "testC1") != NULL && strstr(szTarName, "door2") != NULL  ){
		m_pTest1->SetSpriteLinearVelocityY(0);
	}
	//����2����===============================================================================
	if(strstr(szSrcName, "testC2") != NULL && strstr(szTarName, "Block_L") != NULL){
		m_pTest2->SetSpriteLinearVelocityY(0);
	}									//����������ͼ
	if(strstr(szSrcName, "testC2") != NULL && strstr(szTarName, "portal") != NULL){
		if(strcmp(szTarName, "portalA") == 0){
			Transmission(m_pPortalB, m_pTest2);
		}
		if(strcmp(szTarName, "portalB") == 0){
			Transmission(m_pPortalA, m_pTest2);
		}
	}									//�������Ŵ���
	if(strstr(szSrcName, "testC2") != NULL && strstr(szTarName, "trigger") != NULL){
		m_pTrigger2->SetTriggerResult(1);
		m_SoundOpenDoor->PlaySoundA();
		m_pTrigger2->DeleteSprite();
	}									//������������
//Ԥ�贫����==================================================================================
//��Ϸ��ͼ�ϵ�Ԥ�贫���� ��Ϊ���������źͲ��ȶ�������
//���ȶ�������ֻ�ܴ��ͽ�ɫA
	//Ԥ�贫����1=============================================================================
	if(strcmp(szSrcName, "testA") == 0 && strstr(szTarName, "preportal") != NULL){
		if(strstr(szTarName, "preportalA1") != NULL){
			Transmission(m_pPrePortalB1, m_pPlayerSpriteA);
		}
		if(strstr(szTarName, "preportalB1") != NULL){
			Transmission(m_pPrePortalA1, m_pPlayerSpriteA);
		}
	}									//Ԥ�贫���Ŵ��ͽ�ɫA
	if(strcmp(szSrcName, "testB") == 0 && strstr(szTarName, "preportal") != NULL){
		if(strstr(szTarName, "preportalA1") != NULL){
			Transmission(m_pPrePortalB1, m_pPlayerSpriteB);
		}
		if(strstr(szTarName, "preportalB1") != NULL){
			Transmission(m_pPrePortalA1, m_pPlayerSpriteB);
		}
	}									//Ԥ�贫���Ŵ��ͽ�ɫB
	//Ԥ�贫����2=============================================================================
	if(strcmp(szSrcName, "testA") == 0 && strstr(szTarName, "preportal") != NULL){
		
		if(strstr(szTarName, "preportalA2") != NULL){
			Transmission(m_pPrePortalB2, m_pPlayerSpriteA);
		}
		if(strstr(szTarName, "preportalB2") != NULL){
			Transmission(m_pPrePortalA2, m_pPlayerSpriteA);
		}
	}									//Ԥ�贫���Ŵ��ͽ�ɫA
	if(strcmp(szSrcName, "testB") == 0 && strstr(szTarName, "preportal") != NULL){
		if(strstr(szTarName, "preportalA2") != NULL){
			Transmission(m_pPrePortalB2, m_pPlayerSpriteB);
		}
		if(strstr(szTarName, "preportalB2") != NULL){
			Transmission(m_pPrePortalA2, m_pPlayerSpriteB);
		}
	}									//Ԥ�贫���Ŵ��ͽ�ɫB
	//Ԥ�贫����3=============================================================================
	if(strcmp(szSrcName, "testA") == 0 && strstr(szTarName, "preportal") != NULL){
		
		if(strstr(szTarName, "preportalA3") != NULL){
			Transmission(m_pPrePortalB3, m_pPlayerSpriteA);
		}
		if(strstr(szTarName, "preportalB3") != NULL){
			Transmission(m_pPrePortalA3, m_pPlayerSpriteA);
		}
	}									//Ԥ�贫���Ŵ��ͽ�ɫA
	if(strcmp(szSrcName, "testB") == 0 && strstr(szTarName, "preportal") != NULL){
		if(strstr(szTarName, "preportalA3") != NULL){
			Transmission(m_pPrePortalB3, m_pPlayerSpriteB);
		}
		if(strstr(szTarName, "preportalB3") != NULL){
			Transmission(m_pPrePortalA3, m_pPlayerSpriteB);
		}
	}									//Ԥ�贫���Ŵ��ͽ�ɫB
	//Ԥ�贫����4=============================================================================
	if(strcmp(szSrcName, "testA") == 0 && strstr(szTarName, "preportal") != NULL){
		
		if(strstr(szTarName, "preportalA4") != NULL){
			Transmission(m_pPrePortalB4, m_pPlayerSpriteA);
		}
		if(strstr(szTarName, "preportalB4") != NULL){
			Transmission(m_pPrePortalA4, m_pPlayerSpriteA);
		}
	}									//Ԥ�贫���Ŵ��ͽ�ɫA
	if(strcmp(szSrcName, "testB") == 0 && strstr(szTarName, "preportal") != NULL){
		if(strstr(szTarName, "preportalA4") != NULL){
			Transmission(m_pPrePortalB4, m_pPlayerSpriteB);
		}
		if(strstr(szTarName, "preportalB4") != NULL){
			Transmission(m_pPrePortalA4, m_pPlayerSpriteB);
		}
	}									//Ԥ�贫���Ŵ��ͽ�ɫB
	//Ԥ�贫����5=============================================================================
	if(strcmp(szSrcName, "testA") == 0 && strstr(szTarName, "preportal") != NULL){
		
		if(strstr(szTarName, "preportalA5") != NULL){
			Transmission(m_pPrePortalB5, m_pPlayerSpriteA);
		}
		if(strstr(szTarName, "preportalB5") != NULL){
			Transmission(m_pPrePortalA5, m_pPlayerSpriteA);
		}
	}									//Ԥ�贫���Ŵ��ͽ�ɫA
	if(strcmp(szSrcName, "testB") == 0 && strstr(szTarName, "preportal") != NULL){
		if(strstr(szTarName, "preportalA5") != NULL){
			Transmission(m_pPrePortalB5, m_pPlayerSpriteB);
		}
		if(strstr(szTarName, "preportalB5") != NULL){
			Transmission(m_pPrePortalA5, m_pPlayerSpriteB);
		}
	}									//Ԥ�贫���Ŵ��ͽ�ɫB
//��Ҵ�������================================================================================
//���ͨ�����Ӵ���������
//ֻ��ͨ����ɫB����
	if(strcmp(szSrcName, "testB") == 0 && strstr(szTarName, "trigger4") != NULL){
		m_pTrigger4->SetTriggerResult(1);
		m_pTrigger4->SetSpriteVisible(0);
		m_SoundTrig->PlaySoundA();
		m_pTrigger4->DeleteSprite();
	}									//���B��������
	if(strcmp(szSrcName, "testB") == 0 && strstr(szTarName, "trigger5") != NULL){
		m_pTrigger5->SetTriggerResult(1);
		m_pTrigger5->SetSpriteVisible(0);
		m_pJetSmoke1->SetSpriteVisible(0);
		m_pJetSmoke2->SetSpriteVisible(0);
		m_SoundTrig->PlaySoundA();
		m_pTrigger5->DeleteSprite();
	}									//���B��������
	if(strcmp(szSrcName, "testB") == 0 && strstr(szTarName, "trigger6") != NULL){
		m_pTrigger6->SetTriggerResult(1);
		m_pTrigger6->SetSpriteVisible(0);
		m_SoundTrig->PlaySoundA();
		m_pTrigger6->DeleteSprite();
	}									//���B��������
	if(strcmp(szSrcName, "testB") == 0 && strstr(szTarName, "trigger7") != NULL){
		m_pTrigger7->SetTriggerResult(1);
		m_pTrigger7->SetSpriteVisible(0);
		m_SoundTrig->PlaySoundA();
		m_pTrigger7->DeleteSprite();
	}									//���B��������
//C���ӵ�����=================================================================================
//C�����ӵ���ǹ�ַ���
//���Ա������Ŵ���
	if(strstr(szSrcName, "bulletC") != NULL && strstr(szTarName, "Block") != NULL  ){
		OnBulletHitC(szSrcName, szTarName);
	}
	if(strstr(szSrcName, "bulletC") != NULL && strstr(szTarName, "door") != NULL  ){
		OnBulletHitC(szSrcName, szTarName);
	}									//�ӵ�����ǽ����ʧ
	if(strstr(szSrcName, "bulletC") != NULL && strstr(szTarName, "portal") != NULL){
		if(strcmp(szTarName, "portalA") == 0){
			TransmissionBullet(m_pPortalB, FindBulletC(szSrcName));
		}
		if(strcmp(szTarName, "portalB") == 0){
			TransmissionBullet(m_pPortalA, FindBulletC(szSrcName));
		}
	}									//�ӵ�����Ҵ����Ŵ���
	if(strstr(szSrcName, "bulletC") != NULL && strcmp(szTarName, "bullettrigger1") == 0){
		m_pBulletTrigger1->SetTriggerResult(1);
		m_pBulletTrigger1->SetSpriteVisible(0);
		m_SoundWarning->PlaySoundA();
		m_pBulletTrigger1->DeleteSprite();
	}									//�ӵ���������
//D���ӵ�����=================================================================================
//D�����ӵ���ǹ�ַ���
//���Ա������Ŵ���
	if(strstr(szSrcName, "bulletD") != NULL && strstr(szTarName, "Block") != NULL  ){
		OnBulletHitD(szSrcName, szTarName);
	}									//�ӵ�����ǽ����ʧ
	if(strstr(szSrcName, "bulletD") != NULL && strstr(szTarName, "portal") != NULL){
		if(strcmp(szTarName, "portalA") == 0){
			TransmissionBullet(m_pPortalB, FindBulletD(szSrcName));
		}
		if(strcmp(szTarName, "portalB") == 0){
			TransmissionBullet(m_pPortalA, FindBulletD(szSrcName));
		}
	}									//�ӵ�����Ҵ����Ŵ���
	if(strstr(szSrcName, "bulletD") != NULL && strstr(szTarName, "portal") != NULL){
		if(strcmp(szTarName, "preportalA1") == 0){
			TransmissionBullet(m_pPrePortalB1, FindBulletD(szSrcName));
		}
		if(strcmp(szTarName, "preportalB1") == 0){
			TransmissionBullet(m_pPrePortalA1, FindBulletD(szSrcName));
		}
	}									//�ӵ���Ԥ�贫����1����
	if(strstr(szSrcName, "bulletD") != NULL && strstr(szTarName, "portal") != NULL){
		if(strcmp(szTarName, "preportalA2") == 0){
			TransmissionBullet(m_pPrePortalB2, FindBulletD(szSrcName));
		}
		if(strcmp(szTarName, "preportalB2") == 0){
			TransmissionBullet(m_pPrePortalA2, FindBulletD(szSrcName));
		}
	}									//�ӵ���Ԥ�贫����2����
	if(strstr(szSrcName, "bulletD") != NULL && strcmp(szTarName, "bullettrigger2") == 0){
		m_pBulletTrigger2->SetTriggerResult(1);
		m_pBulletTrigger2->SetSpriteVisible(0);
		m_SoundWarning->PlaySoundA();
		m_pBulletTrigger2->DeleteSprite();
	}									//�ӵ���������
//�������������ײ============================================================================
	if(strcmp(szSrcName, "testA") ==0 && strstr(szTarName, "trap") != NULL){
		m_iIfAlive = 0;
		m_SoundWomanDead->PlaySoundA();
	}
	if(strcmp(szSrcName, "testB") ==0 && strstr(szTarName, "trap") != NULL){
		m_iIfAlive = 0;
		m_SoundManDead->PlaySoundA();
	}
//�������ӵ�����ײ============================================================================
	if(strstr(szSrcName, "bulletC") != NULL && strstr(szTarName, "testA") != NULL){
		m_iIfAlive = 0;
		m_SoundManDead->PlaySoundA();
	}
	if(strstr(szSrcName, "bulletC") != NULL && strstr(szTarName, "testB") != NULL){
		m_iIfAlive = 0;
		m_SoundWomanDead->PlaySoundA();
	}
	if(strstr(szSrcName, "bulletD") != NULL && strstr(szTarName, "testA") != NULL){
		m_iIfAlive = 0;
		m_SoundManDead->PlaySoundA();
	}
	if(strstr(szSrcName, "bulletD") != NULL && strstr(szTarName, "testB") != NULL){
		m_iIfAlive = 0;
		m_SoundWomanDead->PlaySoundA();
	}
//�������ŵ���ײ==============================================================================
//�Ż���֯��ɫ����
//���ɻ��س�����
	if(strstr(szSrcName, "test") != NULL && strstr(szTarName, "door2") != NULL){
		m_pPlayerSpriteA->SetSpriteLinearVelocityY(0);
		m_pPlayerSpriteB->SetSpriteLinearVelocityY(0);
		m_pPlayerSpriteA->SetJumpState(0);
		m_pPlayerSpriteB->SetJumpState(0);
	}
	else if(strstr(szSrcName, "test") != NULL && strstr(szTarName, "door") != NULL){
		m_pPlayerSpriteA->SetSpriteLinearVelocityX(0);
		m_pPlayerSpriteB->SetSpriteLinearVelocityX(0);
	}
//�����ؿ�������ײ==========================================================================
	if(strcmp(szSrcName, "testA") == 0 && strcmp(szTarName, "levelgate1") == 0){
		m_iPlayerAState = 1;
	}
	if(strcmp(szSrcName, "testB") == 0 && strcmp(szTarName, "levelgate2") == 0){
		m_iPlayerBState = 1;
	}
}
//============================================================================================
//
// ����������߽���ײ
// ���� szName����ײ���߽�ľ�������
// ���� iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
void CGameMain::OnSpriteColWorldLimit( const char *szName, const int iColSide )
{

}
//============================================================================================
void CGameMain::AddBulletA()
{	
	m_SoundFire->PlaySoundA();
	char* szName = CSystem::MakeSpriteName("bulletA",m_iBulletNum_1);	//�����ӵ�����
	CBullet* tmpBullet = new CBullet(szName);							//������ʱ�����洢�ӵ���������Ϣ
	tmpBullet->CloneSprite("bulletA");									//���ӵ�����Ϣ���Ƶ���ʱ����֮��
	tmpBullet->SetSpriteCollisionSend(true);							//���ý�����ײ
	m_vBulletA.push_back(tmpBullet);
	tmpBullet->OnMove(m_pPlayerSpriteA->GetSpritePositionX(), m_pPlayerSpriteA->GetSpritePositionY(), m_fMousePosX, m_fMousePosY);
																		//����OnMove() �����ӵ��ĳ�ʼλ�� �ӵ��ķ��� �ӵ����ٶ�
	m_iBulletNum_1++;													//�ӵ�������1
}
void CGameMain::AddBulletB()
{	
	m_SoundFire->PlaySoundA();
	char* szName = CSystem::MakeSpriteName("bulletB",m_iBulletNum_2);	//�����ӵ�����
	CBullet* tmpBullet = new CBullet(szName);							//������ʱ�����洢�ӵ���������Ϣ
	tmpBullet->CloneSprite("bulletB");									//���ӵ�����Ϣ���Ƶ���ʱ����֮��
	tmpBullet->SetSpriteCollisionSend(true);							//���ý�����ײ
	m_vBulletB.push_back(tmpBullet);
	tmpBullet->OnMove(m_pPlayerSpriteA->GetSpritePositionX(), m_pPlayerSpriteA->GetSpritePositionY(), m_fMousePosX, m_fMousePosY);
																		//����OnMove() �����ӵ��ĳ�ʼλ�� �ӵ��ķ��� �ӵ����ٶ�
	m_iBulletNum_2++;													//�ӵ�������1
}
void CGameMain::AddBulletC()
{	
	char* szName = CSystem::MakeSpriteName("bulletC",m_iBulletNum_3);	//�����ӵ�����
	CBullet* tmpBullet = new CBullet(szName);							//������ʱ�����洢�ӵ���������Ϣ
	tmpBullet->CloneSprite("bulletC");									//���ӵ�����Ϣ���Ƶ���ʱ����֮��
	tmpBullet->SetSpriteCollisionSend(true);							//���ý�����ײ
	m_vBulletC.push_back(tmpBullet);
	tmpBullet->OnMove(m_pShooter1->GetSpritePositionX(), m_pShooter1->GetSpritePositionY(), m_pShooter1->GetSpritePositionX(), m_pShooter1->GetSpritePositionY() - 1);
																		//����OnMove() �����ӵ��ĳ�ʼλ�� �ӵ��ķ��� �ӵ����ٶ�
	m_iBulletNum_3++;													//�ӵ�������1
}
void CGameMain::AddBulletD()
{	
	char* szName = CSystem::MakeSpriteName("bulletD",m_iBulletNum_4);	//�����ӵ�����
	CBullet* tmpBullet = new CBullet(szName);							//������ʱ�����洢�ӵ���������Ϣ
	tmpBullet->CloneSprite("bulletD");									//���ӵ�����Ϣ���Ƶ���ʱ����֮��
	tmpBullet->SetSpriteCollisionSend(true);							//���ý�����ײ
	m_vBulletD.push_back(tmpBullet);
	tmpBullet->OnMove(m_pShooter2->GetSpritePositionX(), m_pShooter2->GetSpritePositionY(), m_pShooter2->GetSpritePositionX() + 1, m_pShooter2->GetSpritePositionY());
																		//����OnMove() �����ӵ��ĳ�ʼλ�� �ӵ��ķ��� �ӵ����ٶ�
	m_iBulletNum_4++;													//�ӵ�������1
}
//============================================================================================
CSprite* CGameMain::FindBulletA(const char* szName)
{
	for(int i = 0;i < m_vBulletA.size();i++){
		if(strcmp(szName, m_vBulletA[i]->GetName()) == 0){
			return m_vBulletA[i];
		}
	}
}
CSprite* CGameMain::FindBulletB(const char* szName)
{
	for(int i = 0;i < m_vBulletB.size();i++){
		if(strcmp(szName, m_vBulletB[i]->GetName()) == 0){
			return m_vBulletB[i];
		}
	}
}
CSprite* CGameMain::FindBulletC(const char* szName)
{
	for(int i = 0;i < m_vBulletC.size();i++){
		if(strcmp(szName, m_vBulletC[i]->GetName()) == 0){
			return m_vBulletC[i];
		}
	}
}
CSprite* CGameMain::FindBulletD(const char* szName)
{
	for(int i = 0;i < m_vBulletD.size();i++){
		if(strcmp(szName, m_vBulletD[i]->GetName()) == 0){
			return m_vBulletD[i];
		}
	}
}
//============================================================================================
void CGameMain::OnBulletHitA(const char* szSrcName, const char*szTarName)
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
void CGameMain::OnBulletHitB(const char* szSrcName, const char*szTarName)
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
void CGameMain::OnBulletHitC(const char* szSrcName, const char*szTarName)
{
	FindBulletC(szSrcName)->DeleteSprite();
}
void CGameMain::OnBulletHitD(const char* szSrcName, const char*szTarName)
{
	FindBulletD(szSrcName)->DeleteSprite();
}
//============================================================================================
void CGameMain::Transmission(CPortal* pPortal, CPlayer* pPlayerSprite){
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
void CGameMain::TransmissionBullet(CPortal* pPortal, CSprite* pBulletSprite){
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
// ���ý����Ľ���Ч��
// ���� AlphaStart����ʼ�����͸����
// ���� AlphaEnd�����������͸����
// ���� Accuracy���仯����
int CGameMain::ColorAlphaMaking(const double AlphaStart,const double AlphaEnd,const double Accuracy)
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