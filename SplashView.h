#pragma once
class SplashView
{
public:
	SplashView(void);
	~SplashView(void);

	void Update(double);
	void Draw(sf::RenderWindow&);

private:
	//sf::RectangleShape _outline;
	sf::RectangleShape _animateRect;
	sf::Text _titleText;
	sf::Text _messageText;
	sf::Font _font;

	double _totalTimeElapsed;
	float _alphaTime;
	bool _decreaseAlpha;
};

