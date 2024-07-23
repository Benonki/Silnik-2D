#pragma once
#include <SFML/Graphics.hpp>
#include "Point2D.h"

/**
 * @file Prostokat.cpp
 * @brief Implementacja metod klasy Prostokat.
 */
class Prostokat : public sf::Drawable, public sf::Transformable {
public:
    /**
     * @brief Konstruktor klasy Prostokat.
     * @param _punktA Punkt lewego g�rnego rogu prostok�ta.
     * @param _punktB Punkt prawego dolnego rogu prostok�ta.
     * @param _kolor Kolor prostok�ta.
     * @param _wypelniony Flaga okre�laj�ca, czy prostok�t ma by� wype�niony kolorem.
     */
    Prostokat(Point2D _punktA, Point2D _punktB, sf::Color _kolor, bool _wypelniony);

    /**
     * @brief Funkcja rysuj�ca prostok�t na danym obiekcie renderuj�cym.
     * @param target Obiekt renderuj�cy, na kt�rym ma zosta� narysowany prostok�t.
     * @param states Informacje o transformacji i stanie renderowania prostok�ta.
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    /**
     * @brief Zwraca pozycj� �rodka prostok�ta.
     * @return Pozycja �rodka prostok�ta jako obiekt sf::Vector2f.
     */
    sf::Vector2f getPosition() const;

    /**
     * @brief Ustawia punkty prostok�ta na podstawie dw�ch przeciwnych rog�w.
     * @param _punktA Punkt lewego g�rnego rogu prostok�ta.
     * @param _punktB Punkt prawego dolnego rogu prostok�ta.
     */
    void ustawPunkty(Point2D _punktA, Point2D _punktB);

    /**
     * @brief Ustawia kolor obrysu prostok�ta.
     * @param color Kolor obrysu prostok�ta.
     */
    void setOutlineColor(const sf::Color& color);

    /**
     * @brief Ustawia tekstur� jako wype�nienie prostok�ta.
     * @param texture Tekstura, kt�ra ma by� u�yta jako wype�nienie prostok�ta.
     */
    void ustawWypelnienie(const sf::Texture& texture);

private:
    Point2D punktA; ///< Punkt lewego g�rnego rogu prostok�ta.
    Point2D punktB; ///< Punkt prawego dolnego rogu prostok�ta.
    sf::Color kolor; ///< Kolor prostok�ta.
    bool wypelniony; ///< Flaga okre�laj�ca, czy prostok�t ma by� wype�niony kolorem.
    sf::Texture texture; ///< Tekstura u�ywana jako wype�nienie prostok�ta.
};
