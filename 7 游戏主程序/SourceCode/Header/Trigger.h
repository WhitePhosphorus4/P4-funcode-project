#pragma once
#include "commonclass.h"
class CTrigger :
	public CSprite
{
private:
	int				m_iTriggerResult;			//�������Ƿ񱻴��� 1Ϊ���� 2Ϊδ����	
	int				m_iTriggerState;			//������״̬ 1Ϊ���ﴥ��λ�� 0Ϊδ���ﴥ��λ��

public:
	CTrigger(const char* szNamem);
	~CTrigger(void);
	//===========================================================================
	void			SetTriggerResult(int iTriggerResult)	{m_iTriggerResult = iTriggerResult;}
	void			SetTriggerState(int iTriggerState)		{m_iTriggerState = iTriggerState;}
	//===========================================================================
	int				GetTriggerResult()						{return m_iTriggerResult;}
	int				GetTriggerState()						{return m_iTriggerState;}
};

