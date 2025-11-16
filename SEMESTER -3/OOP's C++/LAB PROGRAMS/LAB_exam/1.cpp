#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool isSpecial(char c) {
    return !isalnum(c) && !isspace(c);
}

int main() {
    

    ifstream file("sanjai.txt");
    if (!file) {
        cout << "Unable to open file: "  << endl;
        return 1;
    }

    char character;
    int vowelCount = 0, specialCount = 0;
    
    while (file.get(character)) {
        if (isVowel(character)) {
            vowelCount++;
        }
        else if (isSpecial(character)) {
            specialCount++;
        }
    }

    file.close();

    cout << "Vowel count: " << vowelCount << endl;
    cout << "Special character count: " << specialCount << endl;

    return 0;
}
