#include "../MarketDataProcessor.h"
// Метод который запускает основной цикл жизни нашей программы (ниже комментарий для отключения проверки кода)
void MarketDataProcessor::start() { // NOLINT(*-convert-member-functions-to-static)
    // Устанавливаем нашу переменную жизни программы
    bool programAlive = true;

    while (programAlive) {
        this->drawInterface();
        this->choiceStep(programAlive);
    }
    // Завершение программы
};