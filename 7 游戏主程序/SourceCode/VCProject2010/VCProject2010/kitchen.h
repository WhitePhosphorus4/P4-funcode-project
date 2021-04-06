#include "scene.h"
class Kitchen : public Scene
{
protected:
	CSprite* canzhuo;
	CSprite* zaotai;
public:
	Kitchen();
	void Init();
	void InitMap(double x, double y);
};