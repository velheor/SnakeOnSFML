#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <time.h>
#include <windows.h>
#include <iomanip>
#include "Menu.h"
#include "Map1.h"
#include "Map2.h"
#include "Map3.h"
#include "Map4.h"
#include "Map5.h"
#include "Map6.h"


using namespace sf;

using namespace std;

struct Snake
{
	int x = 0, y = 0;
}  s[100];

struct Fruit
{
	int x, y;
} f;

struct Levels
{
	int l;
}level[7];

int main();

void sleep()
{
	Sleep(15000);
}

void end(RenderWindow & window)
{
	Texture end;
	end.loadFromFile("images/died.png");
	Sprite sprite1(end);
	window.clear();

	Music music;
	music.openFromFile("died.ogg");
	music.play();
	sprite1.setPosition(0, 0);
	window.draw(sprite1);
	window.display();
	Sleep(7500);
	window.close();
	main();
}

void saving(int &numberLevel, int &score, int &game, int &direction, int &length)
{
	ofstream saves;
	saves.open("saves.txt");
	saves << s[0].x << endl;
	saves << s[0].y << endl;
	saves << numberLevel << endl;
	saves << score << endl;
	saves << game << endl;
	saves << direction << endl;
	saves << length << endl;
	
	for (int i = 1; i < length; i++)
	{
		saves << s[i].x << endl;
		saves << s[i].y << endl;
	}
	
	saves.close();
}

void loading(int &numberLevel, int &score, int &game, int &direction, int &length)
{
	ifstream saves;
	saves.open("saves.txt");

	saves >> s[0].x;
	saves >> s[0].y;
	saves >> numberLevel;
	saves >> score;
	saves >> game;
	saves >> direction;
	saves >> length;
	for (int i = 1; i < length; i++)
	{
		saves >> s[i].x;
		saves >> s[i].y;
	}

	saves.close();
}

void Move(int &numberLevel, int &score,int &game, int &size, int &direction, int &length)
{
	for (int i = length; i > 0; --i) 
	{
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
	}

	if (direction == 0) 
	{
		s[0].y += 1;
	}
	if (direction == 1) 
	{
		s[0].x -= 1;
	}
	if (direction == 2)
	{
		s[0].x += 1;
	}
	if (direction == 3) 
	{
		s[0].y -= 1;
	}

	if ((s[0].x == f.x) && (s[0].y == f.y))
	{
		score += 10;
		length++;
		f.x = rand() % width;
		f.y = rand() % height;
	}
	if (s[0].x > width - 1 || s[0].x < 0 || s[0].y > height - 1 || s[0].y < 0)
	{
		game = 1;
	}

	switch (numberLevel)
	{
	case 1:
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (s[0].x == i && s[0].y == j && TileMap1[i][j] == 'w')
				{
					game = 1;
				}
			}
		}
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				for (int v = 0; v < length; v++)
				{
					if ((f.x == s[v].x && f.y == s[v].y) || (f.x == i && f.y == j && TileMap1[i][j] == 'w'))
					{
						f.x = rand() % width;
						f.y = rand() % height;
						v = 0;
						i = 0;
						j = 0;
					}
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (s[0].x == i && s[0].y == j && TileMap2[i][j] == 'w')
				{
					game = 1;
				}
			}
		}
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				for (int v = 0; v < length; v++)
				{
					if ((f.x == s[v].x && f.y == s[v].y) || (f.x == i && f.y == j && TileMap2[i][j] == 'w'))
					{
						f.x = rand() % width;
						f.y = rand() % height;
						v = 0;
						i = 0;
						j = 0;
					}
				}
			}
		}
		break;
	case 3:
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (s[0].x == i && s[0].y == j && TileMap3[i][j] == 'w')
				{
					game = 1;
				}
			}
		}
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				for (int v = 0; v < length; v++)
				{
					if ((f.x == s[v].x && f.y == s[v].y) || (f.x == i && f.y == j && TileMap3[i][j] == 'w'))
					{
						f.x = rand() % width;
						f.y = rand() % height;
						v = 0;
						i = 0;
						j = 0;
					}
				}
			}
		}
		break;
	case 4:
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (s[0].x == i && s[0].y == j && TileMap4[i][j] == 'w')
				{
					game = 1;
				}
			}
		}
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				for (int v = 0; v < length; v++)
				{
					if ((f.x == s[v].x && f.y == s[v].y) || (f.x == i && f.y == j && TileMap4[i][j] == 'w'))
					{
						f.x = rand() % width;
						f.y = rand() % height;
						v = 0;
						i = 0;
						j = 0;
					}
				}
			}
		}
		break;
	case 5:
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (s[0].x == i && s[0].y == j && TileMap5[i][j] == 'w')
				{

					game = 1;
				}
			}
		}
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				for (int v = 0; v < length; v++)
				{
					if ((f.x == s[v].x && f.y == s[v].y) || (f.x == i && f.y == j && TileMap5[i][j] == 'w'))
					{
						f.x = rand() % width;
						f.y = rand() % height;
						v = 0;
						i = 0;
						j = 0;
					}
				}
			}
		}
		break;
	case 6:
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (s[0].x == i && s[0].y == j && TileMap6[i][j] == 'w')
				{
					game = 1;
				}
			}
		}
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				for (int v = 0; v < length; v++)
				{
					if ((f.x == s[v].x && f.y == s[v].y) || (f.x == i && f.y == j && TileMap6[i][j] == 'w'))
					{
						f.x = rand() % width;
						f.y = rand() % height;
						v = 0;
						i = 0;
						j = 0;
					}
				}
			}
		}
		break;
	}
	
	for (int i = 1; i < length; i++) 
	{
		if (s[0].x == s[i].x && s[0].y == s[i].y)
		{
			game = 1;
		}
	}
}


