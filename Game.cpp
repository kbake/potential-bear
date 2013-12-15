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
	_mainWindow.create(sf::VideoMode(800, 600), "Just a Second!");

	sf::Clock clock;
	sf::Time elapsed;

	while (!IsExiting())
	{
		elapsed = clock.restart();

		Update(elapsed.asSeconds());
		Render();
	}
}

void Game::Update(double deltaTime)
{
	sf::Event event;

	_mainWindow.pollEvent(event);

	if (event.type == sf::Event::Closed)
	{
		_currentState = Exiting;
	}
	if (event.type == sf::Event::KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			_currentState = Exiting;
		}
	}

	switch (_currentState)
	{
	case Initializing:	// first starting
		break;
	case Splash:		// at splash
		break;
	case Menu:			// at menu
		break;
	case Playing:		// game's running
		break;
	case Paused:		// game paused (will there be a pause??)
		break;
	case Credits:		// at credits screen
		break;
	case Exiting:		// clean up or go to menu? maybe should have a separate state for shutdown?
		break;
	}
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