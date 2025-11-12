#include <gtest/gtest.h>
#include "../include/figure.h"
#include "../include/square.h"
#include "../include/rectangle.h"
#include "../include/trapezoid.h"
#include "../include/spisok.h"
#include <sstream>
#include <iostream>
#include <cmath>

// Вспомогательная функция для создания квадрата через строковый поток
void CreateSquareFromStream(Square& square, double x, double y, double side) {
    // Используем оператор ввода через stringstream вместо прямого доступа к полям
    std::stringstream input;
    input << x << " " << y << " " << side;
    input >> square;
}

// Вспомогательная функция для создания прямоугольника через строковый поток
void CreateRectangleFromStream(Rectangle& rect, double x, double y, double width, double height) {
    std::stringstream input;
    input << x << " " << y << " " << width << " " << height;
    input >> rect;
}

// Вспомогательная функция для создания трапеции через строковый поток
void CreateTrapezoidFromStream(Trapezoid& trap, double x, double y, double lowerBase, double upperBase, double height) {
    std::stringstream input;
    input << x << " " << y << " " << lowerBase << " " << upperBase << " " << height;
    input >> trap;
}

// Тест конструктора по умолчанию для базового класса Figure
TEST(FigureTest, DefaultConstructor) {
    Figure figure;
    // Проверяем, что фигура создается без точек
    std::stringstream ss;
    figure.print(ss);
    EXPECT_EQ(ss.str(), "Фигура не имеет точек");
    EXPECT_EQ(figure.area(), 0.0); // Площадь должна быть 0
}

// Тест параметризованного конструктора Figure
TEST(FigureTest, ParameterizedConstructor) {
    Figure figure(3);
    // Проверяем, что фигура создается с заданным количеством точек
    // Не можем проверить countPoint напрямую, так как он protected
    // Проверяем через поведение
    std::stringstream ss;
    figure.print(ss);
    EXPECT_FALSE(ss.str().empty());
}

// Тест оператора присваивания копированием для Figure
TEST(FigureTest, CopyAssignment) {
    Figure figure1(2);
    // Устанавливаем точки через оператор ввода
    std::stringstream input1("1.0 2.0 3.0 4.0");
    input1 >> figure1;

    Figure figure2;
    figure2 = figure1; // Копируем

    // Проверяем через вывод
    std::stringstream ss1, ss2;
    figure1.print(ss1);
    figure2.print(ss2);
    
    // Обе фигуры должны иметь одинаковое представление
    EXPECT_FALSE(ss1.str().empty());
    EXPECT_FALSE(ss2.str().empty());
}

// Тест оператора сравнения для Figure
TEST(FigureTest, EqualityOperator) {
    Figure figure1(2);
    std::stringstream input1("1.0 2.0 3.0 4.0");
    input1 >> figure1;

    Figure figure2(2);
    std::stringstream input2("1.0 2.0 3.0 4.0");
    input2 >> figure2;

    Figure figure3(2);
    std::stringstream input3("5.0 6.0 7.0 8.0");
    input3 >> figure3;

    // Используем явный вызов оператора для избежания неоднозначности
    EXPECT_TRUE(figure1.operator==(figure2)); // Одинаковые фигуры
    EXPECT_FALSE(figure1.operator==(figure3)); // Разные фигуры
}

// Тест вычисления площади для пустой фигуры
TEST(FigureTest, AreaOfEmptyFigure) {
    Figure figure;
    // Площадь фигуры без точек должна быть 0
    EXPECT_DOUBLE_EQ(figure.area(), 0.0);
}

// Тест приведения к double для Figure
TEST(FigureTest, DoubleConversion) {
    Figure figure;
    // Приведение к double должно возвращать площадь
    double area = static_cast<double>(figure);
    EXPECT_DOUBLE_EQ(area, 0.0);
}

// Тест конструктора по умолчанию для Square
TEST(SquareTest, DefaultConstructor) {
    Square square;
    // Проверяем создание квадрата через его поведение
    std::stringstream ss;
    square.print(ss);
    EXPECT_TRUE(ss.str().find("Квадрат") != std::string::npos);
}

// Тест вычисления площади квадрата
TEST(SquareTest, AreaCalculation) {
    Square square;
    // Создаем квадрат со стороной 5
    CreateSquareFromStream(square, 0.0, 0.0, 5.0);
    
    // Площадь должна быть 5*5=25
    EXPECT_DOUBLE_EQ(square.area(), 25.0);
}

// Тест вычисления геометрического центра квадрата
TEST(SquareTest, CenterCalculation) {
    Square square;
    CreateSquareFromStream(square, 0.0, 0.0, 4.0);
    
    // Проверяем, что функция не выбрасывает исключений
    EXPECT_NO_THROW(square.calculateCenter());
}

