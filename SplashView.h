#pragma once
class SplashView
{
public:
	SplashView(void);
	//SplashView(sf::Text&, sf::Font&);
	~SplashView(void);

	//void SetFont(sf::Font&);
	//void SetText(std::string);
	//void SetTextPosition(sf::Vector2f);

	void Update(double);
	void Draw(sf::RenderWindow&);

private:
	sf::RectangleShape _outline;
	sf::RectangleShape _animateRect;
	sf::Text _titleText;
	sf::Text _messageText;
	sf::Font _font;

	double _totalTimeElapsed;
	float _alphaTime;
	bool _decreaseAlpha;
};

