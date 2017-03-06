#include "stdafx.h"
#include "Plateau.h"


Plateau::Plateau(int nbLigne, int nbColonne) : nbLigne(nbLigne), nbColonne(nbColonne)
{
	createTab();
}


Plateau::~Plateau()
{
}

std::vector<std::vector<int>> Plateau::getTab()
{
	return tab;
}

void Plateau::createTab()
{
	for (int i = 0; i < nbLigne; i++) {
		tab.push_back(std::vector<int>(nbColonne, 0));
	}
}

void Plateau::deleteLigne(int ligne)
{
	tab.erase(tab.begin() + ligne);
	tab.insert(tab.begin(), std::vector<int>(nbColonne, 0));
}

void Plateau::setShapeOnTab(Tetriminos shape, int value)
{
	tab[shape.getBlocCentre()[0]][shape.getBlocCentre()[1]] = value + 1;
	tab[shape.getBloc2()[0]][shape.getBloc2()[1]] = value;
	tab[shape.getBloc3()[0]][shape.getBloc3()[1]] = value;
	tab[shape.getBloc4()[0]][shape.getBloc4()[1]] = value;
	/*int ligne(0);
	int colonne;
	for (int i = shape.getBlocCentre()[0] - 1; i < shape.getBlocCentre()[0] + 2; i++) {
		colonne = 0;
		for (int j = shape.getBlocCentre()[1] - 1; j < shape.getBlocCentre()[1] + 2; j++) {
			if (shape.getTabRotate()[ligne][colonne] == 1) {
				tab[i][j] = value;
			}
			colonne++;
		}
		ligne++;
	}*/
}

void Plateau::setBaseOnTab(std::vector<std::vector<int>> & baseTab)
{
	for (int i = 0; i < nbLigne; i++) {
		for (int j = 0; j < nbColonne; j++) {
			if (baseTab[i][j] != 0) {
				tab[i][j] = 3;
			}
		}
	}
}

void Plateau::clearTab()
{
	for (int i = 0; i < nbLigne; i++) {
		for (int j = 0; j < nbColonne; j++) {
			tab[i][j] = 0;
		}
	}
}

int Plateau::checkLignes()
{
	int count(0);
	for (int i = 0; i < nbLigne; i++) {
		bool fullLigne(true);
		for (int j = 0; j < nbColonne; j++) {
			if (fullLigne == true) {
				if (tab[i][j] == 0) {
					fullLigne = false;
				}
			}
		}
		//supprimer ligne
		if (fullLigne == true) {
			deleteLigne(i);
			count++;
		}
	}
	return count * 10;
}

void Plateau::setCase(int ligne, int colonne, int value)
{
	tab[ligne][colonne] = value;
}

bool Plateau::loseParty()
{
	return std::find(tab[0].begin(), tab[0].end(), 3) != tab[0].end();
}

