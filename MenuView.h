#pragma once
class MenuView
{
public:
	MenuView(void);
	~MenuView(void);

	void Update(double);
	void Draw(sf::RenderWindow&);
	
private:
	sf::Texture _texture;
	sf::Sprite _background;
};

