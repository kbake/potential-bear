#pragma once
class SplashView : public View
{
public:
	SplashView(void);
	~SplashView(void);

	void Update(double);
	void Draw(sf::RenderWindow&);
};

