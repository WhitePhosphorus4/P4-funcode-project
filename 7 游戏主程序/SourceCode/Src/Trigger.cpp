#include "..\Header\Trigger.h"


CTrigger::CTrigger(const char* szNamem):CSprite(szNamem)
{
	m_iTriggerResult = 0;
	m_iTriggerState = 0;
}

CTrigger::~CTrigger(void)
{
}
