#include <iostream>
#include <regex>
#include <string>

int main() {
    // The pattern includes \s+ to allow for spaces and newlines between the words and times
    std::regex pattern(R"((\w+)\s+(\w+)\s+(\w+)\s+((\d{2}):(\d{2})))");
    std::string input = " \nThe time is 14:55\nThe time is 14:47\nThe time is 14:50\nThe time is 14:26";
    std::sregex_iterator it(input.begin(), input.end(), pattern);
    std::sregex_iterator end;

    // Iterate over all matches in the input string
    for (; it != end; ++it) {
        std::smatch match_result = *it;
        // Print the capturing groups for each match
        for (size_t i = 1; i < match_result.size(); ++i) {
            std::cout << "Group " << i << ": " << match_result[i] << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
