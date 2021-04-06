#include "..\Header\PlayerSpriteA.h"
//================================================================================================================================================================
CPlayerSpriteA::CPlayerSpriteA( const char *szName ):CPlayer( szName )
{
}
//================================================================================================================================================================

CPlayerSpriteA::~CPlayerSpriteA(void)
{
}
//================================================================================================================================================================
void CPlayerSpriteA::OnMove(int iKey, bool bPress)
{
	if(bPress){									//����AD����ʱ�������ٶ�����
		switch(iKey){
			case KEY_LEFT:
				SetSpeedLeft(-200);	
				break;
			case KEY_RIGHT:
				SetSpeedRight(200) ;
				break;
		}
	}	
	else{										//̧��AD����ʱ�������ٶȹ���
		if(iKey == KEY_LEFT ||iKey == KEY_RIGHT){
				SetSpeedLeft(0);
				SetSpeedRight(0);
		}
	}
	if((GetSpeedLeft() + GetSpeedRight()) > 0){
		SetSpriteFlipX( false);					//���ݺ��ٶȷ��� �ж��������߳��򣺶�����ʼ�������� ���ٶ����� ��������ת
	}
	else if((GetSpeedLeft() + GetSpeedRight()) < 0){
		SetSpriteFlipX( true);					//���ݺ��ٶȷ��� �ж��������߳��򣺶�����ʼ�������� ���ٶ����� ������ת
	}
	SetSpriteLinearVelocityX( GetSpeedLeft() + GetSpeedRight() );
	if(GetSpeedLeft() + GetSpeedRight() == 0){
		AnimateSpritePlayAnimation( "PlayerPic03Animation1", 0 );
	}
	else{
		AnimateSpritePlayAnimation( "PlayerPic03Animation3", 0 );
	}
}
//================================================================================================================================================================
void CPlayerSpriteA::OnJump()
{	//��Ҷ�����Ծ�������� ���漰�������� ������趨��Ϊ�麯��
	if( GetJumpState() == 0 ){					//����֮ǰ״̬0 ��ʾ��һ������ǰ����վ�ڵ�����
		SetJumpState(1);						//������״̬��Ϊ1 ��ʾ��һ����������ڿ�״̬
		SetSpriteImpulseForcePolar(-90,500,0);	//����������˲ʱ����С
	}
}
//================================================================================================================================================================


