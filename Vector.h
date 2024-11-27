#ifndef VECTOR_H // ��������������� ���������: ������������� ������������ ��������� ������������� �����
#define VECTOR_H

#include <iostream>  // ����������� ����������� ���������� ��� ������� �����/������
#include <stdexcept> // ��� ��������� ����������, ��������, std::out_of_range
#include <sstream>   // ��� �������������� ������� � ������

// ��������� ����� Vector
template <typename T> // ��������, ��� ����� ����������� � ����� �������� � ����� ����� ������
class Vector {
private:
    T* data;          // ��������� �� ������ ���������
    size_t size;      // ������� ���������� ��������� � �������
    size_t capacity;  // ����������� ������� (������������ ���������� ���������, ��� ��������� ����� ������)

    // ����� ��� ���������� ����������� �������
    void increaseCapacity();

public:
    // ����������� �� ���������
    Vector();

    // ���������� ��� ������������ ������
    ~Vector();

    // ������ CRUD
    void push_back(const T& value); // ���������� ��������
    T at(size_t index) const;       // ������ �������� �� �������
    void update(size_t index, const T& value); // ���������� ��������
    void erase(size_t index);       // �������� ��������

    // �������
    size_t getSize() const;         // ��������� ������� �������
    std::string toString() const;   // �������������� ������� � ������

    // ���������� ����������
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Vector<U>& vec); // ����� �������
    template <typename U>
    friend std::istream& operator>>(std::istream& is, Vector<U>& vec); // ���� �������

    // ��������� �����-��������
    class Iterator {
    private:
        T* current; // ��������� �� ������� �������
    public:
        explicit Iterator(T* ptr);  // ����������� ���������
        T& operator*() const;       // �������������
        Iterator& operator++();     // ������� � ���������� ��������
        bool operator!=(const Iterator& other) const; // ��������� ����������
    };

    // ������ ��� ���������
    Iterator begin(); // �������� �� ������
    Iterator end();   // �������� �� �����
};

#include "vector_impl.h" // ��������� ����� � ����������� ���������� ������

#endif // VECTOR_H