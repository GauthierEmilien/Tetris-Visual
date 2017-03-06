#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Tetriminos.h"

class Affichage
{
public:
	static void plateau(std::vector<std::vector<int>> tab, int score, int level, Tetriminos shape);		//Affiche le plateau de jeu
	static void help();																					//Affiche le menu d'aide
	static void lose(int score, int level);																//Affiche le menu de defaite
	static void menu();																					//Affiche le menu principal
private:	
	static void HUD(int score, int level, Tetriminos shape, int ligne);									//Affiche le score, le niveau et la piece suivante a cote du plateau de jeu
};

