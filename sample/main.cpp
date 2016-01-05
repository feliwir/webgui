#include <SFML/Window.hpp>
#include "../include/webgui/webcore.hpp"

int main(int argc,char** argv)
{
	sf::Window win(sf::VideoMode(800, 600), "webgui sample");
	wg::Core core;

	while (win.isOpen())
	{
		sf::Event ev;
		while (win.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
				win.close();
				break;
			}
		}
		
	}
}