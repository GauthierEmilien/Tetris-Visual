#include "stdafx.h"
#include "Tetriminos.h"


Tetriminos::Tetriminos(char forme) : shape(forme)
{
	createShape();
}


Tetriminos::~Tetriminos()
{
}

int * Tetriminos::getBlocCentre()
{
	return allBlocs[0];
}

int * Tetriminos::getBloc2()
{
	return allBlocs[1];
}

int * Tetriminos::getBloc3()
{
	return allBlocs[2];
}

int * Tetriminos::getBloc4()
{
	return allBlocs[3];
}

std::vector<std::vector<int>> Tetriminos::getTabRotate()
{
	return tabRotate;
}


bool Tetriminos::down(std::vector<std::vector<int>>& tab)
{
	int nbL = tab.size() - 1;
	if (allBlocs[0][0] < nbL && allBlocs[1][0] < nbL
		&& allBlocs[2][0] < nbL && allBlocs[3][0] < nbL)
	{
		if (tab[allBlocs[0][0] + 1][allBlocs[0][1]] < 3 &&
			tab[allBlocs[1][0] + 1][allBlocs[1][1]] < 3 &&
			tab[allBlocs[2][0] + 1][allBlocs[2][1]] < 3 &&
			tab[allBlocs[3][0] + 1][allBlocs[3][1]] < 3) {
			allBlocs[0][0]++;
			allBlocs[1][0]++;
			allBlocs[2][0]++;
			allBlocs[3][0]++;
			return true;
		}
	}
	return false;
}

bool Tetriminos::right(std::vector<std::vector<int>>& tab)
{
	int nbC = tab[0].size() - 1;

	if (allBlocs[0][1] < nbC && allBlocs[1][1] < nbC
		&& allBlocs[2][1] < nbC && allBlocs[3][1] < nbC) {
		if (tab[allBlocs[0][0]][allBlocs[0][1] + 1] < 3 &&
			tab[allBlocs[1][0]][allBlocs[1][1] + 1] < 3 &&
			tab[allBlocs[2][0]][allBlocs[2][1] + 1] < 3 &&
			tab[allBlocs[3][0]][allBlocs[3][1] + 1] < 3) {
			allBlocs[0][1]++;
			allBlocs[1][1]++;
			allBlocs[2][1]++;
			allBlocs[3][1]++;
			return true;
		}
	}
	return false;
}

bool Tetriminos::left(std::vector<std::vector<int>>& tab)
{
	if (allBlocs[0][1] > 0 && allBlocs[1][1] > 0
		&& allBlocs[2][1] > 0 && allBlocs[3][1] > 0) {
		if (tab[allBlocs[0][0]][allBlocs[0][1] - 1] < 3 &&
			tab[allBlocs[1][0]][allBlocs[1][1] - 1] < 3 &&
			tab[allBlocs[2][0]][allBlocs[2][1] - 1] < 3 &&
			tab[allBlocs[3][0]][allBlocs[3][1] - 1] < 3) {
			allBlocs[0][1]--;
			allBlocs[1][1]--;
			allBlocs[2][1]--;
			allBlocs[3][1]--;
			return true;
		}
	}
	return false;
}

void Tetriminos::rotateShape(std::vector<std::vector<int>>& moveTab, std::vector<std::vector<int>>& baseTab)
{
	if (shape != 'O') {
		rotate(moveTab, baseTab);
	}
	setCoordBlocs(baseTab);
}

void Tetriminos::transpose()
{
	std::vector<std::vector<int>> tabCopy(tabRotate);
	for (int i = 0; i < tabCopy.size(); i++) {
		for (int j = 0; j < tabCopy[0].size(); j++) {
			tabRotate[i][j] = tabCopy[j][i];
		}
	}
}

void Tetriminos::rotate(std::vector<std::vector<int>>& tab, std::vector<std::vector<int>>& baseTab)
{
	bool rotatePossible = true;
	if (allBlocs[0][1] == 0) {
		if (!right(baseTab)) {
			rotatePossible = false;
		}
	}
	else if (allBlocs[0][1] == tab[0].size() - 1) {
		if (!left(baseTab)) {
			rotatePossible = false;
		}
		else {
			if (shape == 'I') {
				left(baseTab);
			}
		}
	}
	else if (allBlocs[0][1] == tab[0].size() - 2 && shape == 'I') {
		if (!left(baseTab)) {
			rotatePossible = false;
		}
	}

	if (rotatePossible) {
		setBlocInTabRotate(tab);
		transpose();
		if (shape != 'I') {
			std::reverse(tabRotate.begin(), tabRotate.end());
		}
	}	
}

