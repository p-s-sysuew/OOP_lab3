#include "../include/rectangle.h"
#include <iostream>
#include <math.h>

Rectangle::Rectangle() : Figure(4)
{
    pointsX[0] = 0, pointsX[1] = 0, pointsX[2] = 0, pointsX[3] = 0;
    pointsY[0] = 0, pointsY[1] = 0, pointsY[2] = 0, pointsY[3] = 0;

}

// Деструктор
Rectangle::~Rectangle()
{
    // Деструктор базового класса автоматически вызовется
    // и освободит память для pointsX и pointsY
}

void Rectangle::print(std::ostream& os) const
{
    os << "Прямоугольник: \n";
    int i;
    for (i = 0; i < 4; i++) {
        os << "x = " << pointsX[i] << " y = " << pointsY[i];
        if (i < 3) os << "\n";
    }
}

// Оператор ввода
std::istream& operator>>(std::istream& is, Rectangle& s) 
{
    double x, y, lenX, lenY;
    std::cout << "Введите координаты правого нижнего угла прямоугольника\n";
    std::cout << "x = "; is >> x;
    std::cout << "y = "; is >> y;
    std::cout << "Введите длину прямоугольника >> "; is >> lenX;
    std::cout << "Введите высоту прямоугольника >> "; is >> lenY;

    s.pointsX[0] = x;          s.pointsY[0] = y;
    s.pointsX[1] = x + lenX;    s.pointsY[1] = y;
    s.pointsX[2] = x + lenX;    s.pointsY[2] = y + lenY;
    s.pointsX[3] = x;          s.pointsY[3] = y + lenY;

    return is;
}


// Оператор присваивания копированием
Rectangle& Rectangle::operator=(const Rectangle& other)
{
    if (this != &other) {
        // Используем оператор присваивания базового класса
        Figure::operator=(other);
    }
    return *this;
}

// Оператор присваивания перемещением
Rectangle& Rectangle::operator=(Rectangle&& other) noexcept
{
    if (this != &other) {
        // Используем оператор перемещения базового класса
        Figure::operator=(std::move(other));
    }
    return *this;
}

// Вычисление площади
double Rectangle::area() const
{
    if (countPoint < 2) return 0.0;
    
    // Вычисляем длину стороны по первым двум точкам
    double sideX = fabs(pointsX[1] - pointsX[0]);
    double sideY = fabs(pointsY[2] - pointsY[1]);
    
    return sideX * sideY;
}

// Вычисление геометрического центра
void Rectangle::calculateCenter() const
{
    double centerX = (pointsX[0] + pointsX[1]) / 2.0;
    double centerY = (pointsY[1] + pointsY[2]) / 2.0;
    
    std::cout << "Геометрический центр прямоугольника: (" << centerX << ", " << centerY << ")" << std::endl;
}


// Приведение к double (площадь)
Rectangle::operator double() const
{
    return area();
}