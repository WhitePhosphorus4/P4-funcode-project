#pragma once
#include "commonclass.h"
class CPlayer :
	public CAnimateSprite
{
private:
	//���������������======================================================================================================================================
	float			m_fPlayerMass;					//��������
	int				m_iJumpState;					//��Ծ״̬���� ʵ�ֶ����� �ж��ڿ�״̬ 0Ϊվ�ڵ��� 1Ϊ�ڿ�һ����״̬ 2Ϊ�ڿն�����״̬
	float			m_fSpeedTop;					//�����ٶ�
	float			m_fSpeedLeft;					//��������ٶ�
	float			m_fSpeedBottom;					//����½��ٶ�
	float			m_fSpeedRight;					//��������ٶ�
public:
	CPlayer(const char* szName);
	~CPlayer(void);									//�̳����ͣ�CAnimateSprite
	//set����===============================================================================================================================================
	//�������������������
	void			SetPlayerMass(float fPlayerMass)	{fPlayerMass = m_fPlayerMass;}		//�����������
	void			SetJumpState(int iJumpState)		{m_iJumpState = iJumpState;}		//������Ծ״̬ 0Ϊվ�ڵ��� 1Ϊ�ڿ�һ����״̬ 2Ϊ�ڿն�����״̬
	void			SetSpeedTop(float fSpeedTop)		{m_fSpeedTop = fSpeedTop;}			//������������ٶ�
	void			SetSpeedLeft(float fSpeedLeft)		{m_fSpeedLeft = fSpeedLeft;}		//������������ٶ�
	void			SetSpeedBottom(float fSpeedBottom)	{m_fSpeedBottom = fSpeedBottom;}	//��������½��ٶ�
	void			SetSpeedRight(float fSpeedRight)	{m_fSpeedRight = fSpeedRight;}		//������������ٶ�
	//get����===============================================================================================================================================
	//��ȡ���������������
	float			GetPlayerMass()						{return m_fPlayerMass;}				//��ȡ�������
	int				GetJumpState()						{return m_iJumpState;}				//��ȡ��Ծ״̬ 0Ϊվ�ڵ��� 1Ϊ�ڿ�һ����״̬ 2Ϊ�ڿն�����״̬
	float			GetSpeedTop()						{return m_fSpeedTop;}				//��ȡ��������ٶ�
	float			GetSpeedLeft()						{return m_fSpeedLeft;}				//��ȡ��������ٶ�
	float			GetSpeedBottom()					{return m_fSpeedBottom;}			//��ȡ����½��ٶ�
	float			GetSpeedRight()						{return m_fSpeedRight;}				//��ȡ��������ٶ�
	//��ҹ��ܺ���==========================================================================================================================================
	void			PlayerSpriteInit(float fPlayerMass);									//��Ҿ����ʼ������
	virtual	void	OnMove(int iKey, bool bPress) = 0;										//������Һ������ú��� ���麯�� ���嶨��ֱ���CPlayerSpriteA��CPlayerSpriteB��ʵ��
	virtual void	OnJump() = 0;															//��Ҷ���������ʵ�ֺ��� ���漰�������� ������趨��Ϊ�麯��
};

