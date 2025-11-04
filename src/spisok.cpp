#include "../include/spisok.h"

Spisok::Spisok() 
{
    head = tail = nullptr;
    len = 0;
}

Spisok::~Spisok()
{
    elem_of_spisok* current = head;
    while (current != nullptr) {
        elem_of_spisok* next = current->next;
        delete current->value; // удаляем фигуру
        delete current;        // удаляем элемент списка
        current = next;
    }
}

Figure* Spisok::operator[](size_t index)
{
    if (index >= len) {
        std::cerr << "Произошёл выход за пределы списка" << std::endl;
        return nullptr;
    }
    
    elem_of_spisok* current = head;
    for (size_t i = 0; i < index && current != nullptr; i++) {
        current = current->next;
    }
    
    return current ? current->value : nullptr;
}

const Figure* Spisok::operator[](size_t index) const
{
    if (index >= len) {
        return nullptr;
    }
    
    elem_of_spisok* current = head;
    for (size_t i = 0; i < index && current != nullptr; i++) {
        current = current->next;
    }
    
    return current ? current->value : nullptr;
}

// Добавить элемент в конец списка
void Spisok::add(Figure* f)
{
    elem_of_spisok* new_elem = new elem_of_spisok;
    new_elem->value = f;
    new_elem->next = nullptr;
    
    if (head == nullptr) {
        // Первый элемент
        head = new_elem;
        tail = new_elem;
        new_elem->prev = nullptr;
    } else {
        // Добавление в конец
        tail->next = new_elem;
        new_elem->prev = tail;
        tail = new_elem;
    }
    
    len++;
}

size_t Spisok::size() const
{
    return len;
}

void Spisok::pop(size_t index)
{
    if (index >= len || head == nullptr) {
        std::cerr << "Неверный индекс или пустой список" << std::endl;
        return;
    }
    
    elem_of_spisok* current = head;
    for (size_t i = 0; i < index && current != nullptr; i++) {
        current = current->next;
    }
    
    if (current == nullptr) {
        return;
    }
    
    // Случай: один элемент в списке
    if (head == tail) {
        head = tail = nullptr;
    }
    // Удаление первого элемента
    else if (current == head) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
    }
    // Удаление последнего элемента
    else if (current == tail) {
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
    }
    // Удаление из середины
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    
    delete current->value; // удаляем фигуру
    delete current;        // удаляем элемент списка
    len--;
}