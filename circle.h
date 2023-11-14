#pragma once
#include <SFML/Graphics.hpp>
namespace object{

    class Ball: public sf::CircleShape
    {
        public:
        float xVelocity = 3.0f;
        float yVelocity = 3.0f;
        sf::Vector2f position;
        float acceleration;
        float mass;
        void setIntialDetails(object::Ball &circleObject);
        void move();
        private:
    };
}
