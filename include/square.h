#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square : public Figure {
    // Оператор потокового вывода
    friend std::istream& operator>>(std::istream& is, Square& f);
public: 
    Square(); // Конструктор по умолчанию

    ~Square(); // Деструктор


    Square& operator=(const Square& other); // Присваивание копированием
    Square& operator=(Square&& other) noexcept; // Присваивание перемещением
    

    virtual double area() const; // Вычисление площади
    virtual void calculateCenter() const; // Вычисление геометрического центра
    
    // Приведение к double (площадь)
    operator double() const;

    virtual void print(std::ostream& os) const override;

    
};

#endif