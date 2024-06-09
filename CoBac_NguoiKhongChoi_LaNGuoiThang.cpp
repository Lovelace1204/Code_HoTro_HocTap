#include<iostream>
#include <windows.h>
#include <iomanip>

#define endl "\n";

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

void DisplayInvalidCommandError () {
	SetConsoleTextAttribute(hConsole, 12);
	cerr << "Cau lenh khong hop le." << endl;
	cout << "Nhap 'n' de khoi tao mo hinh moi" << endl;
	cout << "Nhap 'dong' de thoat" << endl;
	cerr << "Input se duoc tieu chuan hoa, vi du nhap 'dong' hoac 'DONG' deu cho ra 1 ket qua, 'DoNg' hay 'DOng' gi cung duoc luon =))" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	return;
}

void StandardizeInput (string& input) {
	int index = 0;
	while ( input[index] != '\0' ) {
		if ( input[index] >= 'A' && input[index] <= 'Z') input[index]+=32;
		index++;
	}
}

int MoHinh () {
	int VonBatDau = 0;
	cout << "Nhap von bat dau ( don vi K = 1000VND ): "; cin >> VonBatDau; 
//	cout << "K";
//	cout << endl;
	
	int d = 1;
	cout << "So tien tang sau moi ngay ( don vi K = 1000VND ) : "; cin >> d; 
//	cout << "K";
//	cout << endl;
	
	int ChuKi = 100;
	cout << "Nhap chu ki dau tu: "; cin >> ChuKi;
//	cout << endl;
	
	
	int TongDauTu = 0;
	int TongKet = 0;
	int NgayLaiMax = (80*d + (float)d/2 -VonBatDau)/d;
	for ( int i = 1; i <= ChuKi; i++) {
		TongDauTu += VonBatDau + ( i - 1)*d;
		TongKet = -TongDauTu;
		
		if ( i == NgayLaiMax ) SetConsoleTextAttribute(hConsole, 122);
		cout << "Ngay " << i << ". \t| " << "Von bo ra: " << VonBatDau + ( i - 1)*d << "     \t | " << "Tong dau tu = " << TongDauTu << "K      \t| " << " Tong ket = ";
		if ( TongKet >= 0 ) {
			SetConsoleTextAttribute(hConsole, 10);
			cout << TongKet << "K";
			SetConsoleTextAttribute(hConsole, 7);
		} else {
			SetConsoleTextAttribute(hConsole, 12);
			cout << TongKet << "K";
			SetConsoleTextAttribute(hConsole, 7);
		}
		
		cout << "     \t | Neu de ve hom nay thi : lai = ";
		cout << (VonBatDau + (i - 1)*d) << "x80 - " << TongDauTu << " = ";
	    SetConsoleTextAttribute(hConsole, 10);
	    if ( i == NgayLaiMax ) SetConsoleTextAttribute(hConsole, 122);
		cout << "+" << (VonBatDau + (i - 1)*d)*80 - TongDauTu << "K";
		SetConsoleTextAttribute(hConsole, 7);
		
		if ( i == NgayLaiMax ) SetConsoleTextAttribute(hConsole, 7);
		cout << endl;
	}
	
	
	TongDauTu = 0;
	TongKet = 0;
	int NgayHanhPhuc = 0;
	
	cout << "\nDu dinh de ve ngay : "; cin >> NgayHanhPhuc;
	for ( int i = 1; i < NgayHanhPhuc; i++) {
		TongDauTu += VonBatDau + ( i - 1)*d;
		TongKet = -TongDauTu;
		cout << "Ngay " << i << ". \t| " << "Von bo ra: " << VonBatDau + ( i - 1)*d << "     \t | " << "Tong dau tu = " << TongDauTu << "K      \t| " << " Tong ket = ";
		if ( TongKet >= 0 ) {
			SetConsoleTextAttribute(hConsole, 10);
			cout << TongKet << "K";
			SetConsoleTextAttribute(hConsole, 7);
		} else {
			SetConsoleTextAttribute(hConsole, 12);
			cout << TongKet << "K";
			SetConsoleTextAttribute(hConsole, 7);
		}
		cout << endl;
	}
	
	TongDauTu += VonBatDau + (NgayHanhPhuc - 1)*d;
	TongKet = (VonBatDau + (NgayHanhPhuc - 1)*d)*80 - TongDauTu;
	cout << "\n========================" << endl;
	cout << "De ve ngay " << NgayHanhPhuc << endl;
	cout << "Ngay " << NgayHanhPhuc << ". \t| " << "Von bo ra: " << VonBatDau + (NgayHanhPhuc - 1)*d << "     \t | " << "Tong dau tu = " << TongDauTu << "K      \t| " << " Lai = ";
	cout << (VonBatDau + (NgayHanhPhuc - 1)*d) << "x80 - " << TongDauTu << " = ";
	SetConsoleTextAttribute(hConsole, 10);
	cout << "+" << (VonBatDau + (NgayHanhPhuc - 1)*d)*80 - TongDauTu << "K";
	cout << endl;
	SetConsoleTextAttribute(hConsole, 7);
	return 0;
}

int main () {
	
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Nhap 'n' de khoi tao mo hinh moi" << endl;
	cout << "Nhap 'dong' de thoat" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	
	while ( true ) {
		
		
		string input;
		cout << "\nNhap lenh: "; cin >> input;
		StandardizeInput(input);
		
		if 		( input == "n" ) MoHinh();
		else if ( input == "dong" ) return 0;
		else 	DisplayInvalidCommandError();
			
		
		 
	}
	
	
	
	
	
	
}