#pragma once

class Game {
public:
	bool isRunning = false;
	void Setup() {
		isRunning = true;
		Render::Setup();
	}
	void Run() {
		for (int i = 0; i < 10; i++)
		{
			uint8_t rx = rand() % 116 + 3;
			uint8_t ry = rand() % 10 + 1;
			Sprite s(",,,");
			s.ReadColors("\2\2\2");
			s.Move(rx, ry);
			s.Draw();
			Sleep(10);
		}
		while (isRunning)
		{
			Render::Loop();
			_getch();
		}
	}
};