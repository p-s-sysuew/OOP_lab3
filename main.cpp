#include "./include/figure.h"
#include "./include/square.h"
#include "./include/rectangle.h"
#include "./include/trapezoid.h"
#include "include/spisok.h"
#include <iostream>

int main()
{
    Spisok mySpisok;

    std::cout << "Создание геометрических фигур" << std::endl;
    std::cout << std::endl;

    /* 
        Квадраты
    */

    std::cout << "Квадраты" << std::endl;
    std::cout << std::endl;

    Square* my1 = new Square();
    std::cin >> *my1;
    mySpisok.add(my1);
    std::cout << std::endl;

    Square* my2 = new Square();
    std::cin >> *my2;
    mySpisok.add(my2);
    std::cout << std::endl;

    /* 
        Прямоугольники
    */

    std::cout << std::endl;
    std::cout << "Прямоугольники" << std::endl;
    std::cout << std::endl;

    Rectangle* my3 = new Rectangle();
    std::cin >> *my3;
    mySpisok.add(my3);
    std::cout << std::endl;

    Rectangle* my4 = new Rectangle();
    std::cin >> *my4;
    mySpisok.add(my4);
    std::cout << std::endl;

    /* 
        Трапеции
    */

    std::cout << std::endl;
    std::cout << "Трапеции" << std::endl;
    std::cout << std::endl;

    Trapezoid* my5 = new Trapezoid();
    std::cin >> *my5;
    mySpisok.add(my5);
    std::cout << std::endl;

    Trapezoid* my6 = new Trapezoid();
    std::cin >> *my6;
    mySpisok.add(my6);
    std::cout << std::endl;

    /* 
        Вывод всех значений
    */

    std::cout << std::endl;
    std::cout << "Вывод значений" << std::endl;
    std::cout << std::endl;



    for (int i = 0; i < mySpisok.size(); i++) {
        std::cout << *(mySpisok[i]) << std::endl;
        std::cout << "Площадь фигуры = " << (*(mySpisok[i])).area() << std::endl;
        std::cout << "(double) myFigure = " << (double) (*(mySpisok[i])) << std::endl;
        (*(mySpisok[i])).calculateCenter();
        std::cout << std::endl;
    }

    /* 
        Удаление всех элементов в списке
    */

    std::cout << std::endl;
    std::cout << "Удаление элементов ..." << std::endl;
    for (int i = 0; i < 6; i++) {
        mySpisok.pop(0);
        std::cout << "Элемент № " << i + 1 << " удалён из спсика" << std::endl;
    }
    std::cout << "Список отчищен" << std::endl;

    return 0;
    // Деструктор Spisok автоматически удалит все объекты
}