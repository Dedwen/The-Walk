#pragma once


class Map
{

protected:
	int **map; // Mapa propriu zisa
	int index1 = 0, index2 = 0; // Coordonatele retinute pentru robot
	const int N; // Marimea Hartii
	static int nr; // Nr de runde executate de un robot
	int nrCapcane = 0, nrBonusuri = 0;

public:
	Map();
	virtual int push() = 0;
	virtual void item1() = 0;
	virtual void item2() = 0;
	virtual void item3() = 0;
	virtual void display() = 0;
	void pause();
	void check();
	void draw();
	virtual ~Map();

};

