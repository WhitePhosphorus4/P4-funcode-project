#include "bedroom.h"
#include "studyroom.h"
#include "kitchen.h"
class Home : public BedRoom, StudyRoom, Kitchen
{
protected:
	int location;  //0代表第一个场景，以此类推
	int deblocking;  //解锁
	int count;    //场景数量
	CTextSprite* text;
    vector<CSprite*> knapsack;
public:
	CSprite* choose;
	double sx[3][100];
	double sy[3][100];
	CSprite* black;
    int getDeblocking(){ return deblocking;}
	void setDeblocking(int i){ deblocking = i;}
	int iscatch;
    CSprite* file;
	CSprite* last;
	bool ishide;
	bool attack;
	double x;
	int score[7];
	CSprite* left;
	CSprite* right;
	double getGoPositionX(int i, int j)
	{
		return scene[i]->getGos(j)->GetSpritePositionX();
	}
	double getGoPositionY(int i, int j)
	{
		return scene[i]->getGos(j)->GetSpritePositionY();
	}
	double getAtlasPositionX(int i, int j)
	{
		return scene[i]->atlas[j]->GetSpritePositionX();
	}
	double getAtlasPositionY(int i, int j)
	{
		return scene[i]->atlas[j]->GetSpritePositionY();
	}
	CSprite* findArticle(char name[50]);
	void showMyKnapsack();
	void hideMyKnapsack();
	void moveMyKnapsack(int j);
	int seeing;
	void getNext();
	bool isget[100];
	Scene* scene[3];
	void InitKnapsack();
	CSprite* getKnapsack(int i);
    CTextSprite* texts[5];
	CSprite* exit;
	Home();
	int articlecount;  //背包物件数量
	vector<CSprite*> myknapsack;
	void show();
	void move(int l);
	void hide();
	int getLocation();
    void show(char t0[50], char t1[50], char t2[50]);
};
