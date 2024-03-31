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
        "�������� �������� � ����������� Max, Min �� ���������� ���������� �� ���� '������� �� ��'",
        "�������� ��������� ���������"
};

//int findLongestStringLengthInArray(const string strings[], int arrSize) {
//    int maxLength = 0;
//
//    for (int i = 0; i < arrSize; ++i) {
//        const wstring converted = convertStringToWstring(strings[i]);
//        size_t charLengthSizeT = converted.size();
//        int charLength = static_cast<int>(charLengthSizeT);
//
//        if (charLength > maxLength) {
//            maxLength = charLength;
//        }
//    }
//
//    return maxLength;
//}

const int arrSize = sizeof(options) / sizeof(options[0]);
//const int longestStrLength = findLongestStringLengthInArray(options, arrSize);

void MarketDataProcessor::drawInterface() {
    int iteration = 0;

    cout << "\n\n\t+" << setw(70 + 7) << setfill('-') << "|" << endl;

    for (const string &option: options) {
        ++iteration;

        if (iteration > 1) {
            cout << "\t|" << setw(70 + 6) << setfill('-') << "" << "|" << endl;
        }

        cout << "\t| " << iteration << "| " << option << endl;

        if (iteration == arrSize) {
            cout << "\t+" << setw(70 + 6) << setfill('-') << "" << "|" << endl;
        }
    }

    cout << "\n\t��� ���� ��� ������ ��, ������ ����� �� ���� ����������� �������� ��: \n" << endl;
}