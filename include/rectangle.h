#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle : public Figure {
    // Оператор потокового вывода
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& f);
    friend std::istream& operator>>(std::istream& is, Rectangle& f);
public: 
    Rectangle(); // Конструктор по умолчанию

    ~Rectangle(); // Деструктор


    Rectangle& operator=(const Rectangle& other); // Присваивание копированием
    Rectangle& operator=(Rectangle&& other) noexcept; // Присваивание перемещением
    

    virtual double area() const; // Вычисление площади
    virtual void calculateCenter() const; // Вычисление геометрического центра
    
    // Приведение к double (площадь)
    operator double() const;

    virtual void print(std::ostream& os) const override;

    
};

#endif