/////////////////////////////////////////////////////////////////////////////////
//
//游戏开始场景(有一个隐藏的载入接口，初始界面按1进入关卡4）
//
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef _LESSON_S_H_
#define _LESSON_S_H_
//
#include <Windows.h>



/////////////////////////////////////////////////////////////////////////////////
//
// 游戏总管类。负责处理游戏主循环、游戏初始化、结束等工作
class	AGameMain
{
private:
	int				m_iGameState;				// 游戏状态，0：结束或者等待开始；1：初始化；2：在初始菜单界面等待玩家选择：3：选择了剧情模式；4：选择了闯关模式；5：选择了游戏介绍;6:剧情模式等待开始
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
	int				m_AlpahState;		//渐变参数

public:
	AGameMain();            //构造函数
	~AGameMain();           //析构函数  

	// Get方法
	int				GetGameState()											{ return m_iGameState; }
	
	// Set方法
	void			SetGameState( const int iState )				{ m_iGameState	=	iState; }
	
	// 游戏主循环等
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

	//自定义函数
//===========================================================================
//
// 设置渐变块的渐变效果
// 参数 AlphaStart：初始渐变块透明度
// 参数 AlphaEnd：结束渐变块透明度
// 参数 Accuracy：变化精度
	int				ColorAlphaMaking(const double AlphaStart,const double AlphaEnd,const double Accuracy);
};

/////////////////////////////////////////////////////////////////////////////////
// 
extern AGameMain	a_GameMain;

#endif // _LESSON_S_H_