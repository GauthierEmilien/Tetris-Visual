#pragma once
#include <vector>
#include "Tetriminos.h"
#include <algorithm>


class Plateau
{
public:
	Plateau(int nbLigne, int nbColonne);							///Constructeur du plateau de jeu
	~Plateau();
	std::vector<std::vector<int>> getTab();							///Retourne le tableau de jeu
	void setShapeOnTab(Tetriminos shape, int value);				///Rajoute une piece sur le plateau
	void setBaseOnTab(std::vector<std::vector<int>> &baseTab);		///Rajoute toutes les pieces qui sont deja tombes tout en bas
	void clearTab();												///Set toutes les cases du tableau a 0
	int checkLignes();												///Vérifie si il y a une ligne complete dans le tableau, la supprime s'il en trouve une
	void setCase(int ligne, int colonne, int value);				///Change la valeur d'une case
	bool loseParty();												///Fait perdre le joueur lorsqu'une piece arrive tout en haut

private:
	int nbLigne;						//Nombre de ligne dans le tableau
	int nbColonne;						//Nombre de colonne dans le tableau
	std::vector<std::vector<int>> tab;	//Plateau de jeu

	void createTab();					//Initialise toutes les cases du tableau a 0
	void deleteLigne(int ligne);		//Supprime une ligne du tableau et en rajoute une tout en haut
	
};

