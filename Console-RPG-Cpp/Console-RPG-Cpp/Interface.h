#pragma once
#include <list>
#define full_symbol '\333' 
auto hdl = GetStdHandle(STD_OUTPUT_HANDLE);

char* Strcpy(const char* static_text) {
	int8_t i = 0, size = 0;
	for (const char* begin = static_text; *begin != '\0'; begin++) { size++; } 
	char* heap_text = new char[size + 1];
	for (const char* begin = static_text; *begin != '\0'; begin++) { heap_text[i] = *begin; i++; }	
	heap_text[i] = '\0';
	return heap_text;
}

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
		int8_t i = 0, max_w = 0, max_h = 1;
		for (const char* begin = _image; *begin != '\0'; begin++) { 
			if (i > max_w && *begin != '\n') { max_w = i; }
			if (*begin == '\n') { i = 0; max_h++; } 
			i++; 
		}
		w = max_w; h = max_h;
		image = Strcpy(_image);
	}
	void ReadColors(const char* _colors) { colors = Strcpy(_colors); }
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
	void Draw() override {
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
class Text : public Sprite {
public:
	char* text;
	Text(const char* _text) : Sprite(_text), text(image) { }
	void Draw() { Sprite::Draw(); }
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

class PanelVertical : public Area {
private:
	int8_t posy;
public:
	list<char*> labels;
	PanelVertical(int8_t _x, int8_t _y, int8_t _w, int8_t _h) : Area(_w, _h, ' ', full_symbol), posy(0), labels() { Move(_x, _y); }
	void Append(const char* _text) {
		labels.push_back(Strcpy(_text));
		Text element(_text);
		element.Move(x + 1, y + 1 + posy);
		element.Draw();
		posy += element.h;
	}
};