void changeLevel(RenderWindow & window, int &numberLevel, int &score, int &game, int &size, int &direction, int &length)
{
	Texture c1, c2, c3, c4, c5, c6,c12;
	c1.loadFromFile("images/chapter1.png");
	c12.loadFromFile("images/chapter1.1.png");
	c2.loadFromFile("images/chapter2.png");
	c3.loadFromFile("images/chapter3.png");
	c4.loadFromFile("images/chapter4.png");
	c5.loadFromFile("images/chapter5.png");
	c6.loadFromFile("images/chapter6.png");

	Sprite sprite1(c1);
	Sprite sprite2(c2);
	Sprite sprite3(c3);
	Sprite sprite4(c4);
	Sprite sprite5(c5);
	Sprite sprite6(c6);
	Sprite sprite7(c12);

	switch (score)
	{
	case 0:
		if (level[1].l == 0)
		{
			sprite1.setPosition(0,0);
			window.draw(sprite1);
			window.display();
			sleep();
			sprite7.setPosition(0, 0);
			window.draw(sprite7);
			window.display();
			sleep();
			level[1].l = 1;
		}
		break;

	case 20:
		if (level[2].l == 0)
		{
			sprite2.setPosition(0, 0);
			window.draw(sprite2);
			window.display();
			sleep();
			level[2].l = 1;
			length = 4;
			direction = 0;
			for (int i = 0; i < length; i++)
			{
				s[i].x = 0;
				s[i].y = 0;
			}
			numberLevel = 2;
		}
		break;

	case 40:
		if (level[3].l == 0)
		{
			sprite3.setPosition(0, 0);
			window.draw(sprite3);
			window.display();
			sleep();
			level[3].l = 1;
			length = 4;
			direction = 0;
			for (int i = 0; i < length; i++)
			{
				s[i].x = 0;
				s[i].y = 0;
			}
			numberLevel = 3;
		}
		break;
	case 60:
		if (level[4].l == 0)
		{
			sprite4.setPosition(0, 0);
			window.draw(sprite4);
			window.display();
			sleep();
			level[4].l = 1;
			length = 4;
			direction = 0;
			for (int i = 0; i < length; i++)
			{
				s[i].x = 0;
				s[i].y = 0;
			}
			numberLevel = 4;
		}

		break;
	case 80:
		if (level[5].l == 0)
		{
			sprite5.setPosition(0, 0);
			window.draw(sprite5);
			window.display();
			sleep();
			level[5].l = 1;
			length = 4;
			direction = 0;
			for (int i = 0; i < length; i++)
			{
				s[i].x = 0;
				s[i].y = 0;
			}
			numberLevel = 5;
		}
		break;
	case 100:
		if (level[6].l == 0)
		{
			sprite6.setPosition(0, 0);
			window.draw(sprite6);
			window.display();
			sleep();
			level[6].l = 1;
			length = 4;
			direction = 0;
			for (int i = 0; i < length; i++)
			{
				s[i].x = 0;
				s[i].y = 0;
			}
			numberLevel = 6;
		}
		break;
	}
}



