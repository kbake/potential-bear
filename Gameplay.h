#pragma once
class Gameplay
{
public:
	Gameplay(void);
	~Gameplay(void);

	bool EndGame();
	void CheckMouseClick(sf::Vector2i);

	void Init();
	void Update(double);
	void Draw(sf::RenderWindow&);

private:
	enum GameplayState { BeginRound, InRound, EndRound };

	GameplayState _gameplayState;

	sf::Font _font;
	sf::SoundBuffer _getReadyBuffer;
	sf::SoundBuffer _goBuffer;
	sf::SoundBuffer _buttonBuffer;
	sf::Sound _getReadySound;
	sf::Sound _goSound;
	sf::Sound _buttonHitSound;
	sf::Sound _phraseSound;
	sf::Text _roundNumberText;
	sf::Text _messageText;
	sf::Text _goText;
	sf::Text _timeText;
	sf::RectangleShape _timeCover;
	sf::CircleShape _button;

	std::vector<sf::SoundBuffer*> _phraseSoundBuffers;
	std::vector<sf::Drawable*> _toDraw;
	std::vector<std::string> _phrases;

	float _beginRoundTick;
	float _ellipsisTick;
	float _inRoundTick;	
	float _endRoundTick;
	unsigned int _roundNumber;
	bool _failed;
	bool _showGo;
};

