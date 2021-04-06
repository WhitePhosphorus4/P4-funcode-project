/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef _LESSON_E_H_
#define _LESSON_E_H_
//
#include <Windows.h>
#include "..\VCProject2010/VCProject2010/home.h"
/////////////////////////////////////////////////////////////////////////////////
//
// ��Ϸ�ܹ��ࡣ��������Ϸ��ѭ������Ϸ��ʼ���������ȹ���
class	BGameMain
{
private:
	int				m_iGameState;				// ��Ϸ״̬��0���������ߵȴ���ʼ��1����ʼ����2����Ϸ������
	int located1, located2;     //���ڵĴ󳡾���С����λ��
	bool carry;
	bool doorisopen[6];
	double beblack;    // ��Ļ�����Ľ���
	int becomeblack;   //�ж��Ƿ�Ҫ���   1Ϊ���   0Ϊ����   -1Ϊ���  2Ϊ���ñ��
	int now;     //��ʱ�洢Ҫת����ͼ�ı��
	bool isattack;
	bool attackfirst;  //�ж������Ƿ�����
	bool attackafter;
	bool attackafter1;
	CSound* surrounded;
	CSound* keyopen;
//	CSound* horror1;
	CSound* click;
	CSound* openthedoor;
	CSound* shriek;
	CSound* hited;
	CSound* scared;
	bool isagain;
	bool firstsee;
public:
	BGameMain();            //���캯��
	~BGameMain();           //��������  
	// Get����
	int				GetGameState()											{ return m_iGameState; }
	Home* home;
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

};

/////////////////////////////////////////////////////////////////////////////////
// 
extern BGameMain	b_GameMain;

#endif // _LESSON_E_H_