//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
#include "CommonClass.h"
#include "LessonX.h"
#include "LessonY.h"
#include "LessonZ.h"
#include "LessonS.h"
#include "LessonE.h"

////////////////////////////////////////////////////////////////////////////////////////////
//
//全局变量
//
/////////////////////////////////////////////////////////////////////////////////////////////

extern int LevelState=5;			  //游戏关卡数: 1,2,3分别为第一关第二关第三关  4为每一关通关之后的附加关 5开始菜单
extern int MapLoadingState=1;		  //判断是否进行了场景切换 1为是 0为否
extern int PatternState=1;				//关卡的切换模式参数，1为按照剧情模式切换关卡  2为按照闯关模式切换关卡

///////////////////////////////////////////////////////////////////////////////////////////
//
// 主函数入口
//
//////////////////////////////////////////////////////////////////////////////////////////
int PASCAL WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR     lpCmdLine,
                   int       nCmdShow)
{
	// 初始化游戏引擎
	if( !CSystem::InitGameEngine( hInstance, lpCmdLine ) )
		return 0;

	// To do : 在此使用API更改窗口标题
	switch(LevelState)
	{
	case 1:
		CSystem::SetWindowTitle("双子神探---LEVEL ONE");
		break;
	case 2:
		CSystem::SetWindowTitle("双子神探---LEVEL TWO");
		break;
	case 3:
		CSystem::SetWindowTitle("双子神探---LEVEL THREE");
		break;
	case 4:
		CSystem::SetWindowTitle("双子神探---LEVEL FOUT");
		break;
	case 5:
		CSystem::SetWindowTitle("双子神探---");
		break;
	}

	// 引擎主循环，处理屏幕图像刷新等工作
	while( CSystem::EngineMainLoop() ){
		// 获取两次调用之间的时间差，传递给游戏逻辑处理
		float	fTimeDelta	=	CSystem::GetTimeDelta();

		// 执行游戏主循环
		switch(LevelState)
		{
		case 1:
			if(MapLoadingState==1)
			{
				CSystem::LoadMap("level1.t2d");
				MapLoadingState=0;
				c_GameMain.SetGameState(0);
			}
			c_GameMain.GameMainLoop( fTimeDelta );
			break;
		case 2:
			if(MapLoadingState==1)
			{
				CSystem::LoadMap("level2.t2d");
				MapLoadingState=0;
				e_GameMain.SetGameState(0);
			}
			e_GameMain.GameMainLoop( fTimeDelta );
			break;
		case 3:
			if(MapLoadingState==1)
			{
				CSystem::LoadMap("level3.t2d");
				MapLoadingState=0;
				g_GameMain.SetGameState(0);
			}
			g_GameMain.GameMainLoop( fTimeDelta );
			break;
		case 4:
			if(MapLoadingState==1)
			{
				CSystem::LoadMap("level4.t2d");
				MapLoadingState=0;
				b_GameMain.SetGameState(1);
			}
			b_GameMain.GameMainLoop( fTimeDelta );
			break;
		case 5:
			if(MapLoadingState==1)
			{
				CSystem::LoadMap("level5.t2d");
				MapLoadingState=0;
				a_GameMain.SetGameState(1);
			}
			a_GameMain.GameMainLoop( fTimeDelta );
			break;
		}
	}

	// 关闭游戏引擎
	CSystem::ShutdownGameEngine();
	return 0;
}

