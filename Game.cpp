#include "stdafx.h"
#include "Game.h"


Game::Game(void)
{
}


Game::~Game(void)
{
}

void Game::Start()
{
	_mainWindow.create(sf::VideoMode(1020, 800), "Just a Second");

	while (_mainWindow.isOpen())
    {
        sf::Event event;
        while (_mainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
				_mainWindow.close();
        }

		_mainWindow.clear();

		_mainWindow.display();
    }

}

sf::RenderWindow& Game::GetWindow()
{
	return _mainWindow;
}