void startGame(int &numberLevel,int &score,int &game,int &size,int &direction,int &length) 
{
	srand(time(0));

	RenderWindow window(VideoMode(600, 400), "Dune");

	if (menu(window)) 
	{
		loading(numberLevel, score, game, direction, length);
	}

	Image icon;
	icon.loadFromFile("images/icon.png");
	window.setIcon(32, 32, icon.getPixelsPtr());

	Font font;
	font.loadFromFile("arial.ttf");
	Text text("", font, 20);
	text.setFillColor(Color::White);
	text.setStyle(sf::Text::Bold);
	Text text1("", font, 20);
	text1.setFillColor(Color::White);
	text1.setStyle(sf::Text::Bold);

	Texture t1, t2, t3, t4, t5, t6;
	t1.loadFromFile("images/sand.png");
	t2.loadFromFile("images/head.png");
	t3.loadFromFile("images/tail.png");
	t4.loadFromFile("images/red.png");
	t5.loadFromFile("images/walls.png");
	t6.loadFromFile("images/face.png");

	Sprite sprite1(t1);
	Sprite sprite2(t2);
	Sprite sprite3(t3);
	Sprite sprite4(t4);
	Sprite sprite5(t5);
	Sprite sprite6(t6);

	Music main;
	main.openFromFile("main.ogg");
	main.play();

	Clock clock;
	float timer = 0, delay = 0.15;

	f.x = rand() % width;
	f.y = rand() % height;

	while (window.isOpen())
	{
		changeLevel(window, numberLevel, score, game, size, direction, length);

		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			if (direction != 2)
			{
				direction = 1;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			if (direction != 1)
			{
				direction = 2;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			if (direction != 0)
			{
				direction = 3;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			if (direction != 3)
			{
				direction = 0;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Tab))
		{
			saving(numberLevel, score, game, direction, length);
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		if (timer > delay)
		{
			timer = 0;
			Move(numberLevel, score, game, size, direction, length);
		}

		window.clear();

		switch (numberLevel)
		{
		case 1:
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (TileMap1[i][j] == ' ')
					{
						sprite1.setPosition(i*size, j*size);
						window.draw(sprite1);
					}
				}

			}
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (TileMap1[i][j] == 'w')
					{
						sprite5.setPosition(i*size, j*size);
						window.draw(sprite5);
					}
				}
			}
			break;

		case 2:
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (TileMap2[i][j] == ' ')
					{
						sprite1.setPosition(i*size, j*size);
						window.draw(sprite1);
					}
				}

			}
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (TileMap2[i][j] == 'w')
					{
						sprite5.setPosition(i*size, j*size);
						window.draw(sprite5);
					}
				}
			}
			break;
		case 3:
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (TileMap3[i][j] == ' ')
					{
						sprite1.setPosition(i*size, j*size);
						window.draw(sprite1);
					}
				}

			}
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (TileMap3[i][j] == 'w')
					{
						sprite5.setPosition(i*size, j*size);
						window.draw(sprite5);
					}
				}
			}
			break;
		case 4:
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (TileMap4[i][j] == ' ')
					{
						sprite1.setPosition(i*size, j*size);
						window.draw(sprite1);
					}
				}

			}
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (TileMap4[i][j] == 'w')
					{
						sprite5.setPosition(i*size, j*size);
						window.draw(sprite5);
					}
				}
			}
			break;
		case 5:
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (TileMap5[i][j] == ' ')
					{
						sprite1.setPosition(i*size, j*size);
						window.draw(sprite1);
					}
				}

			}
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (TileMap5[i][j] == 'w')
					{
						sprite5.setPosition(i*size, j*size);
						window.draw(sprite5);
					}
				}
			}
			break;
		case 6:
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (TileMap6[i][j] == ' ')
					{
						sprite1.setPosition(i*size, j*size);
						window.draw(sprite1);
					}
				}

			}
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (TileMap6[i][j] == 'w')
					{
						sprite5.setPosition(i*size, j*size);
						window.draw(sprite5);
					}
				}
			}
			break;
		}

		sprite2.setPosition(s[0].x*size, s[0].y*size);
		window.draw(sprite2);

		for (int i = 1; i < length; i++)
		{
			sprite3.setPosition(s[i].x*size, s[i].y*size);
			window.draw(sprite3);
		}

		sprite4.setPosition(f.x*size, f.y*size);
		window.draw(sprite4);

		sprite6.setPosition(400, 0);
		window.draw(sprite6);

		ostringstream ScoreString;
		ostringstream LevelString;

		ScoreString << score;
		text.setString("Score: " + ScoreString.str());
		text.setPosition(450, 100);
		window.draw(text);

		LevelString << numberLevel;
		text1.setString("Level: " + LevelString.str());
		text1.setPosition(450, 150);
		window.draw(text1);

		if (game)
		{
			main.stop();
			end(window);
		}
		window.display();
		window.clear();
	}
}


int main()
{
	int score = 0;
	int game = 0;
	int size = 16;
	int direction = 0, length = 4;

	int numberLevel = 1;

	for (int i = 0; i < length; i++)
	{
		s[i].x = 0;
		s[i].y = 0;
	}

	for (int v = 1; v <= 6; v++)
	{
		level[v].l = 0;
	}

	startGame(numberLevel, score, game, size, direction, length);

	return 0;
}