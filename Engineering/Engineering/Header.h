#ifdef HEADER_H
#define HEADER_H
#include<amp_math.h>

class load_specification
{
	char landform[4];
	load_specification* next;
	int H;
	float alpha;
};
class WindPressure
{
private:
	void height;
	void windward_width;
	void cycle_time;
public:
	void height_change();
	void mode_coefficient;
	void pulsation_upright;
	void pulsation_level;

};

#endif // HEADER_H
