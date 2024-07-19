#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <windows.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// color text handle 
// SetConsoleTextAttribute(hConsole, 12) <key>

const int rangeWidth = 50;  // Adjust the width as needed

//string rangeOfSatisfy ( int rate, string& data ) {
//	float calrate = rate;
//	string result = data;
//	int rangeCount = rangeWidth - rangeWidth/100*rate - 1;
//	result.append(rangeCount, ' ');
//	return result;
//}



//string FillDotAfter (const string& label) {
//    string result = label;
//    int DotCount = LABEL_WIDTH - label.length() - 1; // Subtract 1 for the colon
//    result.append(DotCount, '.');
////    result.append(": ");
//    return result;
//}

int main () {
	string data = "30";
	int rate = 30;
	cout << rangeOfSatisfy(rate, data);
}