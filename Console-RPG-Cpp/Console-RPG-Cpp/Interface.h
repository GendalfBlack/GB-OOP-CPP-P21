#pragma once
#include <list>
#include <string>
#define full_symbol '\333' 
auto hdl = GetStdHandle(STD_OUTPUT_HANDLE);

namespace MyFunctions {
	char* strcpy(const const char*& static_text) {
		int8_t i = 0, size = 0;
		for (const char* begin = static_text; *begin != '\0'; begin++) { size++; } 
		char* heap_text = new char[size + 1];
		for (const char* begin = static_text; *begin != '\0'; begin++) { heap_text[i] = *begin; i++; }	
		heap_text[i] = '\0';
		return heap_text;
	}
};


class Element {
public:
	int8_t x;
	int8_t y;
	int8_t w;
	int8_t h;
	void Print() { SetConsoleCursorPosition(hdl, { x, y });	}
	virtual void Draw() { throw "Calling virtual method Draw() from \"Element\""; }
	void Move(uint8_t _x, uint8_t _y) { x = _x; y = _y; }
};

class Sprite : public Element {
public:
	string image;
	string colors;
	Sprite() { }
	Sprite(string _image) {	image = _image;	Calculate_W_H(); }
	void Calculate_W_H() {
		int8_t i = 0, max_w = 0, max_h = 1;
		for (const char* begin = image.c_str(); *begin != '\0'; begin++) {
			if (i > max_w && *begin != '\n') { max_w = i; }
			if (*begin == '\n') { i = 0; max_h++; }	i++;
		} w = max_w; h = max_h;
	}
	virtual void ReadColors(string _colors) { colors = _colors; }
	void Draw() override{
		Print();
		for (int8_t n = 0, i = 0, j = 0; n < image.size(); n++)
		{
			if (image[n] == ' '){ SetConsoleCursorPosition(hdl, { int16_t(x + i + 1), int16_t(y + j) }); }
			else if (image[n] != '\n'){ 
				if (colors.size() > 0) { SetConsoleTextAttribute(hdl, uint8_t(colors[n])); }
				cout << image[n]; 
			}
			i++;
			if (image[n] == '\n') { j++; i = 0; SetConsoleCursorPosition(hdl, { x, int16_t(y + j) }); }
		}
	}
};

class Label : public Sprite {
public:
	string text;
	char border = '*';
	Label(string _text) : Sprite(_text), text(image) { }
	Label(string _text, char _border) : Sprite(_text), text(image), border(_border) { }
	void Draw() override {	
		if (border != ' ') {
			SetConsoleCursorPosition(hdl, { int16_t(x - 1), int16_t(y - 1) });
			for (int8_t i = 0; i < w + 2; i++) { cout << border; }
			SetConsoleCursorPosition(hdl, { int16_t(x - 1), int16_t(y + h) });
			for (int8_t i = 0; i < w + 2; i++) { cout << border; }
			for (int8_t i = 0; i < h; i++) {
				SetConsoleCursorPosition(hdl, { int16_t(x - 1), int16_t(y + i) });	cout << border;
				SetConsoleCursorPosition(hdl, { int16_t(x + w), int16_t(y + i) });	cout << border;
			}
		}
		Sprite::Draw();
	}
};

class Button : public Label {
public:
	string tempcolors;
	string colors2;
	bool isPressed = false;
	Button(string _text) : Label(_text){ }
	void ReadColors(string _colors) override {
		for (int i = 0; i < w*h; i++){ colors.push_back(_colors[0]); colors2.push_back(_colors[1]); }
	}
	void Draw() override {
		if (isPressed) { 
			tempcolors = colors; colors = colors2;
			SetConsoleTextAttribute(hdl, colors2[0]);
		}
		else {
			if (tempcolors.size() > 0) { colors = tempcolors; }
			SetConsoleTextAttribute(hdl, colors[0]);
		}
		Label::Draw();
	}
};

class Text : public Label {
public:
	Text(string _text) : Label(_text) { border = ' '; }
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
	list<string> labels;
	PanelVertical(int8_t _x, int8_t _y, int8_t _w, int8_t _h) : Area(_w, _h, ' ', full_symbol), posy(0), labels() { Move(_x, _y); }
	void Append(string _text) {
		labels.push_back(_text);
		Text element(_text);
		element.Move(x + 1, y + 1 + posy);
		element.Draw();
		posy += element.h + 1;
	}
};

class PanelGorizontal : public Area {
private:
	int8_t posx;
public:
	list<string> labels;
	PanelGorizontal(int8_t _x, int8_t _y, int8_t _w, int8_t _h) : Area(_w, _h, ' ', full_symbol), posx(0), labels() { Move(_x, _y); }
	void Append(string _text) {
		labels.push_back(_text);
		Text element(_text);
		element.Move(x + 1 + posx, y + 1 );
		element.Draw();
		posx += element.w + 1;
	}
};
#ifndef item_size
#define item_size 3
#endif // !item_size

class Table {
public:
	list<PanelGorizontal> rows;
	Table(int8_t _x, int8_t _y, int8_t _rows, int8_t _columns) {
		for (int j = 0; j < _rows; j++)
		{
			PanelGorizontal row(_x, _y + item_size * j, item_size * _columns, item_size);
			rows.push_back(row);
			for (int i = 0; i < _columns; i++)
			{
				Label empty("...\n...\n...", full_symbol);
				empty.Move(_x + (item_size + 1) * i, _y + (item_size + 1) * j);
				empty.Draw();
			}
		}
	}
};