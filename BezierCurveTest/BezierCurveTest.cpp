#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

#include "Math.h"
#include "Line.h"


int main()
{

    float lerpValue = 0.00f;

    sf::Font font;
    font.loadFromFile("fonts/Ubuntu-Light.ttf");
    sf::Text lerpText;
    lerpText.setFont(font);
    lerpText.setString("Lerp: " + std::to_string(round(100 * lerpValue) / 100));
    lerpText.setPosition(0, 0);

    Line l1(sf::Vector2f(30.f,300.f),sf::Vector2f(300.f,30.f));
    Line l2(sf::Vector2f(300.f, 30.f), sf::Vector2f(500.f, 500.f));

    l1.lerpLength = l1.getLength() * lerpValue;
    l2.lerpLength = l2.getLength() * (1.0f - lerpValue);

    sf::CircleShape c1(10);
    sf::CircleShape c2(10);
    sf::CircleShape c3(10);

    c1.setPosition(Math::getCoordsToDrawLine(l1.getPos1().x - c1.getRadius(), l1.getPos1().y - c1.getRadius(), l1.lerpLength, l1.getAngle()));
    c2.setPosition(Math::getCoordsToDrawLine(l2.getPos2().x - c2.getRadius(), l2.getPos2().y - c2.getRadius(), l2.lerpLength, 180 - l2.getAngle()));

    Line l3(
        sf::Vector2f(c1.getPosition().x + c1.getRadius(), c1.getPosition().y + c1.getRadius()),
        sf::Vector2f(c2.getPosition().x + c2.getRadius(), c2.getPosition().y + c2.getRadius())
    );

    l3.lerpLength = l3.getLength() * lerpValue;
    c3.setPosition(Math::getCoordsToDrawLine(l3.getPos1().x - c3.getRadius(), l3.getPos1().y - c3.getRadius(), l3.lerpLength, l3.getAngle()));

    bool forwards = true;

    std::vector<sf::CircleShape> bezierCurve;

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setFramerateLimit(60);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        window.setFramerateLimit(60);

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                lerpValue = 0;
                forwards = true;
                bezierCurve.clear();
                l2.setPos2((sf::Vector2f)sf::Mouse::getPosition(window));
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                lerpValue = 0;
                forwards = true;
                bezierCurve.clear();
                l1.setPos1((sf::Vector2f)sf::Mouse::getPosition(window));
            }
        }

        if (lerpValue <= 0) {
            forwards = true;
            bezierCurve.clear();
        }
        else if (lerpValue >= 1) {
            forwards = false;
            bezierCurve.clear();
        }

        if (forwards) {
            lerpValue += 0.005f;
        }
        else {
            lerpValue -= 0.005f;
        }

        lerpText.setString("Lerp: " + std::to_string(round(100 * lerpValue) / 100));

        l1.lerpLength = l1.getLength() * lerpValue;
        l2.lerpLength = l2.getLength() * (1.0f - lerpValue);

        c1.setPosition(Math::getCoordsToDrawLine(l1.getPos1().x - c1.getRadius(), l1.getPos1().y - c1.getRadius(), l1.lerpLength, l1.getAngle()));
        c2.setPosition(Math::getCoordsToDrawLine(l2.getPos2().x - c2.getRadius(), l2.getPos2().y - c2.getRadius(), l2.lerpLength, 180 - l2.getAngle()));

        l3.setPos1(sf::Vector2f(c1.getPosition().x + c1.getRadius(), c1.getPosition().y + c1.getRadius()));
        l3.setPos2(sf::Vector2f(c2.getPosition().x + c2.getRadius(), c2.getPosition().y + c2.getRadius()));

        l3.lerpLength = l3.getLength() * lerpValue;

        // c3.setPosition(Math::getCoordsToDrawLine(l3.getPos1().x - c3.getRadius(), l3.getPos1().y - c3.getRadius(), l3.lerpLength, l3.getAngle()));

        sf::Vector2f realPoint;

        // if (l3.getAngle() > 0.0010f) {
        

        if (c1.getPosition().y < c2.getPosition().y) {
            realPoint = Math::getCoordsToDrawLine(l3.getPos1().x, l3.getPos1().y, l3.lerpLength, -l3.getAngle());
        }
        else {
            realPoint = Math::getCoordsToDrawLine(l3.getPos1().x, l3.getPos1().y, l3.lerpLength, l3.getAngle());
        }

        c3.setPosition(sf::Vector2f(realPoint.x - c3.getRadius(),realPoint.y - c3.getRadius()));

        sf::CircleShape c(2);
        c.setPosition(sf::Vector2f(realPoint.x - c.getRadius(),realPoint.y - c.getRadius()));
        c.setFillColor(sf::Color::Green);
        bezierCurve.push_back(c);


        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        window.draw(l1.getVertexArray());
        window.draw(l2.getVertexArray());
        window.draw(l3.getVertexArray());
        window.draw(c1);
        window.draw(c2);
        window.draw(c3);
        for (auto rect : bezierCurve) {
            window.draw(rect);
        }
        window.draw(lerpText);

        // end the current frame
        window.display();
    }

    return 0;
}