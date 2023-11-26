#pragma once

class Game {
public:
	bool isRunning = false;
	void Setup() {
		isRunning = true;
		Render::Setup();
		Render::Start();
	}
	void Run() {
		srand(time(0));
		Area a1(99, 24, '.', full_symbol);
		a1.Move(1, 1);
		a1.Draw();
		Table r(99, 1, 6, 4);
		Sprite* sprites = new Sprite[11];
		int g = 0;
		Sprite player(" o \n-+-\n ^");
		player.ReadColors("\3\3\3\3\3\3\3\3\3\3");
		player.Move(10, 10);
		sprites[g] = player;
		for (int i = 0; i < 10; i++)
		{
			uint8_t rx = rand() % (99-3) + 3;
			uint8_t ry = rand() % 24 + 1;
			Sprite s(",,,");
			s.ReadColors("\2\2\2");
			s.Move(rx, ry);
			sprites[g] = s; g++;
		}
		while (isRunning)
		{
			Render::Update();
			int a = _getch(); 
			switch (a)
			{
			case 'w':
				player.Erase(); player.Move(player.x, player.y - 1); player.Draw();
				break;
			case 's':
				player.Erase(); player.Move(player.x, player.y + 1); player.Draw();
				break;
			case 'a':
				player.Erase(); player.Move(player.x - 1, player.y); player.Draw();
				break;
			case 'd':
				player.Erase(); player.Move(player.x + 1, player.y); player.Draw();
				break;
			default:
				break;
			}
			for (int i = 0; i < 11; i++) { sprites[i].Draw(); }
		}
	}
};