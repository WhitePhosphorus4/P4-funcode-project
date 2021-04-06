#include "studyroom.h"
StudyRoom::StudyRoom()
{
	mapcount = 6;
	InitMap(-1360, 768);
	atlas[0]->SetSpriteVisible(1);
	Init();
	concealgo(3, 7);
}
void StudyRoom::Init()
{
	bookrack = new CSprite("bookrack0");
	bookrack->SetSpritePosition(px - 44, py - 23.24);
	atlas.push_back(bookrack);
	bookrack = new CSprite("bookrack1");
	bookrack->SetSpritePosition(px - 28.24, py - 30.925);
	atlas.push_back(bookrack);
	bookrack = new CSprite("bookrack2");
	bookrack->SetSpritePosition(px + 12.884, py + 15.241);
	atlas.push_back(bookrack);
	bookrack = new CSprite("bookrack3");
	bookrack->SetSpritePosition(px + 4.936, py + 31.075);
	atlas.push_back(bookrack);
	table = new CSprite("table0");
	table->SetSpritePosition(px + 5.14, py - 23.75);
	atlas.push_back(table);
	sofa = new CSprite("sofa0");
	sofa->SetSpritePosition(px - 44.766, py + 4.648);
	atlas.push_back(sofa);
	desk = new CSprite("desk");
	desk->SetSpritePosition(px - 1.784, py + 15.743);
	atlas.push_back(desk);
	letter = new CSprite("letter");
	letter->SetSpritePosition(px + 12, py + 13);
	letter->SetSpriteVisible(0);
	atlas.push_back(letter);
	book = new CSprite("book");
	book->SetSpritePosition(px + 1.953, py - 8);
	book->SetSpriteVisible(0);
	atlas.push_back(book);
	initKey0(-23, 12, 0, false);
	initKey1(12, 13, 0, false);
	initKey2(-5, 9.25, 0, true);
	initKey3(-15, -15.75, true);
	InitWall(-33, -36, 2, 34, true);
	InitWall(-49, -10, 2, 55);
	InitWall(17.622, 19.5, 2, 35);
	InitWall(18.977, -25.127, 2, 24.747);
	InitWall(5.14, -36, 2, 26.263, true);
	InitWall(-20, 36, 2, 75, true);
	InitGo(-11, -22, 1);
	InitGo(-40, 27);
	InitGo(14, -3, 2);
	InitGo(42, 24, 3);
	InitGo(-20, 0);
	InitGo(0, 24, 2);
	InitGo(10, 10, 1);
	InitGo(45, 30, 3);
	Insert();
}
void StudyRoom::InitMap(double x, double y)
{
	px = x;
	py = y;
	char name[50];
	for(int i = 0; i < mapcount; i++)
	{
		sprintf(name, "studyroom%d", i);
		map = new CSprite(name);
		map->SetSpriteVisible(0);
		atlas.push_back(map);
		atlas[i]->SetSpritePosition(px, py);
	}
}




