#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <windows.h>


#define CurrentYear 2024
#define version "1.3.0"
#define endl "\n"
#define motivation cout << "\n\n \t-It's during our darkest moments that we must focus to see the light- \n\t\t\t\t\t\t\t\t-Aristotle Onassis-" << endl;
#define StopCode 10101
// stop code is printout in case the program gives exceed ouput or any malfuntion, please check the main function and CheckRuntimeError() 
#define PassWord "12042005" // Confidential


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// color text handle 
// SetConsoleTextAttribute(hConsole, 12) <key>
using namespace std;

//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (|     |)
//                      0\     /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


struct SubName {
	string DATE;
	
	string s1;
    string s2;
    string s3;
    string s4;
    string s5;
    string s6;
    string s7;
    string s8;
    string s9;
    string s10;
    
};

struct SubName ki2 = {
							.s1 = "Kinh te chinh tri",
							.s2 = "Vat ly ung dung",
							.s3 = "Ky thuat so",
							.s4 = "Giai tich 2",
							.s5 = "Tin hoc co so 2",
							.s6 = "Phap luat dai cuong",
};

struct SubName ki3 = {		.s1 = "Chu nghia xa hoi khoa hoc",
							.s2 = "Xac suat thong ke",
							.s3 = "Xu ly tin hieu so",
							.s4 = "C++",
							.s5 = "Toan roi rac 1",
							.s6 = "Ky nang thuyet trinh",
};

struct SubName kihe = {		.s1 = "Project",
							.s2 = "Code C",
							.s3 = "IT related knowledge / Sth in4mative / positive",
							.s4 = "Self dev",
};

// Function declarations in alphabetical order

void AddEntry(vector<SubName>& reports);
void CheckRuntimeError(int& running);
void ClearScreen(string filename);
void DeleteEntry(vector<SubName>& reports);
void DisplayData(string data);
void DisplayHelp();
void DisplayInvalidCommandError();
void displayData(SubName name, SubName data);
void displayInputIntake();
void displayPlanTimeErr();
void EditEntry(vector<SubName>& reports);
string FillDotAfter(const string& label);
bool IsLeapYear(int year);
void LoadData(vector<SubName>& reports, const string& filename);
void PrintInvalidDateInputError(string CheckDate);
void SaveData(const vector<SubName>& reports, const string& filename);
void showData(const vector<SubName>& reports);
void StandardizeInput(string& input);
SubName specify(SubName sub);
void ThangNaoLamRaCaiNay();
int ValidDateInput(string date);
int ValidDateInputForShow(string date);

// Function definitions in alphabetical order

