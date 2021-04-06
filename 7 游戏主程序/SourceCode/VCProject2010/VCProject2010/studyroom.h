#include "scene.h"
class StudyRoom : public Scene
{
protected:
	CSprite* bookrack;
	CSprite* table;
	CSprite* desk;
public:
	StudyRoom();
	void Init();
	void InitMap(double x, double y);
};