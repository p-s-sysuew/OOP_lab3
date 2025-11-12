#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>

class Figure {
    // Оператор потокового вывода
    friend std::ostream& operator<<(std::ostream& os, const Figure& f);

    // Оператор потокового ввода
    friend std::istream& operator>>(std::istream& is, Figure& f);

public: 
    Figure(); // Конструктор по-умолчанию
    Figure(unsigned int n); // Конструктор, принимающий на вход количество точек и их координаты
    virtual ~Figure(); // Деструктор

    // Виртуальные методы для полиморфизма
    virtual double area() const;
    virtual void calculateCenter() const;

    // Оператор копирования
    Figure& operator=(const Figure& right_operand);

    Figure& operator=(Figure& right_operand) noexcept;

    bool operator==(const Figure& right_operand) const;

    virtual void print(std::ostream& os) const; // Виртуальный метод для вывода


    virtual operator double() const;

    // Метод для установки точек (для тестирования)
    void setPoints(const std::vector<double>& x_coords, const std::vector<double>& y_coords);




protected:
    unsigned int countPoint; // Количество точек фигуры
    double * pointsX;   // Все точки фигуры (координата x)
    double * pointsY;   // Все точки фигуры (координата y)

};



#endif