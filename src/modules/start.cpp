#include "../MarketDataProcessor.h"
// ����� ������� ��������� �������� ���� ����� ����� ��������� (���� ����������� ��� ���������� �������� ����)
void MarketDataProcessor::start() { // NOLINT(*-convert-member-functions-to-static)
    // ������������� ���� ���������� ����� ���������
    bool programAlive = true;

    while (programAlive) {
        this->drawInterface();
        this->choiceStep(programAlive);
    }
    // ���������� ���������
};