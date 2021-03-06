#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "GraphicalObject.h"
#include "Animal.h"
using namespace std;
using namespace sf;

class DynamicObject :public GraphicalObject
{
public:
	DynamicObject(int pPosX, int pPosY, int pSize) :GraphicalObject(pPosX, pPosY, pSize) {};
	virtual void update(Animal*&animal, RenderWindow &window)=0;
	virtual void drawDynamicObject(RenderWindow &window)=0;
};