//==========================================================================
//
// 引擎捕捉鼠标移动消息后，将调用到本函数
// 参数 fMouseX, fMouseY：为鼠标当前坐标
//
void CSystem::OnMouseMove( const float fMouseX, const float fMouseY )
{
	// 可以在此添加游戏需要的响应函数
	switch(LevelState)
	{
		case 1:
			c_GameMain.OnMouseMove(fMouseX, fMouseY);
			break;
		case 2:
			e_GameMain.OnMouseMove(fMouseX, fMouseY);
			break;
		case 3:
			g_GameMain.OnMouseMove(fMouseX, fMouseY);
			break;
		case 4:
			b_GameMain.OnMouseMove(fMouseX, fMouseY);
			break;
		case 5:
			a_GameMain.OnMouseMove(fMouseX, fMouseY);
			break;
	}
}
//==========================================================================
//
// 引擎捕捉鼠标点击消息后，将调用到本函数
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
//
void CSystem::OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
	// 可以在此添加游戏需要的响应函数
	switch(LevelState)
	{
		case 1:
			c_GameMain.OnMouseClick(iMouseType, fMouseX, fMouseY);
			break;
		case 2:
			e_GameMain.OnMouseClick(iMouseType, fMouseX, fMouseY);
			break;
		case 3:
			g_GameMain.OnMouseClick(iMouseType, fMouseX, fMouseY);
			break;
		case 4:
			b_GameMain.OnMouseClick(iMouseType, fMouseX, fMouseY);
			break;
		case 5:
			a_GameMain.OnMouseClick(iMouseType, fMouseX, fMouseY);
			break;
	}
}
//==========================================================================
//
// 引擎捕捉鼠标弹起消息后，将调用到本函数
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
//
void CSystem::OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
	// 可以在此添加游戏需要的响应函数
	switch(LevelState)
	{
		case 1:
			c_GameMain.OnMouseUp(iMouseType, fMouseX, fMouseY);
			break;
		case 2:
			e_GameMain.OnMouseUp(iMouseType, fMouseX, fMouseY);
			break;
		case 3:
			g_GameMain.OnMouseUp(iMouseType, fMouseX, fMouseY);
			break;
		case 4:
			b_GameMain.OnMouseUp(iMouseType, fMouseX, fMouseY);
			break;
		case 5:
			a_GameMain.OnMouseUp(iMouseType, fMouseX, fMouseY);
			break;
	}
}
//==========================================================================
//
// 引擎捕捉键盘按下消息后，将调用到本函数
// 参数 iKey：被按下的键，值见 enum KeyCodes 宏定义
// 参数 iAltPress, iShiftPress，iCtrlPress：键盘上的功能键Alt，Ctrl，Shift当前是否也处于按下状态(0未按下，1按下)
//
void CSystem::OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{
	// 可以在此添加游戏需要的响应函数
	switch(LevelState)
	{
		case 1:
			c_GameMain.OnKeyDown(iKey, bAltPress, bShiftPress, bCtrlPress);
			break;
		case 2:
			e_GameMain.OnKeyDown(iKey, bAltPress, bShiftPress, bCtrlPress);
			break;
		case 3:
			g_GameMain.OnKeyDown(iKey, bAltPress, bShiftPress, bCtrlPress);
			break;
		case 4:
			b_GameMain.OnKeyDown(iKey, bAltPress, bShiftPress, bCtrlPress);
			break;
		case 5:
			a_GameMain.OnKeyDown(iKey, bAltPress, bShiftPress, bCtrlPress);
			break;
	}
}
//==========================================================================
//
// 引擎捕捉键盘弹起消息后，将调用到本函数
// 参数 iKey：弹起的键，值见 enum KeyCodes 宏定义
//
void CSystem::OnKeyUp( const int iKey )
{
	// 可以在此添加游戏需要的响应函数
	switch(LevelState)
	{
		case 1:
			c_GameMain.OnKeyUp(iKey);
			break;
		case 2:
			e_GameMain.OnKeyUp(iKey);
			break;
		case 3:
			g_GameMain.OnKeyUp(iKey);
			break;
		case 4:
			b_GameMain.OnKeyUp(iKey);
			break;
		case 5:
			a_GameMain.OnKeyUp(iKey);
			break;
	}
}

//===========================================================================
//
// 引擎捕捉到精灵与精灵碰撞之后，调用此函数
// 精灵之间要产生碰撞，必须在编辑器或者代码里设置精灵发送及接受碰撞
// 参数 szSrcName：发起碰撞的精灵名字
// 参数 szTarName：被碰撞的精灵名字
//
void CSystem::OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
	// 可以在此添加游戏需要的响应函数
	switch(LevelState)
	{
		case 1:
			c_GameMain.OnSpriteColSprite(szSrcName, szTarName);
			break;
		case 2:
			e_GameMain.OnSpriteColSprite(szSrcName, szTarName);
			break;
		case 3:
			g_GameMain.OnSpriteColSprite(szSrcName, szTarName);
			break;
		case 4:
			b_GameMain.OnSpriteColSprite(szSrcName, szTarName);
			break;
		case 5:
			a_GameMain.OnSpriteColSprite(szSrcName, szTarName);
			break;
	}
}

//===========================================================================
//
// 引擎捕捉到精灵与世界边界碰撞之后，调用此函数.
// 精灵之间要产生碰撞，必须在编辑器或者代码里设置精灵的世界边界限制
// 参数 szName：碰撞到边界的精灵名字
// 参数 iColSide：碰撞到的边界 0 左边，1 右边，2 上边，3 下边
//
void CSystem::OnSpriteColWorldLimit( const char *szName, const int iColSide )
{
	// 可以在此添加游戏需要的响应函数
	switch(LevelState)
	{
		case 1:
			c_GameMain.OnSpriteColWorldLimit(szName, iColSide);
			break;
		case 2:
			e_GameMain.OnSpriteColWorldLimit(szName, iColSide);
			break;
		case 3:
			g_GameMain.OnSpriteColWorldLimit(szName, iColSide);
			break;
		case 4:
			b_GameMain.OnSpriteColWorldLimit(szName, iColSide);
			break;
		case 5:
			a_GameMain.OnSpriteColWorldLimit(szName, iColSide);
			break;
	}
}

