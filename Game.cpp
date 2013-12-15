#include "stdafx.h"
#include "Game.h"
#include "SplashView.h"
#include "MenuView.h"
#include "Gameplay.h"


Game::Game(void) :
	_currentState(GameState::Initializing)
{
}


Game::~Game(void)
{
	if (_splash)
	{
		delete _splash;
		_splash = NULL;
	}

	if (_menu)
	{
		delete _menu;
		_menu = NULL;
	}

	if (_gameplay)
	{
		delete _gameplay;
		_gameplay = NULL;
	}
}

// Set everything up
void Game::Start()
{
	_mainWindow.create(sf::VideoMode(800, 600), "Just One Second!");

	_outline.setFillColor(sf::Color::Transparent);
	_outline.setSize(sf::Vector2f(790, 590));
	_outline.setPosition(5, 5);
	_outline.setOutlineThickness(5);

	sf::Clock clock;
	sf::Time elapsed;

	while (!IsExiting())
	{
		elapsed = clock.restart();

		_mainWindow.clear();
		Update(elapsed.asSeconds());
		_mainWindow.draw(_outline);
		_mainWindow.display();
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
		_splash = new SplashView();
		
		_currentState = Splash;
		break;
	case Splash:		// at splash
		_splash->Update(deltaTime);

		_splash->Draw(_mainWindow);
		
		if (event.type == sf::Event::MouseButtonPressed)
		{
			_currentState = Menu;
			
			delete _splash;
			_splash = NULL;

			_menu = new MenuView();
		}

		break;
	case Menu:			// at menu
		_menu->Update(deltaTime);

		_menu->Draw(_mainWindow);
		_mainWindow.draw(_outline); // because the menu is just an image and I don't feel like resizing it

		if (event.type == sf::Event::MouseButtonPressed)
		{
			_gameplay = new Gameplay();

			_currentState = Playing;
		}

		break;
	case Playing:		// game's running
		_gameplay->Update(deltaTime);
		_gameplay->Draw(_mainWindow);

		if (_gameplay->EndGame())
		{
			delete _gameplay;
			_gameplay = NULL;
			_currentState = Menu;
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				delete _gameplay;
				_gameplay = NULL;

				_currentState = Menu;
			}
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			_gameplay->CheckMouseClick(sf::Mouse::getPosition(_mainWindow));
		}

		break;
	case Paused:		// game paused (will there be a pause??)
		break;
	case Exiting:		// clean up or go to menu? maybe should have a separate state for shutdown?
		break;
	}
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