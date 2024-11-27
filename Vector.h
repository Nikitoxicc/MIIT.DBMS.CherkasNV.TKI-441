#ifndef VECTOR_H // Препроцессорная директива: предотвращает многократное включение заголовочного файла
#define VECTOR_H

#include <iostream>  // Подключение стандартной библиотеки для потоков ввода/вывода
#include <stdexcept> // Для обработки исключений, например, std::out_of_range
#include <sstream>   // Для преобразования вектора в строку

// Шаблонный класс Vector
template <typename T> // Указание, что класс универсален и может работать с любым типом данных
class Vector {
private:
    T* data;          // Указатель на массив элементов
    size_t size;      // Текущее количество элементов в векторе
    size_t capacity;  // Вместимость вектора (максимальное количество элементов, без выделения новой памяти)

    // Метод для увеличения вместимости вектора
    void increaseCapacity();

public:
    // Конструктор по умолчанию
    Vector();

    // Деструктор для освобождения памяти
    ~Vector();

    // Методы CRUD
    void push_back(const T& value); // Добавление элемента
    T at(size_t index) const;       // Чтение элемента по индексу
    void update(size_t index, const T& value); // Обновление элемента
    void erase(size_t index);       // Удаление элемента

    // Утилиты
    size_t getSize() const;         // Получение размера вектора
    std::string toString() const;   // Преобразование вектора в строку

    // Перегрузка операторов
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Vector<U>& vec); // Вывод вектора
    template <typename U>
    friend std::istream& operator>>(std::istream& is, Vector<U>& vec); // Ввод вектора

    // Вложенный класс-итератор
    class Iterator {
    private:
        T* current; // Указатель на текущий элемент
    public:
        explicit Iterator(T* ptr);  // Конструктор итератора
        T& operator*() const;       // Разыменование
        Iterator& operator++();     // Переход к следующему элементу
        bool operator!=(const Iterator& other) const; // Сравнение итераторов
    };

    // Методы для итератора
    Iterator begin(); // Итератор на начало
    Iterator end();   // Итератор на конец
};

#include "vector_impl.h" // Включение файла с реализацией шаблонного класса

#endif // VECTOR_H