void AddEntry(vector<SubName>& reports) {
    SubName newEntry;

    while (true) {
        cout << FillDotAfter("Date") << " : ";
        string CheckDate = "";
        cin >> CheckDate;
        StandardizeInput(CheckDate);

        if (CheckDate == "out") {
            return;
        } else if (ValidDateInput(CheckDate)) {
            newEntry.DATE = CheckDate;
            break;
        } else {
            PrintInvalidDateInputError(CheckDate);
        }
    }

    cin.ignore(); // Clear the newline character from the input buffer
	
	SubName name = specify(newEntry);
	
	if ( name.s1.empty() ) {
		displayPlanTimeErr();
  	 	reports.push_back(newEntry);
   		return;
	}
	cout << FillDotAfter(name.s1) << " : ";
	getline(cin, newEntry.s1);

	if ( name.s2.empty() ) {
    	reports.push_back(newEntry);
    	displayInputIntake();
   	 	return;
	}
	cout << FillDotAfter(name.s2) << " : ";
	getline(cin, newEntry.s2);

	if ( name.s3.empty() ) {
    	reports.push_back(newEntry);
    	displayInputIntake();
    	return;
	}
	cout << FillDotAfter(name.s3) << " : ";
	getline(cin, newEntry.s3);

	if ( name.s4.empty() ) {
    	reports.push_back(newEntry);
    	displayInputIntake();
    	return;
	}
	cout << FillDotAfter(name.s4) << " : ";
	getline(cin, newEntry.s4);

	if ( name.s5.empty() ) {
    	reports.push_back(newEntry);
    	displayInputIntake();
		return;
	}
	cout << FillDotAfter(name.s5) << " : ";
	getline(cin, newEntry.s5);

	if ( name.s6.empty() ) {
    	reports.push_back(newEntry);
    	displayInputIntake();
		return;
	}
	cout << FillDotAfter(name.s6) << " : ";
	getline(cin, newEntry.s6);

	if ( name.s7.empty() ) {
   	 	reports.push_back(newEntry);
    	displayInputIntake();
		return;
	}
	cout << FillDotAfter(name.s7) << " : ";
	getline(cin, newEntry.s7);

	if ( name.s8.empty() ) {
    	reports.push_back(newEntry);
    	displayInputIntake();
		return;
	}
	cout << FillDotAfter(name.s8) << " : ";
	getline(cin, newEntry.s8);

	if ( name.s9.empty() ) {
    	reports.push_back(newEntry);
    	displayInputIntake();
		return;
	}
	cout << FillDotAfter(name.s9) << " : ";
	getline(cin, newEntry.s9);

	if ( name.s10.empty() ) {
    	reports.push_back(newEntry);
    	displayInputIntake();
		return;
	}
	cout << FillDotAfter(name.s10) << " : ";
	getline(cin, newEntry.s10);


    
    reports.push_back(newEntry);

    // motivation;
}

void CheckRuntimeError(int& running) {
	if ( running == 101 ) {
			SetConsoleTextAttribute(hConsole, 14);
			string CheckErr;
			cout << endl << "(0_0)  Manual Check <the numbers of command has reached 100>, every things is still okay? (y/n): ";
			cin >> CheckErr;
			
			StandardizeInput(CheckErr);
			
			if ( CheckErr == "y") {
				SetConsoleTextAttribute(hConsole, 10);
				cout << "Im gald you worked so hard :), lets continue to work ^_^\n";
				running = 1;
				SetConsoleTextAttribute(hConsole, 7);
			}
			else if ( CheckErr == "n") {
				SetConsoleTextAttribute(hConsole, 12);
				running = StopCode;
				cout << "The program has been stopped!" << endl;
				cout << "Please notice us about that error, thanks for your help!" << endl;
				cout << "Contact me via https://www.facebook.com/hung.bu.2k5/" << endl;
				cout << "StopCode <" << running << ">\n";
				SetConsoleTextAttribute(hConsole, 7);
			} else {
				SetConsoleTextAttribute(hConsole, 12);
				running = StopCode;
				cout << "\nInput CheckErr time request expired!. The prorgam has been cancelled\n";
				cout << "Please notice us about that error, thanks for your help!" << endl;
				cout << "Contact me via https://www.facebook.com/hung.bu.2k5/" << endl;
				cout << "=StopCode= <" << running << ">\n";
				SetConsoleTextAttribute(hConsole, 7);
			}
		}
}

void ClearScreen(string filename) {
	system("cls");
	SetConsoleTextAttribute(hConsole, 10);
    cout << "Du lieu duoc lay tu " << filename << endl;
    SetConsoleTextAttribute(hConsole, 7);
    return;
}

