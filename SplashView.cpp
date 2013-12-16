#include "stdafx.h"
#include "SplashView.h"

SplashView::SplashView(void) :
	_totalTimeElapsed(0.0),
	_alphaTime(0.f),
	_decreaseAlpha(true)
{
	_font.loadFromFile("fonts/arial.ttf");

	_titleText.setFont(_font);
	_titleText.setCharacterSize(50);
	_titleText.setPosition(185, 150);
	_titleText.setString("Just. One. Second.");

	_messageText.setFont(_font);
	_messageText.setCharacterSize(30);
	_messageText.setPosition(300, 400);
	_messageText.setString("Spacebar to enter");
	
	_animateRect.setSize(sf::Vector2f(250, 50));
	_animateRect.setFillColor(sf::Color::Black);
	_animateRect.setPosition(_messageText.getPosition());
}


SplashView::~SplashView(void)
{
}

void SplashView::Update(double deltaTime)
{
	_totalTimeElapsed += deltaTime;

	if (_totalTimeElapsed > 2.0)
	{
		_alphaTime += (float)deltaTime;

		if (_alphaTime > .01)
		{
			sf::Color tempColor = _animateRect.getFillColor();

			if (_decreaseAlpha)
			{
				tempColor.a -= 1;
			}
			else
			{
				tempColor.a += 1;
			}
			
			_animateRect.setFillColor(tempColor);

			if (tempColor.a <= 0)
			{
				_decreaseAlpha = false;
			}
			else if (tempColor.a >= 255)
			{
				_decreaseAlpha = true;
			}

			_alphaTime = 0;
		}
	}
}

void SplashView::Draw(sf::RenderWindow& rw)
{
	//rw.draw(_outline);
	rw.draw(_titleText);
	rw.draw(_messageText);
	rw.draw(_animateRect);
}