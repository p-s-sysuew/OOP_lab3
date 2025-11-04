#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"

class Trapezoid : public Figure {
    // Оператор потокового вывода
    friend std::istream& operator>>(std::istream& is, Trapezoid& f);
public: 
    Trapezoid(); // Конструктор по умолчанию

    ~Trapezoid(); // Деструктор


    Trapezoid& operator=(const Trapezoid& other); // Присваивание копированием
   Trapezoid& operator=(Trapezoid&& other) noexcept; // Присваивание перемещением
    

    virtual double area() const; // Вычисление площади
    virtual void calculateCenter() const; // Вычисление геометрического центра
    
    // Приведение к double (площадь)
    operator double() const;

    virtual void print(std::ostream& os) const override;

    
};

#endif