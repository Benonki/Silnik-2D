#pragma once
#include <SFML/Graphics.hpp>
#include "Point2D.h"

/**
 * @brief Klasa reprezentująca obiekt linii w przestrzeni 2D.
 */
class Linia : public sf::Drawable, public sf::Transformable {
public:
    /**
     * @brief Konstruktor inicjalizujący obiekt linii.
     * @param _punktPoczatkowy Początkowy punkt linii.
     * @param _punktKoncowy Końcowy punkt linii.
     * @param _kolor Kolor linii.
     */
    Linia(Point2D _punktPoczatkowy, Point2D _punktKoncowy, sf::Color _kolor);

    /**
     * @brief Metoda rysująca obiekt linii.
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    /**
     * @brief Metoda zwracająca pozycję środka linii.
     */
    sf::Vector2f getPosition() const;

    /**
     * @brief Metoda ustawiająca punkty początkowy i końcowy linii.
     * @param _punktPoczatkowy Nowy punkt początkowy linii.
     * @param _punktKoncowy Nowy punkt końcowy linii.
     */
    void ustawPunkty(Point2D _punktPoczatkowy, Point2D _punktKoncowy);

private:
    Point2D punktPoczatkowy; /**< Początkowy punkt linii. */
    Point2D punktKoncowy;    /**< Końcowy punkt linii. */
    sf::Color kolor;         /**< Kolor linii. */
};
