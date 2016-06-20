#include <SFML/Graphics.hpp>

#include "Func.h"

sf::RenderWindow window;

#define WIN_WIDTH 1100
#define WIN_HEIGHT 500


bool focused = true;
int main()
{

	init(window);


	

	sf::Clock clock;


	
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Sound Maker",sf::Style::Default, settings);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::LostFocus) {
				focused = false;
			}
				

			if (event.type == sf::Event::GainedFocus) {
				focused = true;
			}
				
		}
		

		if (focused) {

			sf::Time elapsed1 = clock.getElapsedTime();

			if (elapsed1 > sf::milliseconds(20)) { //We don't want to hear noises when the window is left open but not active.
				update(window);   //update loop happens 50 times a second.
				clock.restart();
			}

		}
		

		if (focused) {
			window.clear();
			render(window);
			window.display();
		}
		


	}

	return 0;
}
