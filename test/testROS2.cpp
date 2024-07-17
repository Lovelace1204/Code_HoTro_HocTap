#include <iostream>
#include <string>

using namespace std;

const int rangeWidth = 50;  // Adjust the width as needed
const int littleWidth = 5;

string rangeOfSatisfy(int rate) {
    // Calculate the number of '#' characters
    int numHashes = rangeWidth * rate / 100;
    // Calculate the number of spaces
    int numSpaces = rangeWidth - numHashes;

    // Construct the result string
    string result = to_string(rate);
    result.append("%");
    result.append(littleWidth - result.length(), ' ');
    result.append("[");
    result.append(numHashes, '#');
    result.append(numSpaces, ' ');
    result.append("]");

    // Append the constructed string to data
    return result;
}

int main() {
    string data = "Initial";
    cout << rangeOfSatisfy(30) << endl;  // Example usage
    
    cout << rangeOfSatisfy(99) << endl;  // Example usage
    
    cout << rangeOfSatisfy(100) << endl;  // Example usage
    
    cout << rangeOfSatisfy(0) << endl;  // Example usage
    
    cout << rangeOfSatisfy(1) << endl;  // Example usage
    
    cout << rangeOfSatisfy(3) << endl;  // Example usage
    
    cout << rangeOfSatisfy(04) << endl;  // Example usage
    
    return 0;
}
