#pragma once

#include <SFML/Graphics/Drawable.hpp>

namespace sfm
{
    class desk
    {
    public:
        void fillRandom();
        void fillWhite();
        virtual void deaw(sf::RenderTarget& target, sf::RenderStates states);
    };
}