void DeleteEntry(vector<SubName>& reports) {
    string input;
    cout << "Nhap 'all' de xoa tat ca hoac nhap ngay de xoa du lieu cua ngay do: ";
    
	string CheckDate;
    cin >> CheckDate;
    StandardizeInput(CheckDate);
    
    if ( CheckDate != "all" && !ValidDateInput(CheckDate)) {
    	PrintInvalidDateInputError(CheckDate);
    	return;
	}
	
	input = CheckDate;
	if (input == "all") {
        char choice;
        SetConsoleTextAttribute(hConsole, 12);
        cout << "Nguoi ae co chac muon xoa tat ca lam lai tu dau? (y/n): ";
		cin >> choice;
        
		if ( choice == 'y' || choice == 'Y') {
			SetConsoleTextAttribute(hConsole, 206); 
			cout << "Rethink one last time brother || ";
			SetConsoleTextAttribute(hConsole, 192);
			cout << "Nhap mat khau <Confidential>: ";
			SetConsoleTextAttribute(hConsole, 204);
			
			
        	string PassCheck;
       	 	cin >> PassCheck;
       	 	if ( PassWord == PassCheck) {
        	    reports.clear();
        	    SetConsoleTextAttribute(hConsole, 14);
          	 	cout << "\nTat ca du lieu da duoc xoa. Chuc nguoi ae may man!" << endl;
				SetConsoleTextAttribute(hConsole, 11);
				cout << "For all of my respect, please take these last words from me.\nSee you in a better version of youself!";
				motivation;
				SetConsoleTextAttribute(hConsole, 7);
           	    
     	    } else {
     	    	SetConsoleTextAttribute(hConsole, 10);
     	        cout << "\nU forgot our secret. What happened bro ?" << endl;
     	        cout << "<Codeline-error-276>\n";
				cout << "Yeu cau xoa du lieu da bi huy." << endl;
				SetConsoleTextAttribute(hConsole, 7);
				motivation;
				
      		} 
			SetConsoleTextAttribute(hConsole, 7);
			
		} else if ( choice == 'n' || choice == 'N') {
			SetConsoleTextAttribute(hConsole, 14);
        	cout << "Data status-<no update>." << endl << "Relax bro, U should go out side and \"comeback\"." << endl;
        	SetConsoleTextAttribute(hConsole, 7);
		} else {
			SetConsoleTextAttribute(hConsole, 12);
			cout << "Input is invalid!" << endl << "denied-<DeleteEntry>." << endl;
			SetConsoleTextAttribute(hConsole, 7);
			return;
		}
		
        
    } else {
        bool found = false;
        for (auto it = reports.begin(); it != reports.end();) {
            if (it->DATE == input) {
                found = true;
                char choice;
                SetConsoleTextAttribute(hConsole, 12);
                cout << "Nguoi ae co chac muon xoa du lieu ngay " << input << "? (y/n): ";
                
                cin >> choice;
                if (choice == 'y' || choice == 'Y') {
                    it = reports.erase(it);
                    SetConsoleTextAttribute(hConsole, 10);
                    cout << "Du lieu ngay " << input << " da duoc xoa thanh cong!" << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    motivation;
                } else {
                    cout << "Yeu cau xoa du lieu da bi huy." << endl;
                    ++it;
                }
            } else {
                ++it;
            }
        }
        if (!found) {
        	SetConsoleTextAttribute(hConsole, 12);
            cout << "Khong co du lieu ton tai ngay " << input << endl;
        }
    }
    SetConsoleTextAttribute(hConsole, 7);
}

void DisplayData(string data) {
	string TempData = data;
	StandardizeInput(TempData);
	if (data.empty() || TempData == "nope" || TempData == "no" ) {
		SetConsoleTextAttribute(hConsole, 192);
		cout << "nope";
		SetConsoleTextAttribute(hConsole, 7);
		cout << endl;
	} else {
		cout << data << endl;
	}
	
	return;
}

void DisplayInvalidCommandError() {
	SetConsoleTextAttribute(hConsole, 12);
	cerr << "Cau lenh khong hop le." << endl;
	cerr << "Nhap \"Help\" de hien thi <Availble_Command!>" << endl;
	cerr << "Input se duoc tieu chuan hoa, nhap 'help' hoac 'HELP' deu cho ra 1 ket qua, 'HeLp' hay 'HLeP' gi cung duoc luon =))" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	return;
}

