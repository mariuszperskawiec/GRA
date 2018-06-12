//============================================================================
// Name        : Gra.cpp
// Author      : Mariusz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "gra.hpp"
using namespace std;

int main() {

	int maksymalna_glebokosc = 7;
	int rozmiar = 3;
	int ilosc_znakow = 3;
	int wybor = 0;
	char znak = 't';
	enum { latwy, sredni, trudny };
	int poziom = trudny;




	// Menu gry
	while (znak == 't' || znak == 'T') {
		cout << endl;
		cout << "+++++ Gra w Kolko i Krzyzyk +++++" << endl;
		cout << "+++++++++++++++++++++++++++++++++" << endl;
		cout << "+ Rozmiar planszy:        " << rozmiar << "     +" << endl;
		cout << "+ Ilosc znakow w rzedzie: " << ilosc_znakow<< "     +" << endl;
		if (poziom == latwy) cout << "+ Poziom  gry  : latwy (" << maksymalna_glebokosc  << " ruch) +" << endl;
		if (poziom == sredni)cout << "+ Poziom  gry :sredni (" << maksymalna_glebokosc << " ruchy) +" << endl;
		if (poziom == trudny)cout << "+ Poziom gry :trudny (" << maksymalna_glebokosc << " ruchow) +" << endl;
		cout << "+++++++++++++++++++++++++++++++++" << endl << endl;
		cout << "  1 - Zmien rozmiar planszy" << endl;
		cout << "  2 - Zmien ilosc znakow w rzedzie" << endl;
		cout << "  3 - Zmien poziom gry" << endl;
		cout << "  4 - Rozpocznij nowa gre" << endl;
		cout << "  0 - Zakoncz" << endl;
		cout << "  Twoj wybor: ";

		cin >> wybor;
		switch (wybor) {
		case 1:
			cout << "Podaj szerokosc planszy na jakiej chcesz grac: ";
			cin >> rozmiar;
			while (rozmiar < 2) {
				cout << "Podano zly rozmiar planszy, podaj jeszcze raz: ";
				cin >> rozmiar;
			}
			break;

		case 2:
			cout << "Podaj ilosc znakow potrzebnych do wygrania: ";
			cin >> ilosc_znakow;
			while (ilosc_znakow > rozmiar) {
				cout << "Ilosc znakow nie moze byc wieksza, od rozmiaru planszy"
						<< endl;
				cout << "Podaj jeszcze raz: ";
				cin >> ilosc_znakow;
			}
			while (ilosc_znakow < 2) {
				cout << "Ilosc znakow nie moze byc zbyt mala" << endl;
				cout << "Podaj jeszcze raz: ";
				cin >> ilosc_znakow;
			}

			break;

		case 3:
			cout << "1 - latwy" << endl;
			cout << "2 - sredni" << endl;
			cout << "3 - trudny" << endl;
			cout << "Wybierz poziom: ";
			cin >> wybor;
			if (wybor == 1) {poziom =  latwy; maksymalna_glebokosc = 1;}
			if (wybor == 2) {poziom = sredni; maksymalna_glebokosc = 3;}
			if (wybor == 3) {poziom = trudny; maksymalna_glebokosc = 7;}
			break;

		case 4:
		{
			char *tab = new char[rozmiar * rozmiar]; // tworzymy tablicê dynamiczna dla gry
			czyszczenie_planszy(tab, rozmiar);// czyœcimy tablice w celu pozbycia siê œmieci
			rozgrywka(tab, rozmiar, ilosc_znakow, maksymalna_glebokosc);


			cout << "Jeszcze raz? (t -tak) ";
			cin >> znak;
			delete[] tab;
		}
			break;

		case 0:
			znak = 'p';
			break;

		}

	}


	return 0;

}