bool Tetriminos::emptyCheck(std::vector<std::vector<int>>& baseTab)
{
	for (int i = 0; i < tabRotate.size(); i++)
	{
		for (int j = 0; j < tabRotate[0].size(); j++)
		{
			if (tabRotate[i][j] == 1)
			{
				if (!(baseTab[i + (allBlocs[0][0] - 1)][j + (allBlocs[0][1] - 1)] < 3)) {
					return false;	
				}
			}
		}
	}
	return true;
}

void Tetriminos::setCoordBlocs(std::vector<std::vector<int>>& baseTab)
{
	int bloc = 1;
	if (emptyCheck(baseTab)) {
		for (int i = 0; i < tabRotate.size(); i++)
		{
			for (int j = 0; j < tabRotate[0].size(); j++)
			{
				if (tabRotate[i][j] == 1)
				{
					//trouver pour mettre les coordonnées des blocs
					allBlocs[bloc][0] = i + (allBlocs[0][0] - 1);
					allBlocs[bloc][1] = j + (allBlocs[0][1] - 1);
					bloc++;
				}
			}
		}
	}
	
	
}



void Tetriminos::setBlocInTabRotate(std::vector<std::vector<int>>& tab)
{
	tabRotate[1][1] = 2;
	tabRotate[allBlocs[1][0] - (allBlocs[0][0] - 1)][allBlocs[1][1] - (allBlocs[0][1] - 1)] = 1;
	tabRotate[allBlocs[2][0] - (allBlocs[0][0] - 1)][allBlocs[2][1] - (allBlocs[0][1] - 1)] = 1;
	tabRotate[allBlocs[3][0] - (allBlocs[0][0] - 1)][allBlocs[3][1] - (allBlocs[0][1] - 1)] = 1;
}


void Tetriminos::createShape()
{
	tabRotate.push_back(std::vector<int>(3, 0));
	tabRotate.push_back(std::vector<int>(3, 0));
	tabRotate.push_back(std::vector<int>(3, 0));

	switch (shape)
	{
	case 'I':
		createI();
		break;
	case 'J':
		createJ();
		break;
	case 'L':
		createL();
		break;
	case 'O':
		createO();
		break;
	case 'S':
		createS();
		break;
	case 'Z':
		createZ();
		break;
	case 'T':
		createT();
		break;
	default:
		break;
	}
}

void Tetriminos::createI()
{
	tabRotate[0].push_back(0);
	tabRotate[1].push_back(0);
	tabRotate[2].push_back(0);
	tabRotate.push_back(std::vector<int>(4, 0));

	tabRotate[0][1] = 1;
	tabRotate[1][1] = 1;
	tabRotate[2][1] = 1;
	tabRotate[3][1] = 1;
	allBlocs[2][0] = 2;
	allBlocs[2][1] = 4;
	allBlocs[3][0] = 3;
	allBlocs[3][1] = 4;
;}

void Tetriminos::createJ()
{
	tabRotate[0][1] = 1;
	tabRotate[1][1] = 1;
	tabRotate[2][1] = 1;
	tabRotate[2][0] = 1;
	allBlocs[2][0] = 2;
	allBlocs[2][1] = 4;
	allBlocs[3][0] = 2;
	allBlocs[3][1] = 3;
}

void Tetriminos::createL()
{
	tabRotate[0][1] = 1;
	tabRotate[1][1] = 1;
	tabRotate[2][1] = 1;
	tabRotate[2][2] = 1;
	allBlocs[2][0] = 2;
	allBlocs[2][1] = 4;
	allBlocs[3][0] = 2;
	allBlocs[3][1] = 5;
}

void Tetriminos::createO()
{
	tabRotate[0][0] = 1;
	tabRotate[1][0] = 1;
	tabRotate[0][1] = 1;
	tabRotate[1][1] = 1;
	allBlocs[2][0] = 0;
	allBlocs[2][1] = 5;
	allBlocs[3][0] = 1;
	allBlocs[3][1] = 5;
}

void Tetriminos::createZ()
{
	tabRotate[0][0] = 1;
	tabRotate[0][1] = 1;
	tabRotate[1][1] = 1;
	tabRotate[1][2] = 1;
	allBlocs[2][0] = 0;
	allBlocs[2][1] = 3;
	allBlocs[3][0] = 1;
	allBlocs[3][1] = 5;
}

void Tetriminos::createS()
{
	tabRotate[0][1] = 1;
	tabRotate[0][2] = 1;
	tabRotate[1][0] = 1;
	tabRotate[1][1] = 1;
	allBlocs[2][0] = 1;
	allBlocs[2][1] = 3;
	allBlocs[3][0] = 0;
	allBlocs[3][1] = 5;
}

void Tetriminos::createT()
{
	tabRotate[1][0] = 1;
	tabRotate[1][1] = 1;
	tabRotate[1][2] = 1;
	tabRotate[0][1] = 1;
	allBlocs[2][0] = 1;
	allBlocs[2][1] = 3;
	allBlocs[3][0] = 1;
	allBlocs[3][1] = 5;
}
