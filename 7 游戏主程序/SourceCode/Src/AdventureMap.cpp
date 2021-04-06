#include "AdventureMap.h"


CAdventureMap::CAdventureMap(void)
{

}


CAdventureMap::~CAdventureMap(void)
{

}

void CAdventureMap::SetMapInfo(int iNumBlockL, int iNumBlockV)
{
	for(int i = 0; i < iNumBlockL; i++){
		char* szName = CSystem::MakeSpriteName("Block_L",i + 1);
		CSprite* tmpBlockL = new CSprite(szName);
		tmpBlockL->CloneSprite(szName);
		tmpBlockL->SetSpriteCollisionActive(0, 1);
		m_vBlockL.push_back(tmpBlockL);
	}
	for(int i = 0; i < iNumBlockV; i++){
		char* szName = CSystem::MakeSpriteName("Block_V",i + 1);
		CSprite* tmpBlockV = new CSprite(szName);
		tmpBlockV->CloneSprite(szName);
		tmpBlockV->SetSpriteCollisionActive(0, 1);
		m_vBlockV.push_back(tmpBlockV);
	}
}

CSprite* CAdventureMap::FindMapSprite(const char* szName)
{
	for(int i = 0;i < m_vBlockL.size();i++){
		if(strcmp(szName, m_vBlockL[i]->GetName()) == 0){
			return m_vBlockL[i];
		}
	}
	for(int i = 0;i < m_vBlockV.size();i++){
		if(strcmp(szName, m_vBlockV[i]->GetName()) == 0){
			return m_vBlockV[i];
		}
	}
}