#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "menu.hpp"

using namespace sf;
using namespace std;


int main()
{

    srand(time(0));
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(600, 600), "Memory Trainer");

    // Load a sprite to display


	// Start the game loop
    draw_menu(window);

    return EXIT_SUCCESS;
}
