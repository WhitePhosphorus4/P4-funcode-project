#pragma once
#include "commonclass.h"
class CTrigger :
	public CSprite
{
private:
	int				m_iTriggerResult;			//触发器是否被触发 1为触发 2为未触发	
	int				m_iTriggerState;			//触发器状态 1为到达触发位置 0为未到达触发位置

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

