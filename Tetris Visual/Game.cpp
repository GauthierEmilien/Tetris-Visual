#include "stdafx.h"
#include "Game.h"

Plateau moveTab(nbLigne, nbColonne);
Plateau baseTab(nbLigne, nbColonne);
Plateau mainTab(nbLigne, nbColonne);

Game::Game()
{
	using namespace std::chrono_literals;

	etat = menu;
	while (etat != exit) {
		mainLoop();
		std::this_thread::sleep_for(17ms);
	}
		
}


Game::~Game()
{
}


char Game::randomNextShape()
{
	srand(time(NULL));
	int rnd = (rand() % (int)(7));
	return allShape[rnd];
}


void Game::detectKeyboardInGame()
{
	if (GetAsyncKeyState('Q') & 0x8000)
	{
		shapes[0].left(mainTab.getTab());
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		shapes[0].right(mainTab.getTab());
	}
	if (GetAsyncKeyState('S') & 0x8000) {
		downOrNewShape();
	}
	if (GetAsyncKeyState('Z') & 0x8000) {
		while (shapes[0].down(mainTab.getTab())) {
			continue;
		}
		Sleep(100);
	}
	if (GetAsyncKeyState(' ') & 0x8000) {
		shapes[0].rotateShape(moveTab.getTab(), baseTab.getTab());
		Sleep(100);
	}

	if (GetAsyncKeyState('H') & 0x8000) {
		etat = help;
	}


	if (GetAsyncKeyState('L') & 0x8000) {
		if (level < 16) {
			level = score / 100 + 1;
		}
			
		speed = 0;
	}
}

void Game::downOrNewShape()
{
	if (!shapes[0].down(mainTab.getTab())) {
		if (baseTab.loseParty()) {
			etat = lose;
		}

		baseTab.setShapeOnTab(shapes[0], 3);
		score += baseTab.checkLignes();
		if (level < 15)
		{
			level = score / 100 + 1;
			speed = 0;
		}

		shapes.erase(shapes.begin());
		shapes.push_back(Tetriminos(randomNextShape()));
	}
}

void Game::fallingSpeed()
{
	speed++;
	if (speed == 16 - level)
	{
		downOrNewShape();
		speed = 0;
	}
}


void Game::mainLoop()
{
	switch (etat)
	{
	case menu:
		menuLoop();
		break;
	case jeu:
		gameLoop();
		break;
	case help:
		helpLoop();
		break;
	case lose:
		loseLoop();
		break;
	case exit:
		etat = exit;
		break;
	default:
		break;
	}

}

void Game::clearMoveMainTab()
{
	for (int i = 0; i < (moveTab.getTab()).size(); i++) {
		for (int j = 0; j < (moveTab.getTab()[0]).size(); j++) {
			moveTab.setCase(i, j, 0);
			mainTab.setCase(i, j, 0);
		}
	}
}

void Game::gameLoop()
{
	detectKeyboardInGame();

	fallingSpeed();

	Affichage::plateau(mainTab.getTab(), score, level, shapes[1]);

	clearMoveMainTab();
	moveTab.setShapeOnTab(shapes[0], 1);

	mainTab.setBaseOnTab(baseTab.getTab());
	mainTab.setShapeOnTab(shapes[0], 1);

	
}

void Game::init()
{
	etat = jeu;
	shapes.push_back(Tetriminos(randomNextShape()));
	Sleep(2000);
	moveTab.setShapeOnTab(shapes[0], 1);
	mainTab.setShapeOnTab(shapes[0], 1);
	speed = 0;
	score = 0;
	level = score / 100 + 1;
	shapes.push_back(Tetriminos(randomNextShape()));
}

void Game::helpLoop()
{
	Affichage::help();

	if (GetAsyncKeyState('H') & 0x8000) {
		etat = jeu;
		Sleep(150);
	}
}

void Game::loseLoop()
{
	Affichage::lose(score, level);
	

	if (GetAsyncKeyState(' ') & 0x8000) {
		init();
		clearAllTab();
	}
	if (GetAsyncKeyState(27) & 0x8000) {
		etat = exit;
	}
}

void Game::menuLoop()
{
	Affichage::menu();

	if (GetAsyncKeyState(' ') & 0x8000) {
		init();
	}
	if (GetAsyncKeyState(27) & 0x8000) {
		etat = exit;
	}
}

void Game::clearAllTab()
{
	for (int i = 0; i < (moveTab.getTab()).size(); i++) {
		for (int j = 0; j < (moveTab.getTab()[0]).size(); j++) {
			moveTab.setCase(i, j, 0);
			mainTab.setCase(i, j, 0);
			baseTab.setCase(i, j, 0);
		}
	}
}


