#pragma once
//=============================================================================================
#include "commonclass.h"
#include "vector"
using namespace std;
//=============================================================================================
class CAdventureMap													//独立类型 用于存储地图信息 背景信息
{
private:
	//地图精灵存储向量=========================================================================
	vector<CSprite*>m_vBlockL;										//水平地图精灵保存向量						
	vector<CSprite*>m_vBlockV;										//垂直题图精灵保存向量
public:
	//构造与析构函数===========================================================================
	CAdventureMap(void);										
	~CAdventureMap(void);
	//基本功能函数====================================================================================
	void			SetMapInfo(int iNumBlockL, int iNumBlockV);		//存储地图信息函数
	CSprite*		FindMapSprite(const char* szName);				//查找函数 通过地图名称找到特定地图精灵 返回指针
};

