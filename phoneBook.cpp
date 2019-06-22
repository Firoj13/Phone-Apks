#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
using namespace std;

//int conId = 1000;
string conName, conMobile[3], conEmail;

void addContact() {
	
	ofstream fout;
	fout.open("phoneBook.txt", ios::app);
	//:value_seprator
	//-contact_seprator
	fout << conName << ":" << conEmail << ":" << conMobile[0] << ":" << conMobile[1] << ":" << conMobile[2] << ":-";
	fout.close();
	
}

void viewContact(string name) {
	
	ifstream fin;
	fin.open("phoneBook.txt");
	string fileData;
	getline(fin, fileData);
	fin.close();

	int foundAt = -1, values = 0;
	
	for(int i=0; i<fileData.length(); i++) {
		if(fileData[i] == name[0]) {
			for(int j=0; j<name.length(); j++) {
				
				if(fileData[i+j] == name[j]) {
					if(j == name.length()-1) {
						foundAt = i;
					}
				}
				else {
					break;
				}
				if(foundAt >= 0) {
					break;
				}
			}
		}
	}
	
	if(foundAt >= 0) {
		cout << "\nName: ";
		for(int i=foundAt; i<fileData.length(); i++) {
			
			if(fileData[i] == ':') {
				values++;
				if(values==1) { //Printing Email
					cout << "\nEmail: ";
				}
				else if(values==2) { //Printing Mobile 1
					cout << "\nMobile No.: ";
				}
				else if(values==3) { //Printing Mobile 2
					if(fileData[i+1] == '0') {
						break;
					}
					cout << "\nMobile No. 2: ";
				}
				else if(values==4) { //Printing Mobile 3
				if(fileData[i+1] == '0') {
						break;
					}
					cout << "\nMobile No. 3: ";
				}
				else {
					break;
				}
				continue;
			}
			
			cout << fileData[i];
			
		}
		cout << "\n\n";
	}
	else {
		cout << "\nSorry No Record Available for " << name << "\n";
	}
	
}

void viewContact(string number, int x) {
	
	ifstream fin;
	fin.open("phoneBook.txt");
	string fileData;
	getline(fin, fileData);
	fin.close();

	int foundAt = -1, term = 0, values = 0;
	
	for(int i=0; i<fileData.length(); i++) {
		
		if(fileData[i] == ':') {
			term++;
			if(term == 5) {
				term = 0;
			}
			continue;
		}
		
		if(fileData[i] == number[0]) {
			for(int j=0; j<number.length(); j++) {
				if(fileData[i+j] == number[j]) {
					if(j == (number.length()-1)) {
						foundAt = i;
						break;
					}
				}
				else {
					break;
				}
			}
		}
		
		if(foundAt >= 0) {
			break;
		}		
		
	}
	
	if(foundAt >= 0) {
		
		int fIndex;
		
		for(int i=foundAt; i>=0; i--) {
			if(fileData[i] == ':') {
				term--;
				if(term == 0) {
					fIndex = i;
					break;
				}
			}
			
		}
		while(fileData[fIndex] != '-') {
			fIndex--;
		}
		fIndex++;
		
		cout << "\nName: ";
		for(int i=fIndex; i<fileData.length(); i++) {
			
			if(fileData[i] == ':') {
				values++;
				if(values==1) { //Printing Email
					cout << "\nEmail: ";
				}
				else if(values==2) { //Printing Mobile 1
					cout << "\nMobile No.: ";
				}
				else if(values==3) { //Printing Mobile 2
					if(fileData[i+1] == '0') {
						break;
					}
					cout << "\nMobile No. 2: ";
				}
				else if(values==4) { //Printing Mobile 3
				if(fileData[i+1] == '0') {
						break;
					}
					cout << "\nMobile No. 3: ";
				}
				else {
					break;
				}
				continue;
			}
			
			cout << fileData[i];
			
		}
		cout << "\n\n";
	}
	else {
		cout << "\nSorry No Record Available for " << number << "\n";
	}
	
}

void viewDirectory() {
	
	ifstream fin;
	fin.open("phoneBook.txt");
	string fileData;
	getline(fin, fileData);
	fin.close();

	int values = 0;
	
	cout << "Name\tEmail\t\tMobile No.1\tMobile No.2\t Mobile No.3\n";
	cout << "-----------------------------------------------------------------------\n";
	
	for(int i=0; i<fileData.length(); i++) {
		if(fileData[i] == ':') {
			values++;
			if(values == 5) {
				values = 0;
				i++;
				cout << "\n-----------------------------------------------------------------------\n";
			}
			else {
				cout << "\t";				
			}
			continue;
		}
		cout << fileData[i];
		if(values == 3 || values == 4) {
			if(fileData[i] == '0') {
				cout << "\t";
			}
		}
	
	
	}
}

int main() {
	int o;
	int conID;
	char t;
	string zero = "0";
	string findName, findNumber;
	
	while(o != 4) {
		system("cls");
		cout << "PhoneBook - Main Menu\n";
		cout << "---------------------------\n";
		cout << "1 - Add Contact\n";
		cout << "2 - Search Contact\n";
		cout << "3 - View Directory\n";
		cout << "4 - Exit\n";
		cout << "\nEnter Option No.: ";
		cin >> o;
		cout << "\n";
		switch(o) {
			case 1: {
				conMobile[1] = zero;
				conMobile[2] = zero;
				cout << "Add New Contact\n";
				cout << "---------------------------\n";
				cout << "Enter Contact Name: ";
				cin >> conName;
				cout << "Enter Contact Email: ";
				cin >> conEmail;
				for(int i=0; i<3; i++) {
					cout << "Enter Mobile No. " << i << " [0 if not]: ";
					cin >> conMobile[i];
					if(i==0 && !conMobile[i].compare(zero)) {
						cout << "\nPlease Enter atleast 1 Mobile No.!\n";
						i = -1;
					}
					else if(!conMobile[i].compare(zero)) {
						break;
					}
				}
				addContact();
				cout << "\nNew Contact Saved!\n";
				system("pause");
				break;
			}
			case 2: {
				int sOpt;
				cout << "Search Contact\n";
				cout << "---------------------------\n";
				cout << "1 - Search by Contact Name\n";
				cout << "2 - Search by Contact Number\n";
				cout << "3 - Main Menu\n";
				cout << "Enter Option No.: ";
				cin >> sOpt;
				switch(sOpt) {
					case 1: {
						cout << "Enter Name to Find Record: ";
						cin >> findName;
						viewContact(findName);
						system("pause");
						break;
					}
					case 2: {
						cout << "Enter Number to Find Record: ";
						cin >> findNumber;
						viewContact(findNumber, 1);
						system("pause");
						break;
					}
					case 3: {
						break;
					}
					default: {
						break;
					}
				}			
				break;
			}
			case 3: {
				viewDirectory();
				cout << "\n\n";
				system("pause");
				break;
			}
			case 4: {
				system("exit");
				break;
			}
			default: {
				cout << "\nPlease Enter Valid Option!\n";
				system("pause");
				cout << "\n\n";
				break;
			}
		}
	}
}
