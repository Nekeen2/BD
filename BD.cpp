#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
class Head{
private:
	const int line = 20;
	ofstream fout;
	fstream fin;
	int n=1, m=3;
	string s,s1;
public:
	Head() {
		fout.open("Headf.txt");
		s = "Id";
		fout << s;
		for (int k = s.size(); k < line; k++) {
			fout << " ";
		}
		s = "Name";
		fout << s;
		for (int k = s.size(); k < line; k++) {
			fout << " ";
		}
		s = "Surname";
		fout << s;
		for (int k = s.size(); k < line; k++) {
			fout << " ";
		}
		fout << "\n";
		fout.close();
	}
	void addLine() {
		fout.open("Headf.txt", ofstream::app);
		fin.open("Headf.txt");
		getline(fin, s1);
		for (int i = 0; i < m; i++) {
		cout << "Print ";
		for (int j = i * 20; j < (i+1)*20; j++) {
			cout << s1[j];
		}
		cout << endl;
		cin >> s;
		fout << s;
			for (int k = s.size(); k < line; k++) {
				fout << " ";
			}
		}
		fout << "\n";
		n++;
		fout.close();
		cout << "Line add" << endl;
	}
	void deleteLine() {
		fin.open("Headf.txt");
		fout.open("tmp.txt", ofstream::app);
		cout << "Print number of the line to be deleted" << endl;
		int a,counter=0;
		cin >> a;
		while(fin.eof()) {
			getline(fin, s);
			if (counter != a) {
				fout << s;
			}
			counter++;
		}
		fin.close();
		fout.close();
		remove("Headf.txt");
		rename("tmp.txt", "Headf.txt");
		cout << "Line delited" << endl;
		n--;
	}
	void addColumn(string s1) {
		fin.open("Headf.txt");
		fout.open("tmp.txt", ofstream::app);
		int counter = 1;
		getline(fin, s);
		fout << s << s1;
		for (int k = s.size(); k < line; k++) {
			fout << " ";
		}
		fout << "\n";
		while (fin.eof()) {
			getline(fin, s);
			cout << "Print for " << counter << "person";
			cin >> s1;
			fout << s << s1;
			for (int k = s.size(); k < line; k++) {
				fout << " ";
			}
			fout << "\n";
			counter++;
		}
		fin.close();
		fout.close();
		remove("Headf.txt");
		rename("tmp.txt", "Headf.txt");
		cout << "Column add" << endl;
		m++;
	}
	void deleteColumn() {
		fin.open("Headf.txt");
		fout.open("tmp.txt", ofstream::app);
		cout << "Print number of the column to be deleted" << endl;
		int a;
		cin >> a;
		while (fin.eof()) {
			getline(fin, s);
			s.erase((a-1)*20,a*20);
			fout << s;
		}
		fin.close();
		fout.close();
		remove("Headf.txt");
		rename("tmp.txt", "Headf.txt");
		cout << "Column delited" << endl;
		m--;
	}
	void printInfo() {
		cout << ifstream("Headf.txt").rdbuf();
	}
};
int main()
{
	setlocale(LC_ALL, "rus");
	int flag;
	string s;
	Head h;
	cout << "Press 1 to add line" << endl <<"Press 2 to add column" << endl << "Press 3 to print info" << endl << "Press 4 to delete line" << endl << "Press 5 to delete column" << endl << "Press 0 to stop program" << endl;
	cin >> flag;
	while (flag != 0) {
		if (flag == 1) {
			h.addLine();
		}
		if (flag == 2) {
			cout << "Print name of column" << endl;
			cin >> s;
			h.addColumn(s);
		}
		if (flag == 3) {
			h.printInfo();
		}
		if (flag == 4) {
			h.deleteLine();
		}
		if (flag == 5) {
			h.deleteColumn();
		}
		cin >> flag;
	}
}