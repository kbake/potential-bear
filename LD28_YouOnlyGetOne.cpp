// LD28_YouOnlyGetOne.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Game game;

	// Let the game handle itself
	game.Start();

	return 0;
}

