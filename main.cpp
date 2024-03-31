#include <windows.h>
#include "src/MarketDataProcessor.h"
#include <locale>

using namespace std;

int main() {
    // ������������� ����� � ������� � ������� UTF-8,
    // ��������� ������ ������� ��� �� �����  UTF-8
    // ��� ��� ���� ����� ���������� ��� ��� ������ � ���� �� �������
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // ������������� ���� ������ � �������
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color, 2);
    // ������� ������ ������
    MarketDataProcessor programProcess;
    // ��������� ������� ����� ������ ������
    programProcess.start();
    // ���������� ���������
    return 0;
}
