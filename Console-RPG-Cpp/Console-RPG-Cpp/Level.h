#pragma once
#include <vector>
#include <fstream>

class gameObject {
public:
	int16_t g_x;
	int16_t g_y;
	Sprite* sprite;
	gameObject() : g_x(0), g_y(0), sprite(new Sprite){}
	gameObject(int16_t x, int16_t y) : g_x(x), g_y(y), sprite(nullptr) {}
	gameObject(int16_t x, int16_t y, const char* text) : g_x(x), g_y(y), sprite(new Sprite(text)) {}
	char* toString() {
		char* line = new char[64];
		line[0] = g_x >> 8; line[1] = g_x; line[2] = g_y >> 8; line[3] = g_y;
		line[4] = sprite->x; line[5] = sprite->y;
		line[6] = sprite->w; line[7] = sprite->h;
		for (int i = 0; i < strlen(sprite->image); i++) {
			line[8 + i] = sprite->image[i];
		}
		for (int i = 0; i < strlen(sprite->colors); i++) {
			line[8 + strlen(sprite->image) + i] = sprite->colors[i];
		}
		line[63] = '\14';
		return line;
	}
	friend static ostream& operator<<(ostream& os, const gameObject& go);
	friend static ostream& operator>>(ostream& os, const gameObject& go);
	explicit operator char* () { return toString(); }
};

ostream& operator<<(ostream& os, const gameObject& go) {
	os << (uint8_t)(go.g_x >> 8);
	os << (uint8_t)go.g_x;
	os << (uint8_t)(go.g_y >> 8);
	os << (uint8_t)go.g_y;
	os << go.sprite->w;
	os << go.sprite->h;
	os << go.sprite->image;
	os << go.sprite->colors;
	return os;
}

istream& operator>>(istream& os, gameObject& go) {
	uint8_t x1, x2; os >> x1; os >> x2; go.g_x = (x1 << 8) + x2;
	uint8_t y1, y2; os >> y1; os >> y2; go.g_y = (y1 << 8) + y2;
	uint8_t w; os >> w; go.sprite->w = w;
	uint8_t h; os >> h; go.sprite->h = h;
	char* image = new char[(go.sprite->w + 1) * go.sprite->h];
	char* colors = new char[(go.sprite->w + 1) * go.sprite->h];
	go.sprite->image = image; os >> go.sprite->image;
	go.sprite->colors = colors; os >> go.sprite->colors;
	return os;
}

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
		for (auto object : objects)	{ file << object; }
		file.close();
	}
	void ReadFromFile(const char* path) {
		ifstream file;
		file.open(path, ifstream::in | ios::binary);
		while (!file.eof()) { 
			gameObject p_go; file >> p_go; 
			objects.push_back(p_go); 
		}
		file.close();
	}

};