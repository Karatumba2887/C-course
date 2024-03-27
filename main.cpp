#include <iostream>
#include <windows.h>
#include <cstdlib>
#include "src/MarketDataProcessor.h"

using namespace std;

//    system("chcp 65001");
//    setlocale(LC_ALL, "Ukrainian");

void welcomemessage()
{
    cout << "\n\n";
    cout << "\t\t########################################\n";
    cout << "\t\t########################################\n";
    cout << "\t\t########################################\n";
    cout << "\t\t##### development by MARIYA DRAPAK #####\n";
    cout << "\t\t########################################\n";
    cout << "\t\t########################################\n";
    cout << "\t\t########################################\n";
    cout << "\n\n";
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color, 13);

    welcomemessage();
    system("pause");
    system("cls");
    MarketDataProcessor programProcess;
    MarketDataProcessor::drawInterface();
    system("pause");
    return 0;
}
