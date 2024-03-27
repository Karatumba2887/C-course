#include <iostream>
#include <windows.h>
#include "src/MarketDataProcessor.h"
#include <cstdlib>

using namespace std;

int main() {
    system("chcp 65001");
    system("chcp");
    //SetConsoleOutputCP(CP_UTF8);
    //setlocale(LC_ALL, "Russian");

    //SetConsoleOutputCP(1251);
    //SetConsoleCP(1251);

    //cout << "Русский текст в консоли" << endl;
    //system("pause");
   // return 0;

cout << "Start!" << endl;
    MarketDataProcessor programProcess;
   programProcess.drawInterface();
    system("pause");
    return 0;
}
