#include "stdafx.h"
#include "Gameplay.h"
#include <iostream>

Gameplay::Gameplay(void) :
	_beginRoundTick(0.f),
	_ellipsisTick(0.f),
	_inRoundTick(0.f),
	_endRoundTick(0.f),
	_roundNumber(1),
	_gameplayState(BeginRound),
	_failed(false)
{
	srand(time(NULL));

	Init();
}


Gameplay::~Gameplay(void)
{
}

void Gameplay::Init()
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
	_timeText.setPosition(170, 70);
	_timeText.setCharacterSize(100);
	_timeText.setScale(4, 4);
	_timeText.setString("00");

	_timeCover.setFillColor(sf::Color(0, 0, 0, 200));
	_timeCover.setSize(sf::Vector2f(800, 600));

	_button.setRadius(50);

	_toDraw.push_back(&_timeText);
	_toDraw.push_back(&_timeCover);
	_toDraw.push_back(&_roundNumberText);
	_toDraw.push_back(&_messageText);
}

void Gameplay::Update(double deltaTime)
{
	switch(_gameplayState)
	{
	case BeginRound:
		_beginRoundTick += deltaTime;
		_ellipsisTick += deltaTime;

		if (_ellipsisTick > .5)
		{
			_ellipsisTick = 0;

			_messageText.setString(_messageText.getString() + ".");
		}

		if (_beginRoundTick >= 2.f)
		{
			_beginRoundTick = 0;
			_ellipsisTick = 0;
			_inRoundTick = 0;

			_toDraw.erase(_toDraw.begin()+2, _toDraw.end());

			if (_roundNumber % 10 == 0)
			{
				_button.setRadius(_button.getRadius() - (_button.getRadius() * .1));
			}

			_button.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
			_button.setPosition(rand() % (800 - (int)_button.getRadius() * 2), rand() % (600 - (int)_button.getRadius() * 2));

			_gameplayState = InRound;
		}

		break;
	case InRound:
		_inRoundTick += deltaTime;

		if (_toDraw.size() < 3)
		{
			_toDraw.push_back(&_button);
		}

		_timeText.setString(std::to_string(_inRoundTick).substr(2, 2));

		if (_inRoundTick >= 1.f)
		{
			_failed = true;

			_timeText.setString("00");

			_gameplayState = EndRound;
		}

		break;
	case EndRound:
		_endRoundTick += deltaTime;

		if (_toDraw.size() < 3)
		{
			_toDraw.push_back(&_roundNumberText);
			_toDraw.push_back(&_messageText);
		}

		if (_endRoundTick >= 2.f)
		{
			_endRoundTick = 0.f;

			_messageText.setString("Get ready");

			_gameplayState = BeginRound;
		}

		break;
	}
}

void Gameplay::Draw(sf::RenderWindow& rw)
{
	std::vector<sf::Drawable*>::iterator end = _toDraw.end();
	for (std::vector<sf::Drawable*>::iterator it = _toDraw.begin(); it != end; it++)
	{
		rw.draw(**(it));
	}
}

void Gameplay::CheckMouseClick(sf::Vector2i pos)
{
	if (_gameplayState != InRound) return;

	sf::FloatRect buttonBounds = _button.getGlobalBounds();	
	
	if (buttonBounds.contains(pos.x, pos.y))
	{
		_failed = false;

		_roundNumber++;

		_timeText.setString("00");
		_messageText.setString("Good stuff!");
		_roundNumberText.setString("Round " + std::to_string(_roundNumber));

		_toDraw.pop_back();

		_gameplayState = EndRound;
	}
}

bool Gameplay::EndGame()
{
	if (_failed)
	{
		return true;
	}

	return false;
}