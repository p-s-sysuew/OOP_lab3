#include "../include/square.h"
#include <iostream>
#include <math.h>

Square::Square() : Figure(4)
{
    pointsX[0] = 0, pointsX[1] = 0, pointsX[2] = 0, pointsX[3] = 0;
    pointsY[0] = 0, pointsY[1] = 0, pointsY[2] = 0, pointsY[3] = 0;

}

// Деструктор
Square::~Square()
{
    // Деструктор базового класса автоматически вызовется
    // и освободит память для pointsX и pointsY
}

void Square::print(std::ostream& os) const
{
    os << "Квадрат: \n";
    int i;
    for (i = 0; i < 4; i++) {
        os << "x = " << pointsX[i] << " y = " << pointsY[i];
        if (i < 3) os << "\n";
    }
}

// Оператор ввода
std::istream& operator>>(std::istream& is, Square& s) 
{
    double x, y, len;
    std::cout << "Введите координаты правого нижнего угла квадрата\n";
    std::cout << "x = "; is >> x;
    std::cout << "y = "; is >> y;
    std::cout << "Введите длину стороны квадрата >> "; is >> len;

    s.pointsX[0] = x;          s.pointsY[0] = y;
    s.pointsX[1] = x + len;    s.pointsY[1] = y;
    s.pointsX[2] = x + len;    s.pointsY[2] = y + len;
    s.pointsX[3] = x;          s.pointsY[3] = y + len;

    return is;
}


// Оператор присваивания копированием
Square& Square::operator=(const Square& other)
{
    if (this != &other) {
        // Используем оператор присваивания базового класса
        Figure::operator=(other);
    }
    return *this;
}

// Оператор присваивания перемещением
Square& Square::operator=(Square&& other) noexcept
{
    if (this != &other) {
        // Используем оператор перемещения базового класса
        Figure::operator=(std::move(other));
    }
    return *this;
}

// Вычисление площади
double Square::area() const
{
    if (countPoint < 2) return 0.0;
    
    // Вычисляем длину стороны по первым двум точкам
    double side = fabs(pointsX[1] - pointsX[0]);
    
    return side * side;
}

// Вычисление геометрического центра
void Square::calculateCenter() const
{
    double centerX = (pointsX[0] + pointsX[1]) / 2.0;
    double centerY = (pointsY[1] + pointsY[2]) / 2.0;
    
    std::cout << "Геометрический центр квадрата: (" << centerX << ", " << centerY << ")" << std::endl;
}


// Приведение к double (площадь)
Square::operator double() const
{
    return area();
}