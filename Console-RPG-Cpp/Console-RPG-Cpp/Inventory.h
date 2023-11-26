#pragma once
#define item_size 3

class Item {
public:
	Label** icon;
	int amount;
	char* name;
	Item(const char* _icon, const char* name): icon(new Label*), amount(1) {
		*icon = new Label(_icon, full_symbol);
	}
	void Draw(int8_t cx, int8_t cy) {
		(*icon)->Move(cx, cy);
		(*icon)->Draw();
	}
};

class Chest {
public:
	Item** items;
	Area** area;
	Chest(int8_t _w, int8_t _h, char _background, char _border) : items(new Item*), area(new Area*){
		*area = new Area(_w * item_size, _h * item_size, ' ', full_symbol);
	}

};