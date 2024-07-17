#include<iostream>
#include <windows.h>
#include <iomanip>
#include <windows.h>


#define endl "\n";

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

void DisplayInvalidCommandError () {
	SetConsoleTextAttribute(hConsole, 12);
	cerr << "Cau lenh khong hop le." << endl;
	cout << "Nhap 'n' de khoi tao mo hinh moi" << endl;
	cout << "Nhap 'dong' de thoat" << endl;
	cout << "Nhap 'clear' de lam sach man hinh" << endl;
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

void BaCang () {
	
	int TiLe = 900;
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Da chon mo hinh : ba cang - ti le x" << TiLe << endl;
	SetConsoleTextAttribute(hConsole, 7);
	
	
	int SoLuong = 1;
	cout << "Nhap so luong so muon danh ( default = 1 ): "; cin >> SoLuong; 
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Voi so luongg da chon = " << SoLuong << " ti le thang se = " << SoLuong << "/" << 1000 << " = " << (float)SoLuong/1000 << endl;
	SetConsoleTextAttribute(hConsole, 7);
	
	float VonBatDau = 0;
	cout << "Nhap von bat dau ( don vi K = 1000VND ) ( Co the nhap so thap phan : 0.1; 0.012 v.v ): "; cin >> VonBatDau; 
//	cout << "K";
//	cout << endl;
	
	float d = 1;
	cout << "So tien tang sau moi ngay ( chia deu cho " << SoLuong << " so da danh )" << " ( don vi K = 1000VND ) ( Co the nhap so thap phan : 0.1; 0.012 v.v ) : "; cin >> d; 
//	cout << "K";
//	cout << endl;
	
	int NgayLaiMax = ((TiLe/SoLuong)*d + d/2 - VonBatDau)/d;
	int ChuKi = 100;
	cout << "Nhap chu ki dau tu (Don vi : Ngay) ( Khuyen Nghi >= " << NgayLaiMax + NgayLaiMax/2 << " ): "; cin >> ChuKi;
//	cout << endl;
	
	float TongDauTu = 0;
	float TongKet = 0;
	
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
		
		if ( (VonBatDau + (i - 1)*d)*TiLe/SoLuong - TongDauTu >= 0) {
			cout << "     \t\t | Neu ba cang ve hom nay thi : lai = ";
	 		cout << "( " << (VonBatDau + (i - 1)*d) << "/" << SoLuong << ") x" << TiLe <<  " - " << TongDauTu << " = ";
	   		SetConsoleTextAttribute(hConsole, 10);
	  	  	if ( i == NgayLaiMax ) SetConsoleTextAttribute(hConsole, 122);
			cout << "+" << (VonBatDau + (i - 1)*d)*TiLe/SoLuong - TongDauTu << "K";
			SetConsoleTextAttribute(hConsole, 7);
		
			if ( i == NgayLaiMax ) SetConsoleTextAttribute(hConsole, 7);
			cout << endl;
		} else {
			cout << "     \t\t | Neu ba cang ve hom nay thi : lo = ";
			cout << "( " << (VonBatDau + (i - 1)*d) << "/" << SoLuong << ") x" << TiLe <<  " - " << TongDauTu << " = ";
			SetConsoleTextAttribute(hConsole, 12);
		   	if ( i == NgayLaiMax ) SetConsoleTextAttribute(hConsole, 122);
			cout  << (VonBatDau + (i - 1)*d)*TiLe/SoLuong - TongDauTu << "K";
			SetConsoleTextAttribute(hConsole, 7);
			
			if ( i == NgayLaiMax ) SetConsoleTextAttribute(hConsole, 7);
			cout << endl;
		}
			
	}
	
	return ;
}

