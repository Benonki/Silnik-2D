#pragma once
#include <SFML/Graphics.hpp>
#include "Point2D.h"

/**
 * @file Kolo.cpp
 * @brief Implementacja metod klasy Kolo.
 */
class Kolo : public sf::Drawable, public sf::Transformable {
public:
    /**
     * @brief Konstruktor tworz�cy obiekt ko�a.
     * @param _srodek �rodek ko�a (punkt pocz�tkowy).
     * @param _promien Promie� ko�a.
     * @param _kolor Kolor ko�a.
     * @param _wypelnione Okre�la, czy ko�o ma by� wype�nione kolorem.
     */
    Kolo(Point2D _srodek, float _promien, sf::Color _kolor, bool _wypelnione);

    /**
     * @brief Metoda rysuj�ca obiekt ko�a.
     * @param target Obiekt docelowy do rysowania.
     * @param states Kondycje rysowania.
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    /**
     * @brief Metoda pobieraj�ca pozycj� �rodka ko�a.
     * @return Pozycja �rodka ko�a jako obiekt sf::Vector2f.
     */
    sf::Vector2f getPosition() const;

    /**
     * @brief Metoda ustawiaj�ca punkty (�rodek i promie�) ko�a.
     * @param _srodek Nowy �rodek ko�a.
     * @param _promien Nowy promie� ko�a.
     */
    void ustawPunkty(Point2D _srodek, float _promien);

    /**
     * @brief Metoda pobieraj�ca promie� ko�a.
     * @return Promie� ko�a.
     */
    float pobierzPromien() const;

    /**
     * @brief Metoda ustawiaj�ca tekstur� jako wype�nienie ko�a.
     * @param texture Tekstura do ustawienia.
     */
    void ustawWypelnienie(const sf::Texture& texture);

    /**
     * @brief Metoda pobieraj�ca �rodek ko�a.
     * @return Pozycja �rodka ko�a jako obiekt sf::Vector2f.
     */
    sf::Vector2f pobierzSrodek() const;

    /**
     * @brief Metoda ustawiaj�ca kolor obramowania ko�a.
     * @param color Kolor obramowania do ustawienia.
     */
    void setOutlineColor(const sf::Color& color);

private:
    Point2D srodek;         ///< �rodek ko�a.
    float promien;          ///< Promie� ko�a.
    sf::Color kolor;        ///< Kolor ko�a.
    bool wypelnione;        ///< Flaga okre�laj�ca, czy ko�o ma by� wype�nione kolorem.
    sf::Texture texture;    ///< Tekstura jako wype�nienie ko�a.
};
