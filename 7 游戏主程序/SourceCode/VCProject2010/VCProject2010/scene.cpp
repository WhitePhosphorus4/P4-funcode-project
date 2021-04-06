#include "scene.h"
void Scene::move(double lengthx, double lengthy)
{
	px += lengthx;
	py += lengthy;
	for(int i = 0; i < atlas.size(); i++)
	{
		double x = atlas[i]->GetSpritePositionX();
		double y = atlas[i]->GetSpritePositionY();
		atlas[i]->SetSpritePosition(x + lengthx, y + lengthy);
	}
}
Scene::Scene()
{
	
}
CSprite* Scene::getGos(int i)
{
	return gos[i];
}
CSprite* Scene::getDoors(int i)
{
	return doors[i];
}
void Scene::Insert()
{
	atlas.insert(atlas.end(), gos.begin(), gos.end());
	atlas.insert(atlas.end(), walls.begin(), walls.end());
	atlas.insert(atlas.end(), doors.begin(), doors.end());
}
void Scene::conceal(int wallstart, int wallend, int doorstart, int doorend, int gostart, int goend, bool wallhide, bool doorhide, bool gohide)
{
	concealwall(wallstart, wallend, wallhide);
	concealdoor(doorstart, doorend, doorhide);
	concealgo(gostart, goend, gohide);
}
void Scene::concealdoor(int doorstart, int doorend, bool doorhide)
{
	if(doorhide)
	for(int i = doorstart; i <= doorend; i++)
	{
		doors[i]->SetSpriteVisible(0);
	}
	else
	for(int i = doorstart; i <= doorend; i++)
	{
		doors[i]->SetSpriteVisible(1);
	}
}
void Scene::concealwall(int wallstart, int wallend, bool wallhide)
{
	if(wallhide)
	for(int i = wallstart; i <= wallend; i++)
	{
		walls[i]->SetSpriteVisible(0);
	}
	else
	for(int i = wallstart; i <= wallend; i++)
	{
		walls[i]->SetSpriteVisible(1);
	}
}
void Scene::concealgo(int gostart, int goend, bool gohide)
{
	if(gohide)
	for(int i = gostart; i <= goend; i++)
	{
		gos[i]->SetSpriteVisible(0);
	}
	else
	for(int i = gostart; i <= goend; i++)
	{
		gos[i]->SetSpriteVisible(1);
	}
}
void Scene::InitWall(double x, double y, double width, double length, bool pflip)
{
	CSprite* wall;
	char* name;
	name = CSystem::MakeSpriteName("wall", wallcount++);
	wall = new CSprite(name);
	wall->CloneSprite("wall");
	wall->SetSpritePosition(px + x, py + y);
	wall->SetSpriteWidth(width);
	wall->SetSpriteHeight(length);
	if(pflip)wall->SpriteRotateTo(90, 1000, true);
	wall->SetSpriteCollisionActive(0,1);
	wall->SetSpriteCollisionResponse(COL_RESPONSE_CUSTOM);
	walls.push_back(wall);
}
void Scene::InitDoor(double x, double y, bool pflip)
{
	CSprite* door;
	char* name;
	name = CSystem::MakeSpriteName("door", doorcount++);
	door = new CSprite(name);
	door->CloneSprite("door");
	door->SetSpritePosition(px + x, py + y);
	if(pflip)door->SpriteRotateTo(90, 1000, true);
	door->SetSpriteCollisionActive(0,1);
	door->SetSpriteCollisionResponse(COL_RESPONSE_CUSTOM);
	doors.push_back(door);
}
void Scene::InitGo(double x, double y, int pflip)
{
	CSprite* go;
	char* name;
	name = CSystem::MakeSpriteName("go", gocount++);
	go = new CSprite(name);
	go->CloneSprite("go");
	go->SetSpritePosition(px + x, py + y);
	switch(pflip)
	{
	case 0:
		break;
	case 1:
		go->SpriteRotateTo(90, 1000, true);
		break;
	case 2:
		go->SpriteRotateTo(180, 1000, true);
		break;
	case 3:
		go->SpriteRotateTo(-90, 1000, true);
		break;
	}
	gos.push_back(go);
}
CSprite* Scene::getLetter()
{
	return letter;
}
int Scene::getMapCount()
{
	return mapcount;
}
CSprite* Scene::getBook()
{
	return book;
}
CSprite* Scene::getSofa()
{
	return sofa;
}
CSprite* Scene::getDianshi()
{
	return dianshi;
}
CSprite* Scene::getDecoration()
{
	return decoration;
}
CSprite* Scene::getKey0(int i)
{
	return key0[i];
}
CSprite* Scene::getKey1(int i)
{
	return key1[i];
}
CSprite* Scene::getKey2(int i)
{
	return key2[i];
}
CSprite* Scene::getKey3()
{
	return key3;
}
CSprite* Scene::getKey4()
{
	return key4;
}
CSprite* Scene::getKey5(int i)
{
	return key5[i];
}
CSprite* Scene::getKey6(int i)
{
	return key6[i];
}
CSprite* Scene::getKey7(int i)
{
	return key7[i];
}
void Scene::initKey0(int x, int y, int i, bool pflip)
{
	CSprite* key;
	char* name;
	name = CSystem::MakeSpriteName("key0", i);
	key = new CSprite(name);
	key->CloneSprite("key0");
	key->SetSpritePosition(px + x, py + y);
	if(pflip)key->SpriteRotateTo(90, 1000, true);
	key->SetSpriteVisible(0);
	key0[i] = key;
	atlas.push_back(key);
}
void Scene::initKey1(int x, int y, int i, bool pflip)
{
	CSprite* key;
	char* name;
	name = CSystem::MakeSpriteName("key1", i);
	key = new CSprite(name);
	key->CloneSprite("key1");
	key->SetSpritePosition(px + x, py + y);
	if(pflip)key->SpriteRotateTo(90, 1000, true);
	key->SetSpriteVisible(0);
	key1[i] = key;
	atlas.push_back(key);
}
void Scene::initKey2(int x, int y, int i, bool pflip)
{
	CSprite* key;
	char* name;
	name = CSystem::MakeSpriteName("key2", i);
	key = new CSprite(name);
	key->CloneSprite("key2");
	key->SetSpritePosition(px + x, py + y);
	if(pflip)key->SpriteRotateTo(90, 1000, true);
	key->SetSpriteVisible(0);
	key2[i] = key;
	atlas.push_back(key);
}
void Scene::initKey3(int x, int y, bool pflip)
{
	key3 = new CSprite("key3");
	key3->SetSpritePosition(px + x, py + y);
	if(pflip)key3->SpriteRotateTo(90, 1000, true);
	key3->SetSpriteVisible(0);
	atlas.push_back(key3);
}
void Scene::initKey4(int x, int y, bool pflip)
{
	key4 = new CSprite("key4");
	key4->SetSpritePosition(px + x, py + y);
	if(pflip)key4->SpriteRotateTo(90, 1000, true);
	key4->SetSpriteVisible(0);
	atlas.push_back(key4);
}
void Scene::initKey5(int x, int y, int i, bool pflip)
{
	CSprite* key;
	char* name;
	name = CSystem::MakeSpriteName("key5", i);
	key = new CSprite(name);
	key->CloneSprite("key5");
	key->SetSpritePosition(px + x, py + y);
	if(pflip)key->SpriteRotateTo(90, 1000, true);
	key->SetSpriteVisible(0);
	key5[i] = key;
	atlas.push_back(key);
}
void Scene::initKey6(int x, int y, int i, bool pflip)
{
	CSprite* key;
	char* name;
	name = CSystem::MakeSpriteName("key6", i);
	key = new CSprite(name);
	key->CloneSprite("key6");
	key->SetSpritePosition(px + x, py + y);
	if(pflip)key->SpriteRotateTo(90, 1000, true);
	key->SetSpriteVisible(0);
	key6[i] = key;
	atlas.push_back(key);
}
void Scene::initKey7(int x, int y, int i, bool pflip)
{
	CSprite* key;
	char* name;
	name = CSystem::MakeSpriteName("key7", i);
	key = new CSprite(name);
	key->CloneSprite("key7");
	key->SetSpritePosition(px + x, py + y);
	if(pflip)key->SpriteRotateTo(90, 1000, true);
	key->SetSpriteVisible(0);
	key7[i] = key;
	atlas.push_back(key);
}
CSprite* Scene::getDoctor()
{
	return doctor;
}
CSprite* Scene::getK(int i)
{
	return k[i];
}
CSprite* Scene::getLock()
{
	return plock;
}
CSprite* Scene::getPhone()
{
	return phone;
}
CSprite* Scene::getKeting()
{
	return keting;
}
int Scene::doorcount = 0;
int Scene::wallcount = 0;
int Scene::gocount = 0;
/*int Scene::key0count = 0;
int Scene::key1count = 0;
int Scene::key2count = 0;
int Scene::key5count = 0;
int Scene::key6count = 0;
int Scene::key7count = 0;*/
CSprite* Scene::key0[6] = {NULL};
CSprite* Scene::key1[2] = {NULL};
CSprite* Scene::key2[3] = {NULL};
CSprite* Scene::key5[3] = {NULL};
CSprite* Scene::key6[2] = {NULL};
CSprite* Scene::key7[2] = {NULL};









