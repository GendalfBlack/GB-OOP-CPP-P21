#pragma once

class Character {
public:
	uint16_t hp;
	uint16_t max_hp;
	Sprite* sprite;
	int32_t x;
	int32_t y;
	char* name; 
	virtual void Move(int8_t dx, int8_t dy) { x += dx; y += dy; }
	virtual void Draw() { if (sprite == nullptr) { throw "Draw nullptr sprite in baseclass Character!"; } sprite->Draw(); }
	virtual void TakeDamage(uint8_t damage) { if (int16_t(hp) - damage <= 0) { throw "Damage in baseclass Character! HP < 0"; } hp -= damage; }
};

class Player : public Character {
public:
	Player(int32_t _x, int32_t _y, const char* _name, const char* _sprite, int16_t _max_hp) {
		x = _x;  y = _y;
		int8_t i = 0, size = 0;
		for (const char* begin = _name; *begin != '\0'; begin++) { size++; } name = new char[size + 1];
		for (const char* begin = _name; *begin != '\0'; begin++) { name[i] = *begin; i++; }	name[i] = '\0';
		sprite = new Sprite(_sprite);
		max_hp = _max_hp;
		hp = _max_hp;
	}
};