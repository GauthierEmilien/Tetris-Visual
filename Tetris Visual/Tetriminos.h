#pragma once
#include <vector>
#include <algorithm>

class Tetriminos
{
public:
	Tetriminos(char forme);
	~Tetriminos();

	int *getBlocCentre();								//Retourne le bloc de rotation de la piece
	int *getBloc2();									//Retourne un bloc de la piece
	int *getBloc3();									//   ""    ""  ""  "" ""   ""
	int *getBloc4();									//   ""    ""  ""  "" ""   ""
	std::vector<std::vector<int>> getTabRotate();		//Retourne le tableau contenant la piece (3x3 ou 4x4)

	bool down(std::vector<std::vector<int>> & tab);		//Fait descendre la piece
	bool right(std::vector<std::vector<int>> & tab);	//Fait aller la piece sur la droite
	bool left(std::vector<std::vector<int>> & tab);		//Fait aller la piece sur la gauche

	void rotateShape(std::vector<std::vector<int>>& tab, std::vector<std::vector<int>>& baseTab);	//Lance la rotation de la piece avec toutes les verifications au prealable
	

private:
	std::vector<std::vector<int>> tabRotate;	///Tableau contenant la piece (sert pour la rotation)
	char shape;									///Caractere definissant la forme de la piece
	int allBlocs[4][2] = { {1,4},{0,4} };		///Tableau contenant les positions de chaque bloc de la piece

	void setBlocInTabRotate(std::vector<std::vector<int>> & tab);	//Recupere la piece dans le plateau de jeu et la met dans tabRotate pour effectuer la rotation
	void transpose();												//Transpose la matrice (tableau) tabRotate pour effectuer la rotation
	void rotate(std::vector<std::vector<int>>& tab, std::vector<std::vector<int>>& baseTab);	//lance la rotation de la piece
	void setCoordBlocs(std::vector<std::vector<int>>& tab);			//Set les coordonnees de chaque bloc de la piece dans le plateau de jeu apres rotation
	bool emptyCheck(std::vector<std::vector<int>>& tab);			//Verifie si apres rotation, la piece rentre dans l'espace disponible (elle est lance avant setCoordBloc)

	void createShape();		///Lance la creation de la piece en fonction de son caractere
	void createI();			///Creation du I
	void createJ();			///Creation du J
	void createL();			///Creation du L
	void createO();			///Creation du O
	void createS();			///Creation du S
	void createZ();			///Creation du Z
	void createT();			///Creation du T
	
};

