#include "pch.h"
#include "console.h"


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("RAVIE.ttf"))
	{
		std::cerr << "Error! Failed to open the font file!" << std::endl;
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Green);
	menu[0].setString("Window");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MENU_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Text Window");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MENU_ITEMS + 1) * 2));
	selectedItemIndex = 0;
}
void Menu::draw(sf::RenderWindow & window)
{
	for (auto i = 0; i < MENU_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}
void Menu::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Green);
	}
}
void Menu::moveDown()
{
	if (selectedItemIndex + 1 < MENU_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Green);
	}
}
int Menu::getPressedItem()
{
	return selectedItemIndex;
}

void TextWindows::drawTextWindows()
{
	std::cout << std::endl << "Enter width and height for your Text Window!" << std::endl;
	std::cin >> width >> height;
	sf::RenderWindow window(sf::VideoMode(width, height), "Text Window", sf::Style::None);
	sf::Font font;
	if (!font.loadFromFile("RAVIE.ttf"))
	{
		std::cerr << "Error! Failed to read the font file!" << std::endl;
	}
	sf::Text text;
	text.setFont(font);
	text.setString(chosenText);
	text.setCharacterSize(fontSize);
	text.setPosition(Xcoord, Ycoord);
	text.setFillColor(sf::Color(r_text, g_text, b_text));
	text.setStyle(sf::Text::Style::Bold | sf::Text::Style::Italic);
	
	while (window.isOpen())
	{
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			switch (Event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				std::cout << "New Text Window width: " << Event.size.width << " and height: " << Event.size.height << std::endl;
				break;
			case sf::Event::TextEntered:
				if (Event.text.unicode < 128)
				{
					/*std::cout << Event.text.unicode;*/
					printf("%c", Event.text.unicode);
				}
				break;
			}
		}
		window.clear(sf::Color(r, g, b));
		window.draw(text);
		window.display();
	}
}
void TextWindows::getWindowColor()
{
	std::cout << "What color do you wish your Window to be?" << std::endl << std::endl;
	std::cout << "1.) Black" << std::endl;
	std::cout << "2.) Gray" << std::endl;
	std::cout << "3.) Red" << std::endl;
	std::cout << "4.) Green" << std::endl;
	std::cout << "5.) Blue" << std::endl;
	std::cout << "6.) Yellow" << std::endl;
	std::cout << "7.) Magenta" << std::endl;
	std::cout << "8.) Cyan" << std::endl;
	std::cout << "9.) Purple" << std::endl << std::endl;
	int myColor;
	std::cin >> myColor;
	switch (myColor)
	{
	case 1:
		r = 0;
		g = 0;
		b = 0;
		break;
	case 2:
		r = 128;
		g = 128;
		b = 128;
		break;
	case 3:
		r = 255;
		g = 0;
		b = 0;
		break;
	case 4:
		r = 0;
		g = 255;
		b = 0;
		break;
	case 5:
		r = 0;
		g = 0;
		b = 255;
		break;
	case 6:
		r = 255;
		g = 255;
		b = 0;
		break;
	case 7:
		r = 255;
		g = 0;
		b = 255;
		break;
	case 8:
		r = 0;
		g = 255;
		b = 255;
		break;
	case 9:
		r = 128;
		g = 0;
		b = 128;
		break;
	}
	system("CLS");
}
std::string TextWindows::chooseText()
{
	std::cout << std::endl << "Enter the text that you wish to display on your Text Window!" << std::endl;
	std::cin.ignore();
	getline(std::cin, chosenText);
	return chosenText;
}
void TextWindows::getFontColor()
{
	std::cout << "What color do you wish your text to be?" << std::endl << std::endl;
	std::cout << "1.) Black" << std::endl;
	std::cout << "2.) Gray" << std::endl;
	std::cout << "3.) Red" << std::endl;
	std::cout << "4.) Green" << std::endl;
	std::cout << "5.) Blue" << std::endl;
	std::cout << "6.) Yellow" << std::endl;
	std::cout << "7.) Magenta" << std::endl;
	std::cout << "8.) Cyan" << std::endl;
	std::cout << "9.) Purple" << std::endl << std::endl;
	int myColor;
	std::cin >> myColor;
	switch (myColor)
	{
	case 1:
		r_text = 0;
		g_text = 0;
		b_text = 0;
		break;
	case 2:
		r_text = 128;
		g_text = 128;
		b_text = 128;
		break;
	case 3:
		r_text = 255;
		g_text = 0;
		b_text = 0;
		break;
	case 4:
		r_text = 0;
		g_text = 255;
		b_text = 0;
		break;
	case 5:
		r_text = 0;
		g_text = 0;
		b_text = 255;
		break;
	case 6:
		r_text = 255;
		g_text = 255;
		b_text = 0;
		break;
	case 7:
		r_text = 255;
		g_text = 0;
		b_text = 255;
		break;
	case 8:
		r_text = 0;
		g_text = 255;
		b = 255;
		break;
	case 9:
		r_text = 128;
		g_text = 0;
		b = 128;
		break;
	}
	system("CLS");
}
unsigned int TextWindows::getFontSize()
{
	std::cout << std::endl << "What size do you wish your text to be?" << std::endl;
	std::cin >> fontSize;
	return fontSize;
}
void TextWindows::getFontCoordinates()
{
	std::cout << std::endl << "Enter the X and Y coordinates for your Text on a Window!" << std::endl;
	std::cin >> Xcoord >> Ycoord;
}


void Windows::drawWindows()
{
	int width, height;
	std::cout << std::endl << "Enter width and height for your Window!" << std::endl;
	std::cin >> width >> height;
	sf::RenderWindow window(sf::VideoMode(width, height), "Window", sf::Style::Default);
	while (window.isOpen())
	{
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			switch (Event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				std::cout << "New Window width: " << Event.size.width << " and height: " << Event.size.height << std::endl;
				break;
			case sf::Event::TextEntered:
				if (Event.text.unicode < 128)
				{
					/*std::cout << Event.text.unicode;*/
					printf("%c", Event.text.unicode);
				}
				break;
			}
		}
		window.clear(sf::Color(r, g, b));
		window.display();
	}
}

