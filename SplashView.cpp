#include "stdafx.h"
#include "SplashView.h"


SplashView::SplashView(void)
{
	_outline.setSize(sf::Vector2f(780, 580));
	_outline.setFillColor(sf::Color::Transparent);
	_outline.setPosition(10, 10);
	_outline.setOutlineThickness(10.f);
	_outline.setOutlineColor(sf::Color::Green);

	_font.loadFromFile("fonts/arial.ttf");

	_titleText.setFont(_font);
	_titleText.setCharacterSize(50);
	_titleText.setPosition(200, 50);
	_titleText.setString("Just. One. Second.");

	_messageText.setFont(_font);
	_messageText.setCharacterSize(30);
	_messageText.setPosition(270, 400);
	_messageText.setString("Click to enter");

	_animateRect.setSize(_messageText.getScale());
	_animateRect.setFillColor(sf::Color::Blue);
	_animateRect.setPosition(_messageText.getPosition());
}


SplashView::~SplashView(void)
{
}

//void SplashView::SetFont(sf::Font& font)
//{
//	_font = font;
//}
//
//void SplashView::SetText(std::string str)
//{
//	_text.setString(str);
//}
//
//void SplashView::SetTextPosition(sf::Vector2f pos)
//{
//	_text.setPosition(pos);
//}

void SplashView::Update(double)
{
}

void SplashView::Draw(sf::RenderWindow& rw)
{
	rw.draw(_outline);
	rw.draw(_titleText);
	rw.draw(_messageText);
	rw.draw(_animateRect);
}