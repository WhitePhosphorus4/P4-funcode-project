#include "home.h"
Home::Home()
{
	choose = new CSprite("choose");
	black = new CSprite("black");
	black->SetSpriteColorAlpha(0);
	file = new CSprite("File");
	for(int i = 0; i < 7; i++)
	{
		score[i] = 0;
	}
	iscatch = -1;
	ishide = false;
	attack = false;
	x = -21.352;
	articlecount = 0;
	seeing = -1;
	for(int i = 0; i < 100; i++)
	{
		isget[i] = false;
	}
	exit = new CSprite("exit");
	text = new CTextSprite("text");
	deblocking = 1;
	count = 3;
	location = 0;
	for(int i = 0; i < 5; i++)
	{
		char name[50];
		sprintf(name, "text%d", i);
		texts[i] = new CTextSprite(name);
		texts[i]->SetSpriteVisible(1);
	}
	scene[0] = new StudyRoom();
	scene[1] = new Kitchen();
	scene[2] = new BedRoom();
	InitKnapsack();
	left = new CSprite("left");
	right = new CSprite("right");
}
void Home::show()
{
	text->SetTextString("请输入要去的地方");
	text->SetSpriteVisible(1);
	text->SetSpritePosition(0, 20);
	texts[0]->SetSpritePosition(-30, 25);
	texts[1]->SetSpritePosition(0, 25);
	texts[2]->SetSpritePosition(30, 25);
	texts[0]->SetTextString("书房");
	texts[1]->SetTextString("正厅");
	texts[2]->SetTextString("卧室");
}
void Home::show(char t0[50], char t1[50], char t2[50])
{
	text->SetTextString(t0);
	text->SetSpriteVisible(1);
	text->SetSpritePosition(0, 20);
	texts[3]->SetSpritePosition(-30, 25);
	texts[4]->SetSpritePosition(30, 25);
	texts[3]->SetTextString(t1);
	texts[4]->SetTextString(t2);
}
void Home::showMyKnapsack()
{
	for(int i = 0; i < articlecount; i++)
	{
		myknapsack[i]->SetSpriteWidth(7.3);
		myknapsack[i]->SetSpriteHeight(7.5);
		myknapsack[i]->SetSpritePosition(x + i * 7.3, 33.75);
		if(myknapsack[i]->GetSpritePositionX() < -25 || myknapsack[i]->GetSpritePositionX() > 20)myknapsack[i]->SetSpriteVisible(0);
		else myknapsack[i]->SetSpriteVisible(1);
		if(choose->GetSpritePositionX() < -25 || choose->GetSpritePositionX() > 20)choose->SetSpriteVisible(0);
		else choose->SetSpriteVisible(1);
	}
}
void Home::moveMyKnapsack(int j)
{
	x += j * 7.3;
	choose->SetSpritePositionX(choose->GetSpritePositionX() + j * 7.3);
}
void Home::hideMyKnapsack()
{
	for(int i = 0; i < articlecount; i++)
	{
		myknapsack[i]->SetSpritePositionY(100);
		choose->SetSpritePositionY(100);
	}
}
void Home::move(int l)
{
	if(location == l)
	{
		hide();
		return;
	}
	if(l == 1 && deblocking < 2) //进入关卡2
	{
		LevelState = 2;
		MapLoadingState = 1;
		deblocking = 2;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < scene[i]->atlas.size(); j++)
			{
				sx[i][j] = scene[i]->atlas[j]->GetSpritePositionX();
				sy[i][j] = scene[i]->atlas[j]->GetSpritePositionY();
			}
		}
	}
	if(l == 2 && deblocking == 2)
	{
		if(!attack)
		{
			show("总感觉还有地方没有搜查过", "", "");
			return;
		}
		else             //进入关卡3
		{
		LevelState = 3;
		MapLoadingState = 1;
		deblocking = 3;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < scene[i]->atlas.size(); j++)
			{
				sx[i][j] = scene[i]->atlas[j]->GetSpritePositionX();
				sy[i][j] = scene[i]->atlas[j]->GetSpritePositionY();
			}
		}
		}
	}
	else if(l == 2 && deblocking == 1)
	{
		show("目前到不了这个地方", "", "");
		return;
	}
	double lengthy = scene[location]->py - scene[l]->py;
	double lengthx = scene[location]->px - scene[l]->px;
	scene[location]->move(lengthx, lengthy);
	scene[l]->move(lengthx, lengthy);
	location = l;
	hide();
}
void Home::hide()
{
	text->SetSpritePosition(0, 100);
	texts[0]->SetSpritePosition(-30, 100);
	texts[1]->SetSpritePosition(0, 100);
	texts[2]->SetSpritePosition(30, 100);
	texts[3]->SetSpritePosition(-30, 100);
	texts[4]->SetSpritePosition(30, 100);
}
int Home::getLocation()
{
	return location;
}
void Home::InitKnapsack()
{
	CSprite* article;
	article = new CSprite("letter1");
	article->SetSpritePosition(0, 100);
	knapsack.push_back(article);
	for(int i = 0; i <= 7; i++)
	{
		char name[50];
		sprintf(name, "b%d", i);
		article = new CSprite(name);
		article->SetSpritePosition(0, 100);
		knapsack.push_back(article);
	}
}
CSprite* Home::getKnapsack(int i)
{
	return knapsack[i];
}
void Home::getNext()
{
	if(seeing == 0)
	{
		knapsack[seeing]->SetSpritePosition(0, 0);
		return;
	}
	if(seeing == 1 || seeing == 2)
	{
		knapsack[seeing++]->SetSpritePosition(0, 100);
		knapsack[seeing]->SetSpritePosition(0, 0);
		return;
	}
	if(seeing > 2 && seeing < 7)
	{
		knapsack[++seeing]->SetSpritePosition(13.285, -5);
		return;
	}
	if(seeing == 7)
	{
		for(int i = 3; i <= 7; i++)
		{
			knapsack[i]->SetSpritePosition(0, 100);
		}
		knapsack[++seeing]->SetSpritePosition(0, 0);
		return;
	}
	knapsack[seeing]->SetSpritePosition(0, 100);
	seeing = -1;
}
