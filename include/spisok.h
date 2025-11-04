#ifndef SPISOK_H
#define SPISOK_H

#include "figure.h"
#include <iostream>
#include <cstddef>

class Spisok {
    
public: 
    Spisok(); // Конструктор по умолчанию
    ~Spisok(); // Деструктор

    Figure* operator[](size_t index);
    const Figure* operator[](size_t index) const;

    // Добавить элемент в конец списка
    void add(Figure* f);

    // Возвращает длину списка
    size_t size() const;

    // Удаляет элемент под нужным индексом
    void pop(size_t index);

private:
    struct elem_of_spisok {
        Figure* value;
        elem_of_spisok* next;
        elem_of_spisok* prev;
    };

    elem_of_spisok* head;
    elem_of_spisok* tail;
    size_t len;
};

#endif