#include "resources.hpp"

namespace UI
{
    class Test
    {    
    public:
        void CheckLibrary() {std::cout<<"CheckLibrary_OK"<<std::endl;};
        void drawUI(sf::RenderWindow& window);
    };
    void Test::drawUI(sf::RenderWindow& window)
    {
        sf::RectangleShape rectangle(sf::Vector2f(1920.f, 100.f));
        sf::Text header_text;
        sf::Font header_font;
        if (!header_font.loadFromFile("fonts/arial.ttf"))
        {
            std::cout << "Failed to load font" << std::endl;
            return;
        }
        header_text.setFont(header_font);
        header_text.setString("Ebat', rabotaet!");
        header_text.setPosition(sf::Vector2f(20.f, 20.f));
        header_text.setCharacterSize(50);
        header_text.setColor(sf::Color::Black);
        window.draw(rectangle);
        window.draw(header_text);
    }
}