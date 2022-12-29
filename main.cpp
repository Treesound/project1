#include <ball.hpp>
#include <SFML/Graphics.hpp> 
#include <iostream>
    int main()
    {
        sf::RenderWindow window(sf::VideoMode(800, 600), "game", sf::Style::Close | sf::Style::Titlebar); 

        float radius = 50;
        sf::CircleShape player (radius);
        player.setPosition(400-radius, 300-radius);  //создаем шарик, распологаем его в середине экрана

        sf::Vector2f velocity(0, 0);
        sf::Vector2f ball_position(400 - radius, 300 - radius);

        while (window.isOpen()) {
            sf::Event evnt;
            while (window.pollEvent(evnt)) {
                if (evnt.type == evnt.Closed) {
                    window.close();
                }
            }

            sf::Texture back_texture;                           //текстура и спрайт фона
            back_texture.loadFromFile("assets/board.jpg");
            sf::Sprite background(back_texture);
            background.setScale(2, 2);

            sf::Texture player_texture;                           //текстура и спрайт шарика
            player_texture.loadFromFile("assets/ball.jpg");
            player_texture.setSmooth(true);
            sf::Sprite player_sprite(player_texture);

            player.move(velocity.x, velocity.y);  //д

            ball_position.x += velocity.x;    //записываем расположение шарика (для спрайта)
            ball_position.y += velocity.y;
            
            nk::keyboard_movement(0.2, velocity.x, velocity.y);


            nk::addWallCollisions(ball_position.x, ball_position.y, radius, velocity.x, velocity.y);
            
            window.clear();
            window.draw(background);
            player_sprite.setPosition(player.getPosition());
            window.draw(player_sprite);
            window.display();
        }
            
        return 0;
    }

