#include <fstream>
#include <iostream>
#include <string>

int getDialZeroPositionCount(std::string filename) {
    std::ifstream f{filename};

    if (!f) {
        return -1;
    }

    int position{50};
    int zeroCount{0};

    std::string s;
    while (f >> s) {
        int direction = s.at(0) == 'L' ? -1 : 1;
        int magnitude = std::stoi(s.substr(1));

        position += (magnitude * direction) % 100;

        if (position > 99) {
            position -= 100;
        } else if (position < 0) {
            position += 100;
        }

        if (position == 0) {
            zeroCount++;
        }
    }

    return zeroCount;
}

int getDialZeroClickCount(std::string filename) {
    std::ifstream f{filename};

    if (!f) {
        return -1;
    }

    int position{50};
    int zeroCount{0};

    std::string s;
    while (f >> s) {
        int direction = s.at(0) == 'L' ? -1 : 1;
        int magnitude = std::stoi(s.substr(1));

        for (int i = 0; i < magnitude; i++) {
            position += direction;

            if (position > 99) {
                position -= 100;
            } else if (position < 0) {
                position += 100;
            }

            if (position == 0) {
                zeroCount++;
            }
        }
    }

    return zeroCount;
}

int main(int argc, char *argv[]) {
    auto result = getDialZeroPositionCount("input.txt");
    auto result2 = getDialZeroClickCount("input.txt");

    std::cout << "Zero Count: " << result << std::endl;
    std::cout << "Zero Click Count: " << result2 << std::endl;

    return 0;
}
