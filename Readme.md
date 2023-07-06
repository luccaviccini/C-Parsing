# File Parser 

This program parses a text file to extract the last 8 mappings corresponding to each line that starts with "IN F", and outputs the extracted data to the console. It expects the lines starting with "IN F" to be followed by a number from 1 to 48. If any "IN F" entries are missing, it fills the corresponding space with empty strings.

## Libraries Used

- `<iostream>`: For input-output stream. It is used to output the data to the console.
- `<fstream>`: For file stream. It is used to handle file input.
- `<string>`: For handling strings.
- `<vector>`: For using vector data structure to store the extracted mappings.
- `<sstream>`: For string stream, which is used to break down each line into individual elements.

## Code Explanation

1. **Include necessary libraries**: Necessary C++ standard libraries are included for handling file I/O, strings, vectors, and streams.

2. **Open input file**: An input file stream is created and a text file is opened.

3. **Check if the file is open**: If the file cannot be opened, an error message is printed to the console, and the program exits with a return code of 1.

4. **Create an array to store the elements**: A vector named `elementsArray` is created to store the mappings extracted from the file.

5. **Read and parse file**: The file is read line by line. For each line, it is checked if it starts with "IN F". If it does, the program proceeds to extract the number following "IN F" and the last 8 mappings from the line.

6. **Fill in missing entries**: If any "IN F" entries are missing, empty strings are added to the corresponding positions in the array.

7. **Store the extracted mappings**: The extracted mappings are stored in the `elementsArray`.

8. **Close the file**: The input file stream is closed after reading.

9. **Output the results**: The contents of the `elementsArray` are printed to the console along with the respective "IN F" number.

10. **Print the size of the array**: The size of the `elementsArray` is printed to confirm it has 384 elements (48*8).

## Usage

1. Place the text file you want to parse in an accessible directory.
2. Change the file path in the `ifstream file(...)` line of the code to the path of your file.
3. Compile the program with a C++ compiler (e.g., g++).
4. Run the program.


