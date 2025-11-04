#include "../include/figure.h"
#include <stdbool.h>

// Конструктор по умолчанию
Figure::Figure() : countPoint(0), pointsX(nullptr), pointsY(nullptr)
{
}


Figure::Figure(unsigned int n) : countPoint(n)
{
    if (n == 0) {
        pointsX = nullptr;
        pointsY = nullptr;
    } else {
        try {  
            pointsX = new double[n];
            pointsY = new double[n];
        } catch (const std::bad_alloc& e) {
            std::cout << "Не удалаось выделить память для создания массива. Ошибка: " 
                << e.what() << std::endl;
            return;
        }
    }
    
    
}


// Деструктор
Figure::~Figure()
{
    if (countPoint != 0) {
        // Освобождаем выделенную под массив точек память
        delete pointsX; 
        delete pointsY; 
    }
}

void Figure::print(std::ostream& os) const
{
    if (countPoint == 0) {
        os << "Фигура не имеет точек";
    } else {
        int i;
        for (i = 0; i < countPoint; i++) {
            os << "x = " << pointsX[i] << " y = " << pointsY[i];
            if (i < countPoint - 1) os << "\n";
        }
    }
}


std::ostream& operator<<(std::ostream& os, const Figure& f)
{
    f.print(os);  // Вызов виртуального метода
    return os;
}


std::istream& operator>>(std::istream& is, Figure& f) {
    int i = 0;
    double x, y;
    for (; i < f.countPoint; i++) {
        is >> x >> y;
        f.pointsX[i] = x;
        f.pointsY[i] = y;
    }
    return is;
}


Figure& Figure::operator=(const Figure& right_operand)
{
    // Если длина двух массивов не сопадает
    if (this->countPoint != right_operand.countPoint) {
        delete this->pointsX;
        delete this->pointsY;

        try {
            this->pointsX = new double[right_operand.countPoint];
            this->pointsY = new double[right_operand.countPoint];
            this->countPoint = right_operand.countPoint;
        } catch (const std::bad_alloc& e) {
            std::cout << "Не удалаось выделить память для создания массива. Ошибка: " 
                << e.what() << std::endl;
            this->countPoint = 0;
            this->pointsX = nullptr;
            this->pointsY = nullptr;
            return *this;
        }   
    }

    // Копирование
    for (int i = 0; i < right_operand.countPoint; i++) {
        this->pointsX[i] = right_operand.pointsX[i];
        this->pointsY[i] = right_operand.pointsY[i];
    }
        
    return *this;  // Возвращаем текущий объект
}


Figure& Figure::operator=(Figure& right_operand) noexcept
{
    this->countPoint = right_operand.countPoint;
    this->pointsX = right_operand.pointsX;
    this->pointsY = right_operand.pointsY;

    right_operand.countPoint = 0;
    right_operand.pointsX = nullptr;
    right_operand.pointsY = nullptr;

    return *this;
}


bool Figure::operator==(Figure& right_operand) const
{
    if (this->countPoint != right_operand.countPoint) return false;

    for (int i = 0; i < this->countPoint; i++) {
        if (this->pointsX[i] != right_operand.pointsX[i] || 
            this->pointsY[i] != right_operand.pointsY[i] ) {
                return false;
            }
    }

    return true;
    
}


double Figure::area() const
{
    std::cout << "Площадь\n";
    return 0;
}


void Figure::calculateCenter() const
{
    std::cout << "Геометрический центр\n";
}


Figure::operator double() const
{
    return area();
}