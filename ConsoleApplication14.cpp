#include "pch.h"
#include "console.h"

int main()
{
	Windows windows;
	TextWindows textwindows;
	sf::RenderWindow window(sf::VideoMode(800, 500), "Menu", sf::Style::Default);
	Menu menu(600, 600);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.moveUp();
					break;
				case sf::Keyboard::Down:
					menu.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (menu.getPressedItem())
					{
					case 0:
						system("CLS");
						windows.getWindowColor();
						windows.drawWindows();
						break;
					case 1:
						system("CLS");
						textwindows.getWindowColor();
						textwindows.getFontColor();
						textwindows.getFontSize();
						textwindows.getFontCoordinates();
						textwindows.chooseText();
						textwindows.drawTextWindows();
						break;
					case 2:
						window.close();
						break;
					}
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		window.clear();
		menu.draw(window);
		window.display();
	}
}
