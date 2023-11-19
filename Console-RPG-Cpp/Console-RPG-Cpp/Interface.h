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
	virtual void Draw() { throw "Calling virtual method Draw() from \"Element\""; }
	void Move(int8_t _x, int8_t _y) { x = _x; y = _y; }
};

class Sprite : public Element {
public:
	char* image;
	char* colors = nullptr;
	Sprite(const char* _image) {
		if (_image == nullptr) { throw "Image for constructor Sprite was nullptr!"; }
		int8_t size = 0, i = 0, max_w = 0, max_h = 1;
		for (const char* begin = _image; *begin != '\0'; begin++) { 
			if (i > max_w && *begin != '\n') { max_w = i; }
			if (*begin == '\n') { i = 0; max_h++; } 
			i++; size++; 
		}
		w = max_w; h = max_h;
		image = new char[size + 1]; i = 0;
		for (const char* begin = _image; *begin != '\0'; begin++) { image[i] = *begin; i++; }
		image[i] = '\0';
	}
	void ReadColors(const char* _colors) {
		int8_t i = 0, size = 0;
		for (const char* begin = _colors; *begin != '\0'; begin++) { size++; } colors = new char[size + 1];
		for (const char* begin = _colors; *begin != '\0'; begin++) { colors[i] = *begin; i++; }	colors[i] = '\0';
	}
	void Draw() override{
		Print();
		for (int8_t n = 0, i = 0, j = 0; n < strlen(image); n++)
		{
			if (image[n] == ' '){ SetConsoleCursorPosition(hdl, { int16_t(x + i + 1), int16_t(y + j) }); }
			else if (image[n] != '\n'){ 
				if (colors != nullptr) { SetConsoleTextAttribute(hdl, uint8_t(colors[n])); }
				cout << image[n]; 
			}
			i++;
			if (image[n] == '\n') { j++; i = 0; SetConsoleCursorPosition(hdl, { x, int16_t(y + j) }); }
		}
	}
};

class Label : public Sprite {
public:
	char* text;
	char border = '*';
	Label(const char* _text) : Sprite(_text), text(image) { }
	Label(const char* _text, char _border) : Sprite(_text), text(image), border(_border) { }
	void Draw() {
		Sprite::Draw();
		SetConsoleCursorPosition(hdl, { int16_t(x - 1), int16_t(y - 1) });
		for (int8_t i = 0; i < w + 3; i++) { cout << border; }
		SetConsoleCursorPosition(hdl, { int16_t(x - 1), int16_t(y + h) });
		for (int8_t i = 0; i < w + 3; i++) { cout << border; }
		for (int8_t i = 0; i < h; i++) {
			SetConsoleCursorPosition(hdl, { int16_t(x - 1), int16_t(y + i) });	cout << border;
			SetConsoleCursorPosition(hdl, { int16_t(x + w + 1), int16_t(y + i) });	cout << border;
		}
	}
};

class Area : public Element {
public:
	char background;
	char border;
	Area(int8_t _w, int8_t _h, char _background, char _border) : background(_background), border(_border) { w = _w; h = _h; }
	void Draw() override {
		SetConsoleCursorPosition(hdl, { x, y });
		for (int8_t i = 0; i < w + 1; i++) { cout << border; }
		SetConsoleCursorPosition(hdl, { x, int16_t(y + h) });
		for (int8_t i = 0; i < w + 1; i++) { cout << border; }
		for (int8_t i = 1; i < h; i++) {
			SetConsoleCursorPosition(hdl, { x, int16_t(y + i) }); cout << border;
			for (int8_t i = 0; i < w-2; i++) { cout << background; }
			SetConsoleCursorPosition(hdl, { int16_t(x + w), int16_t(y + i) });	cout << border;
		}
	}
};
