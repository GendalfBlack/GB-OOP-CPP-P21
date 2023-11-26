#pragma once
#include <list>
#define full_symbol '\333' 
#include "Renderer.h"

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
	void Print() { SetConsoleCursorPosition(Render::hdl, { x, y }); }
	virtual void Draw() { throw "Calling virtual method Draw() from \"Element\""; }
	void Move(int8_t _x, int8_t _y) { x = _x; y = _y; }
};

class Sprite : public Element {
public:
	char* image;
	char* colors = nullptr;
	Sprite(){ }
	Sprite(const char* _image) {
		if (_image == nullptr) { throw "Image for constructor Sprite was nullptr!"; }
		image = Strcpy(_image);
		Calculate_W_H();
	}
	Sprite(char* _image) {
		if (_image == nullptr) { throw "Image for constructor Sprite was nullptr!"; }
		image = _image;
		Calculate_W_H();
	}
	void Calculate_W_H() {
		int8_t i = 0, max_w = 0, max_h = 1;
		for (char* begin = image; *begin != '\0'; begin++) {
			if (i > max_w && *begin != '\n') { max_w = i; }
			if (*begin == '\n') { i = 0; max_h++; }
			i++;
		}
		w = max_w; h = max_h;
	}
	virtual void ReadColors(const char* _colors) {
		colors = Strcpy(_colors);
	}
	void Erase() {
		int n = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				Render::buffer[(y + i) * W_WIDTH + (x + j)] = ' ';
				Render::color[(y + i) * W_WIDTH + (x + j)] = 7;
				n++;
			}
		}
	}
	void Draw() override {
		Print();
		int n = 0; 
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				Render::buffer[(y + i) * W_WIDTH + (x + j)] = image[n]; 
				Render::color[(y + i) * W_WIDTH + (x + j)] = colors[n];
				n++;
			}
		}
		SetConsoleTextAttribute(Render::hdl, 7);
	}
};

class Label : public Sprite {
public:
	char* text;
	char border = '*';
	Label(const char* _text) : Sprite(_text), text(image) { }
	Label(const char* _text, char _border) : Sprite(_text), text(image), border(_border) { }
	void Draw() {
		if (border != ' ') {
			for (int8_t i = 0; i < w + 2; i++) {
				Render::buffer[(y - 1) * W_WIDTH + (x - 1 + i)] = border;
				Render::color[(y - 1) * W_WIDTH + (x - 1 + i)] = colors[0];
				Render::buffer[(y - 1 + h) * W_WIDTH + (x - 1 + i)] = border;
				Render::color[(y - 1 + h) * W_WIDTH + (x - 1 + i)] = colors[0];
			}
			for (int8_t i = 0; i < h; i++) {
				Render::buffer[(y - 1 + i) * W_WIDTH + (x - 1)] = border;
				Render::color[(y - 1 + i) * W_WIDTH + (x - 1)] = colors[0];

				Render::buffer[(y - 1 + i) * W_WIDTH + (x - 1 + w + 1)] = border;
				Render::color[(y - 1 + i) * W_WIDTH + (x - 1 + w + 1)] = colors[0];
			}
		}
		Sprite::Draw();
	}
};
class Button : public Label {
public:
	char* tempcolors = nullptr;
	char* colors2 = nullptr;
	bool isPressed = false;
	Button(const char* _text) : Label(_text) { }
	void ReadColors(const char* _colors) override {
		colors = new char[w * h];
		colors2 = new char[w * h];
		for (int i = 0; i < w * h; i++) { colors[i] = _colors[0]; colors2[i] = _colors[1]; }
	}
	void Draw() override {
		if (isPressed) { tempcolors = colors; colors = colors2;	}
		else { if (tempcolors != nullptr) { colors = tempcolors; }	}
		Label::Draw();
	}
};
class Text : public Label {
public:
	Text(const char* _text) : Label(_text) { border = ' '; }
	Text(char* _text) : Label(_text) { border = ' '; }
};

class Area : public Element {
public:
	char background;
	char border;
	char* colors;
	Area(int8_t _w, int8_t _h, char _background, char _border) : background(_background), border(_border), colors(new char[1]) { 
		w = _w; h = _h; colors[0] = '\7';
	}
	void Draw() override {
		for (int8_t i = 0; i < w; i++) {
			Render::buffer[(y - 1) * W_WIDTH + (x - 1 + i)] = border;
			Render::color[(y - 1) * W_WIDTH + (x - 1 + i)] = colors[0];
			Render::buffer[(y + h) * W_WIDTH + (x - 1 + i)] = border;
			Render::color[(y + h) * W_WIDTH + (x - 1 + i)] = colors[0];
		}
		for (int8_t i = 0; i < h; i++) {
			Render::buffer[(y + i) * W_WIDTH + (x - 1)] = border;
			Render::color[(y + i) * W_WIDTH + (x - 1)] = colors[0];
			Render::buffer[(y + i) * W_WIDTH + (x + w - 2)] = border;
			Render::color[(y + i) * W_WIDTH + (x + w - 2)] = colors[0];
		}
		for (int8_t j = 0; j < h; j++) {
			for (int8_t i = 0; i < w-2; i++) {
				Render::buffer[(y + j) * W_WIDTH + (x + i)] = background;
				Render::color[(y + j) * W_WIDTH + (x + i)] = colors[0];
			}
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
		posy += element.h + 1;
	}
};

class PanelGorizontal : public Area {
private:
	int8_t posx;
public:
	list<char*> labels;
	PanelGorizontal(int8_t _x, int8_t _y, int8_t _w, int8_t _h) : Area(_w, _h, ' ', full_symbol), posx(0), labels() { Move(_x, _y); }
	void Append(const char* _text) {
		labels.push_back(Strcpy(_text));
		Text element(_text);
		element.Move(x + 1 + posx, y + 1);
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
				empty.ReadColors("\7");
				empty.Move(_x + (item_size + 1) * i, _y + (item_size + 1) * j);
				empty.Draw();
			}
		}
	}
};