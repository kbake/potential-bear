#pragma once
class Game
{
public:
	Game(void);
	~Game(void);

	void Start();
	sf::RenderWindow& GetWindow();

private:
	sf::RenderWindow _mainWindow;
};

