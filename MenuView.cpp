#include "stdafx.h"
#include "MenuView.h"


MenuView::MenuView(void)
{
	_texture.loadFromFile("images/menu.png");

	_background.setTexture(_texture);
}


MenuView::~MenuView(void)
{
}

void MenuView::Update(double deltaTime)
{
}

void MenuView::Draw(sf::RenderWindow& rw)
{
	rw.draw(_background);
}