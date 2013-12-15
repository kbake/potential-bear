#pragma once
class Gameplay
{
public:
	Gameplay(void);
	~Gameplay(void);

	bool EndGame();
	void SetEvent(sf::Event&);

	void Update(double);
	void Draw(sf::RenderWindow&);

private:
	enum GameplayState { BeginRound, InRound, EndRound };

	GameplayState _gameplayState;

	sf::Event _event;
	sf::Font _font;
	sf::Text _roundNumberText;
	sf::Text _messageText;
	sf::Text _goText;
	sf::Text _timeText;

	std::vector<sf::Text*> _textToDraw;

	float _beginRoundTick;
	float _inRoundTick;	
	float _endRoundTick;
	unsigned int _roundNumber;
	bool _failed;
	bool _quit;
};

