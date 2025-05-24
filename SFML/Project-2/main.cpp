#include <SFML/Graphics.hpp>

int main() {
    // Create window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Basic SFML Game");
    window.setFramerateLimit(60);

    // Create player rectangle
    sf::RectangleShape player(sf::Vector2f(50.f, 50.f));
    player.setFillColor(sf::Color::Green);
    player.setPosition(375.f, 275.f); // center-ish

    const float speed = 200.f; // pixels per second

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Calculate delta time for smooth movement
        float dt = clock.restart().asSeconds();

        // Handle input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player.move(-speed * dt, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            player.move(speed * dt, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            player.move(0.f, -speed * dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            player.move(0.f, speed * dt);

        // Clear screen
        window.clear(sf::Color::Black);

        // Draw player
        window.draw(player);

        // Display window contents
        window.display();
    }

    return 0;
}
