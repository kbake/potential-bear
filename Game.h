#pragma once

class SplashView;

class Game
{
public:
	Game(void);
	~Game(void);

	sf::RenderWindow& GetWindow();

	void Start();
	void Render();
	void Update(double);
	bool IsExiting();

private:
	sf::RenderWindow _mainWindow;

	enum GameState { Initializing, Splash, Menu, Playing, Paused, Credits, ScoreBoard, Exiting };

	GameState _currentState;

	SplashView* _splash;
};

