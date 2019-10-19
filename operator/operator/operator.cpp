// operator.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

/*
class Student
{
	int ocenaCalkowita;
	float ocenaNiecalkowita;
	float suma;
public:
	Student(int oC = 0, float oN = 0) : ocenaCalkowita(oC), ocenaNiecalkowita(oN)
	{};

	Student operator+(Student jakis)
	{
		Student rezultat;
		rezultat.suma = jakis.ocenaCalkowita + jakis.ocenaNiecalkowita;
		return rezultat;
	}
};
*/
class platnosc
{
public:
	
	int kwota;
	string nazwa;
	platnosc * next;
	platnosc(int kw,string na) :kwota(kw),nazwa(na)
	{
		next = nullptr;
	}
	
};

class spis_platnosci
{
protected:
	platnosc *head,
		*obecna;
public:
	
	spis_platnosci():head(NULL){}
	virtual spis_platnosci & operator+=(const platnosc &pl) // virtual!!!
	{
		platnosc *nowa = new platnosc(pl);
		platnosc * obecna = head;
		if (head == nullptr)
		{
			head = nowa;
			nowa->kwota = pl.kwota;
			nowa->nazwa = pl.nazwa;
		}
		else
		{
			while (obecna->next)
			{
				obecna=obecna->next;
			}
			obecna->next = nowa;
			nowa->kwota = pl.kwota;
			nowa->nazwa = pl.nazwa;
			nowa->next = nullptr;
		}
		
		return *this;
	}
	friend ostream & operator<< (ostream &wyjscie, const spis_platnosci &spis)
	{
		platnosc *pl = spis.head;
		while (pl)
		{
			wyjscie << pl->kwota << " ";
			wyjscie << pl->nazwa << " ";
			pl = pl->next;
		}
		return wyjscie;
	}
};

class kolejka_wydatkow :spis_platnosci
{

};


int main()
{
	spis_platnosci spis;
	spis += platnosc(500, "Zosia");
	spis += platnosc(400, "Jan");
	spis += platnosc(300, "Janina");
	cout << spis;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
