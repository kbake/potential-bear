#pragma once
class Game
{
public:
	Game(void);
	~Game(void);

	sf::RenderWindow& GetWindow();

	void Start();
	void Render();
	void Update();
	bool IsExiting();

private:
	sf::RenderWindow _mainWindow;

	enum GameState { Initializing, Splash, Menu, Playing, Credits, ScoreBoard, Exiting };

	GameState _currentState;
};

