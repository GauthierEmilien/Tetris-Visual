#pragma once
#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>
#include "Affichage.h"
#include "Tetriminos.h"
#include "Plateau.h"

const int nbLigne(21);
const int nbColonne(10);
const int levelMax(15);

class Game
{
public:
	Game();
	~Game();
	void mainLoop();

private:
	char randomNextShape();			//Renvoie un caractere qui defini la prochaine piece
	void detectKeyboardInGame();	//Detecte les touches dans la boucle de jeu
	void downOrNewShape();			//Detecte si une piece peut encore descendre ou non, si elle peut pas, cree une nouvelle piece
	void fallingSpeed();			//Regule la vitesse de descente des piece en fonction du niveau
	void clearMoveMainTab();		//Set toutes les case du plateau de mouvement et du tableau principal a 0 en meme temps
	void gameLoop();				//Boucle de jeu principale, lance les méthodes de detection de touches, etc...
	void init();					//Initialise la plateau et le score pour commencer une partie
	void helpLoop();				//Boucle du menu d'aide
	void loseLoop();				//Boucle du menu de defaite
	void menuLoop();				//Boucle du menu principal

	void clearAllTab();				//Set toutes les cases de tous les plateaux a 0

	std::vector<Tetriminos> shapes;					///Liste contenant la piece actuelle et la suivante
	std::string allShape = "IJLSZTO";				///String qui permet de tirer une piece aleatoirement
	enum allState { menu, jeu, help, lose, exit };	///Enumeration des differentes phase de jeu
	allState etat;									///Etat actuel du jeu

	int speed;		///Compteur qui permet de reguler la vitesse de descente des pieces
	int level;		///Niveau du joueur
	int score;		///Score du joueur
};

