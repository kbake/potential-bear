#pragma once

class SplashView;
class MenuView;
class Gameplay;

class Game
{
public:
	Game(void);
	~Game(void);

	sf::RenderWindow& GetWindow();

	void Start();
	void Update(double);
	bool IsExiting();

private:
	sf::Music _gameMusic;
	sf::RenderWindow _mainWindow;
	sf::RectangleShape _outline;

	enum GameState { Initializing, Splash, Menu, Playing, Paused, ScoreBoard, Exiting };

	GameState _currentState;

	SplashView* _splash;
	MenuView* _menu;
	Gameplay* _gameplay;
};

