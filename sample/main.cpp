#include <SFML/Window.hpp>
#include <memory>
#include "../include/webgui/webgui.hpp"
#include "renderer.hpp"

int main(int argc,char** argv)
{
	sf::Window win(sf::VideoMode(800, 600), "webgui sample",sf::Style::Default,
					sf::ContextSettings(24,8,0,3,3,sf::ContextSettings::Core));
	std::shared_ptr<wg::RenderInterface> renderer = std::make_shared<Renderer>();
	wg::Core core;
	core.SetRenderer(renderer);
	bool result = core.AddFontFromFile("arial.ttf");
	auto view = core.CreateView();
	view->LoadDocument("test.html");
	win.setFramerateLimit(60);

	while (win.isOpen())
	{
		std::dynamic_pointer_cast<Renderer>(renderer)->Clear();
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

		win.display();
	}
}