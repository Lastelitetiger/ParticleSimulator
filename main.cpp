#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "circle.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test");
    window.setFramerateLimit(60);
    
    //set rectangle
    sf::RectangleShape rectangle(sf::Vector2f(780.f, 580.f));
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setOutlineThickness(3.0f);
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setPosition(10, 10);
    
    //delta time
    sf::Clock clock;
    sf::Time deltaTime = clock.getElapsedTime();
    //define Ball Class Object
    object::Ball circleObject;
    circleObject.setIntialDetails(circleObject);

    while (window.isOpen())
    {
       
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {

                window.close();
            }
        }
        //window.draw(rectangle);
        deltaTime = clock.getElapsedTime();
        std::cout << deltaTime.asSeconds() << std::endl;

        

        window.draw(circleObject);    
        
        window.display();

    
    }
    return 0;
}
/*
              Bounds Checking

          if(circlePosition.x < 0 || circlePosition.x > 780){
              xVelocity *= -1;
          }
          if(circlePosition.y < 0 || circlePosition.y > 580){
                  yVelocity *= -1;
          }
          circlePosition.y += yVelocity;
      circle.setPosition(circlePosition);
          circlePosition.x += xVelocity;
      circle.setPosition(circlePosition);
          */