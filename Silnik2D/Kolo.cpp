#include "Kolo.h"

/**
 * @brief Konstruktor tworz�cy obiekt ko�a.
 * @param _srodek �rodek ko�a (punkt pocz�tkowy).
 * @param _promien Promie� ko�a.
 * @param _kolor Kolor ko�a.
 * @param _wypelnione Okre�la, czy ko�o ma by� wype�nione kolorem.
 */
Kolo::Kolo(Point2D _srodek, float _promien, sf::Color _kolor, bool _wypelnione)
    : srodek(_srodek), promien(_promien), kolor(_kolor), wypelnione(_wypelnione) {}

/**
 * @brief Metoda rysuj�ca obiekt ko�a.
 * @param target Obiekt docelowy do rysowania.
 * @param states Kondycje rysowania.
 */
void Kolo::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::CircleShape kolo(promien);
    kolo.setPosition(srodek.x - promien, srodek.y - promien);
    kolo.setFillColor(wypelnione ? kolor : sf::Color::Transparent);
    kolo.setOutlineColor(kolor);
    kolo.setOutlineThickness(1.0f);
    kolo.setTexture(&texture);
    states.transform *= getTransform();
    target.draw(kolo, states);
}

/**
 * @brief Metoda pobieraj�ca �rodek ko�a.
 * @return Pozycja �rodka ko�a jako obiekt sf::Vector2f.
 */
sf::Vector2f Kolo::pobierzSrodek() const {
    return sf::Vector2f(srodek.x, srodek.y);
}

/**
 * @brief Metoda ustawiaj�ca kolor obramowania ko�a.
 * @param color Kolor obramowania do ustawienia.
 */
void Kolo::setOutlineColor(const sf::Color& color) {
    kolor = color;
}

/**
 * @brief Metoda pobieraj�ca pozycj� �rodka ko�a.
 * @return Pozycja �rodka ko�a jako obiekt sf::Vector2f.
 */
sf::Vector2f Kolo::getPosition() const {
    return sf::Vector2f(srodek.x, srodek.y);
}

/**
 * @brief Metoda ustawiaj�ca tekstur� jako wype�nienie ko�a.
 * @param texture Tekstura do ustawienia.
 */
void Kolo::ustawWypelnienie(const sf::Texture& texture) {
    this->texture = texture;
    wypelnione = true;
}

/**
 * @brief Metoda ustawiaj�ca punkty (�rodek i promie�) ko�a.
 * @param _srodek Nowy �rodek ko�a.
 * @param _promien Nowy promie� ko�a.
 */
void Kolo::ustawPunkty(Point2D _srodek, float _promien) {
    srodek = _srodek;
    promien = _promien;
}

/**
 * @brief Metoda pobieraj�ca promie� ko�a.
 * @return Promie� ko�a.
 */
float Kolo::pobierzPromien() const {
    return promien;
}
