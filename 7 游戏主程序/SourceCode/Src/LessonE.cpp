/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonClass.h"
#include "LessonE.h"
#include <math.h>
////////////////////////////////////////////////////////////////////////////////
//
//
BGameMain		b_GameMain;	
//==============================================================================
//
// ����ĳ�������Ϊ��GameMainLoop����Ϊ��ѭ��������������ÿ֡ˢ����Ļͼ��֮�󣬶��ᱻ����һ�Ρ�

//==============================================================================
//
// ���캯��
BGameMain::BGameMain()
{
	firstsee = false;
	attackfirst = false;
	isagain = false;
	surrounded = new CSound("horrorsurround1.wav", 1, 1);
	keyopen = new CSound("keyopen.wav", 0, 1);
	click = new CSound("click.wav", 0, 1);
	openthedoor = new CSound("openthedoor.wav", 0, 1);
	shriek = new CSound("shriek.wav", 0, 1);
	hited = new CSound("hited.wav", 0, 1);
	scared = new CSound("scared.wav", 0, 1);
//	horror1 = new CSound("horror1.wav", 0, 1);
//	surrounded->PlaySound();
	isattack = attackafter = attackafter1 = false;
	now = 0;
	beblack = 0;
	becomeblack = 0;
	m_iGameState			=	1;
	located1 = -1;
	located2 = 0;
	carry = false;
	for(int i = 0; i < 6; i++)
	{
		doorisopen[i] = false;
	}
}
//==============================================================================
//
// ��������
BGameMain::~BGameMain()
{
}

