#include "kitchen.h"
Kitchen::Kitchen()
{
	mapcount = 4;
	InitMap(0, 768);
	atlas[0]->SetSpriteVisible(1);
	Init();
	concealgo(3, 5);
}
void Kitchen::Init()
{
	InitDoor(0, -36.5, true);
	InitDoor(-49, -20);
	InitDoor(-46, -5, true);
	InitDoor(46, -5, true);
	InitDoor(0, 15, true);
	InitDoor(6, -3);
	InitWall(-25, -36.5, 2, 48, true);
	InitWall(25, -36.5, 2, 48, true);
	InitWall(0, -5, 2, 90, true);
	InitWall(-25, 15, 2, 50, true);
	InitWall(4, 15, 2, 4, true);
	InitWall(-49, -30, 2, 20);
	InitWall(-49, 12, 2, 60);
	InitWall(49, 0, 2, 80);
	InitWall(0, 36.5, 2, 100, true);
	InitWall(6, 18, 2, 38);
	InitGo(-40, -20);
	InitGo(0, -28, 1);
	InitGo(0, 5, 3);
	InitGo(-10, 15, 1);
	InitGo(15, 15, 2);
	InitGo(38, 25, 3);
	initKey4(14, 24, false);
	initKey5(-32, 14, 0, false);
	initKey6(-24.25, -14.25, 0, false);
	canzhuo = new CSprite("canzhuo");
	canzhuo->SetSpritePosition(px, py - 15);
	atlas.push_back(canzhuo);
	zaotai = new CSprite("zaotai0");
	zaotai->SetSpritePosition(px - 27, py - 34);
	atlas.push_back(zaotai);
	zaotai = new CSprite("zaotai1");
	zaotai->SetSpritePosition(px - 36, py - 34);
	atlas.push_back(zaotai);
	zaotai = new CSprite("zaotai2");
	zaotai->SetSpritePosition(px - 44, py - 31);
	atlas.push_back(zaotai);
	dianshi = new CSprite("dianshi");
	dianshi->SetSpritePosition(px + 26.75, py + 5);
	atlas.push_back(dianshi);
	keting = new CSprite("keting1");
	keting->SetSpritePosition(px + 26.75, py + 10.8);
	atlas.push_back(keting);
	keting = new CSprite("keting2");
	keting->SetSpritePosition(px + 15.619, py + 12);
	atlas.push_back(keting);
	keting = new CSprite("keting3");
	keting->SetSpritePosition(px + 37.875, py + 12);
	atlas.push_back(keting);
	keting = new CSprite("keting0");
	keting->SetSpritePosition(px + 26.75, py + 21.563);
	atlas.push_back(keting);
	decoration = new CSprite("zhuangshi0");
	decoration->SetSpritePosition(px, py - 15);
	atlas.push_back(decoration);
	doctor = new CSprite("doctor");
	doctor->SetSpriteVisible(0);
	doctor->SetSpritePosition(px - 2, py + 22);
	atlas.push_back(doctor);
	phone = new CSprite("phone");
	phone->SetSpriteVisible(0);
	phone->SetSpritePosition(px + 44, py + 19);
	atlas.push_back(phone);
	Insert();
}
void Kitchen::InitMap(double x, double y)
{
	px = x;
	py = y;
	char name[50];
	for(int i = 0; i < mapcount; i++)
	{
		sprintf(name, "kitchen%d", i);
		map = new CSprite(name);
		map->SetSpriteVisible(0);
		atlas.push_back(map);
		atlas[i]->SetSpritePosition(px, py);
	}
}
