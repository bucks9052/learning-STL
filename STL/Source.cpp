/*
Oliver Moore
CIS 1202
4/15/2024
*/
#include "personalLibv1.4.h"
char character(char start, int offset);
class invalidCharacterException : public std::runtime_error {
public:
    invalidCharacterException() : std::runtime_error("\nINVALID CHARACTER EXCEPTION") {};
};
class invalidRangeException : public std::runtime_error {
public:
    invalidRangeException() : std::runtime_error("\nINVALID RANGE EXCEPTION") {};
};
int main() {
    try {
        int offset = 0;
        char start = ' ';
     
        offset = validateInt("\nEnter how much you would like to offset: ");
        cout << "\nEnter a char: ";
        cin >> start;
        if (!isalpha(start)) {
            throw invalidCharacterException();
        }
        char result = character(start, offset);
        if (!isalpha(result)) {
            throw invalid_argument(" out of range...");
        }
        cout << "\nresult: " << result;
    }catch (invalidCharacterException& e) {
        cerr << "Invalid arguement: " << e.what();
    }
    catch (invalidRangeException& e) {
        cerr << "Invalid arguement: " << e.what();
    }
    endProgram();

}
char character(char start, int offset) {
    char result;
    if (start >= 'a' && start <= 'z') {
        result = 'a' + ((start - 'a' + offset) % 26);
    }
    else if (start >= 'A' && start <= 'Z') {
        result = 'A' + ((start - 'A' + offset) % 26);
    }
    else {

        result = start;
    }

    return result;

}