#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <windows.h>


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


struct DailyReport {
    string DATE;
    string APP_DEV;
    string CODE;
    string GIAI_TICH2;
    string KINH_TE_CHINH_TRI;
    string KY_THUAT_SO;
    string OTHER_CODE;
    string SELF_DEV;
    string NOTE;
};

void AddEntry(vector<DailyReport>& reports);
void DeleteEntry(vector<DailyReport>& reports, const string& input);
void EditEntry(vector<DailyReport>& reports);
void LoadData(vector<DailyReport>& reports, const string& filename);
void SaveData(const vector<DailyReport>& reports, const string& filename);
void ShowEntries(const vector<DailyReport>& reports);


// Function to add a new entry to the data
void AddEntry(vector<DailyReport>& reports) {
    DailyReport newEntry;

    cout << "date              : ";
    cin >> newEntry.DATE;

    cout << "App dev           : ";
    cin.ignore();
    getline(cin, newEntry.APP_DEV);

    cout << "Code              : ";
    getline(cin, newEntry.CODE);

    cout << "Giai tich 2       : ";
    getline(cin, newEntry.GIAI_TICH2);

    cout << "Kinh te chinh tri : ";
    getline(cin, newEntry.KINH_TE_CHINH_TRI);

    cout << "Ky thuat so       : ";
    getline(cin, newEntry.KY_THUAT_SO);

    cout << "Other code        : ";
    getline(cin, newEntry.OTHER_CODE);

    cout << "Self dev          : ";
    getline(cin, newEntry.SELF_DEV);

    cout << "Note              : ";
    getline(cin, newEntry.NOTE);

    reports.push_back(newEntry);
	
	SetConsoleTextAttribute(hConsole, 10);
    cout << "Du lieu da duoc luu vao thanh cong!\n";
    SetConsoleTextAttribute(hConsole, 7);
//    motivation;
}

void CheckRuntimeError (int& running) {
	if ( running == 100 ) {
			SetConsoleTextAttribute(hConsole, 14);
			char CheckErr = ' ';
			cout << endl << "(0_0)  Manual Check <the numbers of command has reached 1000>, every things is still okay? (y/n): ";
			cin >> CheckErr;
			if ( CheckErr == 'y') {
				SetConsoleTextAttribute(hConsole, 10);
				cout << "Im gald you worked so hard :), lets continue our works ^_^\n";
				running = 1;
				SetConsoleTextAttribute(hConsole, 7);
			}
			else if ( CheckErr == 'n') {
				SetConsoleTextAttribute(hConsole, 12);
				running = StopCode;
				cout << "Somethings went wrong. Stopped the program!";
				cout << "StopCode <" << running << ">\n";
				SetConsoleTextAttribute(hConsole, 7);
			} else {
				SetConsoleTextAttribute(hConsole, 12);
				running = StopCode;
				cout << "\nInput CheckErr Expired time request!. The prorgam has been cancelled\n";
				cout << "=StopCode= <" << running << ">\n";
				SetConsoleTextAttribute(hConsole, 7);
			}
		}
}

// Function to delete data
void DeleteEntry (vector<DailyReport>& reports, const string& input) {
    if (input == "all") {
        char choice;
        SetConsoleTextAttribute(hConsole, 12);
        cout << "Nguoi ae co chac muon xoa tat ca lam lai tu dau? (y/n): ";
		cin >> choice;
        
		if ( choice == 'y') {
			SetConsoleTextAttribute(hConsole, 206); 
			cout << "Rethink one last time brother || ";
			SetConsoleTextAttribute(hConsole, 192);
			cout << "Nhap mat khau <Confidential>: ";
			
			
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
           	    
     	    } else if ( PassWord != PassCheck ) {
     	    	SetConsoleTextAttribute(hConsole, 10);
     	        cout << "\nU forgot our secret. What happened bro ?" << endl;
     	        cout << "We need to talk!" << endl;
     	        cout << "<Codeline-error-276>\n";
				cout << "Yeu cau xoa du lieu da bi huy." << endl;
				SetConsoleTextAttribute(hConsole, 7);
				motivation;
				
      		} else {
        		SetConsoleTextAttribute(hConsole, 12);
				cout << "Password input is invalid denied-<DeleteEntry>" << endl << "Yeu cau xoa du lieu da bi huy." << endl;
        		SetConsoleTextAttribute(hConsole, 7);
				return;
        		
			}
			
		} else if ( choice == 'n') {
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
                SetConsoleTextAttribute(hConsole, 7);
                cin >> choice;
                if (choice == 'y' || choice == 'Y') {
                    it = reports.erase(it);
                    cout << "Du lieu ngay " << input << " da duoc xoa thanh cong!" << endl;
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
            SetConsoleTextAttribute(hConsole, 7);
        }
    }
}


