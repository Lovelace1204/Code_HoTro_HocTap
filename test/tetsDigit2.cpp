#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

// Your isNumber function
int isNumber(string s) {
    int index = 0;
    int result = 0;
    while (s[index] != '\0' && s[index] != '\n' && s[index] != EOF) {
        if (!isdigit(s[index])) return -1;
        result = result * 10 + (s[index] - '0');
        index++;
    }
    return result;
}

// Function to generate random test cases with diverse characters
vector<string> generateTestCases(int count) {
    vector<string> testCases;
    srand(time(0));
    string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_+-=[]{}|;':\",.<>?/\\ ";
    for (int i = 0; i < count; ++i) {
        string s;
        int len = rand() % 10 + 1; // Random length between 1 and 10
        for (int j = 0; j < len; ++j) {
            s += chars[rand() % chars.size()];
        }
        testCases.push_back(s);
    }
    return testCases;
}

// Function to test isNumber with a set of strings and highlight results
void testIsNumber() {
    vector<string> testCases = generateTestCases(20000);

    for (const auto& s : testCases) {
        int result = isNumber(s);
        bool isValid = (result != -1);

        if (isValid) {
            cout << "\033[1;32m" << "The string \"" << s << "\" is a valid number: " << result << "\033[0m" << endl;
        } else {
            cout << "\033[1;31m" << "The string \"" << s << "\" is not a valid number." << "\033[0m" << endl;
        }
    }
}

int main() {
    testIsNumber();
    return 0;
}
