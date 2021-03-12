#ifndef UI_H
#define UI_H

#include <iostream>
#include <windows.h>
#include <string>

#include "SFML/Graphics.hpp"

class UI
{
    public:
        UI();

        void MainWindow(int win_w, int win_h, std::string title)
        {
            sf::RenderWindow window(sf::VideoMode(win_w, win_h), title, sf::Style::Close);
                             window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - window.getSize().x / 2,
                                                             sf::VideoMode::getDesktopMode().height - window.getSize().y));

            //sf::RenderWindow console_box(sf::VideoMode(win_w, win_h / 2), "Output", sf::Style::Titlebar);
                             //console_box.setPosition(sf::Vector2i(window.getPosition().x, window.getPosition().y + console_box.getSize().y + 25));

            window.requestFocus();

            sf::Texture Logo_Texture;
                        Logo_Texture.loadFromFile("data\\logo.png");
            sf::IntRect Logo_IntRect(110, 140, 250, 30);
            sf::Sprite  Logo_Sprite(Logo_Texture, Logo_IntRect);
                        Logo_Sprite.setPosition(window.getSize().x / 2 - Logo_IntRect.width / 2, 30 - Logo_IntRect.height);

            sf::Font font;
            font.loadFromFile("data\\arial.ttf");

            sf::RectangleShape console_box;
            console_box.setSize(sf::Vector2f(win_w, win_h / 2));
            console_box.setOutlineColor(sf::Color::White);
            console_box.setFillColor(sf::Color::White);
            console_box.setOutlineThickness(1);
            console_box.setPosition(0, win_h - console_box.getSize().y);

            sf::RectangleShape console_box_titlebar;
            console_box_titlebar.setSize(sf::Vector2f(console_box.getSize().x, 25));
            console_box_titlebar.setOutlineColor(sf::Color::Black);
            console_box_titlebar.setFillColor(sf::Color::White);
            console_box_titlebar.setOutlineThickness(1);
            console_box_titlebar.setPosition(0, console_box.getPosition().y);

            sf::RectangleShape Scrollbar_Up;
            Scrollbar_Up.setSize(sf::Vector2f(20, 20));
            Scrollbar_Up.setOutlineColor(sf::Color::Black);
            Scrollbar_Up.setFillColor(sf::Color::Transparent);
            Scrollbar_Up.setOutlineThickness(1);
            Scrollbar_Up.setPosition(console_box.getSize().x - Scrollbar_Up.getSize().x, console_box_titlebar.getPosition().y + console_box_titlebar.getSize().y + 1);

            sf::RectangleShape Scrollbar_Down;
            Scrollbar_Down.setSize(sf::Vector2f(20, 20));
            Scrollbar_Down.setOutlineColor(sf::Color::Black);
            Scrollbar_Down.setFillColor(sf::Color::Transparent);
            Scrollbar_Down.setOutlineThickness(1);
            Scrollbar_Down.setPosition(console_box.getSize().x - Scrollbar_Down.getSize().x, window.getSize().y - Scrollbar_Down.getSize().y);

            sf::RectangleShape Scrollbar;
            Scrollbar.setSize(sf::Vector2f(20, 20));
            Scrollbar.setOutlineColor(sf::Color::Black);
            Scrollbar.setFillColor(sf::Color::White);
            Scrollbar.setOutlineThickness(1);
            Scrollbar.setPosition(0, 0);

            sf::RectangleShape Scrollbar_Border;
            Scrollbar_Border.setSize(sf::Vector2f(console_box.getSize().x, console_box.getSize().y));
            Scrollbar_Border.setOutlineColor(sf::Color::Black);
            Scrollbar_Border.setFillColor(sf::Color::Transparent);
            Scrollbar_Border.setOutlineThickness(1);
            Scrollbar_Border.setPosition(console_box.getSize().x - Scrollbar_Up.getSize().x, Scrollbar_Up.getPosition().y);

            std::string str_console_text;
            sf::Text       _console_text("1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n51\n1\n1\n1\n1\n1\n1\n1\n", font);
                           _console_text.setCharacterSize(12);
                           _console_text.setPosition(0, console_box.getPosition().y + console_box_titlebar.getSize().y);
                           _console_text.setFillColor(sf::Color::Black);

            sf::Texture Scrollbar_Up_Arrow_Texture;
                        Scrollbar_Up_Arrow_Texture.loadFromFile("data\\scrollbar_arrow_up.png");
            sf::Sprite  Scrollbar_Up_Arrow_Sprite(Scrollbar_Up_Arrow_Texture);
                        Scrollbar_Up_Arrow_Sprite.setPosition(Scrollbar_Up.getPosition().x + Scrollbar_Up.getSize().x / 2 - Scrollbar_Up_Arrow_Texture.getSize().x / 2,
                                                              Scrollbar_Up.getPosition().y + Scrollbar_Up.getSize().y / 2 - Scrollbar_Up_Arrow_Texture.getSize().y / 2);

            sf::Texture Scrollbar_Down_Arrow_Texture;
                        Scrollbar_Down_Arrow_Texture.loadFromFile("data\\scrollbar_arrow_down.png");
            sf::Sprite  Scrollbar_Down_Arrow_Sprite(Scrollbar_Down_Arrow_Texture);
                        Scrollbar_Down_Arrow_Sprite.setPosition(Scrollbar_Down.getPosition().x + Scrollbar_Down.getSize().x / 2 - Scrollbar_Down_Arrow_Texture.getSize().x / 2,
                                                                Scrollbar_Down.getPosition().y + Scrollbar_Down.getSize().y / 2 - Scrollbar_Down_Arrow_Texture.getSize().y / 2);

            sf::Clock clock;

            while(window.isOpen())
            {
                sf::Event event;

                //while(window.pollEvent(event) || console_box.pollEvent(event))
                while(window.pollEvent(event))
                {
                    if(event.type == sf::Event::Closed) window.close();

                    if(event.type == sf::Event::KeyPressed)
                    {
                        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) _console_text.setPosition(0,-270);
                    }

                    if(event.type == sf::Event::MouseWheelMoved)
                    {
                        std::cout << "\n_console_text.getPosition().y - 45 = " << _console_text.getPosition().y - 45;
                        std::cout << "\n_console_text.getPosition().y - 25 = " << _console_text.getPosition().y - 25;
                        std::cout << "\nconsole_box.getPosition().y - 45 = " << console_box.getPosition().y - 45;
                        std::cout << "\nconsole_box.getPosition().y + _console_text.getLocalBounds().height = " << console_box.getPosition().y + _console_text.getLocalBounds().height;

                        if(event.mouseWheel.delta == -1) // down
                        {
                            std::cout << "\n 1";
                            if(_console_text.getPosition().y - 45
                            >= console_box.getPosition().y - 45)
                            {
                                _console_text.setPosition(0, _console_text.getPosition().y - 1);
                            }
                        }

                        if(event.mouseWheel.delta == 1) // up
                        {
                            std::cout << "\n 2";
                            if(_console_text.getPosition().y - 25
                            >= console_box.getPosition().y - 45)
                            {
                                _console_text.setPosition(0, _console_text.getPosition().y + 1);
                            }
                        }
                    }

                    if(event.type == sf::Event::MouseMoved)
                    {
                        if(sf::Mouse::getPosition(window).x >= Scrollbar_Up.getPosition().x
                        && sf::Mouse::getPosition(window).x <= Scrollbar_Up.getPosition().x + Scrollbar_Up.getSize().x
                        && sf::Mouse::getPosition(window).y >= Scrollbar_Up.getPosition().y
                        && sf::Mouse::getPosition(window).y <= Scrollbar_Up.getPosition().y + Scrollbar_Up.getSize().y)
                        {
                            Scrollbar_Up.setFillColor(sf::Color(50.0, 50.0, 50.0, 50.0));

                            //std::cout << "UP\n";

                            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                            {
                                std::cout << "UP\n";
                                //if(view.getCenter().y >= 150) view.move(0, -1);
                                //window.requestFocus();
                            }
                        }
                        else Scrollbar_Up.setFillColor(sf::Color::White);

                        if(sf::Mouse::getPosition(window).x >= Scrollbar_Down.getPosition().x
                        && sf::Mouse::getPosition(window).x <= Scrollbar_Down.getPosition().x + Scrollbar_Down.getSize().x
                        && sf::Mouse::getPosition(window).y >= Scrollbar_Down.getPosition().y
                        && sf::Mouse::getPosition(window).y <= Scrollbar_Down.getPosition().y + Scrollbar_Down.getSize().y)
                        {
                            Scrollbar_Down.setFillColor(sf::Color(50.0, 50.0, 50.0, 50.0));

                            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                            {
                                std::cout << "DOWN\n";
                                //if(_console_text.getLocalBounds().height + console_box.getSize().y / 2 - _console_text.getCharacterSize() * 2 >= view.getCenter().y) view.move(0, 1);
                                //window.requestFocus();
                            }
                        }
                        else Scrollbar_Down.setFillColor(sf::Color::White);
                    }
                }

                if(window.getPosition().x > window.getPosition().x
                || window.getPosition().x < window.getPosition().x) window.setPosition(sf::Vector2i(window.getPosition().x, window.getPosition().y + console_box.getSize().y + 20));

                if(clock.getElapsedTime().asSeconds() > 0.1f)
                {
                    if (Logo_IntRect.left == 11630) Logo_IntRect.left = 110;
                    else Logo_IntRect.left += 480;

                    //str_console_text = str_console_text + std::to_string(Logo_IntRect.left) + "\n";

                    //std::cout << str_console_text;

                    //_console_text.setString(str_console_text);

                    Logo_Sprite.setTextureRect(Logo_IntRect);
                    clock.restart();
                }

                window.clear(sf::Color::Transparent);

                window.draw(console_box);
                window.draw(console_box_titlebar);

                window.draw(_console_text);
                window.draw(Scrollbar_Up);
                window.draw(Scrollbar_Up_Arrow_Sprite);
                window.draw(Scrollbar);
                window.draw(Scrollbar_Border);
                window.draw(Scrollbar_Down);
                window.draw(Scrollbar_Down_Arrow_Sprite);

                window.draw(Logo_Sprite);

                /*console_box.clear(sf::Color::White);

                console_box.draw(_console_text);
                console_box.draw(Scrollbar_Up);
                console_box.draw(Scrollbar_Up_Arrow_Sprite);
                console_box.draw(Scrollbar);
                console_box.draw(Scrollbar_Border);
                console_box.draw(Scrollbar_Down);
                console_box.draw(Scrollbar_Down_Arrow_Sprite);

                console_box.display();*/

                window.display();
            }
        }

    protected:

    private:
};

#endif // UI_H
