#ifndef VECTOR_IMPL_H // ��������������� ��������� ��� �������������� ������������
#define VECTOR_IMPL_H
#include "Vector.h"

// ���������� ������������ �� ���������
template <typename T>
Vector<T>::Vector() : data(nullptr), size(0), capacity(0) {} // ������������� ���������, ������� � �����������

// ���������� �����������
template <typename T>
Vector<T>::~Vector() {
    delete[] data; // ������������ ������, ���������� ��� �������
}

// ���������� ������ ��� ���������� �����������
template <typename T>
void Vector<T>::increaseCapacity() {
    capacity = (capacity == 0) ? 1 : capacity * 2; // ���������� ����������� � 2 ���� (��� ��������� �� 1)
    T* newData = new T[capacity]; // ��������� ����� ������
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i]; // ����������� ���������
    }
    delete[] data; // ������������ ������ ������
    data = newData; // �������������� ���������
}

// ���������� ������ ���������� ��������
template <typename T>
void Vector<T>::push_back(const T& value) {
    if (size == capacity) {
        increaseCapacity(); // ���������� �����������, ���� ����������
    }
    data[size++] = value; // ���������� �������� � ���������� �������
}

// ���������� ������ ��������� �������� �� �������
template <typename T>
T Vector<T>::at(size_t index) const {
    if (index >= size) { // �������� �� ����� �� ������� �������
        throw std::out_of_range("Index out of range"); // ��������� ����������
    }
    return data[index]; // ������� ��������
}

// ���������� ������ ���������� ��������
template <typename T>
void Vector<T>::update(size_t index, const T& value) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    data[index] = value; // ���������� ��������
}

// ���������� ������ �������� ��������
template <typename T>
void Vector<T>::erase(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < size - 1; ++i) { // ����� ���������
        data[i] = data[i + 1];
    }
    --size; // ���������� �������
}

// ���������� ������ ��������� �������
template <typename T>
size_t Vector<T>::getSize() const {
    return size;
}

// ���������� ������ �������������� ������� � ������
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

// ���������� ���������� ��������� ������
template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
    os << vec.toString(); // ����� ������, �������������� toString()
    return os;
}

// ���������� ���������� ��������� �����
template <typename T>
std::istream& operator>>(std::istream& is, Vector<T>& vec) {
    size_t newSize;
    is >> newSize; // ������ ������ �������
    vec.size = newSize;
    vec.capacity = newSize;
    delete[] vec.data; // ������������ ������ ������
    vec.data = new T[newSize]; // ��������� ����� ������
    for (size_t i = 0; i < newSize; ++i) {
        is >> vec.data[i]; // ������ ���������
    }
    return is;
}

// ���������� ������� ���������
template <typename T>
Vector<T>::Iterator::Iterator(T* ptr) : current(ptr) {}

template <typename T>
T& Vector<T>::Iterator::operator*() const {
    return *current; // ������������� �������� ���������
}

template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator++() {
    ++current; // ������� � ���������� ��������
    return *this;
}

template <typename T>
bool Vector<T>::Iterator::operator!=(const Iterator& other) const {
    return current != other.current; // ��������� ����������
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::begin() {
    return Iterator(data); // �������� �� ������ �������
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::end() {
    return Iterator(data + size); // �������� �� ����� �������
}

#endif // VECTOR_IMPL_H