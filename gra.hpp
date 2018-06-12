/*
 * gra.hpp
 *
 *  Created on: 4 maj 2018
 *      Author: Mariusz
 */

#ifndef GRA_HPP_
#define GRA_HPP_

#include <iostream>
#include <cstdlib>
using namespace std;

void rysuj_plansze(char *tab, int rozmiar);
bool wygrana(char *tab, int rozmiar, int znaki, char symbol);
bool remis(char *tab, int rozmiar, int znaki);
void czyszczenie_planszy(char *tab, int rozmiar);
void rozgrywka(char *tab, int rozmiar, int znaki, int maksymalna_glebokosc);

int ruch_komputera(char *tab, int rozmiar, int znaki, int maksymalna_glebokosc);
int minmax(char *tab, int rozmiar, int znaki, int obecna_glebokosc, int maksymalna_glebokosc, bool MAX, int alpha, int beta);

#endif /* GRA_HPP_ */
