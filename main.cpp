#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>


std::vector<sf::CircleShape> createRandomBalls(sf::CircleShape circle)
{
    std::vector<sf::CircleShape> dots = {};
    int counter = 0;
    while(counter <= 100)
    {
        dots.push_back(circle);
        counter++;
    }
    //set positions of each of the balls based off size of box
    int spacerX = 20;
    int spacerY = 40;
    for(int i=0;i<dots.size();i++)
    {
        dots[i].setPosition(spacerX,spacerY);
        if(spacerX >= 480){
            spacerY += 40;
            spacerX = 20;
        }
        spacerX += 20;
    }
    return dots;
}
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test");
    window.setFramerateLimit(60);
    sf::RectangleShape rectangle(sf::Vector2f(780.f, 580.f));
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setOutlineThickness(3.0f);
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setPosition(10,10);
    
    sf::CircleShape circle(5.f);
    circle.setFillColor(sf::Color::Red);
    sf::Vector2f circlePosition(100,100);
    
    

    sf::Clock clock;
    float dt;


    float const gravity = 10.0f;
    
    int xVelocity = 3;
    int yVelocity = 3;


    
    int counter = 0;
    while (window.isOpen())
    {
       
        sf::Event event;
        while (window.pollEvent(event))
        {
           
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        
        window.draw(rectangle);    
        window.draw(circle);   
       std::vector<sf::CircleShape> shapes = createRandomBalls(circle);
       for(int i=0;i<shapes.size();i++)
       {
        if(circlePosition.x < 0 || circlePosition.x > 780){
            xVelocity *= -1;
        }
        if(circlePosition.y < 0 || circlePosition.y > 580){
                yVelocity *= -1;
        }
        circlePosition.x += xVelocity;
        shapes[i].setPosition(circlePosition);
        window.draw(shapes[i]);
        circlePosition.y += yVelocity;
        shapes[i].setPosition(circlePosition);
        window.draw(shapes[i]); 
       }

        window.display();
    }

    return 0;
}