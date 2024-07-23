#pragma once
#include <SFML/Graphics.hpp>
#include "Point2D.h"

/**
 * @file Trojkat.cpp
 * @brief Implementacja metod klasy Trojkat.
 */
class Trojkat : public sf::Drawable, public sf::Transformable {
public:
    /**
     * @brief Konstruktor klasy Trojkat.
     * @param _punktA Punkt pierwszego wierzcho�ka tr�jk�ta.
     * @param _punktB Punkt drugiego wierzcho�ka tr�jk�ta.
     * @param _punktC Punkt trzeciego wierzcho�ka tr�jk�ta.
     * @param _kolor Kolor tr�jk�ta.
     * @param _wypelniony Flaga okre�laj�ca, czy tr�jk�t ma by� wype�niony kolorem.
     */
    Trojkat(Point2D _punktA, Point2D _punktB, Point2D _punktC, sf::Color _kolor, bool _wypelniony);

    /**
     * @brief Funkcja rysuj�ca tr�jk�t na danym obiekcie renderuj�cym.
     * @param target Obiekt renderuj�cy, na kt�rym ma zosta� narysowany tr�jk�t.
     * @param states Informacje o transformacji i stanie renderowania tr�jk�ta.
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    /**
     * @brief Zwraca pozycj� �rodka tr�jk�ta.
     * @return Pozycja �rodka tr�jk�ta jako obiekt sf::Vector2f.
     */
    sf::Vector2f getPosition() const;

    /**
     * @brief Ustawia wierzcho�ki tr�jk�ta na podstawie trzech punkt�w.
     * @param _punktA Punkt pierwszego wierzcho�ka tr�jk�ta.
     * @param _punktB Punkt drugiego wierzcho�ka tr�jk�ta.
     * @param _punktC Punkt trzeciego wierzcho�ka tr�jk�ta.
     */
    void ustawPunkty(Point2D _punktA, Point2D _punktB, Point2D _punktC);

    /**
     * @brief Ustawia kolor obrysu tr�jk�ta.
     * @param color Kolor obrysu tr�jk�ta.
     */
    void setOutlineColor(const sf::Color& color);

    /**
     * @brief Ustawia tekstur� jako wype�nienie tr�jk�ta.
     * @param texture Tekstura, kt�ra ma by� u�yta jako wype�nienie tr�jk�ta.
     */
    void ustawWypelnienie(const sf::Texture& texture);

private:
    Point2D punktA; ///< Punkt pierwszego wierzcho�ka tr�jk�ta.
    Point2D punktB; ///< Punkt drugiego wierzcho�ka tr�jk�ta.
    Point2D punktC; ///< Punkt trzeciego wierzcho�ka tr�jk�ta.
    sf::Color kolor; ///< Kolor tr�jk�ta.
    bool wypelniony; ///< Flaga okre�laj�ca, czy tr�jk�t ma by� wype�niony kolorem.
    sf::Texture texture; ///< Tekstura u�ywana jako wype�nienie tr�jk�ta.
};
