/**
 * @file Linia.cpp
 * @brief Implementacja metod klasy Linia.
 */

#include "Linia.h"

 /**
  * @brief Konstruktor klasy Linia.
  * @param _punktPoczatkowy Punkt pocz�tkowy linii.
  * @param _punktKoncowy Punkt ko�cowy linii.
  * @param _kolor Kolor linii.
  */
Linia::Linia(Point2D _punktPoczatkowy, Point2D _punktKoncowy, sf::Color _kolor)
    : punktPoczatkowy(_punktPoczatkowy), punktKoncowy(_punktKoncowy), kolor(_kolor) {}

/**
 * @brief Metoda rysuj�ca lini� na docelowym obiekcie renderuj�cym.
 * @param target Obiekt renderuj�cy, na kt�rym rysowa�.
 * @param states Stany renderowania do zastosowania.
 */
void Linia::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Tworzenie linii za pomoc� dw�ch wierzcho�k�w
    sf::Vertex linia[] = {
        sf::Vertex(sf::Vector2f(punktPoczatkowy.x, punktPoczatkowy.y), kolor),
        sf::Vertex(sf::Vector2f(punktKoncowy.x, punktKoncowy.y), kolor)
    };

    // Zastosowanie transformacji obiektu
    states.transform *= getTransform();
    target.draw(linia, 2, sf::Lines, states);
}

/**
 * @brief Pobranie pozycji �rodkowego punktu linii.
 * @return Pozycja �rodkowego punktu linii.
 */
sf::Vector2f Linia::getPosition() const {
    return sf::Vector2f((punktPoczatkowy.x + punktKoncowy.x) / 2, (punktPoczatkowy.y + punktKoncowy.y) / 2);
}

/**
 * @brief Ustawienie punkt�w pocz�tkowego i ko�cowego linii.
 * @param _punktPoczatkowy Punkt pocz�tkowy linii.
 * @param _punktKoncowy Punkt ko�cowy linii.
 */
void Linia::ustawPunkty(Point2D _punktPoczatkowy, Point2D _punktKoncowy) {
    punktPoczatkowy = _punktPoczatkowy;
    punktKoncowy = _punktKoncowy;
}
