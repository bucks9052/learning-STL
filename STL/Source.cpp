/*
Oliver Moore
CIS 1202
4/15/2024
*/
#include "personalLibv1.4.h"
char character(char start, int offset);
int main() {
    try {
        int offset = 0;
        char start = ' ';
     
        offset = validateInt("\nEnter how much you would like to offset: ");
        cout << "\nEnter a char: ";
        cin >> start;
        if (!isalpha(start)) {
            throw invalid_argument(" proper character not inputted...");
        }
        char result = character(start, offset);
        
        cout << "\nresult: " << result;
    }
    catch (invalid_argument& e) {
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