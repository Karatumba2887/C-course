#include <iostream>
#include <iomanip>
#include "../helpers/helpers.cpp"
#include "../MarketDataProcessor.h"

using namespace std;

string options[] = {
        "������� ���������� � ���������� �����",
        "������ ����� ������� � ����� ������",
        "����������� �� �������� ������",
        "�������� ���������� � ��������� ����",
        "��������� ������ �� ����� (�������� ����������), �� ����� �������� (��������������� ��������)",
        "������ ����� ������� ����� �������",
        "������ ����� ������� ���� ��������",
        "����� �������� ��������",
        "�������� �������, ��������� �� ��������",
        "�������� �������� � ����������� Max, Min �� ���������� ���������� �� ���� '����'",
        "�������� ��������� ���������"
};

const int arrSize = sizeof(options) / sizeof(options[0]);

void MarketDataProcessor::drawInterface() {
    int iteration = 0;

    cout << "\n\n\t+" << setw(90 + 7) << setfill('-') << "|" << endl;

    for (const string &option: options) {
        ++iteration;

        if (iteration > 1) {
            cout << "\t|" << setw(90 + 6) << setfill('-') << "" << "|" << endl;
        }

        cout << "\t| " << iteration << "| " << option << endl;

        if (iteration == arrSize) {
            cout << "\t+" << setw(90 + 6) << setfill('-') << "" << "|" << endl;
        }
    }

    cout << "\n\t��� ���� ��� ������ ��, ������ ����� �� ���� ����������� �������� ��: \n" << endl;
}