void displayData(SubName name, SubName data) {
	
	if (name.s1.empty()) return;
    int checkNum = isNumber(data.s1);
    if ( checkNum == -1 ) {
        cout << FillDotAfter(name.s1) << " : " << data.s1 << endl;
    } 
    else {
        cout << FillDotAfter(name.s1) << " " << rangeOfSatisfy(checkNum) << endl;
    } 

    if (name.s2.empty()) return;
    checkNum = isNumber(data.s2);
    if ( checkNum == -1 ) {
        cout << FillDotAfter(name.s2) << " : " << data.s2 << endl;
    } 
    else {
        cout << FillDotAfter(name.s2) << " " << rangeOfSatisfy(checkNum) << endl;
    } 

    // ... (similar blocks for s3 to s10)

    return;
}

void displayInputIntake() {
	SetConsoleTextAttribute(hConsole, 10);
    cout << "Du lieu da duoc luu vao thanh cong!\n";
    SetConsoleTextAttribute(hConsole, 7);
}

void displayPlanTimeErr() {
	SetConsoleTextAttribute(hConsole, 12);
	cout << "No subject or plan was set at this time!" << endl;
	cout << "The first added is the 2nd semester, the lastest yet is the 3rd one" << endl;
	cout << "All vary from 15/01/2024 -> now" << endl;
	cout << "Please consider double-check the time" << endl;
	SetConsoleTextAttribute(hConsole, 7);
}

void EditEntry(vector<SubName>& reports) {
    string editDate;
    cout << "Nhap ngay ban muon thay doi du lieu: ";
    
    string CheckDate;
    cin >> CheckDate;
    if ( !ValidDateInput(CheckDate)) {
    	PrintInvalidDateInputError(CheckDate);
    	return;
	}
	
	editDate = CheckDate;

    bool found = false;
    for (auto& entry : reports) {
        if (entry.DATE == editDate) {
            cout << "Du lieu goc ngay "  << entry.DATE << endl;
            SubName name =  specify(entry);
    
			displayData(name, entry);
            
            cout << "\nNhap du lieu moi:\n";
			
			cin.ignore();
			
			// ... (similar blocks for s1 to s10 as in AddEntry)

			SetConsoleTextAttribute(hConsole, 10);
            cout << "Du lieu da duoc cap nhat thanh cong!\n";
            found = true;
            break;
        }
    }

    if (!found) {
    	SetConsoleTextAttribute(hConsole, 12);
        cout << "Khong co du lieu ton tai ngay " << editDate << ", nguoi ae xem lai xem nao" << endl;
    }
    SetConsoleTextAttribute(hConsole, 7);
}

string FillDotAfter(const string& label) {
    string result = label;
    int DotCount = LABEL_WIDTH - label.length() - 1; // Subtract 1 for the colon
    result.append(DotCount, '.');
    return result;
}

bool IsLeapYear(int year) {
   if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) return true;
   else return false;
}

void LoadData(vector<SubName>& reports, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        reports.clear(); // Clear existing data

        SubName entry;
        while (file >> entry.DATE >> ws
                    && getline(file, entry.s1) 
                    && getline(file, entry.s2) 
                    && getline(file, entry.s3) 
                    && getline(file, entry.s4) 
                    && getline(file, entry.s5) 
                    && getline(file, entry.s6) 
                    && getline(file, entry.s7) 
                    && getline(file, entry.s8) 
                    && getline(file, entry.s9) 
                    && getline(file, entry.s10)) {
            reports.push_back(entry); 
        }
        file.close();
        SetConsoleTextAttribute(hConsole, 15);
        cout << "BaoCao_HocTap [ version " << version << " ]" << endl;
        SetConsoleTextAttribute(hConsole, 10);
        cout << "Du lieu duoc lay tu " << filename << endl;
        SetConsoleTextAttribute(hConsole, 14);
        motivation;
    } else {
    	SetConsoleTextAttribute(hConsole, 12);
        cerr << "Khong the mo file de load data. <create-mode>BaoCao_HocTap.text" << endl;
    }
    SetConsoleTextAttribute(hConsole, 7);
}

