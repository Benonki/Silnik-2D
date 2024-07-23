#pragma once

/**
 * @brief Struktura reprezentuj�ca punkt 2D o wsp�rz�dnych x i y.
 */
struct Point2D {
    float x, y; ///< Wsp�rz�dne punktu.

    /**
     * @brief Konstruktor domy�lny ustawiaj�cy wsp�rz�dne na 0.
     */
    Point2D() : x(0.0f), y(0.0f) {}

    /**
     * @brief Konstruktor inicjalizuj�cy wsp�rz�dne zadanymi warto�ciami.
     * @param _x Wsp�rz�dna x.
     * @param _y Wsp�rz�dna y.
     */
    Point2D(float _x, float _y) : x(_x), y(_y) {}
};
