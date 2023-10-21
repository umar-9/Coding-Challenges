#include <iostream>
#include <string>

std::string cipher(std::string s, int k) {
    std::string output;
    for (int i = 0; i < s.size(); i++) {
        int ascii = int(s[i]);
        int new_val = ascii;

        if (ascii < 123 && ascii > 96) {
            new_val = ((int(s[i]) + k - 97) % 26 + 97);
        }
        else if (ascii < 91 && ascii > 64) {
            new_val = ((int(s[i]) + k - 65) % 26 + 65);
        }

        char new_char = int(new_val);
        output += new_char;
    }
    return output;
}


int main() {
    std::cout << cipher("middle-Outz", 2);
}