void PrintInvalidDateInputError(string CheckDate) {
	SetConsoleTextAttribute(hConsole, 12);
	cout << "The input '" << CheckDate << "' is invalid, please type in date as DD/MM/YYYY of DD-MM-YYYY" << endl;
	cout << "Invalid DateInput <ErrorCode-472>" << endl;
	cout << "Vui long nhap lai du lieu <Nhap 'out' de thoat>" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	return;
}

void SaveData(const vector<SubName>& reports, const string& filename) {
    ofstream file(filename);

    if (file.is_open()) {
        for (const auto& entry : reports) {
        	file << entry.DATE << '\n';
            file << entry.s1 << '\n';
            file << entry.s2 << '\n';
            file << entry.s3 << '\n';
            file << entry.s4 << '\n';
            file << entry.s5 << '\n';
            file << entry.s6 << '\n';
            file << entry.s7 << '\n';
            file << entry.s8 << '\n';
            file << entry.s9 << '\n';
            file << entry.s10 << '\n';
        }
        file.close();
    } else {
    	SetConsoleTextAttribute(hConsole, 12);
        cerr << "Khong the mo file luu du lieu .<CodeLine-220>" << endl;
        SetConsoleTextAttribute(hConsole, 7);
    }
}

void showData(const vector<SubName>& reports) {
    if (reports.empty()) {
        cout << "No data available to show." << endl;
        return;
    }

    cout << "Nhap 'all' de show tat ca hoac nhap ngay de show du lieu cua ngay do: ";
    string CheckDate;
    cin >> CheckDate;
    StandardizeInput(CheckDate);
    
    if ( CheckDate != "all" && !ValidDateInputForShow(CheckDate)) {
    	PrintInvalidDateInputError(CheckDate);
    	return;
	}
	
	string input = CheckDate;
	
    if (input == "all") {
        for (const auto& entry : reports) {
			SubName name = specify(entry);
			cout << endl;
			
			SetConsoleTextAttribute(hConsole, 142);
            cout << "date           : " << entry.DATE;
            SetConsoleTextAttribute(hConsole, 7); cout << endl;
            
       		displayData(name, entry);
       		cout << "-------------------\n";
        }
    } else {
        bool found = false;
        for (const auto& entry : reports) {
            if (entry.DATE == input) {
				SubName name = specify(entry);
				cout << endl;
				
				SetConsoleTextAttribute(hConsole, 142);
      	     	cout << "date           : " << entry.DATE;
          	 	SetConsoleTextAttribute(hConsole, 7); cout << endl;
				
                displayData(name, entry);
                cout << "-------------------\n";
                found = true;
            }
        }
        if (!found) {
        	SetConsoleTextAttribute(hConsole, 12);
            cout << "No data found for the specified date " << input << endl;
            SetConsoleTextAttribute(hConsole, 7);
        }
    }
}

void StandardizeInput(string& input) {
	int index = 0;
	while ( input[index] != '\0' ) {
		if ( input[index] >= 'A' && input[index] <= 'Z') input[index]+=32;
		index++;
	}
}

SubName specify(SubName sub) {
	string date = sub.DATE;
	int intDate[3] = {0};
	int TempIndex = 0;
	for ( int i = 0; i < 3; i++) {
		while ( date[TempIndex] != '\0' && date[TempIndex] != '/' && date[TempIndex] != '-' && date[TempIndex] != EOF) {
			intDate[i] = intDate[i]*10 + (date[TempIndex]-48);
			TempIndex++;
		}
		TempIndex++;
    }
	
	if ( intDate[2] == 2024 ) {
		if ( (intDate[1] > 1 && intDate[1] < 7) || ((intDate[1] == 1 && intDate[0] >= 15) || (intDate[1] == 7 && intDate[0] <= 14)) ) {
			return ki2;
		} 
		else if (( intDate[1] == 7 && intDate[0] >= 15) || (intDate[1] == 8 && intDate[0] <= 11)) {
			return kihe;
		}
		else if ( intDate[1] == 8 && intDate[0] >= 12 ) {
			return ki3;
		} 
		else if ( intDate[1] > 8 ){
			return ki3;
		} 
		else {
			return sub;
		}
	} else {
		return sub;
	}
}

