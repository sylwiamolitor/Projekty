#pragma once
#include <fstream>
#include "Game.h"
#include "MyButton.h"
#include <TGUI/TGUI.hpp>
using namespace std;

class GuiButton: public MyButton, public tgui::Button
{
	tgui::Button::Ptr m_button;
	int textSize;
public:
	GuiButton(int pPosX, int pPosY, int pSize, string pText, int pTextSize) :MyButton(pPosX, pPosY, pSize,pText)
	{
		textSize = pTextSize;
		this->create();
		this->setText(buttonText);
		this->setSize(size+50,size);
		this->setPosition(posX, posY);
		
		this->setInheritedFont("BebasNeue-Regular.ttf");
		this->setTextSize(textSize);
	};
	FloatRect gGlobalBounds();
	void Draw(RenderWindow &window);
	void changeColor(Color textColor);
	bool containsMouse(Vector2f & mouse);
};