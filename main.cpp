#include "C:\Users\cherk\source\repos\Vector&Stack\Domain\Vector.cpp" // Подключение интерфейса для взаимодействия с вектором
#include <iostream> // Для стандартных потоков ввода/вывода

int main() {
    setlocale(LC_ALL, "Russian");
    // Запуск пользовательского интерфейса с использованием стандартных потоков
    runVectorInterface(std::cin, std::cout);

    return 0; // Завершение программы
}