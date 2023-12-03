#pragma once
#include <vector>

class gameObject {
public:
	int16_t g_x;
	int16_t g_y;
	Sprite* sprite;
	gameObject(int16_t x, int16_t y) : g_x(x), g_y(y), sprite(nullptr){}
	gameObject(int16_t x, int16_t y, const char* text) : g_x(x), g_y(y), sprite(new Sprite(text)){}
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
};