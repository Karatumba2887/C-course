#include <iostream>
#include <windows.h>
#include <cstdlib>
#include "src/MarketDataProcessor.h"

using namespace std;

void welcomemessage() {
    cout << "\n\n";
    cout << "\t########################################\n";
    cout << "\t########################################\n";
    cout << "\t########################################\n";
    cout << "\t##### development by MARIYA DRAPAK #####\n";
    cout << "\t########################################\n";
    cout << "\t########################################\n";
    cout << "\t########################################\n";
    cout << "\n\n";
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color, 2);

    welcomemessage();
    cout << "\t";
    system("pause");
    system("cls");
    MarketDataProcessor programProcess;

    MarketDataProcessor::drawInterface();
    programProcess.choiceStep();

//    system("pause");
    return 0;
}
