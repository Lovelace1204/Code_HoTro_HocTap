#include<iostream>

using namespace std;



int isNumber ( string s ) {
	int index = 0;
	int result = 0;
	while ( s[index] != '\0' && s[index] != '\n' && s[index] != EOF ) {
		if ( !isdigit(s[index]) ) return -1;
		result = result*10 + (s[index]-48);
		index++;
	}
	
	return result;
}

int main () {
	
}