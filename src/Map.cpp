#include "../include/Map.h"
#include <time.h>
#include <iostream>
using namespace std;


int Map::nr = 0;


/* Constructorul fara parametrii care aloca dinamic memorie pentru matricea mapei */
Map::Map() 
	: N(15)
{
	map = new int*[N] { 0 }; // Avem o mapa de coordonate de la 0 la 14.
	for (int i = 0; i < N; ++i)
		map[i] = new int[N] { 0 };
	
	/* Itemul1 initializat random pe mapa */
	//srand(time(0));
	map[0 + (rand() % 14)][0 + (rand() % 14)] = 1;
	map[0 + (rand() % 14)][0 + (rand() % 14)] = 1;
	map[0 + (rand() % 14)][0 + (rand() % 14)] = 1;

	/* Itemul2 initializat random pe mapa */
	//srand(time(0));
	map[0 + (rand() % 14)][0 + (rand() % 14)] = 2;
	map[0 + (rand() % 14)][0 + (rand() % 14)] = 2;
	map[0 + (rand() % 14)][0 + (rand() % 14)] = 2;

	/* Itemul3 initializat random pe mapa */
	//srand(time(0));
	map[0 + (rand() % 14)][0 + (rand() % 14)] = 3;
	map[0 + (rand() % 14)][0 + (rand() % 14)] = 3;
	map[0 + (rand() % 14)][0 + (rand() % 14)] = 3;

	/* Finish-ul initializat random pe mapa */
	//srand(time(0));
	map[0 + (rand() % 14)][1 + (rand() % 14)] = 9; // valoarea '9' este recunoscuta ca valoare pentru "finish"

}


/* Functie de iesire sau continuare a jocului dupa ce robotul ajunge la un item
   Raspunsul este primit de la tastatura
*/
void Map::pause()
{
	int r;
	cout << " Robotul a luat un item ! " << endl << " Continuati ?(1/0) " << endl << " R: ";
	cin >> r;
	if (!r)
		exit(1);
}


/* Functie de verificare a obiectului primit */
void Map::check()
{

	switch (map[index1][index2])
	{
	case 1:
	{
		map[index1][index2] = 0;
		pause();
		item1();
		break;
	}
	case 2:
	{
		map[index1][index2] = 0;
		pause();
		item2();
		break;
	}
	case 3:
	{
		map[index1][index2] = 0;
		pause();
		item3();
		break;
	}
	}
}


/* Functie care desenaza mapa in consula */
void Map::draw() 
{

	system("cls"); // Curata ecranul
	for (int i = 0; i < N + 2; ++i) // Zidul de sus(width+2 deoarece trebuie sa acopere si marginile laterale)
		cout << "#";
	cout << endl; // Se trece pe randul urmator

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (j == 0)       //  Zidul
				cout << "#"; //       din stanga.

			if (i == index1 && j == index2) // Verificam daca coordonatele corespundul cu cele ale robotului si apoi afisam
				cout << "R";
			else
				switch (map[i][j])
				{
				case 1:
				{
					cout << "1";
					break;
				}
				case 2:
				{
					cout << "2";
					break;
				}
				case 3:
				{
					cout << "3";
					break;
				}
				case 9:
				{
					cout << "X";
					break;
				}
				default:
					cout << " "; // Interiorul mapei
				}

			if (j == N - 1) // Zidul
				cout << "#";   //      din dreapta
		}
		cout << endl; // Se trece cu urmatoarea linie pe randul urmator
	}

	for (int i = 0; i < N + 2; ++i) // Zidul de jos
		cout << "#";
	cout << endl; // Se trece pe randul urmator

	cout << " Round: " << ++nr << endl;
}


/* Dezalocare memorie alocata */
Map::~Map()
{

	for (int i = 0; i < N; ++i)
		delete[] map[i];
	delete[] map;

}