#include "stdafx.h"
#include "Affichage.h"

void Affichage::plateau(std::vector<std::vector<int>> tab, int score, int level, Tetriminos shape)
{
	system("cls");
	for (int ligne = 0; ligne < tab.size(); ligne++) {
		std::cout << "||";
		for (int colonne = 0; colonne < tab[ligne].size(); colonne++) {
			if (tab[ligne][colonne] == 0) {
				std::cout << "  ";
			}
			else {
				char a(176);
				std::cout << a << a;
			}

		}
		std::cout << "||";
		HUD(score, level, shape, ligne);
		std::cout << std::endl;
	}
	std::cout << " ====================== " << std::endl;
}

void Affichage::help()
{
	system("cls");
	std::cout << " =======HELP MENU====== " << std::endl;
	std::cout << "Q/D : deplacer la pièce respectivement a gauche et a droite" << std::endl;
	std::cout << "S : accelerer la chute de la piece" << std::endl;
	std::cout << "Z : poser la piece directement le plus bas possible" << std::endl;
	std::cout << "ESPACE : changer la sens de la piece" << std::endl;
	std::cout << "H : entrer/sortir du menu d'aide" << std::endl;
}

void Affichage::lose(int score, int level)
{
	system("cls");
	std::cout << "\n\n\n =======GAME OVER====== " << std::endl;
	std::cout << "    Votre score  : " << score << std::endl;
	std::cout << "    Votre niveau : " << level << std::endl;
	std::cout << "\n\n\n  ESPACE pour rejouer" << std::endl;
	std::cout << "  ECHAP pour quitter" << std::endl;
}

void Affichage::menu()
{
	system("cls");
	std::cout << "\n ========TETRIS========= " << std::endl;
	std::cout << "    ESPACE pour jouer" << std::endl;
	std::cout << "    ECHAP pour quitter" << std::endl;

}

void Affichage::HUD(int score, int level, Tetriminos shape, int ligne)
{
	std::vector<std::vector<int>> tabShape = shape.getTabRotate();
	if (ligne == 2) {
		std::cout << "  Score : " << score;
	}
	else if (ligne == 3) {
		std::cout << "  Level : " << level;
	}
	else if (ligne == 5) {
		std::cout << "   Next :";
	}
	else if (ligne > 5 && ligne < tabShape.size() + 6) {
		std::cout << "  |";
		for (int colonne = 0; colonne < tabShape[0].size(); colonne++) {
			if (tabShape[ligne - 6][colonne] == 0) {
				std::cout << "  ";
			}
			else {
				char a(176);
				std::cout << a << a;
			}	
		}
		std::cout << "|";
	}
}
