#include <cmath>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>

int maxJoltage(const std::string &bank) {
    int firstDigit = 0;
    int firstDigitIndex = 0;

    for (int i = 0; i < bank.size() - 1; i++) {
        int digit = std::stoi(bank.substr(i, 1));
        if (digit > firstDigit) {
            firstDigit = digit;
            firstDigitIndex = i;
        }
    }

    int secondDigit = 0;
    for (int i = firstDigitIndex + 1; i < bank.size(); i++) {
        int digit = std::stoi(bank.substr(i, 1));
        if (digit > secondDigit) {
            secondDigit = digit;
        }
    }

    return (firstDigit * 10) + secondDigit;
}

uint64_t maxJoltageDynamicBatteryCount(const std::string &bank, const int batteryCount) {
    int startIndex = 0;

    uint64_t total = 0;

    for (int batteryIndex = batteryCount - 1; batteryIndex >= 0; batteryIndex--) {

        int largestDigit = 0;
        for (int i = startIndex; i < bank.size() - batteryIndex; i++) {
            int digit = std::stoi(bank.substr(i, 1));
            if (digit > largestDigit) {
                largestDigit = digit;
                startIndex = i;
            }
        }

        startIndex += 1;
        total += largestDigit * (std::pow(10, batteryIndex));
    }

    return total;
}

int main(int argc, char *argv[]) {
    std::ifstream f{"input.txt"};

    if (!f) {
        return -1;
    }

    uint64_t totaljoltage = 0;
    std::string bank;
    while (f >> bank) {
        // totaljoltage += maxJoltage(bank);
        totaljoltage += maxJoltageDynamicBatteryCount(bank, 12);
    }

    std::cout << "total joltage: " << totaljoltage << std::endl;

    return 0;
}
