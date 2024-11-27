#ifndef VECTOR_IMPL_H // Препроцессорная директива для предотвращения дублирования
#define VECTOR_IMPL_H
#include "Vector.h"

// Реализация конструктора по умолчанию
template <typename T>
Vector<T>::Vector() : data(nullptr), size(0), capacity(0) {} // Инициализация указателя, размера и вместимости

// Реализация деструктора
template <typename T>
Vector<T>::~Vector() {
    delete[] data; // Освобождение памяти, выделенной для массива
}

// Реализация метода для увеличения вместимости
template <typename T>
void Vector<T>::increaseCapacity() {
    capacity = (capacity == 0) ? 1 : capacity * 2; // Увеличение вместимости в 2 раза (или установка на 1)
    T* newData = new T[capacity]; // Выделение новой памяти
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i]; // Копирование элементов
    }
    delete[] data; // Освобождение старой памяти
    data = newData; // Переназначение указателя
}

// Реализация метода добавления элемента
template <typename T>
void Vector<T>::push_back(const T& value) {
    if (size == capacity) {
        increaseCapacity(); // Увеличение вместимости, если необходимо
    }
    data[size++] = value; // Добавление элемента и увеличение размера
}

// Реализация метода получения элемента по индексу
template <typename T>
T Vector<T>::at(size_t index) const {
    if (index >= size) { // Проверка на выход за пределы массива
        throw std::out_of_range("Index out of range"); // Генерация исключения
    }
    return data[index]; // Возврат элемента
}

// Реализация метода обновления элемента
template <typename T>
void Vector<T>::update(size_t index, const T& value) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    data[index] = value; // Обновление элемента
}

// Реализация метода удаления элемента
template <typename T>
void Vector<T>::erase(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < size - 1; ++i) { // Сдвиг элементов
        data[i] = data[i + 1];
    }
    --size; // Уменьшение размера
}

// Реализация метода получения размера
template <typename T>
size_t Vector<T>::getSize() const {
    return size;
}

// Реализация метода преобразования вектора в строку
template <typename T>
std::string Vector<T>::toString() const {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < size; ++i) {
        oss << data[i];
        if (i < size - 1) {
            oss << ", ";
        }
    }
    oss << "]";
    return oss.str();
}

// Реализация перегрузки оператора вывода
template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
    os << vec.toString(); // Вывод строки, представленной toString()
    return os;
}

// Реализация перегрузки оператора ввода
template <typename T>
std::istream& operator>>(std::istream& is, Vector<T>& vec) {
    size_t newSize;
    is >> newSize; // Чтение нового размера
    vec.size = newSize;
    vec.capacity = newSize;
    delete[] vec.data; // Освобождение старой памяти
    vec.data = new T[newSize]; // Выделение новой памяти
    for (size_t i = 0; i < newSize; ++i) {
        is >> vec.data[i]; // Чтение элементов
    }
    return is;
}

// Реализация методов итератора
template <typename T>
Vector<T>::Iterator::Iterator(T* ptr) : current(ptr) {}

template <typename T>
T& Vector<T>::Iterator::operator*() const {
    return *current; // Разыменование текущего указателя
}

template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator++() {
    ++current; // Переход к следующему элементу
    return *this;
}

template <typename T>
bool Vector<T>::Iterator::operator!=(const Iterator& other) const {
    return current != other.current; // Сравнение указателей
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::begin() {
    return Iterator(data); // Итератор на начало массива
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::end() {
    return Iterator(data + size); // Итератор на конец массива
}

#endif // VECTOR_IMPL_H