#pragma once
#include <vector>
#include <fstream>

class gameObject {
public:
	int16_t g_x;
	int16_t g_y;
	Sprite* sprite;
	gameObject(int16_t x, int16_t y) : g_x(x), g_y(y), sprite(nullptr){}
	gameObject(int16_t x, int16_t y, const char* text) : g_x(x), g_y(y), sprite(new Sprite(text)){}
	char* toString() {
		char* line = new char[64];
		line[0] = g_x >> 8; line[1] = g_x; line[2] = g_y >> 8; line[3] = g_y;
		line[4] = sprite->x; line[5] = sprite->y; 
		line[6] = sprite->w; line[7] = sprite->h;
		for (int i = 0; i < strlen(sprite->image); i++)	{
			line[8 + i] = sprite->image[i];
		}
		for (int i = 0; i < strlen(sprite->colors); i++) {
			line[8 + strlen(sprite->image) + i] = sprite->colors[i];
		}
		line[63] = '\14';
		return line;
	}
	operator char*() { return toString(); }
};

class Level {
public:
	int16_t width;
	int16_t height;
	int8_t screen_width = 99;
	int8_t screen_height = 24;
	int16_t screen_x = 0;
	int16_t screen_y = 0;

	vector<gameObject> objects;
	Level(int16_t w, int16_t h) : objects() { 
		width = w * screen_width;
		height = h* screen_height;
	}

	void drawAll() {
		for (auto object : objects)
		{
			if (object.g_x - screen_x > 0 && object.g_y - screen_y > 0 &&
				object.g_x - screen_x < screen_width && object.g_y - screen_y < screen_height)
			{
				object.sprite->Move(object.g_x - screen_x, object.g_y - screen_y);
				object.sprite->Draw();
			}
		}
	}

	void add(const gameObject& object) { objects.push_back(object); }

	void WriteToFile(const char* path) {
		ofstream file;
		file.open(path, ofstream::out | ios::binary);
		for (auto object : objects)	{ file.write(object, 128); }
		file.close();
	}

};