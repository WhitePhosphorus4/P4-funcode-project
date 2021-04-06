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
//ȫ�ֱ���
//
/////////////////////////////////////////////////////////////////////////////////////////////

extern int LevelState=5;			  //��Ϸ�ؿ���: 1,2,3�ֱ�Ϊ��һ�صڶ��ص�����  4Ϊÿһ��ͨ��֮��ĸ��ӹ� 5��ʼ�˵�
extern int MapLoadingState=1;		  //�ж��Ƿ�����˳����л� 1Ϊ�� 0Ϊ��
extern int PatternState=1;				//�ؿ����л�ģʽ������1Ϊ���վ���ģʽ�л��ؿ�  2Ϊ���մ���ģʽ�л��ؿ�

///////////////////////////////////////////////////////////////////////////////////////////
//
// ���������
//
//////////////////////////////////////////////////////////////////////////////////////////
int PASCAL WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR     lpCmdLine,
                   int       nCmdShow)
{
	// ��ʼ����Ϸ����
	if( !CSystem::InitGameEngine( hInstance, lpCmdLine ) )
		return 0;

	// To do : �ڴ�ʹ��API���Ĵ��ڱ���
	switch(LevelState)
	{
	case 1:
		CSystem::SetWindowTitle("˫����̽---LEVEL ONE");
		break;
	case 2:
		CSystem::SetWindowTitle("˫����̽---LEVEL TWO");
		break;
	case 3:
		CSystem::SetWindowTitle("˫����̽---LEVEL THREE");
		break;
	case 4:
		CSystem::SetWindowTitle("˫����̽---LEVEL FOUT");
		break;
	case 5:
		CSystem::SetWindowTitle("˫����̽---");
		break;
	}

	// ������ѭ����������Ļͼ��ˢ�µȹ���
	while( CSystem::EngineMainLoop() ){
		// ��ȡ���ε���֮���ʱ�����ݸ���Ϸ�߼�����
		float	fTimeDelta	=	CSystem::GetTimeDelta();

		// ִ����Ϸ��ѭ��
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

	// �ر���Ϸ����
	CSystem::ShutdownGameEngine();
	return 0;
}

//==========================================================================
//
// ���沶׽����ƶ���Ϣ�󣬽����õ�������
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
//
void CSystem::OnMouseMove( const float fMouseX, const float fMouseY )
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
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
// ���沶׽�������Ϣ�󣬽����õ�������
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
//
void CSystem::OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
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
// ���沶׽��굯����Ϣ�󣬽����õ�������
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
//
void CSystem::OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
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
// ���沶׽���̰�����Ϣ�󣬽����õ�������
// ���� iKey�������µļ���ֵ�� enum KeyCodes �궨��
// ���� iAltPress, iShiftPress��iCtrlPress�������ϵĹ��ܼ�Alt��Ctrl��Shift��ǰ�Ƿ�Ҳ���ڰ���״̬(0δ���£�1����)
//
void CSystem::OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
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
// ���沶׽���̵�����Ϣ�󣬽����õ�������
// ���� iKey������ļ���ֵ�� enum KeyCodes �궨��
//
void CSystem::OnKeyUp( const int iKey )
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
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
// ���沶׽�������뾫����ײ֮�󣬵��ô˺���
// ����֮��Ҫ������ײ�������ڱ༭�����ߴ��������þ��鷢�ͼ�������ײ
// ���� szSrcName��������ײ�ľ�������
// ���� szTarName������ײ�ľ�������
//
void CSystem::OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
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
// ���沶׽������������߽���ײ֮�󣬵��ô˺���.
// ����֮��Ҫ������ײ�������ڱ༭�����ߴ��������þ��������߽�����
// ���� szName����ײ���߽�ľ�������
// ���� iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
//
void CSystem::OnSpriteColWorldLimit( const char *szName, const int iColSide )
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
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

