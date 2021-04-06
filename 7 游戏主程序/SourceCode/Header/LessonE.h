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
// 游戏总管类。负责处理游戏主循环、游戏初始化、结束等工作
class	BGameMain
{
private:
	int				m_iGameState;				// 游戏状态，0：结束或者等待开始；1：初始化；2：游戏进行中
	int located1, located2;     //所在的大场景和小场景位置
	bool carry;
	bool doorisopen[6];
	double beblack;    // 黑幕产生的进度
	int becomeblack;   //判断是否要变黑   1为变黑   0为不变   -1为便白  2为永久变黑
	int now;     //暂时存储要转换的图的编号
	bool isattack;
	bool attackfirst;  //判断音乐是否响起
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
	BGameMain();            //构造函数
	~BGameMain();           //析构函数  
	// Get方法
	int				GetGameState()											{ return m_iGameState; }
	Home* home;
	// Set方法
	void			SetGameState( const int iState )				{ m_iGameState	=	iState; }
	
	// 游戏主循环等
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