#pragma once
#define W_WIDTH 120
#define W_HEIGHT 30

static class Render {
public:
	static HANDLE hdl;
	static char* buffer;
	static char* last;
	static char* color;
	static char* color_last;
	static void Setup() {
		CONSOLE_CURSOR_INFO cursorInfo;
		GetConsoleCursorInfo(Render::hdl, &cursorInfo);
		cursorInfo.bVisible = false; // set the cursor visibility
		SetConsoleCursorInfo(Render::hdl, &cursorInfo);
		PCOORD p = new COORD{ W_WIDTH, W_HEIGHT };
		SetConsoleDisplayMode(hdl, CONSOLE_WINDOWED_MODE, p);
		for (int n = 0; n < W_WIDTH * W_HEIGHT; n++)
		{
			buffer[n] = ' ';
			last[n] = ' ';
			color[n] = 7;
			color_last[n] = 7;
		}
	}
	static void Start() { }
	static void Loop() {
		for (int n = 0; n < W_HEIGHT * W_WIDTH; n++)
		{
			if (buffer[n] != last[n] && color[n]!= color_last[n]) {
				SetConsoleCursorPosition(hdl, { int16_t(n%W_WIDTH), int16_t(n/W_HEIGHT) });
				SetConsoleTextAttribute(hdl, color[n]);
				cout << buffer[n];
			}
		}
		for (int n = 0; n < W_HEIGHT * W_WIDTH; n++)
		{
			color_last[n] = color[n];
			last[n] = buffer[n];
		}
	}
};	
HANDLE Render::hdl = GetStdHandle(STD_OUTPUT_HANDLE);
char* Render::buffer = new char[W_WIDTH * W_HEIGHT];
char* Render::last = new char[W_WIDTH * W_HEIGHT];
char* Render::color = new char[W_WIDTH * W_HEIGHT];
char* Render::color_last = new char[W_WIDTH * W_HEIGHT];