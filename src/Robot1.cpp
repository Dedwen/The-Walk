#include "../include/Robot1.h"
#include <iostream>
using namespace std;


/* Modul de deplasare al robotului1 la fiecare runda executata */
int Robot1::push() 
{

	if (map[index1][index2] == 9)
	{
		cout << " Robotul a sosit la finish ! " << endl;
		return 1;
	}

	if (index1 < N - 1 && index2 < N - 1)
	{
		index2++;

		return 0; // Continuam deplasarea robotului cu o pozitie
	}
	else if (index1 < N - 1 && index2 == N - 1) // Daca ajungem la sfarsitul liniei , atunci 
	{                                          // trecem la urmatoarea linie prin "Index1++" 
		index2 = 0;                           // si resetam valoarea lui Index2
		index1++;
	}
	return 0;
}


/* Itemul1 este compatibil pentru Robotul1, deci inainteaza 3 casute ajutat de acel item */
void Robot1::item1()
{

	switch (index2)
	{
	case 14:
	{
		index1++;
		index2 = 2;
		break;
	}
	case 13:
	{
		index1++;
		index2 = 1;
		break;
	}
	case 12:
	{
		index1++;
		index2 = 0;
		break;
	}

	default:
		index2 += 3;
	}
}


/* Itemul2 nu este compatibil pentru Robotul1 ,deci devine capcana si se da inapoi o casuta */
void Robot1::item2() 
{
	
	if (index2 != 0)
		index2--;
	else
	{
		index1--;
		index2 = N - 1;
	}
}


/* Itemul3 nu este compatibil pentru Robotul1 ,deci devine capcana si se da inapoi doua casute */
void Robot1::item3()
{
	
	switch (index2)
	{
	case 0:
	{
		if (index1 != 0)
		{
			index1--;
			index2 = N - 2;
		}
		break;
	}
	case 1:
	{
		index1--;
		index2 = N - 1;
		break;
	}
	default:
		index2 -= 2;
	}
}


/* Afisarea pozitiei curente a robotului, si a numarului de bonusuri si capcane culese */
void Robot1::display()
{
	if (index2 != N)
		cout << " Robotul Nr.1 se afla pe linia " << index1 << ", coloana " << index2 << endl;
	switch (map[index1][index2])

	{
	case 1:
		nrBonusuri++;
		break;
	case 2:
		nrCapcane++;
		break;
	case 3:
		nrCapcane++;
		break;
	}
	cout << " Bonuses: " << nrBonusuri << endl;
	cout << " Traps: " << nrCapcane << endl;

}

