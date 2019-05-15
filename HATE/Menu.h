#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

void menu(RenderWindow & window) 
{
	Texture menuTexture1, menuTexture2, menuTexture3, menuBackground;
	menuTexture1.loadFromFile("images/111.png");
	menuTexture2.loadFromFile("images/222.png");
	menuTexture3.loadFromFile("images/333.png");
	menuBackground.loadFromFile("images/background.jpg");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menuBg(menuBackground);
	
	Image icon;
	icon.loadFromFile("images/icon.png");
	window.setIcon(32, 32, icon.getPixelsPtr());

	Music menu;
	menu.openFromFile("menu.ogg");
	menu.play();

	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(100, 30);
	menu2.setPosition(100, 90);
	menu3.setPosition(100, 150);
	menuBg.setPosition(0, 0);

	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window)))
		{
			menu1.setColor(Color::Blue); 
			menuNum = 1;
		}
		if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window)))
		{
			menu2.setColor(Color::Blue);
			menuNum = 2; 
		}
		if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window)))
		{ 
			menu3.setColor(Color::Blue); menuNum = 3; 
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1)
			{
				isMenu = false;
			} 
			if (menuNum == 2)
			{
				isMenu = false; 
			}
			if (menuNum == 3) 
			{
				window.close();
				isMenu = false; 
			}

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
}