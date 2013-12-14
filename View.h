#pragma once
class View
{
public:
	View(void);
	~View(void);

	void Update(double);
	void Draw(sf::RenderWindow&);
};

