#include "../include/Robot3.h"
#include <iostream>
using namespace std;


/* Modul de deplasare al robotului1 la fiecare runda executata */
int Robot3::push()
{

	if (index1 < N - 1 && index2 < N - 1)
	{
		index1++;
		index2++;

		return 0; // Continuam deplasarea robotului cu o pozitie
	}
	else if (index1 == N - 1 && index2 == N - 1) // Robotul3 se deplaseaza pe diagonala principala a hartii
		if (map[index1][index2] == 9)           // si apoi afiseaza un mesaj corespunzator 
		{
			cout << " Robotul a sosit la finish ! " << endl;
			return 1;
		}
		else
		{
			cout << " Robotul nu a sosit la finish ! A ramas blocat in colt ! " << endl;
			return 1;
		}
	return 0;
}


/* Itemul1  nu este compatibil pentru Robotul3 ,deci devine capcana pentru acesta si se da inapoi o casuta */
void Robot3::item1()
{
	if (index1 != 0 && index2 != 0)
	{
		index1--;
		index2--;
	}
}


/* Itemul2 nu este compatibil pentru Robotul3 ,deci devine capcana si se da inapoi doua casute */
void Robot3::item2()
{
	if (index1 != 0 && index2 != 0)
		if (index1 != 1 && index2 != 1)
		{
			index1 -= 2;
			index2 -= 2;
		}
		else
		{
			index1--; // In cazul in care nu are cum sa mai scada doua casute si scade una daca este posibil
			index2--;
		}

}


/* Itemul3 este compatibil pentru Robotul3 ,deci devine bonus si inainteaza 3 casute */
void Robot3::item3()
{
	if (index1 != N - 1 && index2 != N - 1)
		if (index1 != N - 2 && index2 != N - 2)
			if (index1 != N - 3 && index2 != N - 3)
			{
				index1 += 3;
				index2 += 3;
			}
			else
			{
				index1 += 2; // In cazul in care nu are cum sa mai inainteze 3 casute si inainteaza 2 daca este posibil
				index2 += 2;
			}
		else
		{
			index1 += 1; // In cazul in care nu are cum sa mai inainteze 3 sau 2 casure si inainteaza 1 daca este posibil
			index2 += 1;
		}
}


/* Afisarea pozitiei curente a robotului, si a numarului de bonusuri si capcane culese */
void Robot3::display()
{

	if (index2 != N)
		cout << " Robotul Nr.3 se afla pe linia " << index1 << ", coloana " << index2 << endl;
	switch (map[index1][index2])
	{
	case 1:
		nrCapcane++;
		break;
	case 2:
		nrCapcane++;
		break;
	case 3:
		nrBonusuri++;
		break;
	}
	cout << " Bonuses: " << nrBonusuri << endl;
	cout << " Traps: " << nrCapcane << endl;

}