void LoDe () {
	float TiLe = 80;
	
	
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Da chon mo hinh : lo/de" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	
	
	cout << "Nhap ti le x : "; cin >> TiLe;
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Da chon mo hinh : lo/de - Ti le x" << TiLe << endl;
	SetConsoleTextAttribute(hConsole, 7);
	
	float SoLuong = 1;
	cout << "Nhap so luong so muon danh ( default = 1 ): "; cin >> SoLuong; 
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Voi so luongg da chon = " << SoLuong << " ti le thang se = " << SoLuong << "/" << 100 << " = " << SoLuong/100 << endl;
	SetConsoleTextAttribute(hConsole, 7);
	
	float VonBatDau = 0;
	cout << "Nhap von bat dau ( don vi K = 1000VND ) ( Co the nhap so thap phan : 0.1; 0.012 v.v ): "; cin >> VonBatDau; 
//	cout << "K";
//	cout << endl;
	
	float d = 1;
	cout << "So tien tang sau moi ngay ( chia deu cho " << SoLuong << " so da danh )" << " ( don vi K = 1000VND ) ( Co the nhap so thap phan : 0.1; 0.012 v.v ) : "; cin >> d; 
//	cout << "K";
//	cout << endl;
	
	int NgayLaiMax = ((TiLe/SoLuong)*d + d/2 - VonBatDau)/(d);
	int ChuKi = 100;
	cout << "Nhap chu ki dau tu (Don vi : Ngay) ( Khuyen Nghi >= " << NgayLaiMax + NgayLaiMax/2 << " ): "; cin >> ChuKi;
//	cout << endl;
	
	float TongDauTu = 0;
	float TongKet = 0;
	
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
		
		if ( (VonBatDau + (i - 1)*d)*TiLe/SoLuong - TongDauTu >=  0) {
			cout << "     \t | Neu de ve hom nay thi : lai = ";
			cout << "( " << (VonBatDau + (i - 1)*d) << "/" << SoLuong << ") x" << TiLe <<  " - " << TongDauTu << " = ";
	 	    SetConsoleTextAttribute(hConsole, 10);
	 	   if ( i == NgayLaiMax ) SetConsoleTextAttribute(hConsole, 122);
			cout << "+" << (VonBatDau + (i - 1)*d)*TiLe/SoLuong - TongDauTu << "K";
			SetConsoleTextAttribute(hConsole, 7);
			
			if ( i == NgayLaiMax ) SetConsoleTextAttribute(hConsole, 7);
			cout << endl;
		} else {
			cout << "     \t | Neu de ve hom nay thi : lo = ";
			cout << "( " << (VonBatDau + (i - 1)*d) << "/" << SoLuong << ") x" << TiLe <<  " - " << TongDauTu << " = ";
	 	   SetConsoleTextAttribute(hConsole, 12);
	 	   if ( i == NgayLaiMax ) SetConsoleTextAttribute(hConsole, 122);
			cout << (VonBatDau + (i - 1)*d)*TiLe/SoLuong - TongDauTu << "K";
			SetConsoleTextAttribute(hConsole, 7);
			
			if ( i == NgayLaiMax ) SetConsoleTextAttribute(hConsole, 7);
			cout << endl;
		}
		
	}
	
	return ;
}

void MoHinh () {
	string pipe;
	cout << "Chon mo hinh dau tu 'Lo' - 'BaCang' : "; cin >> pipe;
	StandardizeInput(pipe);
	
	
	if 			( pipe == "lo" ) {
		LoDe();
		return;
	} else if 	( pipe == "bacang" ) {
		BaCang();
		return;
	} else {
		DisplayInvalidCommandError();
		return;
	}
}

int main () {
	
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Nhap 'n' de khoi tao mo hinh moi" << endl;
	cout << "Nhap 'dong' de thoat" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	
	while ( true ) {
		
		SetConsoleTextAttribute(hConsole, 10);
		cout << "\n" << "Chuong trinh duoc viet boi : Nguyen Hai Hung" << endl;
		SetConsoleTextAttribute(hConsole, 192);
		cout << "Luu y: du an chi mang tinh chat giai tri, khong co xuy bat ki hanh vi vi pham phap luat nao";
		SetConsoleTextAttribute(hConsole, 7);
		cout << endl;
		
		
		string input;
		cout << "\nNhap lenh: "; cin >> input;
		StandardizeInput(input);
		
		if 		( input == "n" ) MoHinh();
		else if ( input == "dong" ) return 0;
		else if ( input == "clear") system("cls");
		else 	DisplayInvalidCommandError();
			
		
		 
	}
	
	
	
	
	
	
}