#pragma once
class View
{
public:
	View(void);
	~View(void);

	virtual void Update(double) =0;
	virtual void Draw(sf::RenderWindow&) =0;
};