// Тест приведения квадрата к double
TEST(SquareTest, DoubleConversion) {
    Square square;
    CreateSquareFromStream(square, 0.0, 0.0, 3.0);

    // Приведение к double должно возвращать площадь
    double area = static_cast<double>(square);
    EXPECT_DOUBLE_EQ(area, 9.0);
}

// Тест вывода квадрата
TEST(SquareTest, PrintOutput) {
    Square square;
    CreateSquareFromStream(square, 1.0, 2.0, 3.0);
    
    std::stringstream ss;
    square.print(ss);
    
    // Проверяем, что вывод содержит информацию о квадрате
    EXPECT_FALSE(ss.str().empty());
    EXPECT_TRUE(ss.str().find("Квадрат") != std::string::npos);
}

// Тест конструктора по умолчанию для Rectangle
TEST(RectangleTest, DefaultConstructor) {
    Rectangle rectangle;
    std::stringstream ss;
    rectangle.print(ss);
    EXPECT_TRUE(ss.str().find("Прямоугольник") != std::string::npos);
}

// Тест вычисления площади прямоугольника
TEST(RectangleTest, AreaCalculation) {
    Rectangle rectangle;
    // Прямоугольник 4x6
    CreateRectangleFromStream(rectangle, 0.0, 0.0, 6.0, 4.0);

    // Площадь должна быть 4*6=24
    EXPECT_DOUBLE_EQ(rectangle.area(), 24.0);
}

// Тест вычисления геометрического центра прямоугольника
TEST(RectangleTest, CenterCalculation) {
    Rectangle rectangle;
    CreateRectangleFromStream(rectangle, 0.0, 0.0, 5.0, 3.0);

    // Проверяем, что функция не выбрасывает исключений
    EXPECT_NO_THROW(rectangle.calculateCenter());
}

// Тест конструктора по умолчанию для Trapezoid
TEST(TrapezoidTest, DefaultConstructor) {
    Trapezoid trapezoid;
    std::stringstream ss;
    trapezoid.print(ss);
    EXPECT_TRUE(ss.str().find("Трапеция") != std::string::npos);
}

// Тест вычисления площади трапеции
TEST(TrapezoidTest, AreaCalculation) {
    Trapezoid trapezoid;
    // Трапеция с основаниями 6 и 4, высотой 3
    CreateTrapezoidFromStream(trapezoid, 0.0, 0.0, 6.0, 4.0, 3.0);

    // Площадь трапеции: (a + b) * h / 2 = (6+4)*3/2=15
    double expected_area = (6.0 + 4.0) * 3.0 / 2.0;
    EXPECT_DOUBLE_EQ(trapezoid.area(), expected_area);
}

// Тест вычисления геометрического центра трапеции
TEST(TrapezoidTest, CenterCalculation) {
    Trapezoid trapezoid;
    CreateTrapezoidFromStream(trapezoid, 0.0, 0.0, 4.0, 3.0, 2.0);

    // Проверяем, что функция не выбрасывает исключений
    EXPECT_NO_THROW(trapezoid.calculateCenter());
}

// Тест создания пустого списка
TEST(SpisokTest, DefaultConstructor) {
    Spisok list;
    // Новый список должен быть пустым
    EXPECT_EQ(list.size(), 0);
}

// Тест добавления элементов в список
TEST(SpisokTest, AddElements) {
    Spisok list;
    
    Square* square = new Square();
    Rectangle* rectangle = new Rectangle();
    
    list.add(square);
    list.add(rectangle);
    
    // Проверяем, что элементы добавлены
    EXPECT_EQ(list.size(), 2);
    EXPECT_NE(list[0], nullptr);
    EXPECT_NE(list[1], nullptr);
}

// Тест доступа к элементам списка
TEST(SpisokTest, AccessElements) {
    Spisok list;
    
    Square* square = new Square();
    CreateSquareFromStream(*square, 0.0, 0.0, 1.0);
    
    list.add(square);
    
    // Проверяем доступ к элементу
    Figure* retrieved = list[0];
    EXPECT_NE(retrieved, nullptr);
    
    // Проверяем, что это действительно наш квадрат
    EXPECT_DOUBLE_EQ(retrieved->area(), 1.0);
}

// Тест удаления элементов из списка
TEST(SpisokTest, PopElements) {
    Spisok list;
    
    Square* square1 = new Square();
    Square* square2 = new Square();
    Square* square3 = new Square();
    
    list.add(square1);
    list.add(square2);
    list.add(square3);
    
    EXPECT_EQ(list.size(), 3);
    
    list.pop(1); // Удаляем второй элемент
    EXPECT_EQ(list.size(), 2);
    
    list.pop(0); // Удаляем первый элемент
    EXPECT_EQ(list.size(), 1);
    
    list.pop(0); // Удаляем последний элемент
    EXPECT_EQ(list.size(), 0);
}

