#pragma once
#include <vector>
#include <fstream>


class Character {
public:
	uint16_t hp;
	uint16_t max_hp;
	Sprite* sprite;
	int16_t x;
	int16_t y;
	char* name;
	Character() : hp(0), x(0), y(0), max_hp(0), sprite(nullptr), name(nullptr) {}
	virtual void Move(int8_t dx, int8_t dy) { x += dx; y += dy; }
	virtual void Draw() { if (sprite == nullptr) { throw "Draw nullptr sprite in baseclass Character!"; } sprite->Draw(); }
	virtual void TakeDamage(uint8_t damage) { if (int16_t(hp) - damage <= 0) { throw "Damage in baseclass Character! HP < 0"; } hp -= damage; }
};

class Player : public Character {
public:
	int8_t length_name;

	Player() : Character(), length_name(0) {}
	Player(int16_t _x, int16_t _y, const char* _name, const char* _sprite, int16_t _max_hp) {
		length_name = 0;
		x = _x;  y = _y;
		name = MyFunctions::strcpy(_name);
		sprite = new Sprite(_sprite);
		max_hp = _max_hp;
		hp = _max_hp;
		for (int i = 0; name[i] != '\0'; i++) { length_name++; }
	}

	vector<Player> objects;
	void add(const Player& object) { objects.push_back(object); }
	void WriteToFile(const char* path) {
		ofstream file;
		file.open(path, ofstream::out | ios::binary);
		file << *this;
		file.close();
	}
	void ReadFromFile(const char* path) {
		ifstream file;
		file.open(path, ifstream::in | ios::binary);
		file >> *this;
		file.close();
	}

	friend static ofstream& operator<<(ofstream& os, const Player& p);
	friend static ifstream& operator>>(ifstream& os, Player& p);

};

//запис у файл
ofstream& operator<<(ofstream& os, const Player& p) {
	byte hp = p.hp >> 8; os.write((char*)&hp, 1);
	byte hp2 = p.hp;		os.write((char*)&hp2, 1);
	byte m_hp = p.max_hp >> 8; os.write((char*)&m_hp, 1);
	byte m_hp2 = p.max_hp;		os.write((char*)&m_hp2, 1);
	byte x1 = p.x >> 8; os.write((char*)&x1, 1);
	byte x2 = p.x;		os.write((char*)&x2, 1);
	byte y1 = p.y >> 8; os.write((char*)&y1, 1);
	byte y2 = p.y;		os.write((char*)&y2, 1);
	os << p.length_name;
	for (int i = 0; i < p.length_name; i++) { os << p.name[i]; }
	os << p.sprite->w;
	os << p.sprite->h;
	byte length2 = (p.sprite->w + 1) * p.sprite->h;
	for (int i = 0; i < length2; i++) { os << p.sprite->image[i]; }
	/*for (int i = 0; i < length2; i++) { os << p.sprite->colors[i]; }*/
	return os;
}

//читання з файлу
ifstream& operator>>(ifstream& os, Player& p) {
	byte hp, hp2; os.read((char*)&hp, 1); os.read((char*)&hp2, 1); p.hp |= hp; p.hp <<= 8; p.hp |= hp2;
	byte m_hp, m_hp2; os.read((char*)&m_hp, 1); os.read((char*)&m_hp2, 1); p.max_hp |= m_hp; p.max_hp <<= 8; p.max_hp |= m_hp2;
	byte x1, x2; os.read((char*)&x1, 1); os.read((char*)&x2, 1); p.x |= x1; p.x <<= 8; p.x |= x2;
	byte y1, y2; os.read((char*)&y1, 1); os.read((char*)&y2, 1); p.y |= y1; p.y <<= 8; p.y |= y2;
	byte l1; os.read((char*)&l1, 1); p.length_name |= l1;
	char* name = new char[p.length_name]; p.name = name;
	os.read(p.name, p.length_name);
	p.name[p.length_name] = '\0';
	p.sprite = new Sprite;
	char w; os.read(&w, 1); p.sprite->w = w;
	char h; os.read(&h, 1); p.sprite->h = h;
	byte length = p.sprite->w * p.sprite->h;
	char* image = new char[length]; 
	//char* colors = new char[length]; p.sprite->colors = colors;
	os.read(image, length);
	p.sprite->image = image;
	//os.read(p.sprite->colors, length);
	p.sprite->image[length] = '\0';
	//p.sprite->colors[length] = '\0';
	return os;
}