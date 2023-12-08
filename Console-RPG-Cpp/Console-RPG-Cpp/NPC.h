#pragma once

class NPC : public Character {
public:
	NPC(int32_t _x, int32_t _y, const char* _name, const char* _sprite, int16_t _max_hp) {
		sprite = new Sprite*;
		x = _x;  y = _y;
		name = MyFunctions::strcpy(_name);
		*sprite = new Sprite(_sprite);
		max_hp = _max_hp;
		hp = _max_hp;
	}
	void Draw() override {
		Text text(name);
		(*sprite)->Draw();
		SetConsoleTextAttribute(hdl, 7);
		text.Move(x - text.w / 2 + (*sprite)->w / 2, y - 1);
		text.Draw();
	}
};