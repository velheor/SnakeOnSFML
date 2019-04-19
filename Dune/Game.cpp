#include <SFML/Graphics.hpp>
#include <sstream>
#include <time.h>
#include "menu.h"
#include "map1.h"

using namespace sf;

int score;
int game = 0;
int size = 16;


int dir, num = 4;

struct Snake
{
	int x=0, y=0;
}  s[100];

struct Fruct
{
	int x, y;
} f;

void Move()
{
	for (int i = num; i > 0; --i)
	{
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
	}

	if (dir == 0) s[0].y += 1;
	if (dir == 1) s[0].x -= 1;
	if (dir == 2) s[0].x += 1;
	if (dir == 3) s[0].y -= 1;

	if ((s[0].x == f.x) && (s[0].y == f.y))
	{
		score += 10;
		num++;
		f.x = rand() % N;
		f.y = rand() % M;
		for (int i = 0; i < num; i++) {
			if (f.x == s[i].x && f.y == s[i].y) {
				f.x = rand() % N;
				f.y = rand() % M;
				i = 0;
			}
		}
	}
		if (s[0].x > N - 1) game = 1;  if (s[0].x < 0) game = 1;
		if (s[0].y > M - 1) game = 1;   if (s[0].y < 0) game = 1;

		for (int i = 1; i < num; i++) {
			if (s[0].x == s[i].x && s[0].y == s[i].y)
			{
				game = 1;
			}
		}
}

bool startGame() {
	srand(time(0));

	RenderWindow window(VideoMode(600, 400), "Dune");
	menu(window);

	Font font;
	font.loadFromFile("arial.ttf");
	Text text("", font, 20);
	text.setFillColor(Color::White);
	text.setStyle(sf::Text::Bold);
	Text text1("", font, 20);
	text1.setFillColor(Color::Red);
	text1.setStyle(sf::Text::Bold);

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
			if (dir != 2)
			{
				dir = 1;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			if (dir != 1)
			{
				dir = 2;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			if (dir != 0)
			{
				dir = 3;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			if (dir != 3)
			{
				dir = 0;
			}
		}

		if (timer > delay) { timer = 0; Move(); }

		if (Keyboard::isKeyPressed(Keyboard::Tab)) { return true; }
		if (Keyboard::isKeyPressed(Keyboard::Escape)) { return false; }


		////// draw  ///////
		window.clear();

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++)
			{
				if (TileMap[i][j] == ' ')
				{
					sprite1.setPosition(i*size, j*size);
					window.draw(sprite1);
				}
			}

		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++)
			{
				if (TileMap[i][j] == 'w')
				{
					sprite4.setPosition(i*size, j*size);
					window.draw(sprite4);
				}
			}
		}

		sprite2.setPosition(s[0].x*size, s[0].y*size);  window.draw(sprite2);
		sprite3.setPosition(s[1].x*size, s[1].y*size);  window.draw(sprite3);

		for (int i = 2; i < num; i++)
		{
			sprite3.setPosition(s[i].x*size, s[i].y*size);  window.draw(sprite3);
		}

		sprite4.setPosition(f.x*size, f.y*size);  window.draw(sprite4);

		std::ostringstream ScoreString;
		ScoreString << score;
		text.setString("Score: " + ScoreString.str());
		text.setPosition(450, 100);
		window.draw(text);

		if (game)
		{
			text1.setString("You died");
			text1.setPosition(225, 200);
			window.draw(text1);
		}
		if (game)
		{
			system("pause");
			window.close();
		}
		window.display();
	}
}

/*void changeLevel(Level &lvl, int &numberLevel) 
{
	if (numberLevel == 1) { lvl.LoadFromFile("Map.tmx"); }
	if (numberLevel == 2) { lvl.LoadFromFile("Map1.tmx"); }
}*/

void gameRunning() {//ф-ция перезагружает игру , если это необходимо
	if (startGame()) {gameRunning(); }//принимает с какого уровня начать игру
}

int main()
{
	gameRunning();
	return 0;
}