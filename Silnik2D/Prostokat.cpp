#include "Prostokat.h"

/**
 * @brief Konstruktor klasy Prostokat.
 * @param _punktA Punkt lewego g�rnego rogu prostok�ta.
 * @param _punktB Punkt prawego dolnego rogu prostok�ta.
 * @param _kolor Kolor prostok�ta.
 * @param _wypelniony Flaga okre�laj�ca, czy prostok�t ma by� wype�niony kolorem.
 */
Prostokat::Prostokat(Point2D _punktA, Point2D _punktB, sf::Color _kolor, bool _wypelniony)
    : punktA(_punktA), punktB(_punktB), kolor(_kolor), wypelniony(_wypelniony) {}

/**
 * @brief Funkcja rysuj�ca prostok�t na danym obiekcie renderuj�cym.
 * @param target Obiekt renderuj�cy, na kt�rym ma zosta� narysowany prostok�t.
 * @param states Informacje o transformacji i stanie renderowania prostok�ta.
 */
void Prostokat::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::RectangleShape prostokat(sf::Vector2f(std::abs(punktB.x - punktA.x), std::abs(punktB.y - punktA.y)));
    prostokat.setPosition(std::min(punktA.x, punktB.x), std::min(punktA.y, punktB.y));
    prostokat.setFillColor(wypelniony ? kolor : sf::Color::Transparent);
    prostokat.setOutlineColor(kolor);
    prostokat.setOutlineThickness(1.0f);
    prostokat.setTexture(&texture);
    states.transform *= getTransform();
    target.draw(prostokat, states);
}

/**
 * @brief Zwraca pozycj� �rodka prostok�ta.
 * @return Pozycja �rodka prostok�ta jako obiekt sf::Vector2f.
 */
sf::Vector2f Prostokat::getPosition() const {
    return sf::Vector2f((punktA.x + punktB.x) / 2, (punktA.y + punktB.y) / 2);
}

/**
 * @brief Ustawia punkty prostok�ta na podstawie dw�ch przeciwnych rog�w.
 * @param _punktA Punkt lewego g�rnego rogu prostok�ta.
 * @param _punktB Punkt prawego dolnego rogu prostok�ta.
 */
void Prostokat::ustawPunkty(Point2D _punktA, Point2D _punktB) {
    punktA = _punktA;
    punktB = _punktB;
}

/**
 * @brief Ustawia kolor obrysu prostok�ta.
 * @param color Kolor obrysu prostok�ta.
 */
void Prostokat::setOutlineColor(const sf::Color& color) {
    kolor = color;
}

/**
 * @brief Ustawia tekstur� jako wype�nienie prostok�ta.
 * @param texture Tekstura, kt�ra ma by� u�yta jako wype�nienie prostok�ta.
 */
void Prostokat::ustawWypelnienie(const sf::Texture& texture) {
    this->texture = texture;
    wypelniony = true;
}