void EditEntry (vector<DailyReport>& reports) {
    string editDate;
    cout << "Nhap ngay ban muon thay doi du lieu: ";
    cin >> editDate;

    bool found = false;
    for (auto& entry : reports) {
        if (entry.DATE == editDate) {
            // Show original data
            cout << "Du lieu goc ngay "  << entry.DATE << endl;
            cout << "App dev        : " << entry.APP_DEV << endl;
            cout << "Code           : " << entry.CODE << endl;
            cout << "Giai tich 2    : " << entry.GIAI_TICH2 << endl;
            cout << "Kinh te chinh  : " << entry.KINH_TE_CHINH_TRI << endl;
            cout << "Ky thuat so    : " << entry.KY_THUAT_SO << endl;
            cout << "Other code     : " << entry.OTHER_CODE << endl;
            cout << "Self dev       : " << entry.SELF_DEV << endl;
            cout << "Note           : " << entry.NOTE << endl;

            // Let the user type new data
            cout << "\nNhap du lieu moi:\n";

            cout << "App dev        : ";
            cin.ignore();
            getline(cin, entry.APP_DEV);

            cout << "Code           : ";
            getline(cin, entry.CODE);

            cout << "Giai tich 2    : ";
            getline(cin, entry.GIAI_TICH2);

            cout << "Kinh te chinh  : ";
            getline(cin, entry.KINH_TE_CHINH_TRI);

            cout << "Ky thuat so    : ";
            getline(cin, entry.KY_THUAT_SO);

            cout << "Other code     : ";
            getline(cin, entry.OTHER_CODE);

            cout << "Self dev       : ";
            getline(cin, entry.SELF_DEV);

            cout << "Note           : ";
            getline(cin, entry.NOTE);

            cout << "Du lieu da duoc cap nhat thanh cong!\n";
        //    motivation;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Khong co du lieu ton tai ngay " << editDate << ", nguoi ae xem lai xem nao" << endl;
    }
}


// Function to load data from a file
void LoadData (vector<DailyReport>& reports, const string& filename) {
    ifstream file(filename);

    if (file.is_open()) {
        reports.clear(); // Clear existing data

        DailyReport entry;
        while (file >> entry.DATE >> ws
                    && getline(file, entry.APP_DEV) 
                    && getline(file, entry.CODE) 
                    && getline(file, entry.GIAI_TICH2) 
                    && getline(file, entry.KINH_TE_CHINH_TRI) 
                    && getline(file, entry.KY_THUAT_SO) 
                    && getline(file, entry.OTHER_CODE) 
                    && getline(file, entry.SELF_DEV) 
                    && getline(file, entry.NOTE)) {
            reports.push_back(entry); 
        }
        file.close();
        SetConsoleTextAttribute(hConsole, 10);
        cout << "Du lieu duoc lay tu " << filename << endl;
        SetConsoleTextAttribute(hConsole, 7);
        motivation;
    } else {
        cerr << "Khong the mo file de load data. <create-mode>BaoCao_HocTap.text" << endl;
    }
}

// Function to save data to a file
void SaveData (const vector<DailyReport>& reports, const string& filename) {
    ofstream file(filename);

    if (file.is_open()) {
        for (const auto& entry : reports) {
            file << entry.DATE << '\n';
            file << entry.APP_DEV << '\n';
            file << entry.CODE << '\n';
            file << entry.GIAI_TICH2 << '\n';
            file << entry.KINH_TE_CHINH_TRI << '\n';
            file << entry.KY_THUAT_SO << '\n';
            file << entry.OTHER_CODE << '\n';
            file << entry.SELF_DEV << '\n';
            file << entry.NOTE << '\n';
        }
        file.close();
     //   cout << filename << " saved successfully!" << endl;
    } else {
    	SetConsoleTextAttribute(hConsole, 12);
        cerr << "Khong the mo file luu du lieu .<CodeLine-220>" << endl;
        SetConsoleTextAttribute(hConsole, 7);
    }
}

// Function to show entries based on user input
void ShowEntries (const vector<DailyReport>& reports) {
    if (reports.empty()) {
        cout << "No data available to show." << endl;
        return;
    }

    cout << "Nhap 'all' de show tat ca hoac nhap ngay de show du lieu cua ngay do: ";
    string input;
    cin >> input;

    if (input == "all") {
        
		for (const auto& entry : reports) {
			cout << endl;
			SetConsoleTextAttribute(hConsole, 142);
            cout << "date           : " << entry.DATE << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "App dev        : " << entry.APP_DEV << endl;
            cout << "Code           : " << entry.CODE << endl;
            cout << "Giai tich 2    : " << entry.GIAI_TICH2 << endl;
            cout << "Kinh te chinh  : " << entry.KINH_TE_CHINH_TRI << endl;
            cout << "Ky thuat so    : " << entry.KY_THUAT_SO << endl;
            cout << "Other code     : " << entry.OTHER_CODE << endl;
            cout << "Self dev       : " << entry.SELF_DEV << endl;
            cout << "Note           : " << entry.NOTE << endl;
            cout << "-------------------\n";
        //    motivation;
        }
    } else {
        bool found = false;
        for (const auto& entry : reports) {
            if (entry.DATE == input) {

                cout << "date           : " << entry.DATE << endl;
                cout << "App dev        : " << entry.APP_DEV << endl;
                cout << "Code           : " << entry.CODE << endl;
                cout << "Giai tich 2    : " << entry.GIAI_TICH2 << endl;
                cout << "Kinh te chinh  : " << entry.KINH_TE_CHINH_TRI << endl;
                cout << "Ky thuat so    : " << entry.KY_THUAT_SO << endl;
                cout << "Other code     : " << entry.OTHER_CODE << endl;
                cout << "Self dev       : " << entry.SELF_DEV << endl;
                cout << "Note           : " << entry.NOTE << endl;
                cout << "-------------------\n";
                found = true;
            //    motivation;
            }
        }
        if (!found) {
        	SetConsoleTextAttribute(hConsole, 12);
            cout << "No data found for the specified date " << input << endl;
            SetConsoleTextAttribute(hConsole, 7);
        }
    }
}

void ThangNaoLamRaCaiNay () {
	       	
   	SetConsoleTextAttribute(hConsole, 15);
	cout << "\n _Please stand by_ " << endl;
    cout << "===================" << endl;
    cout << " _Nguyen Hai Hung_ " << endl;
    cout << "Powered by GPT_3.5, GPT_4thGen and GPT 4o" << endl;
    cout << "Thanks for using the app :3" << endl;
    string s = "I Love U ";
   	// origin 0.06 0.025
	for ( float y = 1.3 ; y >= -1.1 ; y -= 0.12 ) {       			
		int index = 0;
       	for ( float x = -1.2; x <= 1.2; x += 0.05 ) {
		SetConsoleTextAttribute(hConsole, 14);
        if( pow((x*x+y*y-1.0),3) - x*x*y*y*y <= 0.0 )
            cout << s[(index++)%s.size()];
        else
       	    cout << ' ';
		}
       	cout << endl;
       		// author Yubo Liu
       		// repo github
       		// https://github.com/liuyubobobo/heart-curve-cplusplus/tree/master
       	SetConsoleTextAttribute(hConsole, 7);
   		}
    return;
}

int main() {
    
	
	vector<DailyReport> reports;
    string filename = "BaoCao_HocTap.txt";
    
    LoadData(reports, filename);
	
	int running = 1;
    while (running <= 100) {
		SetConsoleTextAttribute(hConsole, 14);
		cout << "authorised-<HungBu> ~$ Nhap lenh: ";
		SetConsoleTextAttribute(hConsole, 7);
        string command;
        cin >> command;

        if (command == "add") {
            AddEntry(reports);
        } else if (command == "show") {
            ShowEntries(reports);
        } else if (command == "edit") {
            EditEntry(reports);
        } else if (command == "delete") {
            string input;
            cout << "Nhap 'all' de xoa tat ca hoac nhap ngay de xoa du lieu cua ngay do: ";
            cin >> input;
            DeleteEntry(reports, input);
        } else if ( command == "thangnaolamracainay?" ){
 			ThangNaoLamRaCaiNay();
		} else if ( command == "clear") {
			system("cls");
			SetConsoleTextAttribute(hConsole, 10);
       	    cout << "Du lieu duoc lay tu " << filename << endl;
            SetConsoleTextAttribute(hConsole, 7);
			
		} else {
            SetConsoleTextAttribute(hConsole, 12);
			cerr << "Cau lenh khong hop le. Hay nhap 'add' - 'show' - 'edit' - 'delete' - 'clear' - 'thangnaolamracainay?'\n";
			SetConsoleTextAttribute(hConsole, 7);
        }

        SaveData(reports, filename);
        
		running++;
		CheckRuntimeError(running);
    }

    return 0;
}

// for color text in console 
// consider revise https://iq.opengenus.org/print-text-in-color-in-c/