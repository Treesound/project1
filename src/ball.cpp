#include <ball.hpp>
#include <SFML/Graphics.hpp> 
#include <iostream>
namespace nk {
    void addWallCollisions(float& ball_position_x, float& ball_position_y, int radius, float& velocity_x, float& velocity_y) {
        if (ball_position_x <= 0 || ball_position_x >= 800 - radius * 2) {
            velocity_x *= -1;
        }

        if (ball_position_y <= 0 || ball_position_y >= 600 - radius * 2) {
            velocity_y *= -1;
        }
    }

    void keyboard_movement(float acceleration, float& velocity_x, float& velocity_y) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            velocity_x -= acceleration;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            velocity_x += acceleration;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            velocity_y += acceleration;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            velocity_y -= acceleration;
        }
    }
}