void ThangNaoLamRaCaiNay() {
   	SetConsoleTextAttribute(hConsole, 15);
	cout << "\n _Please stand by_ " << endl;
    cout << "===================" << endl;
    cout << " _Nguyen Hai Hung_ " << endl;
    cout << "\nPowered by GPT_3.5, GPT_4thGen and Gemini" << endl;
    cout << "Thanks for using the app :3" << endl;
    cout << "Contact me via https://www.facebook.com/hung.bu.2k5/" << endl;
    string s = "+";
    
   	int set = 10;
	for ( float y = 1.3 ; y >= -1.1 ; y -= 0.12 ) {       			
		int index = 0;
       	for ( float x = -1.2; x <= 1.2; x += 0.05 ) {
		
		SetConsoleTextAttribute(hConsole, set); set++;
        if( pow((x*x+y*y-1.0),3) - x*x*y*y*y <= 0.0 )
            cout << s[(index++)%s.size()];
        else
       	    cout << ' ';
       	if ( set == 15 ) set = 10;
		}
       	cout << endl;
   	}
   	SetConsoleTextAttribute(hConsole, 7);
    return;
}

int ValidDateInput(string date) {
    SetConsoleTextAttribute(hConsole, 10);
	int index = 0;
	int IntDate[3] = {0};
	int TempIndex = index;
	for ( int i = 0; i < 3; i++) {
		while ( date[TempIndex] != '\0' && date[TempIndex] != '/' && date[TempIndex] != '-' && date[TempIndex] != EOF) {
			if ( date[TempIndex] < '0' || date[TempIndex] > '9' ) {
				return 0;
			}
			IntDate[i] = IntDate[i]*10 + (date[TempIndex]-48);
			TempIndex++;
		}
		
		if (i == 0 && (IntDate[0] < 0 || IntDate[0] > 31)) {
			cout << "Day " << IntDate[0] << " exist ? bro u serious?:)" << endl;
			SetConsoleTextAttribute(hConsole, 7);
			return 0;
		}
		else if (i == 1 && (IntDate[1] < 0 || IntDate[1] > 12)) {
			cout << "Month " << IntDate[1] << " exist ? bro u serious?:)" << endl;
			SetConsoleTextAttribute(hConsole, 7);
			return 0;
		} else if ( i == 2 && IntDate[2] != CurrentYear ) {
			cout << "Bro living in " << IntDate[2] << " =))?? R you serious" << endl;
			cout << "The lastest valid year for this update is " << CurrentYear << " | Ver : " << version << endl;
		}
		else if ( IntDate[i] == 0) {
			return 0;
		}
		else TempIndex++;
		
		if ( i == 2 && date[TempIndex-1] != '\0') {
			return 0;
		}
	}
	
	if ( IntDate[0] < 10 && date[0] != '0' ) return 0;
	if ( IntDate[1] < 10 && date[3] != '0' ) return 0;
	
	if ( (IntDate[1] == 4 || IntDate[1] == 6 || IntDate[1] == 9 || IntDate[1] == 11) && IntDate[0] > 30) {
		cout << "The " << IntDate[1] << " month does'nt have 31 days bro =))" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		return 0;
	} 
	else if ( !IsLeapYear(IntDate[2]) && IntDate[1] == 2 && IntDate[0] > 28 ) {
		cout << "The " << IntDate[2] << " is not a leap year so february can only have 28 days bro" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		return 0; 
	} 
	else if ( IsLeapYear(IntDate[2]) && IntDate[1] == 2 && IntDate[0] > 29 ) {
		cout << "The " << IntDate[2] << " is a leap year, but february it only can have 29 but not " << IntDate[0] << " bro, double-check on that." << endl;
		SetConsoleTextAttribute(hConsole,