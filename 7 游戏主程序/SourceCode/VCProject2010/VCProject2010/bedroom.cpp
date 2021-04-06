#include "bedroom.h"
BedRoom::BedRoom()
{
	mapcount = 6;
	InitMap(1360, 768);
	atlas[0]->SetSpriteVisible(1);
	Init();
	concealgo(4, 7);
}
void BedRoom::Init()
{
	InitWall(-20, -30);
	InitWall(-20, -10);
	InitWall(-35, -2, 2, 32, true);
	InitWall(20, -30);
	InitWall(20, -10);
	InitWall(35, -2, 2, 32, true);
	InitDoor(-20, -20);
	InitDoor(20, -20);
	InitDoor(0, -37, true);
	InitGo(0, 0, 3);
	InitGo(13, -20, 2);
	InitGo(-13, -20);
	InitGo(0, -30, 1);
	InitGo(-40, 30);
	InitGo(30, 30, 2);
	InitGo(-40, 30);
	InitGo(0, 25, 1);
	initKey7(17, -12, 0, false);
	for(int i = 0; i < 7; i++)
	{
		char name[50];
		sprintf(name, "k%d", i);
		k[i] = new CSprite(name);
		k[i]->SetSpriteVisible(0);
	}
	plock = new CSprite("lock");
	plock->SetSpritePosition(px - 37.971, py - 13.294);
	plock->SetSpriteVisible(0);
	atlas.push_back(plock);
	Insert();
}
void BedRoom::InitMap(double x, double y)
{
	px = x;
	py = y;
	char name[50];
	for(int i = 0; i < mapcount; i++)
	{
		sprintf(name, "bedroom%d", i);
		map = new CSprite(name);
		map->SetSpriteVisible(0);
		atlas.push_back(map);
		atlas[i]->SetSpritePosition(px, py);
	}
}