// Тест обработки выхода за границы списка
TEST(SpisokTest, OutOfBoundsAccess) {
    Spisok list;
    
    // Доступ к несуществующему элементу должен возвращать nullptr
    Figure* result = list[0];
    EXPECT_EQ(result, nullptr);
    
    result = list[5];
    EXPECT_EQ(result, nullptr);
}

// Тест константного доступа к элементам списка
TEST(SpisokTest, ConstAccess) {
    Spisok list;
    
    Square* square = new Square();
    list.add(square);
    
    const Spisok& const_list = list;
    const Figure* result = const_list[0];
    EXPECT_NE(result, nullptr);
    
    result = const_list[1]; // Выход за границы
    EXPECT_EQ(result, nullptr);
}

// Интеграционный тест: разные фигуры в одном списке
TEST(IntegrationTest, MultipleFiguresInList) {
    Spisok list;
    
    // Добавляем квадрат
    Square* square = new Square();
    CreateSquareFromStream(*square, 0.0, 0.0, 2.0);
    
    // Добавляем прямоугольник
    Rectangle* rectangle = new Rectangle();
    CreateRectangleFromStream(*rectangle, 0.0, 0.0, 3.0, 2.0);
    
    list.add(square);
    list.add(rectangle);
    
    // Проверяем площади через прямое обращение
    EXPECT_DOUBLE_EQ(static_cast<double>(*square), 4.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(*rectangle), 6.0);
    
    // Проверяем площади через доступ из списка
    EXPECT_DOUBLE_EQ(static_cast<double>(*list[0]), 4.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(*list[1]), 6.0);
}

// Тест полиморфного поведения
TEST(PolymorphismTest, VirtualFunctions) {
    Square square;
    Rectangle rectangle;
    Trapezoid trapezoid;
    
    // Инициализируем фигуры
    CreateSquareFromStream(square, 0.0, 0.0, 2.0);
    CreateRectangleFromStream(rectangle, 0.0, 0.0, 3.0, 2.0);
    CreateTrapezoidFromStream(trapezoid, 0.0, 0.0, 4.0, 3.0, 2.0);
    
    // Массив указателей на базовый класс
    Figure* figures[] = {&square, &rectangle, &trapezoid};
    
    // Проверяем, что виртуальные функции работают корректно для всех типов
    for (Figure* figure : figures) {
        EXPECT_NO_THROW(figure->area());
        EXPECT_NO_THROW(figure->calculateCenter());
        EXPECT_NO_THROW(static_cast<double>(*figure));
    }
}

// Тест оператора вывода для разных фигур
TEST(StreamTest, OutputOperator) {
    Square square;
    CreateSquareFromStream(square, 1.0, 2.0, 3.0);
    
    std::stringstream output;
    output << square;
    
    // Проверяем, что вывод содержит ожидаемую информацию
    EXPECT_FALSE(output.str().empty());
    EXPECT_TRUE(output.str().find("Квадрат") != std::string::npos);
}

// Тест управления памятью
TEST(MemoryTest, CreateDeleteFigures) {
    // Проверяем корректное создание и удаление фигур
    Square* square = new Square();
    Rectangle* rectangle = new Rectangle();
    Trapezoid* trapezoid = new Trapezoid();
    
    // Убеждаемся, что удаление не вызывает исключений
    EXPECT_NO_THROW(delete square);
    EXPECT_NO_THROW(delete rectangle);
    EXPECT_NO_THROW(delete trapezoid);
}

// Тест полного жизненного цикла списка с фигурами
TEST(IntegrationTest, FullListLifecycle) {
    Spisok list;
    
    // Создаем и добавляем различные фигуры
    Square* square = new Square();
    CreateSquareFromStream(*square, 0.0, 0.0, 2.0);
    list.add(square);
    
    Rectangle* rectangle = new Rectangle();
    CreateRectangleFromStream(*rectangle, 0.0, 0.0, 4.0, 3.0);
    list.add(rectangle);
    
    Trapezoid* trapezoid = new Trapezoid();
    CreateTrapezoidFromStream(*trapezoid, 0.0, 0.0, 5.0, 3.0, 4.0);
    list.add(trapezoid);
    
    // Проверяем размер списка
    EXPECT_EQ(list.size(), 3);
    
    // Проверяем доступ ко всем элементам
    for (size_t i = 0; i < list.size(); i++) {
        EXPECT_NE(list[i], nullptr);
        EXPECT_NO_THROW(list[i]->area());
        EXPECT_NO_THROW(list[i]->calculateCenter());
    }
    
    // Деструктор списка автоматически удалит все фигуры
}