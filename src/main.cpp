/* 
   Avem o clasa principala "Map" si inca 3 clase derivate "Robot1", "Robot2", "Robot3".
   Clasa principala reprezinta mapa propriu zisa unde robotul se misca si actioneaza in functie de itemi si modul in care se deplaseaza.
   Clasele derivate reprezinta tipul ficarui robot din joc. 
   Fiecare robot se deplaseaza diferit si reactioneaza altfel fata te itemele altui robot.

*/
#include "../include/Map.h"
#include "../include/Robot1.h"
#include "../include/Robot2.h"
#include "../include/Robot3.h"
#include <windows.h>
#include <iostream>
using namespace std;

/* Alegem modelul robotului de la tastatura */
int main()
{
	int choice = 0;
	cout << endl << "   B I N E   A I   V E N I T   I N   J O C U L   \" T H E   W A L K \"   ! " << endl;
	cout << endl << " ALEGETI MODELUL ROBOTULUI (R: 1/2/3). " << endl;
	cout << " R: ";
	cin >> choice;

	Map *start = NULL;

	switch (choice)
	{
	case 1:
	{
		start = new Robot1(); // Startul pentru robotul1 pe mapa

		break;
	}
	case 2:
	{
		start = new Robot2(); // Startul pentru robotul1 pe mapa
		break;
	}
	case 3:
	{
		start = new Robot3(); // Startul pentru robotul1 pe mapa
		break;
	}
	default:

		cout << " MODELUL ALES DE TINE NU EXISTA ! " << endl;
	
	}

	while (start->push() == 0)
	{
		start->draw();
		start->display();
		Sleep(100);
		start->check();
	}

	system("pause");
	return 0;

}

