/////////////////////////////////////////////////////////////////////////////////
//
//��Ϸ�Ŀ�ʼ����
//(��һ�����ص�����ӿڣ���ʼ���水1����ؿ�4��
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
// ����ĳ�������Ϊ��GameMainLoop����Ϊ��ѭ��������������ÿ֡ˢ����Ļͼ��֮�󣬶��ᱻ����һ�Ρ�

//==============================================================================
//
// ���캯��
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
// ��������
AGameMain::~AGameMain()
{
}

//==============================================================================
//
// ��Ϸ��ѭ�����˺���������ͣ�ĵ��ã�����ÿˢ��һ����Ļ���˺�����������һ��
// ���Դ�����Ϸ�Ŀ�ʼ�������С������ȸ���״̬. 
// ��������fDeltaTime : �ϴε��ñ��������˴ε��ñ�������ʱ��������λ����
void AGameMain::GameMainLoop( float	fDeltaTime )
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
	case 3:
		{
			// TODO �޸Ĵ˴���Ϸѭ�������������ȷ��Ϸ�߼�
			if( true )
			{
				GameRun3( fDeltaTime );
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
			// TODO �޸Ĵ˴���Ϸѭ�������������ȷ��Ϸ�߼�
			if( true )
			{
				GameRun4( fDeltaTime );
			}
			else // ��Ϸ������������Ϸ���㺯����������Ϸ״̬�޸�Ϊ����״̬
			{				
				SetGameState(0);
				GameEnd();
			}
		}
		break;
	case 5:
		{
			// TODO �޸Ĵ˴���Ϸѭ�������������ȷ��Ϸ�߼�
			if( true )
			{
				GameRun5( fDeltaTime );
			}
			else // ��Ϸ������������Ϸ���㺯����������Ϸ״̬�޸�Ϊ����״̬
			{				
				SetGameState(0);
				GameEnd();
			}
		}
		break;
	case 6:
		{
			// TODO �޸Ĵ˴���Ϸѭ�������������ȷ��Ϸ�߼�
			if( true )
			{
				GameRun6( fDeltaTime );
			}
			else // ��Ϸ������������Ϸ���㺯����������Ϸ״̬�޸�Ϊ����״̬
			{				
				SetGameState(0);
				GameEnd();
			}
		}
		break;
		// ��Ϸ����/�ȴ����ո����ʼ
	case 0:
	default:
		break;
	};
}
//=============================================================================
//
// ÿ�ֿ�ʼǰ���г�ʼ���������һ���������
void AGameMain::GameInit()
{
	//����Ч��������ʼ��===============================================
	m_AlpahState			=	0;
	ColorAlpha				=	255;
	//���ó�ʼλ��====================================================
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
	//���ÿ���ʼ���ɼ�
	m_pKuang11->SetSpriteVisible(0);
	m_pKuang12->SetSpriteVisible(0);
	m_pKuang13->SetSpriteVisible(0);
	m_pKuang21->SetSpriteVisible(0);
	m_pKuang22->SetSpriteVisible(0);
	m_pKuang23->SetSpriteVisible(0);
	m_pKuang31->SetSpriteVisible(0);
	m_pKuang32->SetSpriteVisible(0);
	m_pKuang33->SetSpriteVisible(0);
	//��߿�ʼ�˵����ƶ�===============================================
	m_pCampaign1->SpriteMoveTo(-456.615,-64.146,1200,1);
	m_pFight->SpriteMoveTo(-456.615,32.243,1200,1);
	m_pIntroduce->SpriteMoveTo(-456.615,128.632,1200,1);
	m_SoundMenu->StopAllSound();
	m_BgmA->PlaySoundA();
}
//=============================================================================
//
// �ڳ�ʼ�˵�����ȴ����ѡ��
void AGameMain::GameRun( float fDeltaTime )
{
	//��������Ч��
	ColorAlphaMaking(255,0,1);
}
//=============================================================================
//
// ѡ���˾���ģʽ
void AGameMain::GameRun3( float fDeltaTime )
{
}
//=============================================================================
//
// ѡ���˴���ģʽ
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
// ѡ������Ϸ����
void AGameMain::GameRun5( float fDeltaTime )
{
}
//=============================================================================
//
// ����ģʽ�ȴ���ʼ
void AGameMain::GameRun6( float fDeltaTime )
{
	switch(m_AlpahState)
	{
		//��͸���䲻͸��
	case 0:
		{
			if(ColorAlphaMaking(0,255,1)==1)
			{
				m_AlpahState=1;
			}
		}
		break;
		//�Ӳ�͸����͸��
	case 1:
		{
			m_pLetter->SetSpritePosition(0,0);
			if(ColorAlphaMaking(255,0,1)==1)
			{
				m_AlpahState=3;
			}
		}
		break;
		//��͸���䲻͸��
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
// ������Ϸ����
void AGameMain::GameEnd()
{
}
//==========================================================================
//
// ����ƶ�
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
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
// �����
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
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
// ��굯��
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void AGameMain::OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
	
}
//==========================================================================
//
// ���̰���
// ���� iKey�������µļ���ֵ�� enum KeyCodes �궨��
// ���� iAltPress, iShiftPress��iCtrlPress�������ϵĹ��ܼ�Alt��Ctrl��Shift��ǰ�Ƿ�Ҳ���ڰ���״̬(0δ���£�1����)
void AGameMain::OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{	
}
//==========================================================================
//
// ���̵���
// ���� iKey������ļ���ֵ�� enum KeyCodes �궨��
void AGameMain::OnKeyUp( const int iKey )
{
	
}
//===========================================================================
//
// �����뾫����ײ
// ���� szSrcName��������ײ�ľ�������
// ���� szTarName������ײ�ľ�������
void AGameMain::OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
	
}
//===========================================================================
//
// ����������߽���ײ
// ���� szName����ײ���߽�ľ�������
// ���� iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
void AGameMain::OnSpriteColWorldLimit( const char *szName, const int iColSide )
{
	
}

//===========================================================================
//
// ���ý����Ľ���Ч��
// ���� AlphaStart����ʼ�����͸����
// ���� AlphaEnd�����������͸����
// ���� Accuracy���仯����
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