#include "Trojkat.h"

/**
 * @brief Konstruktor klasy Trojkat.
 * @param _punktA Punkt pierwszego wierzcho�ka tr�jk�ta.
 * @param _punktB Punkt drugiego wierzcho�ka tr�jk�ta.
 * @param _punktC Punkt trzeciego wierzcho�ka tr�jk�ta.
 * @param _kolor Kolor tr�jk�ta.
 * @param _wypelniony Flaga okre�laj�ca, czy tr�jk�t ma by� wype�niony kolorem.
 */
Trojkat::Trojkat(Point2D _punktA, Point2D _punktB, Point2D _punktC, sf::Color _kolor, bool _wypelniony)
    : punktA(_punktA), punktB(_punktB), punktC(_punktC), kolor(_kolor), wypelniony(_wypelniony) {}

/**
 * @brief Funkcja rysuj�ca tr�jk�t na danym obiekcie renderuj�cym.
 * @param target Obiekt renderuj�cy, na kt�rym ma zosta� narysowany tr�jk�t.
 * @param states Informacje o transformacji i stanie renderowania tr�jk�ta.
 */
void Trojkat::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::ConvexShape trojkat(3);
    trojkat.setPoint(0, sf::Vector2f(punktA.x, punktA.y));
    trojkat.setPoint(1, sf::Vector2f(punktB.x, punktB.y));
    trojkat.setPoint(2, sf::Vector2f(punktC.x, punktC.y));
    trojkat.setFillColor(wypelniony ? kolor : sf::Color::Transparent);
    trojkat.setOutlineColor(kolor);
    trojkat.setOutlineThickness(1.0f);
    trojkat.setTexture(&texture);
    states.transform *= getTransform();
    target.draw(trojkat, states);
}

/**
 * @brief Zwraca pozycj� �rodka tr�jk�ta.
 * @return Pozycja �rodka tr�jk�ta jako obiekt sf::Vector2f.
 */
sf::Vector2f Trojkat::getPosition() const {
    return sf::Vector2f((punktA.x + punktB.x + punktC.x) / 3, (punktA.y + punktB.y + punktC.y) / 3);
}

/**
 * @brief Ustawia wierzcho�ki tr�jk�ta na podstawie trzech punkt�w.
 * @param _punktA Punkt pierwszego wierzcho�ka tr�jk�ta.
 * @param _punktB Punkt drugiego wierzcho�ka tr�jk�ta.
 * @param _punktC Punkt trzeciego wierzcho�ka tr�jk�ta.
 */
void Trojkat::ustawPunkty(Point2D _punktA, Point2D _punktB, Point2D _punktC) {
    punktA = _punktA;
    punktB = _punktB;
    punktC = _punktC;
}

/**
 * @brief Ustawia kolor obrysu tr�jk�ta.
 * @param color Kolor obrysu tr�jk�ta.
 */
void Trojkat::setOutlineColor(const sf::Color& color) {
    kolor = color;
}

/**
 * @brief Ustawia tekstur� jako wype�nienie tr�jk�ta.
 * @param texture Tekstura, kt�ra ma by� u�yta jako wype�nienie tr�jk�ta.
 */
void Trojkat::ustawWypelnienie(const sf::Texture& texture) {
    this->texture = texture;
    wypelniony = true;
}
