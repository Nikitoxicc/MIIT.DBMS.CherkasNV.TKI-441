#include "Vector.h" // Подключение заголовочного файла Vector
#include <sstream>  // Для работы с потоками строк

// Функция для обработки ошибок ввода
void handleInvalidInput(std::istream& input, std::ostream& output) {
    if (input.fail()) {
        input.clear(); // Сбрасываем флаг ошибки
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем оставшиеся данные в потоке
        output << "Ошибка: введено некорректное значение. Попробуйте снова.\n";
    }
}

// Функция взаимодействия с вектором через входной и выходной потоки
void runVectorInterface(std::istream& input, std::ostream& output) {
    Vector<int> vec; // Создаем объект вектора для работы с типом int
    bool exit = false; // Флаг завершения работы
    int choice; // Переменная для хранения выбора пользователя

    while (!exit) {
        // Вывод меню в выходной поток
        output << "\nМеню:\n";
        output << "1. Добавить элемент\n";
        output << "2. Показать элемент по индексу\n";
        output << "3. Обновить элемент\n";
        output << "4. Удалить элемент\n";
        output << "5. Показать весь вектор\n";
        output << "6. Завершить работу\n";
        output << "Введите ваш выбор: ";
        output.flush(); // Принудительная запись данных в поток

        input >> choice; // Считываем выбор пользователя из входного потока
        handleInvalidInput(input, output); // Проверка корректности ввода

        if (input.fail()) {
            continue; // Если ввод некорректный, пропускаем оставшуюся часть текущей итерации
        }

        switch (choice) {
        case 1: { // Добавление элемента
            int value;
            output << "Введите значение: ";
            output.flush();
            input >> value;
            handleInvalidInput(input, output); // Проверка корректности ввода

            if (input.fail()) {
                break;
            }

            vec.push_back(value); // Добавляем значение в вектор
            output << "Элемент добавлен.\n";
            break;
        }
        case 2: { // Чтение элемента
            size_t index;
            output << "Введите индекс: ";
            output.flush();
            input >> index;
            handleInvalidInput(input, output); // Проверка корректности ввода

            if (input.fail()) {
                break;
            }

            try {
                output << "Элемент: " << vec.at(index) << "\n"; // Выводим элемент
            }
            catch (const std::out_of_range& e) {
                output << "Ошибка: " << e.what() << "\n"; // Обработка выхода за границы
            }
            break;
        }
        case 3: { // Обновление элемента
            size_t index;
            int value;
            output << "Введите индекс: ";
            output.flush();
            input >> index;
            handleInvalidInput(input, output); // Проверка корректности ввода

            if (input.fail()) {
                break;
            }

            output << "Введите новое значение: ";
            output.flush();
            input >> value;
            handleInvalidInput(input, output); // Проверка корректности ввода

            if (input.fail()) {
                break;
            }

            try {
                vec.update(index, value); // Обновляем значение
                output << "Элемент обновлен.\n";
            }
            catch (const std::out_of_range& e) {
                output << "Ошибка: " << e.what() << "\n"; // Обработка выхода за границы
            }
            break;
        }
        case 4: { // Удаление элемента
            size_t index;
            output << "Введите индекс: ";
            output.flush();
            input >> index;
            handleInvalidInput(input, output); // Проверка корректности ввода

            if (input.fail()) {
                break;
            }
            try {
                vec.erase(index); // Удаляем элемент
                output << "Элемент удален.\n";
            }
            catch (const std::out_of_range& e) {
                output << "Ошибка: " << e.what() << "\n"; // Обработка выхода за границы
            }
            break;
        }
        case 5: { // Показ всего вектора
            output << "Текущий вектор: " << vec.toString() << "\n"; // Используем toString()
            break;
        }
        case 6: { // Завершение работы
            exit = true; // Устанавливаем флаг завершения работы
            break;
        }
        default: {
            output << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
        }
    }
}