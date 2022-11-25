#include <SFML/Graphics.hpp>
#include <iostream>
#include <complex>

const int ITERATIONS = 20;

int main() {
    sf::RenderWindow window(sf::VideoMode(1500,1000), "Fourier series", sf::Style::Default);

    std::complex<double> c(0,0);
    std::complex<double> z(0,0);
    bool extended = false;


    window.clear(sf::Color::White);      

    for (int x = 0; x <= 1500; x++) { 
        for (int y = 0; y <= 1000; y++) {
            c = {0.00266666*x-2,-0.002*y+1};
            z = {0,0};
            //std::cout << "x: " << std::real(c) << ", y: " << std::imag(c) << std::endl;
            for (int i = 0; i <= ITERATIONS; i++) {
                z = {std::pow(z,2)+c};
                //std::cout << "Iteration: " << i << " " << std::abs(z);
                if (std::abs(z) > 2) {
                    //std::cout << " extended" << std::endl;
                    sf:: Vertex ver;
                    ver.position = sf::Vector2f(x,y);
                    ver.color = sf::Color(50*(i/20),0*i,0*i,250);
                    window.draw(&ver, 1, sf::Points);
                    extended = true;
                  
                    break;
                }
               // std::cout << " passed" << std::endl;
            }
            if (extended) {
                extended = false;
                continue;
            }
            sf:: Vertex ver;
            ver.position = sf::Vector2f(x,y);

            //std::cout << "x: " << std::real(c) << ", y: " << std::imag(c) << " is part of set" << std::endl;
            ver.color = sf::Color::Black;
            window.draw(&ver, 1, sf::Points);
           // std::cout << "x: " << x << ", y: " << y << " drawn" << std::endl;
        }   
    }
    std:: cout << "finished" << std::endl;
    window.display();
    
    while (window.isOpen()) {   
        sf::Event event;     
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    return 0;
}