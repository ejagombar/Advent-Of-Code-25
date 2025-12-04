#include <cstdint>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>

bool containsAnyRepeatedPattern(const std::string &in) {
    int maxPatternSize = in.size() - 1;

    for (int patternSize = 1; patternSize <= maxPatternSize; patternSize++) {
        std::string pattern = in.substr(0, patternSize);

        bool foundPattern = true;
        for (int i = patternSize; i < in.size(); i += patternSize) {
            std::string searchArea = in.substr(i, patternSize);

            if (pattern != searchArea) {
                foundPattern = false;
            }
        }

        if (foundPattern) {
            return true;
        }
    }

    return false;
}

bool containsRepeatedPattern(const std::string &in) {
    int n = in.size();
    if (n % 2 != 0)
        return false;

    int half = n / 2;
    return in.substr(0, half) == in.substr(half);
}

uint64_t invalidIDsTotal(const std::string filename, std::function<bool(const std::string &)> func) {
    uint64_t total{0};

    std::ifstream f{filename};

    if (!f) {
        return 0;
    }

    std::string rangeStr{};
    while (std::getline(f, rangeStr, ',')) {
        auto x = rangeStr.find("-");

        uint64_t lower = std::stoull(rangeStr.substr(0, x));
        uint64_t upper = std::stoull(rangeStr.substr(x + 1));

        for (uint64_t i = lower; i <= upper; i++) {
            if (func(std::to_string(i))) {
                total += i;
            }
        }
    }

    return total;
}

int main(int argc, char *argv[]) {
    auto out = invalidIDsTotal("input.txt", containsRepeatedPattern);
    std::cout << "Total invalid ids (part 1): " << out << std::endl;

    out = invalidIDsTotal("input.txt", containsAnyRepeatedPattern);
    std::cout << "Total invalid ids (part 2): " << out << std::endl;

    return 0;
}
