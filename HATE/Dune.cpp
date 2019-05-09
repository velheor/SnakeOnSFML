#include <SFML/Graphics.hpp>
#include <sstream>
#include <time.h>
#include "Menu.h"
#include "Map1.h"
#include "Map2.h"

using namespace sf;


struct Snake
{
	int x = 0, y = 0;
}  s[100];

struct Fruit
{
	int x, y;
} f;

void gameRunning(int, int, int, int, int &, int &);

void Move(int numberLevel, int &score,int &game, int &size, int &direction, int &length)
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
				if (s[0].x == i && s[0].y==j && TileMap1[i][j] == 'w')
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
	}
	
	for (int i = 1; i < length; i++) 
	{
		if (s[0].x == s[i].x && s[0].y == s[i].y)
		{
			game = 1;
		}
	}
}


void changeLevel(int &numberLevel, int &score, int &game, int &size, int &direction, int &length)
{
	switch (score)
	{
	case 0:

		numberLevel = 1;
		break;
	case 20:

		numberLevel = 2;
		break;
	}
}

bool startGame(int &numberLevel,int &score,int &game,int &size,int &direction,int &length) 
{
	srand(time(0));

	RenderWindow window(VideoMode(600, 400), "Dune");
	menu(window);

	Font font;
	font.loadFromFile("arial.ttf");
	Text text("", font, 20);
	text.setFillColor(Color::White);
	text.setStyle(sf::Text::Bold);

	Texture t1, t2, t3, t4;
	t1.loadFromFile("images/White.png");
	t2.loadFromFile("images/Head.png");
	t3.loadFromFile("images/Tail.png");
	t4.loadFromFile("images/red.png");

	Sprite sprite1(t1);
	Sprite sprite2(t2);
	Sprite sprite3(t3);
	Sprite sprite4(t4);

	Clock clock;
	float timer = 0, delay = 0.1;

	f.x = 10;
	f.y = 10;

	while (window.isOpen())
	{
		changeLevel(numberLevel, score, game, size, direction, length);

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

		if (timer > delay)
		{ 
			timer = 0; 
			Move(numberLevel, score, game, size, direction, length);
		}

		if (Keyboard::isKeyPressed(Keyboard::Tab)) 
		{
			return true; 
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)) 
		{ 
			return false;
		}


		////// draw  ///////
		window.clear();

		switch (numberLevel) {
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
						sprite4.setPosition(i*size, j*size);
						window.draw(sprite4);
						
					}
				}
			}
			break;
		case 2:
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++)
				{
					if (TileMap2[i][j] == ' ')
					{
						sprite1.setPosition(i*size, j*size);
						window.draw(sprite1);
					}
				}

			}
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++)
				{
					if (TileMap2[i][j] == 'w')
					{
						sprite4.setPosition(i*size, j*size);
						window.draw(sprite4);
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

		std::ostringstream ScoreString;
		ScoreString << score;
		text.setString("Score: " + ScoreString.str());
		text.setPosition(450, 100);
		window.draw(text);

		if (game)
		{
			system("pause");
			window.close();
		}
		window.display();
		window.clear();
	}
}

void gameRunning(int numberLevel,int score, int game, int size,int &direction, int &length)
{
	if (startGame(numberLevel, score, game, size, direction, length))
	{
		length = 4;
		direction = 0;
		for (int i = 0; i < length; i++)
		{
			s[i].x = 0;
			s[i].y = 0;
		}
		gameRunning(numberLevel, score, game, size, direction, length);
	}
}

int main()
{
	int score = 0;
	int game = 0;
	int size = 16;

	int direction = 0, length = 4;

	int numberLevel = 1;

	gameRunning(numberLevel, score, game, size, direction, length);
	return 0;
}