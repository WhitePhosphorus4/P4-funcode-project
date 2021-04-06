#include "..\Header\PLayerSpriteB.h"
//================================================================================================================================================================
CPLayerSpriteB::CPLayerSpriteB( const char *szName ):CPlayer( szName )
{
}
//================================================================================================================================================================
CPLayerSpriteB::~CPLayerSpriteB(void)
{
}
//================================================================================================================================================================
void CPLayerSpriteB::OnMove(int iKey, bool bPress)
{
	if(bPress){									//����AD����ʱ�������ٶ�����
		switch(iKey){
			case KEY_A:
				SetSpeedLeft(-200);	
				break;
			case KEY_D:
				SetSpeedRight(200) ;
				break;
		}
	}	
	else{										//̧��AD����ʱ�������ٶȹ���
		if(iKey == KEY_A ||iKey == KEY_D){
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
	if(GetSpeedLeft() + GetSpeedRight() == 0){	//�����ٶȷ���ѡ�����ﶯ�� ��������
		AnimateSpritePlayAnimation( "PlayerPic04Animation1", 0 );
	}
	else{
		AnimateSpritePlayAnimation( "PlayerPic04Animation3", 0 );
	}
}
//================================================================================================================================================================
void CPLayerSpriteB::OnJump()
{	//��Ҷ�����Ծ�������� ���漰�������� ������趨��Ϊ�麯��
	if( GetJumpState() == 0 ){					//����֮ǰ״̬0 ��ʾ��һ������ǰ����վ�ڵ�����
		SetJumpState(1);						//������״̬��Ϊ1 ��ʾ��һ����������ڿ�״̬
		SetSpriteImpulseForcePolar(-90,500,0);	//����������˲ʱ����С
	}
	else if( GetJumpState() == 1 ){				//����֮ǰ״̬Ϊ1 ��ʾ�Ѿ�������һ����������ڿ�״̬
		SetJumpState(2);						//�ڶ���������״̬��Ϊ1 ��ʾ�ڶ�����������ڿ�״̬
		SetSpriteLinearVelocityY(0);			//���õ�ǰ�ٶ�Ϊ�㣬���ų�˲ʱ�ٶȶ���Ծ�߶ȵ�Ӱ��
		SetSpriteImpulseForcePolar(-90,500,0);	//����������˲ʱ����С
	}
}
//================================================================================================================================================================