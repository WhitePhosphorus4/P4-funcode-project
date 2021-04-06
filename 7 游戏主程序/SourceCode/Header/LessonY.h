/////////////////////////////////////////////////////////////////////////////////
//
//������
//
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef _LESSON_Y_H_
#define _LESSON_Y_H_
//
#include <Windows.h>
#include <PlayerSpriteA.h>
#include <PlayerSpriteB.h>
#include <Bullet.h>
#include <Portal.h>
#include <AdventureMap.h>
#include <Trigger.h>
#include"vector"
using namespace std;
/////////////////////////////////////////////////////////////////////////////////
//
// ��Ϸ�ܹ��ࡣ��������Ϸ��ѭ������Ϸ��ʼ���������ȹ���
class	DGameMain
{
private:
	int				m_iGameState;			// ��Ϸ״̬��0���������ߵȴ���ʼ��1����ʼ����2����Ϸ������
	int				m_iIfAlive;
	float			m_fTime;
	CSprite*		m_pGameStart;
	CAdventureMap	m_pMap;
	CPlayerSpriteA*	m_pPlayerSpriteA;
	CPLayerSpriteB*	m_pPlayerSpriteB;

	CSprite*		m_pShooter1;
	CSprite*		m_pShooter2;
	
	float			m_fMousePosX;
	float			m_fMousePosY;

	vector<CBullet*>m_vBulletA;
	vector<CBullet*>m_vBulletB;
	vector<CBullet*>m_vBulletC;

	int				m_iBulletNum_1;
	int				m_iBulletNum_2;
	int				m_iBulletNum_3;

	CPortal*		m_pPortalA;
	CPortal*		m_pPortalB;

	CPortal*		m_pPrePortalA1;
	CPortal*		m_pPrePortalB1;
	CPortal*		m_pPrePortalA2;
	CPortal*		m_pPrePortalB2;

	CSprite*		m_pDoor1;
	float			fDoor1PosX;
	float			fDoor1PosY;
	CSprite*		m_pDoor2;
	float			fDoor2PosX;
	float			fDoor2PosY;
	CSprite*		m_pDoor3;
	float			fDoor3PosX;
	float			fDoor3PosY;

	CTrigger*		m_pTrigger1;
	CTrigger*		m_pTrigger2;
	CSprite*		m_pJetSmoke;
	CTrigger*		m_pBulletTrigger1;

	CSprite*		m_pTrap1;
	CSprite*		m_pTrap2;
	CSprite*		m_pTrap3;
	CSprite*		m_pTrap4;
	CSprite*		m_pTrap5;
	CSprite*		m_pTrap6;

	CSprite*		m_pLevelGate;
	int				m_iPlayerAState;
	int				m_iPlayerBState;

	CSprite*        m_PausePhoto;
	CSprite*		m_DeadPhoto;
	CSprite*		m_ConPhoto1;
	CSprite*		m_ConPhoto2;

	CSound*         m_SoundMenu;
	CSound*         m_SoundRunning1;
	int				m_iRunningFlag1;
	CSound*         m_SoundRunning2;
	int				m_iRunningFlag2;
	CSound*         m_SoundFire;
	CSound*         m_SoundPortal;
	CSound*         m_SoundOpenDoor;
	CSound*         m_Soundtaping;
	CSound*         m_SoundManDead;
	CSound*         m_SoundWomanDead;
	CSound*         m_SoundTrig;
	CSound*         m_SoundWarning;
	CSound*         m_SoundTrans;
	CSound*         m_BgmC;

	CSprite*		m_pBlack;
	double			ColorAlpha;
	int				m_AlpahState;		//�������

public:
	DGameMain();            //���캯��
	~DGameMain();           //��������  

	// Get����
	int				GetGameState()											{ return m_iGameState; }
	
	// Set����
	void			SetGameState( const int iState )				{ m_iGameState	=	iState; }
	
	// ��Ϸ��ѭ����
	void			GameMainLoop( float	fDeltaTime );
	void			GameInit();
	void			GameRun( float fDeltaTime );
	void			GameEnd();
	void 			OnMouseMove( const float fMouseX, const float fMouseY );
	void 			OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY );
	void 			OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY );
	void 			OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress );
	void 			OnKeyUp( const int iKey );
	void 			OnSpriteColSprite( const char *szSrcName, const char *szTarName );
	void 			OnSpriteColWorldLimit( const char *szName, const int iColSide );
	void			AddBulletA();
	void			AddBulletB();
	void			AddBulletC();
	CSprite*		FindBulletA(const char* szName);
	CSprite*		FindBulletB(const char* szName);
	CSprite*		FindBulletC(const char* szName);
	void			Transmission(CPortal* pPortal, CPlayer* pPlayerSprite);
	void			TransmissionBullet(CPortal* pPortal, CSprite* pBulletSprite);
	void			OnBulletHitA(const char* szSrcName, const char*szTarName);
	void			OnBulletHitB(const char* szSrcName, const char*szTarName);
	void			OnBulletHitC(const char* szSrcName, const char*szTarName);

	int				ColorAlphaMaking(const double AlphaStart,const double AlphaEnd,const double Accuracy);
};

/////////////////////////////////////////////////////////////////////////////////
// 
extern DGameMain	e_GameMain;

#endif // _LESSON_Y_H_