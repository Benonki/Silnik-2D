#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Point2D.h"
#include "Linia.h"
#include "Kolo.h"
#include "Trojkat.h"
#include "Prostokat.h"

/**
 * @file Silnik.cpp
 * @brief Klasa Silnik odpowiada za zarz�dzanie g��wn� logik� programu.
 */
class Silnik {
public:
    /**
     * @brief Konstruktor klasy Silnik.
     */
    Silnik();

    /**
     * @brief Destruktor klasy Silnik.
     */
    ~Silnik();

    /**
     * @brief Metoda uruchamiaj�ca g��wn� p�tl� programu.
     */
    void uruchom();

private:
    sf::RenderTexture renderTexture; ///< Tekstura u�ywana do renderowania obiekt�w.
    sf::RenderWindow window; ///< Okno g��wne programu.
    std::vector<sf::Drawable*> obiekty; ///< Wektor przechowuj�cy wska�niki do rysowalnych obiekt�w.
    sf::Drawable* aktualnyObiekt; ///< Wska�nik do aktualnie rysowanego obiektu.
    bool czyWypelnione; ///< Flaga okre�laj�ca, czy obiekt ma by� wype�niony kolorem.
    sf::Color kolor; ///< Kolor aktualnie rysowanego obiektu.
    Point2D punktStartowy; ///< Punkt pocz�tkowy dla rysowanego obiektu.
    Point2D punktKoncowy; ///< Punkt ko�cowy dla rysowanego obiektu.
    Point2D punktA, punktB, punktC; ///< Punkty pomocnicze dla niekt�rych obiekt�w.
    float promien; ///< Promie� u�ywany dla okr�g�w.
    bool trybEdycji; ///< Flaga okre�laj�ca, czy program dzia�a w trybie edycji.
    sf::Color kolorEdycji; ///< Kolor zaznaczenia w trybie edycji.
    sf::Drawable* obiektDoEdycji; ///< Wska�nik do obiektu podlegaj�cego edycji.
    sf::Vector2i poprzedniaPozycjaMyszy; ///< Poprzednia pozycja myszy, u�ywana do przesuwania obiekt�w.
    bool czyZaznaczony; ///< Flaga okre�laj�ca, czy obiekt jest zaznaczony w trybie edycji.
    float katObracaniaZaznaczenia; ///< K�t obrotu zaznaczonego obiektu.
    bool wybieranieKoloru; ///< Flaga okre�laj�ca, czy u�ytkownik wybiera kolor.
    sf::Color kolorWyboru; ///< Kolor wybrany przez u�ytkownika.
    std::string sciezkaObrazu; ///< �cie�ka do wczytywanego obrazu.

    /**
     * @brief Metoda odpowiedzialna za rysowanie wszystkich obiekt�w na renderTexture.
     */
    void rysujObiekty();

    /**
     * @brief Metoda obs�uguj�ca zdarzenia generowane przez u�ytkownika.
     * @param event Zdarzenie SFML.
     */
    void obslugaZdarzen(const sf::Event& event);

    /**
     * @brief Metoda przesuwaj�ca obiekt o zadane warto�ci dx i dy.
     * @param obiekt Wska�nik do rysowalnego obiektu.
     * @param dx Przesuni�cie w osi X.
     * @param dy Przesuni�cie w osi Y.
     */
    void przesunObiekt(sf::Drawable* obiekt, float dx, float dy);

    /**
     * @brief Metoda obracaj�ca obiekt o zadany k�t.
     * @param obiekt Wska�nik do rysowalnego obiektu.
     * @param kat K�t obrotu.
     */
    void rotujObiekt(sf::Drawable* obiekt, float kat);

    /**
     * @brief Metoda wczytuj�ca obraz do obiektu, je�eli jest to mo�liwe (obiekt wype�nialny).
     * @param obiekt Wska�nik do rysowalnego obiektu.
     * @param sciezkaObrazu �cie�ka do wczytywanego obrazu.
     */
    void wczytajObraz(sf::Drawable* obiekt, const std::string& sciezkaObrazu);
};
