#include "stdafx.h"
#include "Gameplay.h"


Gameplay::Gameplay(void) :
	_roundNumber(0),
	_gameplayState(RoundBegin)
{
	_font.loadFromFile("fonts/arial.ttf");

	_roundNumberText.setFont(_font);
	_roundNumberText.setPosition(6, 6);
	_roundNumberText.setString("Round " + std::to_string(_roundNumber));

	_ellipsisText.setFont(_font);
	_ellipsisText.setPosition(518, 254);
}


Gameplay::~Gameplay(void)
{
}

void Gameplay::Update(double deltaTime)
{
	switch(_gameplayState)
	{
	case RoundBegin:
		break;
	case InRound:
		break;
	case RoundEnd:
		break;
	}
}

void Gameplay::Draw(sf::RenderWindow& rw)
{
}