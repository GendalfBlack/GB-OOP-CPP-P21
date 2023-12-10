#pragma once
#include <vector>
#include <fstream>

class gameObject {
public:
	uint16_t g_x;
	uint16_t g_y;
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
	friend static ofstream& operator<<(ofstream& os, const gameObject& go);
	friend static ifstream& operator>>(ifstream& os, gameObject& go);
	explicit operator char* () { return toString(); }
};

ofstream& operator<<(ofstream& os, const gameObject& go) {
	byte gx1 = go.g_x >> 8; os.write((char*)&gx1, 1);
	byte gx2 = go.g_x;		os.write((char*)&gx2, 1);
	byte gy1 = go.g_y >> 8; os.write((char*)&gy1, 1);
	byte gy2 = go.g_y;		os.write((char*)&gy2, 1);
	os << go.sprite->w;
	os << go.sprite->h;
	byte length = (go.sprite->w + 1) * go.sprite->h;
	for (int i = 0; i < length; i++) { os << go.sprite->image[i]; }
	for (int i = 0; i < length; i++) { os << go.sprite->colors[i]; }
	return os;
}

ifstream& operator>>(ifstream& os, gameObject& go) {
	byte x1, x2; os.read((char*)&x1, 1); os.read((char*)&x2, 1); go.g_x |= x1; go.g_x <<= 8; go.g_x |= x2;
	byte y1, y2; os.read((char*)&y1, 1); os.read((char*)&y2, 1); go.g_y |= y1; go.g_y <<= 8; go.g_y |= y2;
	char w; os.read(&w, 1); go.sprite->w = w;
	char h; os.read(&h, 1); go.sprite->h = h;
	byte length = (go.sprite->w + 1) * go.sprite->h;
	char* image = new char[length]; go.sprite->image = image;
	char* colors = new char[length]; go.sprite->colors = colors;
	os.read(go.sprite->image, length);
	os.read(go.sprite->colors, length);
	go.sprite->image[length] = '\0';
	go.sprite->colors[length] = '\0';
	return os;
}

class Level {
public:
	uint16_t width;
	uint16_t height;
	uint8_t screen_width = 99;
	uint8_t screen_height = 24;
	uint16_t screen_x = 0;
	uint16_t screen_y = 0;

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