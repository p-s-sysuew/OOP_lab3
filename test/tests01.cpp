#include <gtest/gtest.h>
#include "../include/figure.h"
#include "../include/square.h"
#include "../include/rectangle.h"
#include "../include/trapezoid.h"
#include "../include/spisok.h"
#include <sstream>
#include <iostream>
#include <cmath>

// Тесты для класса Figure
TEST(FigureTest, DefaultConstructor) {
    Figure figure;
    // Проверяем через публичные методы или поведение
    std::stringstream ss;
    figure.print(ss);
    EXPECT_EQ(ss.str(), "Фигура не имеет точек");
}

TEST(FigureTest, ParameterizedConstructor) {
    Figure figure(3);
    // Проверяем, что можно работать с фигурой
    std::stringstream ss;
    figure.print(ss);
    EXPECT_FALSE(ss.str().empty());
}

TEST(FigureTest, CopyAssignment) {
    Figure figure1(2);
    std::stringstream input1("1.0 2.0 3.0 4.0");
    input1 >> figure1;

    Figure figure2;
    figure2 = figure1;

    std::stringstream ss1, ss2;
    figure1.print(ss1);
    figure2.print(ss2);
    EXPECT_EQ(ss1.str(), ss2.str());
}

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

    EXPECT_TRUE(figure1 == figure2);
    EXPECT_FALSE(figure1 == figure3);
}

TEST(FigureTest, PrintEmptyFigure) {
    Figure figure;
    std::stringstream ss;
    figure.print(ss);
    EXPECT_EQ(ss.str(), "Фигура не имеет точек");
}

TEST(FigureTest, PrintWithPoints) {
    Figure figure(2);
    std::stringstream input("1.5 3.5 2.5 4.5");
    input >> figure;

    std::stringstream ss;
    figure.print(ss);
    std::string result = ss.str();
    EXPECT_TRUE(result.find("1.5") != std::string::npos);
    EXPECT_TRUE(result.find("3.5") != std::string::npos);
    EXPECT_TRUE(result.find("2.5") != std::string::npos);
    EXPECT_TRUE(result.find("4.5") != std::string::npos);
}

// Тесты для класса Square
TEST(SquareTest, DefaultConstructor) {
    Square square;
    // Проверяем, что квадрат создан
    std::stringstream ss;
    square.print(ss);
    EXPECT_TRUE(ss.str().find("Квадрат") != std::string::npos);
}

TEST(SquareTest, AreaCalculation) {
    Square square;
    // Создаем квадрат со стороной 5 через ввод
    std::stringstream input("0.0 0.0 5.0");
    input >> square;
    
    EXPECT_DOUBLE_EQ(square.area(), 25.0);
}

TEST(SquareTest, DoubleConversion) {
    Square square;
    std::stringstream input("0.0 0.0 3.0");
    input >> square;

    double area = static_cast<double>(square);
    EXPECT_DOUBLE_EQ(area, 9.0);
}

TEST(SquareTest, Print) {
    Square square;
    std::stringstream ss;
    square.print(ss);
    std::string result = ss.str();
    EXPECT_TRUE(result.find("Квадрат") != std::string::npos);
}

// Тесты для класса Rectangle
TEST(RectangleTest, DefaultConstructor) {
    Rectangle rectangle;
    std::stringstream ss;
    rectangle.print(ss);
    EXPECT_TRUE(ss.str().find("Прямоугольник") != std::string::npos);
}

TEST(RectangleTest, AreaCalculation) {
    Rectangle rectangle;
    // Прямоугольник 4x6
    std::stringstream input("0.0 0.0 6.0 4.0");
    input >> rectangle;

    EXPECT_DOUBLE_EQ(rectangle.area(), 24.0);
}

TEST(RectangleTest, DoubleConversion) {
    Rectangle rectangle;
    std::stringstream input("0.0 0.0 5.0 3.0");
    input >> rectangle;

    double area = static_cast<double>(rectangle);
    EXPECT_DOUBLE_EQ(area, 15.0);
}

// Тесты для класса Trapezoid
TEST(TrapezoidTest, DefaultConstructor) {
    Trapezoid trapezoid;
    std::stringstream ss;
    trapezoid.print(ss);
    EXPECT_TRUE(ss.str().find("Трапеция") != std::string::npos);
}

TEST(TrapezoidTest, AreaCalculation) {
    Trapezoid trapezoid;
    // Трапеция с основаниями 6 и 4, высотой 3
    std::stringstream input("0.0 0.0 6.0 4.0 3.0");
    input >> trapezoid;

    double expected_area = (6.0 + 4.0) * 3.0 / 2.0;
    EXPECT_DOUBLE_EQ(trapezoid.area(), expected_area);
}

