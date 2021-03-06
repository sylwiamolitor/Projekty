#pragma once
#include "Animal.h"

class Cat: public Animal
{
public:
	Cat() {};
	Cat(string imgDirectory, int pPosX, int pPosY, int pSize) :Animal(imgDirectory, pPosX, pPosY, pSize)
	{
		this->setTexture(animalTexture);
		this->setPosition(posX,posY);
		this->setScale(size,size);
		enableWalking = 0;
	}
	void moveAnimal(char direction, float moveSpeed);
	void eat();
	void sleep();
	void play();
	void setInitialPosition();
};