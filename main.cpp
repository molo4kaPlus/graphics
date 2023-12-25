#include "lib\UI.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "huge cocks");
    sf::Image icon;
    icon.loadFromFile("res/icons/fx.jpg"); 
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    UI::Test test;
    test.CheckLibrary();


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        test.drawUI(window);
        window.display();
    }

    return 0;
}