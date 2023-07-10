#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

vector<string> processFile(const string &fileUrl)
{
    ifstream file(fileUrl);
    if (!file)
    {
        cerr << "Failed to open the file: " << fileUrl << endl;
        return vector<string>();
    }

    regex linePattern(R"(IN\s+F(\d+)\s+([\w\d]+)\s+([\w\d]+)\s+([\w\d]+)\s+([\w\d]+)\s+([\w\d]+)\s+([\w\d]+)\s+([\w\d]+)\s+([\w\d]+)\s+([\w\d]+)\s+([\w\d]+))");
    smatch matches;
    vector<string> elementsArray;
    string line;
    int expectedInNumber = 1;

    while (getline(file, line))
    {
        if (regex_search(line, matches, linePattern))
        {
            int currentInNumber = stoi(matches[1].str());

            while (currentInNumber > expectedInNumber)
            {
                for (int i = 0; i < 8; i++)
                {
                    elementsArray.push_back("");
                }
                expectedInNumber++;
            }

            for (size_t i = 4; i < matches.size(); i++)
            {
                elementsArray.push_back(matches[i].str());
            }

            expectedInNumber++;
        }
    }

    // Fill the remaining elements with empty strings if the file ended before IN F48
    while (expectedInNumber <= 48)
    {
        for (int i = 0; i < 8; i++)
        {
            elementsArray.push_back("");
        }
        expectedInNumber++;
    }

    file.close();
    return elementsArray;
}

void printProcessFile()
{
    const string baseDir = "../assets/"; // Change the directory accordingly
    vector<string> fileNamesForProcessFile = {
        "EMBA_1" // Add the file names you want to process with the processFile function
    };

    for (const string& fileName : fileNamesForProcessFile) {
        string fileUrl = baseDir + fileName + ".txt";
        vector<string> elementsArray = processFile(fileUrl);

        cout << "Processing file with processFile: " << fileName << ".txt" << endl;

        size_t inNumber = 1;
        for (size_t i = 0; i < elementsArray.size(); i++) {
            cout << "IN F" << inNumber << " Element: " << elementsArray[i] << endl;
            if ((i + 1) % 8 == 0) {
                inNumber++;
            }
        }

        cout << "Size of elementsArray: " << elementsArray.size() << endl << endl;
    }
}

vector<string> process_pu_list_latome(const string &fileUrl)
{
    ifstream file(fileUrl);

    if (!file)
    {
        cerr << "Failed to open the file: " << fileUrl << endl;
        return vector<string>();
    }

    regex linePattern(R"(PU(\d+)\s+([\w_]+|GND)(?:\s+\(.*?\))?\s+([\w_]+|GND)(?:\s+\(.*?\))?\s+([\w_]+|GND)(?:\s+\(.*?\))?\s+([\w_]+|GND)(?:\s+\(.*?\))?\s+([\w_]+|GND)(?:\s+\(.*?\))?\s+([\w_]+|GND)(?:\s+\(.*?\))?)");
    smatch matches;
    vector<string> elementsArray;
    string line;
    int expectedPuNumber = 1;

    while (getline(file, line))
    {
        if (regex_search(line, matches, linePattern))
        {
            int currentPuNumber = stoi(matches[1].str());

            while (currentPuNumber > expectedPuNumber)
            {
                for (int i = 0; i < 6; i++)
                {
                    elementsArray.push_back("");
                }
                expectedPuNumber++;
            }

            for (size_t i = 2; i < matches.size(); i++)
            {
                elementsArray.push_back(matches[i].str());
            }

            expectedPuNumber++;
        }
    }

    // Fill the remaining elements with empty strings if the file ended before PU62
    while (expectedPuNumber <= 62)
    {
        for (int i = 0; i < 6; i++)
        {
            elementsArray.push_back("");
        }
        expectedPuNumber++;
    }

    file.close();

    return elementsArray;
}

