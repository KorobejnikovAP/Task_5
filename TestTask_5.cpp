#include "Task_5.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream in("ProcCenter.txt");
	ProcCenter cnt(10);
	in >> cnt;
	in.close();
	ofstream out("ProcCenter.txt");
	Depozit dp();
	
	cout << "�����:" << endl <<
		"1 ����������� " << endl <<
		"2 �������� ���������� � ��������� ���������" << endl <<
		"3 ��������� ������� ��������� ��������" << endl <<
		"4 ������� �������" << endl <<
		"5 �������� ��������� ��������" << endl <<
		"6 ����� ��������" << endl <<
		"7 ������� �������" << endl <<
		"8 ��������� �����" << endl;
	bool flag = 1;
	while (flag) {
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
			dp.signin(cnt);
			break;
		case 2:
			dp.info(cnt);
			break;
		case 3:
			dp.check1(cnt);
			break;
		case 4:
			dp.opendp(cnt);
			out << cnt;
			break;
		case 5:
			dp.infodp(cnt);
			break;
		case 6:
			dp.getproc(cnt);
			break;
		case 7:
			dp.closedp(cnt);
			out << cnt;
			break;
		case 8:
			flag = 0;
			break;
		}
	}
}