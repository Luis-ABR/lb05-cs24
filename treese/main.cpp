#include "Treese.h"
#include <iostream>

std::string to_string(const Treese& t) {
    std::string s;
    for (size_t i=0;i<t.length();++i) s.push_back(t.at(i));
    return s;
}

int main() {
    Treese first("Hello, ");
    Treese second("World");
    Treese third("! again goodbye");

    Treese combined = first.concat(second);
    Treese combinedmore = combined.concat(third);

    std::cout << to_string(combinedmore) << "\n";
    std::cout << "char7=" << combinedmore.at(7) << " char15=" << combinedmore.at(15) << "\n";
}
