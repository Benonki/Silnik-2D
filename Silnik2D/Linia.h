#pragma once
#include <SFML/Graphics.hpp>
#include "Point2D.h"

/**
 * @brief Klasa reprezentuj�ca obiekt linii w przestrzeni 2D.
 */
class Linia : public sf::Drawable, public sf::Transformable {
public:
    /**
     * @brief Konstruktor inicjalizuj�cy obiekt linii.
     * @param _punktPoczatkowy Pocz�tkowy punkt linii.
     * @param _punktKoncowy Ko�cowy punkt linii.
     * @param _kolor Kolor linii.
     */
    Linia(Point2D _punktPoczatkowy, Point2D _punktKoncowy, sf::Color _kolor);

    /**
     * @brief Metoda rysuj�ca obiekt linii.
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    /**
     * @brief Metoda zwracaj�ca pozycj� �rodka linii.
     */
    sf::Vector2f getPosition() const;

    /**
     * @brief Metoda ustawiaj�ca punkty pocz�tkowy i ko�cowy linii.
     * @param _punktPoczatkowy Nowy punkt pocz�tkowy linii.
     * @param _punktKoncowy Nowy punkt ko�cowy linii.
     */
    void ustawPunkty(Point2D _punktPoczatkowy, Point2D _punktKoncowy);

private:
    Point2D punktPoczatkowy; /**< Pocz�tkowy punkt linii. */
    Point2D punktKoncowy;    /**< Ko�cowy punkt linii. */
    sf::Color kolor;         /**< Kolor linii. */
};
