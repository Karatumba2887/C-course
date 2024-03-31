#include <windows.h>
#include "src/MarketDataProcessor.h"
#include <locale>

using namespace std;

int main() {
    // Устанавливаем вывод в консоль в формате UTF-8,
    // кодировка файлов проекта так же стоит  UTF-8
    // так что весь текст написанный тут для вывода в жтом же формате
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // Устанавливаем цвет текста в консоли
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color, 2);
    // Создаем обьект класса
    MarketDataProcessor programProcess;
    // Запускаем главный метод нашего класса
    programProcess.start();
    // Завершение программы
    return 0;
}
