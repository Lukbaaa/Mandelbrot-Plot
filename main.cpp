#include <SFML/Graphics.hpp>
#include <iostream>
#include <complex>
#include <cmath>


int main() {
    sf::RenderWindow window(sf::VideoMode(1500,1000), "Fourier series", sf::Style::Default);
    std::complex<double> c(10.0, 2.0);
    std::cout << std::real(c) << std::endl;
    std::cout << std::imag(c) << std::endl;
    std::cout << std::pow(c, 2) << std::endl;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (int x = 0; x <= 1500; x+=2) { 
            for (int y = 0; y <= 1000; y+=8) {
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