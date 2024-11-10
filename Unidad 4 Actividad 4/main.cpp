#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    // Crear la ventana
    RenderWindow window(VideoMode(800, 600), "Atrapado");

    // Cargar las texturas
    Texture textureSquare, textureCircle;
    if (!textureSquare.loadFromFile("cuadrado amarillo/cuad_yellow.png")) {
        // cargar la textura del cuadrado
    }
    if (!textureCircle.loadFromFile("circulo verde/rcircleg.png")) {
        // cargar la textura del círculo
    }

    // Configurar el sprite inicial
    Sprite player;
    player.setTexture(textureSquare);
    player.setPosition(400, 300);  // Posición inicial
    player.setScale(0.5f, 0.5f);   // Escala para mantener el tamaño consistente

    bool isCircle = false;  // Estado para alternar entre cuadrado y círculo

    // Bucle principal
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            // Cambiar a círculo cuando se presiona la barra espaciadora
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
                if (isCircle) {
                    player.setTexture(textureSquare);
                    isCircle = false;
                }
                else {
                    player.setTexture(textureCircle);
                    isCircle = true;
                }
            }
        }

        // Mover el sprite con las teclas de dirección
        Vector2f movement(0.f, 0.f);
        if (Keyboard::isKeyPressed(Keyboard::Left) && player.getPosition().x > 0)
            movement.x -= 5.f;
        if (Keyboard::isKeyPressed(Keyboard::Right) && player.getPosition().x + player.getGlobalBounds().width < window.getSize().x)
            movement.x += 5.f;
        if (Keyboard::isKeyPressed(Keyboard::Up) && player.getPosition().y > 0)
            movement.y -= 5.f;
        if (Keyboard::isKeyPressed(Keyboard::Down) && player.getPosition().y + player.getGlobalBounds().height < window.getSize().y)
            movement.y += 5.f;

        player.move(movement);

        // Limpiar la ventana
        window.clear(Color::Black);

        // Dibujar el sprite
        window.draw(player);

        // Mostrar la ventana
        window.display();
    }

    return 0;
}