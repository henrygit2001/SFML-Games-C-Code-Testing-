#pragma once
#include <SFML/Graphics.hpp>
class Game
{
private:
	sf::RenderWindow* window;
	sf::Event event;
	sf::Texture texture;
	sf::CircleShape circle;
	float xpos;
	float ypos;
	float xvel;
	float yvel;
	float yacc;
	float abs_yvel;
public:
	Game();
	~Game();
	void happy();
	void Circle();
	void isOpening();
	void Update();
	void Physics();
	void Render();
};
