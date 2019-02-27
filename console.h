#ifndef CONSOLE_H
#define CONSOLE_H
#include "pch.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#define MENU_ITEMS 2

class Menu
{
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MENU_ITEMS];
public:
	Menu(float width, float height);
	void draw(sf::RenderWindow & window);
	void moveUp();
	void moveDown();
	int getPressedItem();
};

class TextWindows
{
protected:
	float Xcoord;
	float Ycoord;
	float width;
	float height;
	unsigned int r, g, b;
	unsigned int r_text;
	unsigned int g_text;
	unsigned int b_text;
	unsigned int fontSize;
	std::string chosenText;
public:
	void drawTextWindows();
	void getWindowColor();
	std::string chooseText();
	void getFontColor();
	unsigned int getFontSize();
	void getFontCoordinates();
};

class Windows : public TextWindows
{
public:
	void drawWindows();
};
#endif