TEST(TrapezoidTest, CenterCalculation) {
    Trapezoid trapezoid;
    std::stringstream input("0.0 0.0 4.0 3.0 2.0");
    input >> trapezoid;

    // Проверяем, что функция не падает
    EXPECT_NO_THROW(trapezoid.calculateCenter());
}

// Тесты для класса Spisok
TEST(SpisokTest, DefaultConstructor) {
    Spisok list;
    EXPECT_EQ(list.size(), 0);
}

TEST(SpisokTest, AddElements) {
    Spisok list;
    
    Square* square = new Square();
    Rectangle* rectangle = new Rectangle();
    
    list.add(square);
    list.add(rectangle);
    
    EXPECT_EQ(list.size(), 2);
    EXPECT_NE(list[0], nullptr);
    EXPECT_NE(list[1], nullptr);
}

TEST(SpisokTest, AccessElements) {
    Spisok list;
    
    Square* square = new Square();
    std::stringstream input("1.0 1.0 1.0");
    input >> *square;
    
    list.add(square);
    
    Figure* retrieved = list[0];
    EXPECT_NE(retrieved, nullptr);
    
    // Проверяем через вычисление площади
    EXPECT_DOUBLE_EQ(retrieved->area(), 1.0);
}

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

TEST(SpisokTest, OutOfBoundsAccess) {
    Spisok list;
    
    // Доступ к несуществующему элементу
    Figure* result = list[0];
    EXPECT_EQ(result, nullptr);
    
    result = list[5];
    EXPECT_EQ(result, nullptr);
}

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

// Интеграционные тесты
TEST(IntegrationTest, MultipleFiguresInList) {
    Spisok list;
    
    // Добавляем разные фигуры
    Square* square = new Square();
    std::stringstream input1("0.0 0.0 2.0");
    input1 >> *square;
    
    Rectangle* rectangle = new Rectangle();
    std::stringstream input2("0.0 0.0 3.0 2.0");
    input2 >> *rectangle;
    
    list.add(square);
    list.add(rectangle);
    
    // Проверяем площади
    EXPECT_DOUBLE_EQ(static_cast<double>(*square), 4.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(*rectangle), 6.0);
    
    // Проверяем доступ через список
    EXPECT_DOUBLE_EQ(static_cast<double>(*list[0]), 4.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(*list[1]), 6.0);
}

TEST(IntegrationTest, StreamOperators) {
    // Тестирование операторов ввода/вывода
    Square square;
    std::stringstream output;
    
    // Тестируем, что операторы не падают
    EXPECT_NO_THROW(square.print(output));
    EXPECT_FALSE(output.str().empty());
}

// Тест на полиморфизм
TEST(PolymorphismTest, VirtualFunctions) {
    Square square;
    Rectangle rectangle;
    Trapezoid trapezoid;
    
    Figure* figures[] = {&square, &rectangle, &trapezoid};
    
    // Устанавливаем точки через ввод
    std::stringstream input1("0.0 0.0 2.0");
    input1 >> square;
    
    std::stringstream input2("0.0 0.0 3.0 2.0");
    input2 >> rectangle;
    
    std::stringstream input3("0.0 0.0 4.0 3.0 2.0");
    input3 >> trapezoid;
    
    // Проверяем, что виртуальные функции работают корректно
    for (Figure* figure : figures) {
        EXPECT_NO_THROW(figure->area());
        EXPECT_NO_THROW(figure->calculateCenter());
        EXPECT_NO_THROW(static_cast<double>(*figure));
    }
}

// Тест оператора вывода
TEST(StreamTest, OutputOperator) {
    Square square;
    std::stringstream input("1.0 2.0 3.0");
    input >> square;
    
    std::stringstream output;
    output << square;
    
    EXPECT_FALSE(output.str().empty());
    EXPECT_TRUE(output.str().find("Квадрат") != std::string::npos);
}

// Тест на создание и удаление фигур
TEST(MemoryTest, CreateDeleteFigures) {
    // Проверяем, что нет утечек памяти
    Square* square = new Square();
    Rectangle* rectangle = new Rectangle();
    Trapezoid* trapezoid = new Trapezoid();
    
    EXPECT_NO_THROW(delete square);
    EXPECT_NO_THROW(delete rectangle);
    EXPECT_NO_THROW(delete trapezoid);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}