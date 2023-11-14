#include "circle.h"
#include <iostream>
#include <SFML/Graphics.hpp>

void object::Ball::setIntialDetails(object::Ball &circleObject){
    
    circleObject.setFillColor(sf::Color::Red);
    circleObject.setPosition(sf::Vector2f(200,200));
    circleObject.setRadius(5.f);

}
void object::Ball::move()
{
    position.y += yVelocity;
    position.x += xVelocity;
}








