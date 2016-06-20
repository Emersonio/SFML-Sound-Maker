#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Func.h"
#include <iostream>
#include <vector>

#include "osc.h"
sf::Vector2i mousePos;

sf::Vector2i mPos;


#define WIN_WIDTH 1100
#define WIN_HEIGHT 500

std::vector<sf::CircleShape> clickVector;

int clickTime = 0;

sf::Sound clickNoise;

sf::SoundBuffer buffer;


void init(sf::RenderWindow& window) {
	


	if (!buffer.loadFromFile("res/doot.wav")) {
		std::cout << "did not doot";
	}


	clickNoise.setBuffer(buffer);

	clickNoise.setVolume(0); //Raise the volume only when mouse is clicked
	clickNoise.play();
	clickNoise.setLoop(true);
}

void update(sf::RenderWindow& window) {
	mPos = sf::Mouse::getPosition(window);
//	mouseDot.setPosition(mPos.x-10, mPos.y-10);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		clickTime++;
		clickVector.push_back(sf::CircleShape(10.f, 10));
		clickVector.back().setPosition(mPos.x, mPos.y);
		clickVector.back().setFillColor(sf::Color(mPos.x, mPos.y, clickTime));


		//Modify clicknoise depending on mouse coordinates
		clickNoise.setPitch( (((mPos.y / 5) / 10) * 0.1) + 0.2); 
		clickNoise.setVolume(3); //Make clicknoise audible
		
	}
	else {
		clickTime = 0;
		clickNoise.setVolume(0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		clickVector.clear();
	}

}

void render(sf::RenderWindow& window) {
	for (unsigned int i = 0; i < clickVector.size(); i++) {
		window.draw(clickVector[i]);
	}

}