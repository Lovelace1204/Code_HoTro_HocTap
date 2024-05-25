#include <iostream>
#include <string>
#include <vector> // Include vector header
#include <windows.h>

#define version "1.2.0"
#define CurrentYear 2024
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void PrintInvalidDateInputError(const std::string& date) {
    std::cout << "Invalid date input: " << date << std::endl;
}

bool IsLeapYear(int year) {
    if (year % 4 != 0) return false;
    if (year % 100 != 0) return true;
    if (year % 400 != 0) return false;
    return true;
}

// DD/MM/YYYY
int ValidDateInput (string date) {
	        SetConsoleTextAttribute(hConsole, 10);
			int index = 0;
			int IntDate[3] = {0};
			int TempIndex = index;
			for ( int i = 0; i < 3; i++) {
				
				while ( date[TempIndex] != '\0' && date[TempIndex] != '/' && date[TempIndex] != '-') {
					
					if ( date[TempIndex] < '0' || date[TempIndex] > '9' ) return 0;
					
					IntDate[i] = IntDate[i]*10 + (date[TempIndex]-48);
					TempIndex++;
				}
				
				if ( i == 2 && date[TempIndex] != '\0') return 0;
				if ( IntDate[i] == 0) return 0;
				TempIndex++;
			}
				
			if (IntDate[0] < 0 || IntDate[0] > 31) {
				cout << "Day " << IntDate[0] << " exist ? bro u serious?:)" << endl;
				SetConsoleTextAttribute(hConsole, 7);
				return 0;
			}
			if (IntDate[1] < 0 || IntDate[1] > 12) {
				cout << "Month " << IntDate[1] << " exist ? bro u serious?:)" << endl;
				SetConsoleTextAttribute(hConsole, 7);
				return 0;
			}
//			if (IntDate[2] != CurrentYear) {
//   			 	cout << "U living in " << IntDate[2] << "  ? bro u serious =))? <This last updated verion is in " << CurrentYear << ">" << "- Ver : " << version << endl;
//   			 	SetConsoleTextAttribute(hConsole, 7);
//   			 	return 0;
//			} 

		
		// Handle valid value but in special case
		if ( (IntDate[1] == 4 || IntDate[1] == 6 || IntDate[1] == 9 || IntDate[1] == 11) && IntDate[0] > 30) {
			cout << "The " << IntDate[1] << " month does'nt have 31 days bro =))" << endl;
			SetConsoleTextAttribute(hConsole, 7);
			return 0;
		} 
		if ( !IsLeapYear(IntDate[2]) && IntDate[0] > 28 && IntDate[1] == 2 ) {
			cout << "The " << IntDate[2] << " is not a leap year so the 2nd month can only have 28 days bro" << endl;
			SetConsoleTextAttribute(hConsole, 7);
			return 0; 
		} 
		if ( IsLeapYear(IntDate[2]) && IntDate[0] > 29 && IntDate[1] == 2 ) {
			cout << "The " << IntDate[2] << " is a leap year, but the second month can only have 29 but not " << IntDate[0] << " bro, double-check on that." << endl;
			SetConsoleTextAttribute(hConsole, 7);
			return 0;
		}
		else {
			SetConsoleTextAttribute(hConsole, 7);
			return 1;
		}
		
}

