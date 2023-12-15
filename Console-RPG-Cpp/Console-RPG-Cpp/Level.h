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
	gameObject(int16_t x, int16_t y, string text) : g_x(x), g_y(y), sprite(new Sprite(text)) {}
	string toString() {
		string line;
		line.push_back(g_x >> 8); line.push_back(g_x); 
		line.push_back(g_y >> 8); line.push_back(g_y);
		line.push_back(sprite->x); line.push_back(sprite->y);
		line.push_back(sprite->w); line.push_back(sprite->h);
		for (int i = 0; i < sprite->image.size(); i++) { line.push_back(sprite->image[i]); }
		for (int i = 0; i < sprite->colors.size(); i++) { line.push_back(sprite->colors[i]); }
		line.push_back('\14');
		return line;
	}
	friend static ofstream& operator<<(ofstream& os, const gameObject& go);
	friend static ifstream& operator>>(ifstream& os, gameObject& go);
	explicit operator string () { return toString(); }
};

ofstream& operator<<(ofstream& os, const gameObject& go) {
	byte gx1 = go.g_x >> 8; os.write((char*)&gx1, 1);
	byte gx2 = go.g_x;		os.write((char*)&gx2, 1);
	byte gy1 = go.g_y >> 8; os.write((char*)&gy1, 1);
	byte gy2 = go.g_y;		os.write((char*)&gy2, 1);
	os << go.sprite->w;
	os << go.sprite->h;
	byte length = go.sprite->w * go.sprite->h;
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
	char* image = new char[length]; 
	char* colors = new char[length]; 
	os.read(image, length);
	os.read(colors, length);
	for (int i = 0; i < length; i++) { go.sprite->image.push_back(image[0]); }
	for (int i = 0; i < length; i++) { go.sprite->colors.push_back(colors[0]); }
	go.sprite->image.push_back('\0');
	go.sprite->colors.push_back('\0');
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
		file << *this;
		for (auto object : objects)	{ file << object; }
		file.close();
	}
	void ReadFromFile(const char* path) {
		ifstream file;
		file.open(path, ifstream::in | ios::binary);
		file >> *this;
		while (!file.eof()) { 
			gameObject p_go; file >> p_go;
			objects.push_back(p_go); 
		}
		file.close();
	}
	friend static ofstream& operator<<(ofstream& os, const Level& l);
	friend static ifstream& operator>>(ifstream& os, Level& l);
};

ofstream& operator<<(ofstream& os, const Level& l) {
	byte w1 = l.width >> 8; os.write((char*)&w1, 1);
	byte w2 = l.width;		os.write((char*)&w2, 1);
	byte h1 = l.height >> 8; os.write((char*)&h1, 1);
	byte h2 = l.height;		os.write((char*)&h2, 1);
	byte x1 = l.screen_x >> 8; os.write((char*)&x1, 1);
	byte x2 = l.screen_x;		os.write((char*)&x2, 1);
	byte y1 = l.screen_y >> 8; os.write((char*)&y1, 1);
	byte y2 = l.screen_y;		os.write((char*)&y2, 1);
	os << l.screen_width;
	os << l.screen_height;
	return os;
}
ifstream& operator>>(ifstream& os, Level& l) {
	byte w1, w2; os.read((char*)&w1, 1); os.read((char*)&w2, 1); l.width |= w1; l.width <<= 8; l.width |= w2;
	byte h1, h2; os.read((char*)&h1, 1); os.read((char*)&h2, 1); l.height |= h1; l.height <<= 8; l.height |= h2;
	byte x1, x2; os.read((char*)&x1, 1); os.read((char*)&x2, 1); l.screen_x |= x1; l.screen_x <<= 8; l.screen_x |= x2;
	byte y1, y2; os.read((char*)&y1, 1); os.read((char*)&y2, 1); l.screen_y |= y1; l.screen_y <<= 8; l.screen_y |= y2;
	char w; os.read(&w, 1); l.screen_width = w;
	char h; os.read(&h, 1); l.screen_height = h;
	return os;
}