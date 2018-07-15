#include "../include/Robot2.h"
#include <iostream>
using namespace std;


/* Modul de deplasare al robotului1 la fiecare runda executata */
int Robot2::push() 
{

		if (map[index1][index2] == 9)
		{
			cout << " Robotul a sosit la finish ! " << endl;
			return 1;
		}

		if (index1 < N - 1 && index2 < N - 1)
		{
			index1++;

			return 0; // Continuam deplasarea robotului cu o pozitie
		}
		else if (index1 == N - 1 && index2 < N - 1) // Daca ajungem la sfarsitul coloanei , atunci 
		{                                          // trecem la urmatoarea coloana prin "index2++" si
			index1 = 0;                           // resetam valoarea lui "index1"
			index2++;


		}

	return 0;
}


/* Itemul1 nu este compatibil pentru Robotul2, deci devine capcana si se da inapoi o casuta */
void Robot2::item1()
{
	if (index1 != 0)
		index1--;
	else
	{
		index2--;
		index1 = N - 1;
	}
}


/* Itemul2 este compatibil pentru Robotul2, deci devine bonus si inainteaza 3 casute */
void Robot2::item2()
{
	switch (index1)
	{
	case 14:
	{
		index2++;
		index1 = 2;
		break;
	}
	case 13:
	{
		index2++;
		index1 = 1;
		break;
	}
	case 12:
	{
		index2++;
		index1 = 0;
		break;
	}

	default:
		index1 += 3;
	}

}


/* Itemul3 nu este compatibil pentru Robotul2, deci devine capcana si se da inapoi doua casute */
void Robot2::item3()
{
	switch (index1)
	{
	case 0:
	{
		if (index2 != 0)
		{
			index2--;
			index1 = N - 2;
		}
		break;
	}
	case 1:
	{
		index2--;
		index1 = N - 1;
		break;
	}
	default:
		index1 -= 2;
	}
}


/* Afisarea pozitiei curente a robotului, si a numarului de bonusuri si capcane culese */
void Robot2::display()
{

	if (index2 != N)
		cout << " Robotul Nr.2 se afla pe linia " << index1 << ", coloana " << index2 << endl;
	switch (map[index1][index2])
	{
	case 1:
		nrCapcane++;
		break;
	case 2:
		nrBonusuri++;
		break;
	case 3:
		nrCapcane++;
		break;
	}
	cout << " Bonuses: " << nrBonusuri << endl;
	cout << " Traps: " << nrCapcane << endl;


}

