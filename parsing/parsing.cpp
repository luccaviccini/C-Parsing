#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

vector<string> processFile(const string& fileUrl) {
    ifstream file(fileUrl);
    if (!file) {
        cerr << "Failed to open the file: " << fileUrl << endl;
        return vector<string>();
    }

    regex linePattern(R"(IN\s+F(\d+)\s+([\w\d]+)\s+([\w\d]+)\s+([\w\d]+)\s+([\w\d]+)\s+([\w\d]+)\s+([\w\d]+)\s+([\w\d]+)\s+([\w\d]+)\s+([\w\d]+)\s+([\w\d]+))");
    smatch matches;
    vector<string> elementsArray;
    string line;
    int expectedInNumber = 1;

    while (getline(file, line)) {
        if (regex_search(line, matches, linePattern)) {
            int currentInNumber = stoi(matches[1].str());

            while (currentInNumber > expectedInNumber) {
                for (int i = 0; i < 8; i++) {
                    elementsArray.push_back("");
                }
                expectedInNumber++;
            }

            for (size_t i = 4; i < matches.size(); i++) {
                elementsArray.push_back(matches[i].str());
            }

            expectedInNumber++;
        }
    }

    // Fill the remaining elements with empty strings if the file ended before IN F48
    while (expectedInNumber <= 48) {
        for (int i = 0; i < 8; i++) {
            elementsArray.push_back("");
        }
        expectedInNumber++;
    }

    file.close();
    return elementsArray;
}


int main() {
    const string baseDir = "../assets/"; // Change the directory accordingly

    // Processing IN data
    vector<string> fileNamesIn = {"EMBA_1"}; // Change the filename accordingly
    for (const string& fileName : fileNamesIn) {
        string fileUrl = baseDir + fileName + ".txt";
        vector<string> elementsArray = processFile(fileUrl);

        cout << "Processing file: " << fileName << ".txt" << endl;

        size_t inNumber = 1;
        for (size_t i = 0; i < elementsArray.size(); i++) {
            cout << "IN F" << inNumber << " Element: " << elementsArray[i] << endl;
            if ((i + 1) % 8 == 0) {
                inNumber++;
            }
        }

        cout << "Size of elementsArray: " << elementsArray.size() << endl << endl;
    }

    
    return 0;
}
