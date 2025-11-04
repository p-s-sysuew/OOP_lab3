#include "../include/trapezoid.h"
#include <iostream>
#include <math.h>

Trapezoid::Trapezoid() : Figure(4)
{
    pointsX[0] = 0, pointsX[1] = 0, pointsX[2] = 0, pointsX[3] = 0;
    pointsY[0] = 0, pointsY[1] = 0, pointsY[2] = 0, pointsY[3] = 0;
}

// Деструктор
Trapezoid::~Trapezoid()
{
    // Деструктор базового класса автоматически вызовется
    // и освободит память для pointsX и pointsY
}

void Trapezoid::print(std::ostream& os) const
{
    os << "Трапеция: \n";
    int i;
    for (i = 0; i < 4; i++) {
        os << "x = " << pointsX[i] << " y = " << pointsY[i];
        if (i < 3) os << "\n";
    }
}

// Оператор ввода
std::istream& operator>>(std::istream& is, Trapezoid& t) 
{
    double xLower, yLower, lowerBase, upperBase, height;
    std::cout << "Введите координаты левого нижнего угла трапеции\n";
    std::cout << "x = "; is >> xLower;
    std::cout << "y = "; is >> yLower;
    std::cout << "Введите длину нижнего основания >> "; is >> lowerBase;
    std::cout << "Введите длину верхнего основания >> "; is >> upperBase;
    std::cout << "Введите высоту трапеции >> "; is >> height;

    // Вычисляем смещение для верхнего основания (чтобы трапеция была симметричной)
    double offset = (lowerBase - upperBase) / 2.0;

    // Задаем точки трапеции (по часовой стрелке, начиная с левого нижнего угла)
    t.pointsX[0] = xLower;                   t.pointsY[0] = yLower;
    t.pointsX[1] = xLower + lowerBase;       t.pointsY[1] = yLower;
    t.pointsX[2] = xLower + offset + upperBase; t.pointsY[2] = yLower + height;
    t.pointsX[3] = xLower + offset;          t.pointsY[3] = yLower + height;

    return is;
}

// Оператор присваивания копированием
Trapezoid& Trapezoid::operator=(const Trapezoid& other)
{
    if (this != &other) {
        // Используем оператор присваивания базового класса
        Figure::operator=(other);
    }
    return *this;
}

// Оператор присваивания перемещением
Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept
{
    if (this != &other) {
        // Используем оператор перемещения базового класса
        Figure::operator=(std::move(other));
    }
    return *this;
}

// Вычисление площади трапеции
double Trapezoid::area() const
{
    if (countPoint < 4) return 0.0;
    
    // Вычисляем длины оснований
    double lowerBase = fabs(pointsX[1] - pointsX[0]);
    double upperBase = fabs(pointsX[2] - pointsX[3]);
    
    // Вычисляем высоту
    double height = fabs(pointsY[3] - pointsY[0]);
    
    // Площадь трапеции: (a + b) * h / 2
    return (lowerBase + upperBase) * height / 2.0;
}

// Вычисление геометрического центра
void Trapezoid::calculateCenter() const
{
    if (countPoint < 4) {
        std::cout << "Недостаточно точек для вычисления центра" << std::endl;
        return;
    }
    
    double centerX = 0, centerY = 0;
    
    // Вычисляем среднее арифметическое всех точек
    for (int i = 0; i < 4; i++) {
        centerX += pointsX[i];
        centerY += pointsY[i];
    }
    
    centerX /= 4.0;
    centerY /= 4.0;
    
    std::cout << "Геометрический центр трапеции: (" << centerX << ", " << centerY << ")" << std::endl;
}

// Приведение к double (площадь)
Trapezoid::operator double() const
{
    return area();
}