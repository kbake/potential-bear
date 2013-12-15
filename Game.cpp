#include "stdafx.h"
#include "Game.h"


Game::Game(void) :
	_currentState(GameState::Initializing)
{
}


Game::~Game(void)
{
}

// Set everything up
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

		Render();
    }

	while (!IsExiting())
	{

	}
}

void Game::Update(double deltaTime)
{
}

void Game::Render()
{
	_mainWindow.clear();

	_mainWindow.display();
}

sf::RenderWindow& Game::GetWindow()
{
	return _mainWindow;
}

bool Game::IsExiting()
{
	if (_currentState == GameState::Exiting)
	{
		return true;
	}

	return false;
}