#ifndef _SCENE_H_
#define _SCENE_H_
#include <iostream>
#include "CommonClass.h"
#include <vector>
using namespace std;
class Scene
{
protected:
	CSprite* doctor;
	CSprite* map;
	int mapcount;
	CSprite* letter;
    CSprite* book;
	CSprite* sofa;
    CSprite* dianshi;
	static CSprite* key0[6];
	static CSprite* key1[2];
	static CSprite* key2[3];
	CSprite* key3;
	CSprite* key4;
	static CSprite* key5[3];
	static CSprite* key6[2];
	static CSprite* key7[2];
    CSprite* decoration;
    CSprite* k[7];
	CSprite* plock;
    CSprite* phone;
	CSprite* keting;
public:
	vector<CSprite*> walls;
	vector<CSprite*> gos;
    vector<CSprite*> doors;
	static int wallcount;
	static int doorcount;
	static int gocount;
	void initKey0(int x, int y, int i, bool pflip);
	void initKey1(int x, int y, int i, bool pflip);
	void initKey2(int x, int y, int i, bool pflip);
	void initKey3(int x, int y, bool pflip);
	void initKey4(int x, int y, bool pflip);
	void initKey5(int x, int y, int i, bool pflip);
	void initKey6(int x, int y, int i, bool pflip);
	void initKey7(int x, int y, int i, bool pflip);
	CSprite* getKey0(int i);
	CSprite* getKey1(int i);
	CSprite* getKey2(int i);
	CSprite* getKey3();
	CSprite* getKey4();
	CSprite* getKey5(int i);
	CSprite* getKey6(int i);
	CSprite* getKey7(int i);
	CSprite* getDecoration();
    CSprite* getDianshi();
	CSprite* getSofa();
	CSprite* getBook();
	CSprite* getK(int i);
	CSprite* getLock();
    CSprite* getPhone();
	CSprite* getKeting();
	int getMapCount();
	CSprite* getLetter();
	CSprite* getDoctor();
	void move(double x, double y);
	vector<CSprite*> atlas;
	CSprite* getDoors(int i);
	double px, py;
	Scene();
	virtual void Init() = 0;
	void InitWall(double x, double y, double width = 2, double length = 15, bool pflip = false);
	void InitDoor(double x, double y, bool pflip = false);
	void InitGo(double x, double y, int pflip = 0 );
	virtual void InitMap(double x, double y) = 0;
	CSprite* getGos(int i);
	void Insert();
	void conceal(int wallstart, int wallend, int doorstart, int doorend, int gostart, int goend, bool wallhide = true, bool doorhide = true, bool gohide = true);    //隐藏或显示墙壁和门还有箭头
	void concealdoor(int doorstart, int doorend, bool doorhide = true);
	void concealwall(int wallstart, int wallend, bool wallhide = true);
	void concealgo(int gostart, int goend, bool gohide = true);
};
#endif