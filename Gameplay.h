#pragma once
class Gameplay
{
public:
	Gameplay(void);
	~Gameplay(void);

	void Update(double);
	void Draw(sf::RenderWindow&);

private:
	enum GameplayState { RoundBegin, InRound, RoundEnd };

	GameplayState _gameplayState;

	sf::Font _font;
	sf::Text _roundNumberText;
	sf::Text _ellipsisText;
	sf::Text _goText;

	unsigned int _roundNumber;
};