int main() {
    std::vector<std::pair<std::string, std::string>> testDates = {
        {"01/01/2024", "Valid"}, {"29/02/2024", "Valid"}, {"30/04/2024", "Valid"}, {"30/06/2024", "Valid"},
        {"30/09/2024", "Valid"}, {"30/11/2024", "Valid"}, {"31/01/2024", "Valid"}, {"31/03/2024", "Valid"},
        {"31/05/2024", "Valid"}, {"31/07/2024", "Valid"}, {"31/08/2024", "Valid"}, {"31/10/2024", "Valid"},
        {"31/12/2024", "Valid"}, {"28/02/2024", "Valid"}, {"31/04/2024", "Invalid"}, {"31/06/2024", "Invalid"},
        {"31/09/2024", "Invalid"}, {"31/11/2024", "Invalid"}, {"30/02/2024", "Invalid"}, {"01/13/2024", "Invalid"},
        {"10/00/2024", "Invalid"}, {"32/05/2024", "Invalid"}, {"00/07/2024", "Invalid"}, {"aa/bb/cccc", "Invalid"},
        {"25-05-2024", "Valid"}, {"29/02/2023", "Invalid"}, {"31/04/2023", "Invalid"}, {"31/06/2023", "Invalid"}, {"31/09/2023", "Invalid"}, {"31/11/2023", "Invalid"},
        {"30/02/2023", "Invalid"}, {"01/13/2023", "Invalid"}, {"10/00/2023", "Invalid"}, {"32/05/2023", "Invalid"},
        {"00/07/2023", "Invalid"}, {"28/02/2023", "Valid"}, {"01/03/2023", "Valid"}, {"31/12/2023", "Valid"},
        {"01/01/2023", "Valid"}, {"31/01/2023", "Valid"}, {"31/03/2023", "Valid"}, {"31/05/2023", "Valid"},
        {"31/07/2023", "Valid"}, {"31/08/2023", "Valid"}, {"31/10/2023", "Valid"}, {"01/12/2023", "Valid"},
        {"15/01/2024", "Valid"}, {"15/03/2024", "Valid"}, {"15/05/2024", "Valid"}, {"15/07/2024", "Valid"},
        {"15/09/2024", "Valid"}, {"15/11/2024", "Valid"}, {"30/01/2024", "Valid"}, {"30/03/2024", "Valid"},
        {"30/05/2024", "Valid"}, {"30/07/2024", "Valid"}, {"30/09/2024", "Valid"}, {"30/11/2024", "Valid"},
        {"29/02/2024", "Valid"}, {"28/02/2024", "Valid"}, {"28/02/2023", "Valid"}, {"30/12/2024", "Valid"},
        {"31/12/2024", "Valid"}, {"30/11/2024", "Valid"}, {"31/10/2024", "Valid"}, {"30/09/2024", "Valid"},
        {"31/08/2024", "Valid"}, {"31/07/2024", "Valid"}, {"30/06/2024", "Valid"}, {"31/05/2024", "Valid"},
        {"30/04/2024", "Valid"}, {"31/03/2024", "Valid"}, {"29/02/2024", "Valid"}, {"01/01/2023", "Valid"},
        {"01/02/2023", "Valid"}, {"01/03/2023", "Valid"}, {"01/04/2023", "Valid"}, {"01/05/2023", "Valid"},
        {"01/06/2023", "Valid"}, {"01/07/2023", "Valid"}, {"01/08/2023", "Valid"}, {"01/09/2023", "Valid"},
        {"01/10/2023", "Valid"}, {"01/11/2023", "Valid"}, {"01/12/2023", "Valid"}, {"15/01/2023", "Valid"},
        {"15/02/2023", "Valid"}, {"15/03/2023", "Valid"}, {"15/04/2023", "Valid"}, {"15/05/2023", "Valid"},
        {"15/06/2023", "Valid"}, {"15/07/2023", "Valid"}, {"15/08/2023", "Valid"}, {"1", "Invalid"},
        {"cas", "Invalid"}, {"0/0/0", "Invalid"}, {"/12/2024", "Invalid"}, {"23/5/2024/23", "Invalid"}
        
    };

    for (const auto& datePair : testDates) {
        const std::string& date = datePair.first;
        const std::string& expected = datePair.second;
        std::cout << "Testing date: " << date << " - Expected: " << expected << std::endl;
        int result = ValidDateInput(date);
        std::string actual = result ? "Valid" : "Invalid";
        std::cout << "Result: " << actual << " - ";
        if ( actual == expected ) {
        	SetConsoleTextAttribute(hConsole, 10);
        	std::cout << "Pass" << endl;
        	SetConsoleTextAttribute(hConsole, 7);
		}
        else {
        	SetConsoleTextAttribute(hConsole, 12);
        	std::cout << "Fail" << endl;
        	SetConsoleTextAttribute(hConsole, 7);
		}
        std::cout << "--------------------------" << std::endl;
    }

    return 0;
}

