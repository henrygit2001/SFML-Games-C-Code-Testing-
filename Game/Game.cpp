#include "Game.h"
#include <iostream>

Game::Game() {
	this -> window = new sf::RenderWindow(sf::VideoMode(2080, 720), "My Program");
	window->setFramerateLimit(60);
}
Game::~Game() {
	delete window;
}
void Game::happy() {
	std::cout << "Hello";
}
void Game::Circle() {
	this->texture;
	this->circle.setRadius(50);
	this->texture.loadFromFile("John_Cena.png");
	this->circle.setTexture(&texture);
	this -> xpos = 000;
	this -> ypos = 000;
	this -> xvel = 000;
	this -> yvel = 000;
	this -> yacc = 1.5;
	this -> abs_yvel = 0;
}

void Game::isOpening() {
	while (this -> window->isOpen()) {
		Game::Update();
		Game::Physics();
		Game::Render();
	};
}
void Game::Update() {

	while (this->window->pollEvent(this->event))
	{
		if (event.type == sf::Event::Closed) window->close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) this->window->close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))this->window->close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		this->yvel = -30;
		this->abs_yvel = 30;
		this->yacc = 1.5;}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			this->ypos += 5; 
			this->circle.setPosition(this->xpos, this->ypos);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			this->xpos -= 100; 
			this->circle.setPosition(this->xpos, this->ypos);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			this->xpos += 100;
			this->circle.setPosition(this->xpos, this->ypos);
		}
	};
}
void Game::Physics() {
	//Replace this with border detection later on: "this->yvel <= this->abs_yvel"
	if (this->yvel <= this->abs_yvel) {
		this->ypos += this->yvel;
		this->yvel += this->yacc;
		this->circle.setPosition(xpos, ypos);
	}
	else {
		this->yvel = (-1 * (this->abs_yvel / 2));
		this->abs_yvel = -1 * this->yvel;
		if (this->abs_yvel < this->yacc) {
			this->abs_yvel = 0;
			this->yvel = 0;
			this->yacc = 0;
		}
	};
}
void Game::Render() {
	window->clear();
	window->draw(this->circle);
	window->display();
}
