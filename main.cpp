#include <SFML/Graphics.hpp>
#include <math.h>


int main() {
    sf::RenderWindow window(sf::VideoMode(1500,1000), "Fourier series", sf::Style::Default);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (int x = 0; x <= 1500; x++) { 
            for (int y = 0; y <= 1000; y++) {
                sf:: Vertex ver;
                ver.position = sf::Vector2f(x,y);
                ver.color = sf::Color::Red;
                window.draw(&ver, 1, sf::Points);
            }
        }

        window.display();
    }

    return 0;
}