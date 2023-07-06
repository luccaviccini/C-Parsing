# File Parser

This program is designed to parse specific text files and extract particular pieces of information. It processes lines that start with "IN F" or "PU" and outputs the extracted data to the console.

## Libraries Used

- `<iostream>`: For input-output streams, primarily used for console output.
- `<fstream>`: For file streams, used to read from files.
- `<string>`: For handling strings.
- `<vector>`: For using the vector data structure to store extracted data.
- `<sstream>`: For string streams, used for string manipulations.
- `<regex>`: For regular expressions, used for pattern matching within strings.

## Code Explanation

1. **Include necessary libraries**: The necessary C++ standard libraries are included for handling file I/O, strings, vectors, regular expressions, and streams.

2. **Open input file**: Input file streams are created and text files are opened for reading.

3. **Check if the file is open**: If the file cannot be opened, an error message is displayed on the console, and the program terminates.

4. **Read and parse file**: The files are read line by line. Depending on the line prefix "IN F" or "PU", different parsing methods are employed:

    a. For lines starting with "IN F", the number following "IN F" and the last 8 mappings from the line are extracted. The extracted mappings are stored in a one-dimensional vector. If any "IN F" entries are missing, empty strings are added to the corresponding positions in the vector.
    
    b. For lines starting with "PU", six elements from each line are extracted and stored in a one-dimensional vector. The extracted elements are either names followed by a pattern within parentheses or the string "GND".
    
5. **Close the file**: The input file streams are closed after reading.

6. **Output the results**: The contents of the vectors storing extracted data are printed to the console along with the respective prefixes ("IN F" or "PU").

## Usage

1. Place the text files you want to parse in an accessible directory.
2. Update the `baseDir` variable and `fileNames` vector in the main function to reflect the directory and names of your files.
3. Compile the program with a C++ compiler (e.g., `g++`).
4. Run the program.
