#include "stdafx.h"
#include "Gameplay.h"


Gameplay::Gameplay(void) :
	_beginRoundTick(0.f),
	_inRoundTick(0.f),
	_endRoundTick(0.f),
	_roundNumber(0),
	_gameplayState(BeginRound),
	_failed(false),
	_quit(false)
{
	_font.loadFromFile("fonts/arial.ttf");

	_roundNumberText.setFont(_font);
	_roundNumberText.setPosition(6, 6);
	_roundNumberText.setString("Round " + std::to_string(_roundNumber));

	_messageText.setFont(_font);
	_messageText.setStyle(sf::Text::Italic);
	_messageText.setCharacterSize(50);
	_messageText.setPosition(260, 208);
	_messageText.setString("Get ready");

	_timeText.setFont(_font);
	_timeText.setPosition(100, 100);
	_timeText.setCharacterSize(80);

	_textToDraw.push_back(&_timeText);
	_textToDraw.push_back(&_roundNumberText);
	_textToDraw.push_back(&_messageText);
}


Gameplay::~Gameplay(void)
{
}

void Gameplay::Update(double deltaTime)
{
	switch(_gameplayState)
	{
	case BeginRound:
		_beginRoundTick += deltaTime;

		if (_beginRoundTick >= 2.f)
		{
			_beginRoundTick = 0;

			_textToDraw.erase(_textToDraw.begin()+1, _textToDraw.end());

			_gameplayState = InRound;
		}

		break;
	case InRound:
		_inRoundTick += deltaTime;

		if (_event.type == sf::Event::KeyPressed)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				_quit = true;
			}
		}

		if (_inRoundTick >= 1.f)
		{
			_failed = true;

			_gameplayState = EndRound;
		}

		break;
	case EndRound:
		_endRoundTick += deltaTime;

		if (_textToDraw.size() < 2)
		{
			_textToDraw.push_back(&_roundNumberText);
			_textToDraw.push_back(&_messageText);
		}

		if (_endRoundTick >= 2.f)
		{
			_endRoundTick = 0.f;

			_gameplayState = BeginRound;
		}

		break;
	}
}

void Gameplay::Draw(sf::RenderWindow& rw)
{
	std::vector<sf::Text*>::iterator end = _textToDraw.end();
	for (std::vector<sf::Text*>::iterator it = _textToDraw.begin(); it != end; it++)
	{
		rw.draw(**(it));
	}
}

void Gameplay::SetEvent(sf::Event& event)
{
	_event = event;
}

bool Gameplay::EndGame()
{
	if (_failed || _quit)
	{
		return true;
	}

	return false;
}