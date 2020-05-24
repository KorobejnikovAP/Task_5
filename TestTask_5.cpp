#include "Task_5.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	setlocale(LC_CTYPE, "Russian");
	ofstream out("OutProcCenter.txt");
	ifstream in("InProcCenter.txt");
	ProcCenter cnt(10);
	in >> cnt;
	out << cnt;
	Depozit dp(-1);
	
	cout << "Опции:" << endl <<
		"1 авторизация " << endl <<
		"2 показать информацию о доступных депозитах" << endl <<
		"3 проверить наличие открытого депозита" << endl <<
		"4 открыть депозит" << endl <<
		"5 показать состояние депозита" << endl <<
		"6 снять проценты" << endl <<
		"7 закрыть депозит" << endl <<
		"8 закончить сеанс" << endl;
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
			break;
		case 5:
			dp.infodp(cnt);
			break;
		case 6:
			dp.getproc(cnt);
			break;
		case 7:
			dp.closedp(cnt);
			break;
		case 8:
			flag = 0;
			break;
		}
	}
}