void printProcessPuListLatome()
{
    const string baseDir = "../assets/"; // Change the directory accordingly
    vector<string> fileNamesForProcessPuListLatome = {
        "pu_list_latome" // Add the file names you want to process with the processPuListLatome function
    };
    
    for (const string& fileName : fileNamesForProcessPuListLatome) {
        string fileUrl = baseDir + fileName + ".txt";
        vector<string> elementsArray = process_pu_list_latome(fileUrl);

        cout << "Processing file with processPuListLatome: " << fileName << ".txt" << endl;

        size_t puNumber = 1;
        for (size_t i = 0; i < elementsArray.size(); i++) {
            cout << "PU" << puNumber << " Element: " << elementsArray[i] << endl;
            if ((i + 1) % 6 == 0) {
                puNumber++;
            }
        }

        cout << "Size of elementsArray: " << elementsArray.size() << endl << endl;
    }
}

vector<string> process_osum_map_full(const string &fileUrl)
{
    ifstream file(fileUrl);

    if (!file)
    {
        cerr << "Failed to open the file: " << fileUrl << endl;
        return vector<string>();
    }

    regex linePattern(R"(^F(\d+)\s+(\w+)(?:\s+\d+:)?([\w\+\*]+)?(?:\s+\d+:)?([\w\+\*]+)?(?:\s+\d+:)?([\w\+\*]+)?(?:\s+\d+:)?([\w\+\*]+)?(?:\s+\d+:)?([\w\+\*]+)?(?:\s+\d+:)?([\w\+\*]+)?(?:\s+\d+:)?([\w\+\*]+)?(?:\s+\d+:)?([\w\+\*]+)?(?:\s+\d+:)?([\w\+\*]+)?(?:\s+\d+:)?([\w\+\*]+)?(?:\s+\d+:)?([\w\+\*]+)?(?:\s+\d+:)?([\w\+\*]+)?(?:\s+\d+:)?([\w\+\*]+)?(?:\s+\d+:)?([\w\+\*]+)?(?:\s+\d+:)?([\w\+\*]+)?(?:\s+\d+:)?([\w\+\*]+)?(?:\s+\d+:)?([\w\+\*]+)?(?:\s+\d+:)?([\w\+\*]+)?(?:\s+\d+:)?([\w\+\*]+)?(?:\s+\d+:)?([\w\+\*]+)?)");
    smatch matches;
    vector<string> elementsArray;
    string line;

    int expectedInNumber = 1;
    while (getline(file, line))
    {
        if (regex_search(line, matches, linePattern))
        {
            int currentFNumber = stoi(matches[1].str());

            // Handle missing Fs
            while (expectedInNumber < currentFNumber)
            {
                for (int i = 0; i < 20; i++)
                {
                    elementsArray.push_back("");
                }
                expectedInNumber++;
            }

            // Handle "GND"
            if (matches[2] == "GND")
            {
                for (int i = 0; i < 20; i++)
                {
                    elementsArray.push_back("");
                }
                expectedInNumber++;
            }
            // Handle other matches
            else
            {
                for (size_t i = 3; i < matches.size(); i++)
                {
                    elementsArray.push_back(matches[i].str());
                }

                // Handle missing elements for the current F
                while (elementsArray.size() % 20 != 0)
                {
                    elementsArray.push_back("");
                }

                expectedInNumber++;
            }
        }
    }

    // Handle missing Fs after the last line
    while (expectedInNumber <= 48)
    {
        for (int i = 0; i < 20; i++)
        {
            elementsArray.push_back("");
        }
        expectedInNumber++;
    }

    file.close();

    return elementsArray;
}
void printProcessOsumMapFull()
{
    const string baseDir = "../assets/"; // Change the directory accordingly
    vector<string> fileNamesForProcessOsumMappingFull = {
        "osum_map_full" // Add the file names you want to process with the processOsumMappingFull function
    };

    for (const string& fileName : fileNamesForProcessOsumMappingFull) {
        string fileUrl = baseDir + fileName + ".txt";
        vector<string> elementsArray = process_osum_map_full(fileUrl);

        cout << "Processing file with processOsumMappingFull: " << fileName << ".txt" << endl;

        size_t fNumber = 1;
        for (size_t i = 0; i < elementsArray.size(); i++) {
            cout << "F" << fNumber << " Element: " << elementsArray[i] << endl;
            if ((i + 1) % 20 == 0) {
                fNumber++;
            }
        }

        cout << "Size of elementsArray: " << elementsArray.size() << endl << endl;
    }
}


int main()
{   
    // COMENT AND UNCOMMENT FOR BETTER READABILITY
    //printProcessFile();
    //printProcessPuListLatome();
    printProcessOsumMapFull();
    
    return 0;
}
