/////////////////////////////////////////////////////////////////////////////////
//
//��Ϸ��ʼ����(��һ�����ص�����ӿڣ���ʼ���水1����ؿ�4��
//
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef _LESSON_S_H_
#define _LESSON_S_H_
//
#include <Windows.h>



/////////////////////////////////////////////////////////////////////////////////
//
// ��Ϸ�ܹ��ࡣ��������Ϸ��ѭ������Ϸ��ʼ���������ȹ���
class	AGameMain
{
private:
	int				m_iGameState;				// ��Ϸ״̬��0���������ߵȴ���ʼ��1����ʼ����2���ڳ�ʼ�˵�����ȴ����ѡ��3��ѡ���˾���ģʽ��4��ѡ���˴���ģʽ��5��ѡ������Ϸ����;6:����ģʽ�ȴ���ʼ
	CSprite*		m_pCampaign1;
	CSprite*		m_pCampaign2;
	CSprite*		m_pFight;
	CSprite*		m_pIntroduce;
	CSprite*		m_pFirstLevel;
	CSprite*		m_pSecondLevel;
	CSprite*		m_pThirdLevel;
	CSprite*		m_pBack1;
	CSprite*		m_pBack2;
	CSprite*		m_pYes;
	CSprite*		m_pOther1;
	CSprite*		m_pOther2;
	CSprite*		m_pIntroduce1;
	CSprite*		m_pIntroduce2;
	CSprite*		m_pLetter;
	CSprite*		m_pKuang11;
	CSprite*		m_pKuang12;
	CSprite*		m_pKuang13;
	CSprite*		m_pKuang21;
	CSprite*		m_pKuang22;
	CSprite*		m_pKuang23;
	CSprite*		m_pKuang31;
	CSprite*		m_pKuang32;
	CSprite*		m_pKuang33;
	CSprite*		m_pBlack;

	CSound*         m_SoundMenu;
	CSound*			m_BgmA;

	double			ColorAlpha;
	int				m_AlpahState;		//�������

public:
	AGameMain();            //���캯��
	~AGameMain();           //��������  

	// Get����
	int				GetGameState()											{ return m_iGameState; }
	
	// Set����
	void			SetGameState( const int iState )				{ m_iGameState	=	iState; }
	
	// ��Ϸ��ѭ����
	void			GameMainLoop( float	fDeltaTime );
	void			GameInit();
	void			GameRun( float fDeltaTime );
	void			GameRun3( float fDeltaTime );
	void			GameRun4( float fDeltaTime );
	void			GameRun5( float fDeltaTime );
	void			GameRun6( float fDeltaTime );
	void			GameEnd();
	void 			OnMouseMove( const float fMouseX, const float fMouseY );
	void 			OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY );
	void 			OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY );
	void 			OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress );
	void 			OnKeyUp( const int iKey );
	void 			OnSpriteColSprite( const char *szSrcName, const char *szTarName );
	void 			OnSpriteColWorldLimit( const char *szName, const int iColSide );

	//�Զ��庯��
//===========================================================================
//
// ���ý����Ľ���Ч��
// ���� AlphaStart����ʼ�����͸����
// ���� AlphaEnd�����������͸����
// ���� Accuracy���仯����
	int				ColorAlphaMaking(const double AlphaStart,const double AlphaEnd,const double Accuracy);
};

/////////////////////////////////////////////////////////////////////////////////
// 
extern AGameMain	a_GameMain;

#endif // _LESSON_S_H_