//==============================================================================
//
// ��Ϸ��ѭ�����˺���������ͣ�ĵ��ã�����ÿˢ��һ����Ļ���˺�����������һ��
// ���Դ�����Ϸ�Ŀ�ʼ�������С������ȸ���״̬. 
// ��������fDeltaTime : �ϴε��ñ��������˴ε��ñ�������ʱ��������λ����
void BGameMain::GameMainLoop( float	fDeltaTime )
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

		// ��Ϸ����/�ȴ����ո����ʼ
	case 0:
	default:
		break;
	};
}
//=============================================================================
//
// ÿ�ֿ�ʼǰ���г�ʼ���������һ���������
void BGameMain::GameInit()
{
	surrounded->StopAllSound();
	surrounded->PlaySoundA();
	if(!isagain)
	{
		home = new Home();
		isagain = true;
	}
	if(located1 == -1)
	{
		home->scene[0]->move(1360, -768);
		located1 = 0;
	}
	if(home->getDeblocking() == 2)
	{
		for(int i = 0; i < 3; i++)
		{
			home->scene[i]->atlas.clear();
			home->scene[i]->walls.clear();
			home->scene[i]->doors.clear();
			home->scene[i]->gos.clear();
		}
		home->doorcount = 0;
		home->wallcount = 0;
		home->gocount = 0;
		home->scene[0]->InitMap(-1360, 768);
		home->scene[0]->atlas[0]->SetSpriteVisible(1);
		home->scene[0]->Init();
		home->scene[0]->concealgo(3, 7);
		home->scene[1]->InitMap(0, 768);
		home->scene[1]->atlas[0]->SetSpriteVisible(1);
		home->scene[1]->Init();
		home->scene[1]->concealgo(3, 5);
		home->scene[2]->InitMap(1360, 768);
		home->scene[2]->atlas[0]->SetSpriteVisible(1);
		home->scene[2]->Init();
		home->scene[2]->concealgo(4, 7);
		home->scene[1]->move(0, -768);
		located1 = 1;
	}
	if(home->getDeblocking() == 3)
	{
		for(int i = 0; i < 3; i++)
		{
			home->scene[i]->atlas.clear();
			home->scene[i]->walls.clear();
			home->scene[i]->doors.clear();
			home->scene[i]->gos.clear();
		}
		home->doorcount = 0;
		home->wallcount = 0;
		home->gocount = 0;
		home->scene[0]->InitMap(-1360, 768);
		home->scene[0]->atlas[0]->SetSpriteVisible(1);
		home->scene[0]->Init();
		home->scene[0]->concealgo(3, 7);
		home->scene[1]->InitMap(0, 768);
		home->scene[1]->atlas[0]->SetSpriteVisible(1);
		home->scene[1]->Init();
		home->scene[1]->concealgo(3, 5);
		home->scene[2]->InitMap(1360, 768);
		home->scene[2]->atlas[0]->SetSpriteVisible(1);
		home->scene[2]->Init();
		home->scene[2]->concealgo(4, 7);
		home->scene[2]->move(-1360, -768);
		located1 = 2;
	}
	home->black->SetSpritePosition(0, 0);
	beblack = 255;
	home->black->SetSpriteColorAlpha(beblack);
	becomeblack = -1;
}
//=============================================================================
//
// ÿ����Ϸ������
void BGameMain::GameRun( float fDeltaTime )
{
	if(home->ishide)home->hideMyKnapsack();
	else home->showMyKnapsack();
	if(becomeblack == 1)
	{
		if(beblack >= 255)
		{
			beblack = 255;
			becomeblack = -1;
			home->move(now);
			located1 = home->getLocation();
			return;
		}
		else
		{
			beblack += 2;
			home->black->SetSpriteColorAlpha(beblack);
		}
	}
	if(isattack)
	{
		hited->PlaySoundA();
		home->show("�飡", "", "");
		return;
	}
	if(becomeblack == -1)
	{
		if(beblack <= 0)
		{
			beblack = 0;
			becomeblack = 0;
			return;
		}
		else
		{
			beblack -= 2;
			home->black->SetSpriteColorAlpha(beblack);
		}
	}
	if(becomeblack == 2)
	{
		if(beblack >= 255)
		{
			home->show("лл���档", "", "");
			beblack = 255;
			SetGameState(3);
		}
		else
		{
			beblack += 0.25;
			home->black->SetSpriteColorAlpha(beblack);
		}
	}
}
//=============================================================================
//
// ������Ϸ����
void BGameMain::GameEnd()
{
}
//==========================================================================
//
// ����ƶ�
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void BGameMain::OnMouseMove( const float fMouseX, const float fMouseY )
{
	
}
//==========================================================================
//
// �����
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void BGameMain::OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
	if(isattack)
	{
		home->hideMyKnapsack();
		isattack = false;
		attackafter = true;
		return;
	}
	if(attackafter)
	{
		attackafter = false;
		home->hideMyKnapsack();
		home->show("���������Ǳ�Ϯ����...\n���飡������", "", "");
		shriek->PlaySoundA();
		attackafter1 = true;
		return;
	}
	if(becomeblack != 0)return;
	if(fabs(fMouseX - home->exit->GetSpritePositionX()) < 5 && fabs(fMouseY - home->exit->GetSpritePositionY()) < 5)
	{
		home->show();
		return;
	}
	else
	for(int i = 0; i < 3; i++)
	{
		if(fabs(fMouseX - home->texts[i]->GetSpritePositionX()) < 5 && fabs(fMouseY - home->texts[i]->GetSpritePositionY()) < 5)
		{
			openthedoor->PlaySoundA();
			now = i;
			becomeblack = 1;
			located2 = 0;
			home->black->SetSpritePosition(0, 0);
		}
	}
	if(fabs(fMouseX - home->left->GetSpritePositionX()) < 3 && fabs(fMouseY - home->left->GetSpritePositionY()) < 3)
	{
		home->moveMyKnapsack(1);
		click->PlaySoundA();
	}
	if(fabs(fMouseX - home->right->GetSpritePositionX()) < 3 && fabs(fMouseY - home->right->GetSpritePositionY()) < 3)
	{
		home->moveMyKnapsack(-1);
		click->PlaySoundA();
	}
	if(located1 == 0 && located2 == 0)
	{
		if(fabs(fMouseX - home->getGoPositionX(0, 0)) < 5 && fabs(fMouseY - home->getGoPositionY(0, 0)) < 5)
		{
			click->PlaySoundA();
			home->show();
			for(int i = 0; i < 3; i++)
			{
				if(fabs(fMouseX - home->texts[i]->GetSpritePositionX()) < 2 && fabs(fMouseY - home->texts[i]->GetSpritePositionY()) < 0.5)
				{
					openthedoor->PlaySoundA();
					now = i;
					located2 = 0;
					home->black->SetSpritePosition(0, 0);
					becomeblack = 1;
				}
			}
			return;
		}
		if(fabs(fMouseX - home->getGoPositionX(0, 1)) < 5 && fabs(fMouseY - home->getGoPositionY(0, 1)) < 5)
		{
			if(doorisopen[0] == false)
			{
				if(home->iscatch != 0)
				{
					home->show("�ű�������,��Ҫһ���ض���Կ��", "", "");
				}
				else
				{
					home->show("�ſ���", "", "");
					keyopen->PlaySoundA();
					doorisopen[0] = true;
				}
				return;
			}
			click->PlaySoundA();
			home->scene[0]->atlas[3]->SetSpriteVisible(1);
			home->scene[0]->getKey3()->SetSpriteVisible(1);
			home->scene[0]->concealgo(0, 2);
			home->scene[0]->concealwall(0, 5);
			home->scene[0]->concealgo(6, 6, false);
			located2 = 3;
		}
		if(fabs(fMouseX - home->getGoPositionX(0, 2)) < 5 && fabs(fMouseY - home->getGoPositionY(0, 2)) < 5)
		{
			click->PlaySoundA();
			home->scene[0]->atlas[1]->SetSpriteVisible(1);
			home->scene[0]->concealgo(0, 2);
			home->scene[0]->concealwall(0, 5);
			home->scene[0]->concealgo(3, 4, false);
			home->scene[0]->getLetter()->SetSpriteVisible(1);
			located2 = 1;
		}
		if(fabs(fMouseX - home->getAtlasPositionX(0, 6)) < 5 && fabs(fMouseY - home->getAtlasPositionY(0, 6)) < 5)
		{
			home->scene[0]->atlas[4]->SetSpriteVisible(1);
			home->scene[0]->getBook()->SetSpriteVisible(1);
			home->scene[0]->concealgo(0, 2);
			home->scene[0]->concealwall(0, 5);
			home->scene[0]->concealgo(7, 7, false);
			located2 = 4;
		}
		if(fabs(fMouseX - home->scene[0]->getSofa()->GetSpritePositionX()) < 5 && fabs(fMouseY - home->scene[0]->getSofa()->GetSpritePositionY()) < 5)
		{
			home->scene[0]->atlas[5]->SetSpriteVisible(1);
			home->scene[0]->concealgo(0, 2);
			home->scene[0]->concealwall(0, 5);
			home->scene[0]->concealgo(7, 7, false);
			home->scene[0]->getKey0(0)->SetSpriteVisible(1);
			located2 = 5;
		}
	}
	if(located1 == 0 && located2 == 1)
	{
		if(fabs(fMouseX - home->getGoPositionX(0, 3)) < 5 && fabs(fMouseY - home->getGoPositionY(0, 3)) < 5)
		{
			click->PlaySoundA();
			home->scene[0]->atlas[1]->SetSpriteVisible(0);
			home->scene[0]->concealgo(0, 2, false);
			home->scene[0]->concealwall(0, 5, false);
			home->scene[0]->concealgo(3, 4);
			if(home->isget[0] == false)home->scene[0]->getLetter()->SetSpriteVisible(0);
			located2 = 0;
		}
		if(fabs(fMouseX - home->getGoPositionX(0, 4)) < 5 && fabs(fMouseY - home->getGoPositionY(0, 4)) < 5)
		{
			if(doorisopen[1] == false)
			{
				if(home->iscatch != 1)
				{
					home->show("�ű�������,��Ҫһ���ض���Կ��", "", "");
				}
				else
				{
					home->show("�ſ���", "", "");
					keyopen->PlaySoundA();
					doorisopen[1] = true;
				}
				return;
			}
			click->PlaySoundA();
			home->scene[0]->atlas[2]->SetSpriteVisible(1);
			home->scene[0]->getKey2(0)->SetSpriteVisible(1);
			home->scene[0]->concealgo(5, 5, false);
			home->scene[0]->concealgo(3, 4);
			if(home->isget[0] == false)home->scene[0]->getLetter()->SetSpriteVisible(0);
			located2 = 2;
		}
	}
	if(located1 == 0 && located2 == 3)
	{
		if(fabs(fMouseX - home->getGoPositionX(0, 6)) < 5 && fabs(fMouseY - home->getGoPositionY(0, 6)) < 5)
		{
			click->PlaySoundA();
			home->scene[0]->atlas[3]->SetSpriteVisible(0);
			home->scene[0]->getKey3()->SetSpriteVisible(0);
			home->scene[0]->concealgo(0, 2, false);
			home->scene[0]->concealwall(0, 5, false);
			home->scene[0]->concealgo(6, 6);
			located2 = 0;
		}
	}
	if(located1 == 0 && located2 == 4 || located2 == 5)
	{
		if(fabs(fMouseX - home->getGoPositionX(0, 7)) < 5 && fabs(fMouseY - home->getGoPositionY(0, 7)) < 5)
		{
			click->PlaySoundA();
			home->scene[0]->atlas[4]->SetSpriteVisible(0);
			home->scene[0]->atlas[5]->SetSpriteVisible(0);
			home->scene[0]->getKey0(0)->SetSpriteVisible(0);
			home->scene[0]->getBook()->SetSpriteVisible(0);
			home->scene[0]->concealgo(0, 2, false);
			home->scene[0]->concealwall(0, 5, false);
			home->scene[0]->concealgo(7, 7);
			located2 = 0;
		}
	}
	if(located1 == 0 && located2 == 2)
	{
		if(fabs(fMouseX - home->scene[0]->getGos(5)->GetSpritePositionX()) < 5 && fabs(fMouseY - home->scene[0]->getGos(5)->GetSpritePositionY()) < 5)
		{
			home->scene[0]->atlas[2]->SetSpriteVisible(0);
			home->scene[0]->getKey2(0)->SetSpriteVisible(0);
			home->scene[0]->concealgo(5, 5);
			home->scene[0]->concealgo(3, 4, false);
			home->scene[0]->getLetter()->SetSpriteVisible(1);
			located2 = 1;
		}
	}
	if(located1 == 1 && located2 == 0)
	{
		if(fabs(fMouseX - home->scene[1]->getKeting()->GetSpritePositionX()) < 5 && fabs(fMouseY - home->scene[1]->getKeting()->GetSpritePositionY()) < 5)
		{
			home->show("���Ͽ��ţ���������Ϊ��", "", "");
			return;
		}
		if(fabs(fMouseX - home->scene[1]->getGos(0)->GetSpritePositionX()) < 5 && fabs(fMouseY - home->scene[1]->getGos(0)->GetSpritePositionY()) < 5)
		{
			click->PlaySoundA();
			home->show();
			for(int i = 0; i < 3; i++)
			{
				if(fabs(fMouseX - home->texts[i]->GetSpritePositionX()) < 2 && fabs(fMouseY - home->texts[i]->GetSpritePositionY()) < 0.5)
				{
					openthedoor->PlaySoundA();
					now = i;
					located2 = 0;
					home->black->SetSpritePosition(0, 0);
					becomeblack = 1;
				}
			}
			return;
		}
		if(fabs(fMouseX - home->scene[1]->getDecoration()->GetSpritePositionX()) < 5 && fabs(fMouseY - home->scene[1]->getDecoration()->GetSpritePositionY()) < 5)
		{
			if(home->getDeblocking() == 7)
			{
				home->last->SetSpritePosition(43.429, 20.800);
			}
			home->scene[1]->atlas[3]->SetSpriteVisible(1);
			home->scene[1]->getKey4()->SetSpriteVisible(1);
			home->scene[1]->getPhone()->SetSpriteVisible(1);
			home->scene[1]->conceal(0, 9, 0, 5, 0, 2);
			home->scene[1]->concealgo(5, 5, false);
			located2 = 3;
		}
		if(fabs(fMouseX - home->getGoPositionX(1, 1)) < 5 && fabs(fMouseY - home->getGoPositionY(1, 1)) < 5)
		{
			if(doorisopen[2] == false)
			{
				if(home->iscatch != 2)
				{
					home->show("�ű�������,��Ҫһ���ض���Կ��", "", "");
				}
				else
				{
					home->show("�ſ���", "", "");
					keyopen->PlaySoundA();
					doorisopen[2] = true;
				}
				return;
			}
			click->PlaySoundA();
			home->scene[1]->atlas[1]->SetSpriteVisible(1);
			home->scene[1]->getKey5(0)->SetSpriteVisible(1);
			home->scene[1]->concealgo(3, 3, false);
			home->scene[1]->conceal(0, 9, 0, 5, 0, 2);
			located2 = 1;
			if(home->attack == true)
			{
				home->scene[1]->getDoctor()->SetSpriteVisible(1);
				if(attackfirst)
				{
					scared->PlaySoundA();
					attackfirst = false;
				}
			}
		}
		if(carry == false)
		{
			if(fabs(fMouseX - home->scene[1]->getDianshi()->GetSpritePositionX()) < 2 && fabs(fMouseY - home->scene[1]->getDianshi()->GetSpritePositionY()) < 6)
			{
				home->show("�Ƿ����?", "��", "��");
				return;
			}
			if(fabs(fMouseX - home->texts[3]->GetSpritePositionX()) < 5 && fabs(fMouseY - home->texts[3]->GetSpritePositionY()) < 5)
			{
				home->hide();
				carry = true;
			}
			if(fabs(fMouseX - home->texts[4]->GetSpritePositionX()) < 5 && fabs(fMouseY - home->texts[4]->GetSpritePositionY()) < 5)
			{
				home->hide();
			}
		}
		else if(carry == true)
		{
			home->scene[1]->getDianshi()->SpriteMoveTo(fMouseX, fMouseY, 100, true);
			carry = false;
			if(fMouseY > 10.8)
			{
				doorisopen[3] = true;
				keyopen->PlaySoundA();
			}
		}
		if(fabs(fMouseX - home->getGoPositionX(1, 2)) < 5 && fabs(fMouseY - home->getGoPositionY(1, 2)) < 5)
		{
			click->PlaySoundA();
			if(doorisopen[3])
			{
				home->scene[1]->atlas[2]->SetSpriteVisible(1);
				home->scene[1]->getKey6(0)->SetSpriteVisible(1);
				home->scene[1]->concealgo(4, 4, false);
				home->scene[1]->conceal(0, 9, 0, 5, 0, 2);
				located2 = 2;
			}
			else
			{
				home->show("�ű�������,��Ҫһ���ض���Կ��", "", "");
				return;
			}
		}
	}
	if(located1 == 1 && located2 == 1)
	{
		if(fabs(fMouseX - home->getGoPositionX(1, 3)) < 5 && fabs(fMouseY - home->getGoPositionY(1, 3)) < 5)
		{
			click->PlaySoundA();
			home->scene[1]->atlas[1]->SetSpriteVisible(0);
			home->scene[1]->conceal(0, 9, 0, 5, 0, 2, false, false, false);
			home->scene[1]->concealgo(3, 3);
			home->scene[1]->getKey5(0)->SetSpriteVisible(0);
			if(home->attack == true)home->scene[1]->getDoctor()->SetSpriteVisible(0);
			located2 = 0;
		}
		if(fabs(fMouseX) < 5 && fabs(fMouseY - 11) < 5)
		{
			if(home->attack == true)home->ishide = false;
		}
	}
	if(located1 == 1 && located2 == 2)
	{
		if(fabs(fMouseX - home->getGoPositionX(1, 4)) < 5 && fabs(fMouseY - home->getGoPositionY(1, 4)) < 5)
		{
			click->PlaySoundA();
			home->scene[1]->atlas[2]->SetSpriteVisible(0);
			home->scene[1]->getKey6(0)->SetSpriteVisible(0);
			home->scene[1]->conceal(0, 9, 0, 5, 0, 2, false, false, false);
			home->scene[1]->concealgo(4, 4);
			located2 = 0;
		}
	}
	if(located1 == 1 && located2 == 3)
	{
		if(fabs(fMouseX - home->getGoPositionX(1, 5)) < 5 && fabs(fMouseY - home->getGoPositionY(1, 5)) < 5)
		{
			click->PlaySoundA();
			if(home->getDeblocking() == 7)
			{
				home->last->SetSpritePosition(100, 19.980);
			}
			home->scene[1]->atlas[3]->SetSpriteVisible(0);
			home->scene[1]->conceal(0, 9, 0, 5, 0, 2, false, false, false);
			home->scene[1]->getKey4()->SetSpriteVisible(0);
			home->scene[1]->getPhone()->SetSpriteVisible(0);
			home->scene[1]->concealgo(5, 5);
			located2 = 0;
		}
	}
	if(located1 == 2 && located2 == 0)
	{
		if(fabs(fMouseX - home->getGoPositionX(2, 0)) < 5 && fabs(fMouseY - home->getGoPositionY(2, 0)) < 5)
		{
			click->PlaySoundA();
			home->scene[2]->atlas[1]->SetSpriteVisible(1);
			home->scene[2]->conceal(0, 5, 0, 2, 0, 3);
			home->scene[2]->concealgo(4, 5, false);
			located2 = 1;
		}
		if(fabs(fMouseX - home->getGoPositionX(2, 1)) < 5 && fabs(fMouseY - home->getGoPositionY(2, 1)) < 5)
		{
			click->PlaySoundA();
			home->scene[2]->atlas[4]->SetSpriteVisible(1);
			home->scene[2]->conceal(0, 5, 0, 2, 0, 3);
			located2 = 4;
		}
		if(fabs(fMouseX - home->getGoPositionX(2, 2)) < 5 && fabs(fMouseY - home->getGoPositionY(2, 2)) < 5)
		{
			click->PlaySoundA();
			home->scene[2]->atlas[3]->SetSpriteVisible(1);
			home->scene[2]->getLock()->SetSpriteVisible(1);
			home->scene[2]->conceal(0, 5, 0, 2, 0, 3);
			home->scene[2]->concealgo(7, 7, false);
			located2 = 3;
		}
		if(fabs(fMouseX - home->getGoPositionX(2, 3)) < 5 && fabs(fMouseY - home->getGoPositionY(2, 3)) < 5)
		{
			click->PlaySoundA();
			home->show();
			for(int i = 0; i < 3; i++)
			{
				if(fabs(fMouseX - home->texts[i]->GetSpritePositionX()) < 2 && fabs(fMouseY - home->texts[i]->GetSpritePositionY()) < 0.5)
				{
					openthedoor->PlaySoundA();
					now = i;
					located2 = 0;
					home->black->SetSpritePosition(0, 0);
					becomeblack = 1;
				}
			}
			return;
		}
	}
	if(located1 == 2 && located2 == 1)
	{
		if(fabs(fMouseX - home->getGoPositionX(2, 4)) < 5 && fabs(fMouseY - home->getGoPositionY(2, 4)) < 5)
		{
			click->PlaySoundA();
			home->scene[2]->atlas[1]->SetSpriteVisible(0);
			home->scene[2]->conceal(0, 5, 0, 2, 0, 3, false, false, false);
			home->scene[2]->concealgo(4, 5);
			located2 = 0;
		}
		if(fabs(fMouseX - home->getGoPositionX(2, 5)) < 5 && fabs(fMouseY - home->getGoPositionY(2, 5)) < 5)
		{
			click->PlaySoundA();
			home->scene[2]->atlas[2]->SetSpriteVisible(1);
			home->scene[2]->concealgo(4, 5);
			home->scene[2]->concealgo(6, 6, false);
			located2 = 2;
			if(firstsee == false)
			{
				scared->PlaySoundA();
				firstsee = true;
			}
//			horror1->PlaySoundA();
		}
	}
	if(located1 == 2 && located2 == 2)
	{
		if(fabs(fMouseX - home->getGoPositionX(2, 6)) < 5 && fabs(fMouseY - home->getGoPositionY(2, 6)) < 5)
		{
			click->PlaySoundA();
			home->scene[2]->atlas[2]->SetSpriteVisible(0);
			home->scene[2]->concealgo(4, 5, false);
			home->scene[2]->concealgo(6, 6);
			located2 = 1;
		}
		if(fabs(fMouseX - 25) < 5 && fabs(fMouseY - 14) < 5)
		{
			home->scene[2]->atlas[2]->SetSpriteVisible(0);
			home->scene[2]->atlas[1]->SetSpriteVisible(0);
			home->scene[2]->atlas[1] = new CSprite("bedroom7");
			home->scene[2]->atlas[1]->SetSpritePosition(0, 0);
			home->scene[2]->concealgo(4, 4, false);
			home->scene[2]->concealgo(5, 6);
			home->scene[2]->getGos(5)->SetSpritePosition(999, 100);
			located2 = 1;
			home->show("��...�ҵ��ļ�......", "", "");
			return;
		}
	}
	if(located1 == 2 && located2 == 3)
	{
		if(fabs(fMouseX - home->getGoPositionX(2, 7)) < 5 && fabs(fMouseY - home->getGoPositionY(2, 7)) < 5)
		{
			click->PlaySoundA();
			home->scene[2]->atlas[3]->SetSpriteVisible(0);
			home->scene[2]->conceal(0, 5, 0, 2, 0, 3, false, false, false);
			home->scene[2]->concealgo(7, 7);
			home->scene[2]->getLock()->SetSpriteVisible(0);
			located2 = 0;
		}
		if(home->getDeblocking() == 3 && fabs(fMouseX + 37) < 8 && fabs(fMouseY + 13) < 8)
		{
			home->setDeblocking(4);
			home->scene[2]->atlas[3]->SetSpriteVisible(0);
			home->scene[2]->atlas[3] = new CSprite("bedroom6");
			home->scene[2]->atlas[3]->SetSpritePosition(0, 0);
			home->scene[2]->getLock()->SetSpriteVisible(1);
		}
		for(int i = 0; i < 7; i++)
		{
			if(fabs(fMouseX - home->scene[2]->getK(i)->GetSpritePositionX()) < 0.5 && fabs(fMouseY - home->scene[2]->getK(i)->GetSpritePositionY()) < 0.5)
			{
				if(home->iscatch == 0)
				{
					home->scene[2]->getK(i)->SetSpriteColorBlue(0);
					home->scene[2]->getK(i)->SetSpriteColorRed(0);
					home->scene[2]->getK(i)->SetSpriteColorGreen(200);
				}
				if(home->iscatch == 1)
				{
					home->scene[2]->getK(i)->SetSpriteColorBlue(137);
					home->scene[2]->getK(i)->SetSpriteColorRed(137);
					home->scene[2]->getK(i)->SetSpriteColorGreen(137);
				}
				if(home->iscatch == 2)
				{
					if(i == 1 || i == 4 || i == 5)
					{
						home->score[i] = 1;
					}
					home->scene[2]->getK(i)->SetSpriteColorBlue(200);
					home->scene[2]->getK(i)->SetSpriteColorRed(0);
					home->scene[2]->getK(i)->SetSpriteColorGreen(0);
				}
				if(home->iscatch == 3)
				{
					if(i == 0)home->score[i] = 1;
					home->scene[2]->getK(i)->SetSpriteColorBlue(0);
					home->scene[2]->getK(i)->SetSpriteColorRed(200);
					home->scene[2]->getK(i)->SetSpriteColorGreen(0);
				}
				if(home->iscatch == 4)
				{
					if(i == 2)home->score[i] = 1;
					home->scene[2]->getK(i)->SetSpriteColorBlue(0);
					home->scene[2]->getK(i)->SetSpriteColorRed(240);
					home->scene[2]->getK(i)->SetSpriteColorGreen(220);
				}
				if(home->iscatch == 5)
				{
					home->scene[2]->getK(i)->SetSpriteColorBlue(232);
					home->scene[2]->getK(i)->SetSpriteColorRed(232);
					home->scene[2]->getK(i)->SetSpriteColorGreen(102);
				}
				if(home->iscatch == 6)
				{
					if(i == 3 || i == 6)home->score[i] = 1;
					home->scene[2]->getK(i)->SetSpriteColorBlue(229);
					home->scene[2]->getK(i)->SetSpriteColorRed(195);
					home->scene[2]->getK(i)->SetSpriteColorGreen(0);
				}
				if(home->iscatch == 7)
				{
					home->scene[2]->getK(i)->SetSpriteColorBlue(0);
					home->scene[2]->getK(i)->SetSpriteColorRed(0);
					home->scene[2]->getK(i)->SetSpriteColorGreen(0);
				}
				home->scene[2]->getK(i)->SetSpriteVisible(1);
				int sum = 0;
				for(int j = 0; j < 7; j++)
					sum += home->score[j];
				if(sum == 7)
				{
					home->setDeblocking(5);
					home->scene[2]->getLock()->SpriteMoveTo(-75, -60, 10, true);
					for(int k = 0; k < 7; k++)
					{
						home->scene[2]->getK(k)->SetSpriteVisible(0);
					}
					home->file->SetSpritePosition(-37.404, -12.251);
				}
				return;
			}
		}
	}
	if(located1 == 2 && located2 == 4)
	{
		if(fabs(fMouseX - 10) < 5 && fabs(fMouseY - 17) < 5)
		{
			click->PlaySoundA();
			home->scene[2]->atlas[4]->SetSpriteVisible(0);
			home->scene[2]->conceal(0, 5, 0, 2, 0, 3, false, false, false);
			located2 = 0;
		}
		if(fabs(fMouseX + 27) < 5 && fabs(fMouseY + 27) < 5)
		{
			click->PlaySoundA();
			home->scene[2]->atlas[5]->SetSpriteVisible(1);
			home->scene[2]->getKey7(0)->SetSpriteVisible(1);
			located2 = 5;
		}
	}
	if(located1 == 2 && located2 == 5)
	{
		if(fabs(fMouseX - 18) < 5 && fabs(fMouseY - 27) < 5)
		{
			click->PlaySoundA();
			home->scene[2]->atlas[5]->SetSpriteVisible(0);
			home->scene[2]->getKey7(0)->SetSpriteVisible(0);
			located2 = 4;
		}
	}
	if(fabs(fMouseX - home->scene[0]->getLetter()->GetSpritePositionX()) < 3 && fabs(fMouseY - home->scene[0]->getLetter()->GetSpritePositionY()) < 3)
	{
		if(home->isget[0] == false && located1 == 0 && located2 == 1)
		{
			home->getKnapsack(0)->SetSpritePosition(0, 0);
			home->isget[0] = true;
			home->myknapsack.push_back(home->scene[0]->getLetter());
			home->articlecount++;
			home->scene[0]->getKey1(0)->SetSpriteVisible(1);
		}
		else if(home->isget[0])home->getKnapsack(0)->SetSpritePosition(0, 0);
	}
	else home->getKnapsack(0)->SetSpritePosition(0, 100);
	if(fabs(fMouseX - home->scene[0]->getBook()->GetSpritePositionX()) < 3 && fabs(fMouseY - home->scene[0]->getBook()->GetSpritePositionY()) < 3)
	{
		if(home->isget[1] == false && located1 == 0 && located2 == 4)
		{
			for(int i = 1; i <= 8; i++)
			{
				home->isget[i] = true;
			}
//			home->scene[0]->getBook()->SetSpriteVisible(0);
			home->getKnapsack(1)->SetSpritePosition(0, 0);
			home->seeing = 1;
			home->articlecount++;
			home->myknapsack.push_back(home->scene[0]->getBook());
		}
		else if(home->isget[1])
		{
			home->getKnapsack(1)->SetSpritePosition(0, 0);
			home->seeing = 1;
		}
	}
	if(fabs(fMouseX - home->scene[0]->getKey0(0)->GetSpritePositionX()) < 3 && fabs(fMouseY - home->scene[0]->getKey0(0)->GetSpritePositionY()) < 3)
	{
		if(home->isget[9] == false && located1 == 0 && located2 == 5)
		{
			home->isget[9] = true;
			home->scene[0]->getKey0(0)->SetSpriteVisible(0);
			home->articlecount++;
			home->myknapsack.push_back(home->scene[0]->getKey0(0));
		}
		else
		{
			home->iscatch = 0;
			home->choose->SetSpritePosition(home->scene[0]->getKey0(0)->GetSpritePositionX(), home->scene[0]->getKey0(0)->GetSpritePositionY());
		}
	}
	if(fabs(fMouseX - home->scene[0]->getKey1(0)->GetSpritePositionX()) < 3 && fabs(fMouseY - home->scene[0]->getKey1(0)->GetSpritePositionY()) < 3)
	{
		if(home->isget[15] == false && located1 == 0 && located2 == 1)
		{
			home->isget[15] = true;
			home->scene[0]->getKey1(0)->SetSpriteVisible(0);
			home->articlecount++;
			home->myknapsack.push_back(home->scene[0]->getKey1(0));
		}
		else
		{
			home->iscatch = 1;
			home->choose->SetSpritePosition(home->scene[0]->getKey1(0)->GetSpritePositionX(), home->scene[0]->getKey1(0)->GetSpritePositionY());
		}
	}
	if(fabs(fMouseX - home->scene[0]->getKey2(0)->GetSpritePositionX()) < 3 && fabs(fMouseY - home->scene[0]->getKey2(0)->GetSpritePositionY()) < 3)
	{
		if(home->isget[17] == false && located1 == 0 && located2 == 2)
		{
			home->isget[17] = true;
			home->scene[0]->getKey2(0)->SetSpriteVisible(0);
			home->articlecount++;
			home->myknapsack.push_back(home->scene[0]->getKey2(0));
		}
		else
		{
			home->iscatch = 2;
			home->choose->SetSpritePosition(home->scene[0]->getKey2(0)->GetSpritePositionX(), home->scene[0]->getKey2(0)->GetSpritePositionY());
		}
	}
	if(fabs(fMouseX - home->scene[0]->getKey3()->GetSpritePositionX()) < 3 && fabs(fMouseY - home->scene[0]->getKey3()->GetSpritePositionY()) < 3)
	{
		if(home->isget[20] == false && located1 == 0 && located2 == 3)
		{
			home->isget[20] = true;
			home->scene[0]->getKey3()->SetSpriteVisible(0);
			home->articlecount++;
			home->myknapsack.push_back(home->scene[0]->getKey3());
		}
		else
		{
			home->iscatch = 3;
			home->choose->SetSpritePosition(home->scene[0]->getKey3()->GetSpritePositionX(), home->scene[0]->getKey3()->GetSpritePositionY());
		}
	}
	if(fabs(fMouseX - home->scene[1]->getKey4()->GetSpritePositionX()) < 3 && fabs(fMouseY - home->scene[1]->getKey4()->GetSpritePositionY()) < 3)
	{
		if(home->attack == false && located1 == 1 && located2 == 3)
		{
			home->black->SetSpritePosition(0, 0);
			home->scene[1]->getPhone()->SetSpriteVisible(0);
			home->scene[1]->atlas[3]->SetSpriteVisible(0);
			home->scene[1]->getKey4()->SetSpriteVisible(0);
			home->scene[1]->conceal(0, 9, 0, 5, 0, 2, false, false, false);
			home->scene[1]->concealgo(5, 5);
			home->attack = true;
			attackfirst = true;
			isattack = true;
			doorisopen[2] = true;
			becomeblack = 1;
			now = 0;
			located1 = 0;
			located2 = 0;
			home->ishide = true;
		}
		else if(home->isget[21] == false && located1 == 1 && located2 == 3)
		{
			home->isget[21] = true;
			home->scene[1]->getKey4()->SetSpriteVisible(0);
			home->articlecount++;
			home->myknapsack.push_back(home->scene[1]->getKey4());
		}
		else
		{
			home->iscatch = 4;
			home->choose->SetSpritePosition(home->scene[1]->getKey4()->GetSpritePositionX(), home->scene[1]->getKey4()->GetSpritePositionY());
		}
	}
	if(fabs(fMouseX - home->scene[1]->getKey5(0)->GetSpritePositionX()) < 3 && fabs(fMouseY - home->scene[1]->getKey5(0)->GetSpritePositionY()) < 3)
	{
		if(home->isget[22] == false && located1 == 1 && located2 == 1)
		{
			home->isget[22] = true;
			home->scene[1]->getKey5(0)->SetSpriteVisible(0);
			home->articlecount++;
			home->myknapsack.push_back(home->scene[1]->getKey5(0));
		}
		else
		{
			home->iscatch = 5;
			home->choose->SetSpritePosition(home->scene[1]->getKey5(0)->GetSpritePositionX(), home->scene[1]->getKey5(0)->GetSpritePositionY());
		}
	}
	if(fabs(fMouseX - home->scene[1]->getKey6(0)->GetSpritePositionX()) < 3 && fabs(fMouseY - home->scene[1]->getKey6(0)->GetSpritePositionY()) < 3)
	{
		if(home->isget[25] == false && located1 == 1 && located2 == 2)
		{
			home->isget[25] = true;
			home->scene[1]->getKey6(0)->SetSpriteVisible(0);
			home->articlecount++;
			home->myknapsack.push_back(home->scene[1]->getKey6(0));
		}
		else
		{
			home->iscatch = 6;
			home->choose->SetSpritePosition(home->scene[1]->getKey6(0)->GetSpritePositionX(), home->scene[1]->getKey6(0)->GetSpritePositionY());
		}
	}
	if(fabs(fMouseX - home->scene[2]->getKey7(0)->GetSpritePositionX()) < 3 && fabs(fMouseY - home->scene[2]->getKey7(0)->GetSpritePositionY()) < 3)
	{
		if(home->isget[27] == false && located1 == 2 && located2 == 5)
		{
			home->isget[27] = true;
			home->scene[2]->getKey7(0)->SetSpriteVisible(0);
			home->articlecount++;
			home->myknapsack.push_back(home->scene[2]->getKey7(0));
		}
		else
		{
			home->iscatch = 7;
			home->choose->SetSpritePosition(home->scene[2]->getKey7(0)->GetSpritePositionX(), home->scene[2]->getKey7(0)->GetSpritePositionY());
		}
	}
	if(fabs(fMouseX - home->file->GetSpritePositionX()) < 5 && fabs(fMouseY - home->file->GetSpritePositionY()) < 5)
	{
		if(home->isget[29] == false && located1 == 2 && located2 == 3)
		{
			home->isget[29] = true;
			home->articlecount++;
			home->myknapsack.push_back(home->file);
			home->setDeblocking(6);
		}
		else home->iscatch = 8;
	}
	if(home->getDeblocking() == 6 && located1 == 2 && located2 == 1)
	{
		if(fabs(fMouseX + 10) < 6 && fabs(fMouseY + 13) < 15)
		{
			if(home->iscatch == 8)
			{
				home->last = new CSprite("last");
				home->setDeblocking(7);
				home->show("лл......����ҽ����Ȼ���......", "", "");
				home->articlecount--;
				return;
			}
			else
			{
				home->show("�ҵ��ļ�......", "", "");
				return;
			}
		}
	}
	if(home->getDeblocking() == 7)
	{
		if(fabs(fMouseX - home->last->GetSpritePositionX()) < 2 && fabs(fMouseY - home->last->GetSpritePositionY()) < 2)
		{
			home->last->SetSpriteVisible(0);
			CSprite* postcard = new CSprite("postcard");
			postcard->SetSpritePosition(0, 0);
			home->show("����?!", "", "");
			scared->PlaySoundA();
			for(int i = 0; i < 100; i++);
			becomeblack = 2;
			return;
		}
	}
	if(home->seeing != -1)
	{
		if(fabs(fMouseX - home->getKnapsack(home->seeing)->GetSpritePositionX()) < 10 && fabs(fMouseY - home->getKnapsack(home->seeing)->GetSpritePositionY()) < 10)
		{
			home->getNext();
		}
	}
	if(home->ishide)home->hideMyKnapsack();
	else home->showMyKnapsack();
	home->hide();
	if(attackafter1)
	{
		home->show("ʲô�������������ǳ����Ǵ����ġ�", "", "");
		attackafter1 = false;
	}
}
//==========================================================================
//
// ��굯��
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void BGameMain::OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
//==========================================================================
//
// ���̰���
// ���� iKey�������µļ���ֵ�� enum KeyCodes �궨��
// ���� iAltPress, iShiftPress��iCtrlPress�������ϵĹ��ܼ�Alt��Ctrl��Shift��ǰ�Ƿ�Ҳ���ڰ���״̬(0δ���£�1����)
void BGameMain::OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{	
	if(GetGameState()==3&&iKey==KEY_SPACE)
	{
		LevelState = 5;
		MapLoadingState = 1;
	}
}
//==========================================================================
//
// ���̵���
// ���� iKey������ļ���ֵ�� enum KeyCodes �궨��
void BGameMain::OnKeyUp( const int iKey )
{
	
}
//===========================================================================
//
// �����뾫����ײ
// ���� szSrcName��������ײ�ľ�������
// ���� szTarName������ײ�ľ�������
void BGameMain::OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
	
}
//===========================================================================
//
// ����������߽���ײ
// ���� szName����ײ���߽�ľ�������
// ���� iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
void BGameMain::OnSpriteColWorldLimit( const char *szName, const int iColSide )
{
	
}