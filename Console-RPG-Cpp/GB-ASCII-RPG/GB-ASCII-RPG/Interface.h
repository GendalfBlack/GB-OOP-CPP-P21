#pragma once

auto hdl = GetStdHandle(STD_OUTPUT_HANDLE);

class Element {
public:
	int8_t x;
	int8_t y;
	int8_t w;
	int8_t h;
	int8_t order;
	void Print() { SetConsoleCursorPosition(hdl, { x, y });	}
};

class Sprite : public Element {
public:
	char* image;
	Sprite(const char* _image) {
		int8_t size = 0, i = 0, max_w = 0, max_h = 1;
		for (const char* begin = _image; *begin != '\0'; begin++) { 
			if (i > max_w) { max_w = i; }
			if (*begin == '\n') { i = 0; max_h++; } 
			i++; size++; 
		}
		image = new char[size + 1]; i = 0;
		for (const char* begin = _image; *begin != '\0'; begin++) { image[i] = *begin; i++; }
		image[i] = '\0';
	}
	void Move(int8_t _x, int8_t _y) { x = _x; y = _y; }
	void Draw() { 
		Print();
		for (int8_t n = 0, i = 0, j = 0; n < strlen(image); n++)
		{
			if (image[n] == ' '){ SetConsoleCursorPosition(hdl, { int16_t(x + i + 1), int16_t(y + j) }); }
			else if (image[n] != '\n'){ cout << image[n]; }
			i++;
			if (image[n] == '\n') { j++; i = 0; SetConsoleCursorPosition(hdl, { x, int16_t(y + j) }); }
		}
	}
};