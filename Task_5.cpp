#include "Task_5.h"
#include <iostream>

client::client() {
	num = "";
	name = "";
	sum = 0;
	pass = "";
	proc = 0;
	sumdp = 0;
	timedp = 0;
	check = 0;
}
client::client(string _num, string _name, int _sum, string _pass, double _proc, int _sumdp, int _timedp, bool _check) {
	num = _num;
	name = _name;
	sum = _sum;
	pass = _pass;
	proc = _proc;
	sumdp = _sumdp;
	timedp = _timedp;
	check = _check;
}
client::client(const client& c) {
	num = c.num;
	name = c.name;
	sum = c.sum;
	pass = c.pass;
	proc = c.proc;
	sumdp = c.sumdp;
	timedp = c.timedp;
	check = c.check;
}
client::~client() {
	num = "";
	name = "";
	sum = 0;
	pass = "";
	proc = 0;
	sumdp = 0;
	timedp = 0;
	check = 0;
}

client& client::operator=(const client& c) {
	num = c.num;
	name = c.name;
	sum = c.sum;
	pass = c.pass;
	proc = c.proc;
	sumdp = c.sumdp;
	timedp = c.timedp;
	check = c.check;
	return *this;
}

ProcCenter::ProcCenter() {
	base = 0;
	kol = 0;
	buf = 0;
}
ProcCenter::ProcCenter(int count_client) {
	kol = 0;
	buf = count_client;
	base = new client[buf];
	for (int i = 0; i < buf; ++i)
		base[i] = client();
}
ProcCenter::ProcCenter(const ProcCenter& p) {
	buf = p.buf;
	kol = p.kol;
	base = new client[kol];
	for (int i = 0; i < kol; ++i)
		base[i] = p.base[i];
}
ProcCenter::~ProcCenter() {
	delete[] base;
	kol = 0;
	buf = 0;
}

ProcCenter& ProcCenter::operator=(const ProcCenter& p) {
	buf = p.buf;
	kol = p.kol;
	for (int i = 0; i < kol; ++i) {
		base[i] = p.base[i];
	}
	return *this;
}

ostream& operator << (ostream& out, const ProcCenter& c) {
	out << c.kol << endl;
	for (int i = 0; i < c.kol; ++i)
		out << c.base[i].name << " " << c.base[i].num << " " << c.base[i].pass << " " << c.base[i].sum << " "
		<< " " << c.base[i].check << " " << c.base[i].sumdp << " " << c.base[i].proc << " " << c.base[i].timedp << endl;
	return out;
}

istream& operator >> (istream& in, ProcCenter& c) {
	int count ;
	in >> count ;
	if (count > c.buf) {
		c.kol = count;
		c.buf = count;
		delete[] c.base;
		c.base = new client[c.buf];
		for (int i = 0; i < c.buf; ++i)
			c.base[i] = client();
	}
	else {
		c.kol = count;
	}
	for (int i = 0; i < c.kol; ++i)
		in >> c.base[i].name >> c.base[i].num >> c.base[i].pass >> c.base[i].sum
		>> c.base[i].check >> c.base[i].sumdp >> c.base[i].proc >> c.base[i].timedp;
	return in;
}

Depozit::Depozit() {
	t_i = -1;
}
Depozit::Depozit(const Depozit& d) {
	t_i = d.t_i;
}
Depozit::Depozit(int _t_i) {
	t_i = _t_i;
}
Depozit::~Depozit() {
	t_i = 0;
}

void Depozit::signin(const ProcCenter& p) {
	int f = 0;
	string _num, _pass;
	cout << "Введите номер карты и пароль" << endl;
	cout << "Номер карты: ";
	cin >> _num;
	cout << "Введите пароль: ";
	cin >> _pass;
	for (int i = 0; i < p.kol; ++i) {
		if (p.base[i].num == _num && p.base[i].pass == _pass) {
			t_i = i;
			f = 1;
			cout << "Здравствуйте " << p.base[t_i].name << endl;
			break;
		}
	}
	if (f == 0)
		cout << "Данные введены неверно !" << endl;
}

void Depozit::info(const ProcCenter& p) {
	if ((t_i != -1) && (p.base[t_i].check == 0)) {
		if (p.base[t_i].sum <= 100000)
			cout << "Вы можете открыть депозит на сумму до 100000 руб. под 5% годовых" << endl
			<< "Возможные сроки депозита:" << endl
			<< "3 месяца" << endl
			<< "6 месяцев" << endl
			<< "1 год" << endl
			<< "2 года" << endl
			<< "3 года" << endl;
		if (p.base[t_i].sum > 100000 && p.base[t_i].sum <= 500000)
			cout << "Вы можете" << endl << "1) открыть депозит на сумму до 100000 руб. под 5%" << endl
			<< "2) открыть депозит на сумму от 100000 до 500000 руб. под 5.5 % годовых" << endl
			<< "Возможные сроки депозита:" << endl
			<< "3 месяца" << endl
			<< "6 месяцев" << endl
			<< "1 год" << endl
			<< "2 года" << endl
			<< "3 года" << endl;
		if (p.base[t_i].sum > 500000 && p.base[t_i].sum <= 1000000)
			cout << "Вы можете" << endl << "1) открыть депозит на сумму до 100000 руб. под 5%" << endl
			<< "2) открыть депозит на сумму от 100000 до 500000 руб. под 5.5 % годовых" << endl
			<< "3) открыть депозит на сумму от 500000 до 1000000 руб. под 6 % годовых" << endl
			<< "Возможные сроки депозита:" << endl
			<< "3 месяца" << endl
			<< "6 месяцев" << endl
			<< "1 год" << endl
			<< "2 года" << endl
			<< "3 года" << endl;
		if (p.base[t_i].sum > 1000000)
			cout << "Вы можете" << endl << "1) открыть депозит на сумму до 100000 руб. под 5%" << endl
			<< "2) открыть депозит на сумму от 100000 до 500000 руб. под 5.5 % годовых" << endl
			<< "3) открыть депозит на сумму от 500000 до 1000000 руб. под 6 % годовых" << endl
			<< "4) открыть депозит на сумму свыше 1000000 руб. под 7 % годовых" << endl
			<< "Возможные сроки депозита:" << endl
			<< "3 месяца" << endl
			<< "6 месяцев" << endl
			<< "1 год" << endl
			<< "2 года" << endl
			<< "3 года" << endl;
	}
	else {
		cout << "У вас уже есть открытый депозит !" << endl;
	}
}

void Depozit::check1(const ProcCenter& p) {
	if (p.base[t_i].check == 1)
		cout << "У вас есть открытый депозит !" << endl;
	else cout << "У вас нет открытого депозита !" << endl;
}

void Depozit::opendp(const ProcCenter& p) {
	int _sumdp, _timedp;
	if (p.base[t_i].check == 0) {
		cout << "Введите сумму депозита: ";
		cin >> _sumdp;
		cout << "Введите срок депозита: ";
		cin >> _timedp;
		if (_sumdp <= p.base[t_i].sum && (_timedp == 3 || _timedp == 6 || _timedp == 12 || _timedp == 24 || _timedp == 36)) {
			p.base[t_i].check = 1;
			p.base[t_i].sumdp = _sumdp;
			p.base[t_i].timedp = _timedp;
			if (_sumdp <= 100000)
				p.base[t_i].proc = 5;
			if (_sumdp > 100000 && _sumdp <= 500000)
				p.base[t_i].proc = 5.5;
			if (_sumdp > 500000 && _sumdp <= 1000000)
				p.base[t_i].proc = 6;
			if (_sumdp > 1000000)
				p.base[t_i].proc = 7;
			cout << "Вы открыли депозит суммой " << _sumdp << " на срок " << _timedp << " месяц(а/ев)." << endl;
		}
		else
			if (_sumdp > p.base[t_i].sum)
				cout << "У вас недостаточно средств, чтобы открыть депозит такой суммы !" << endl;
			else cout << "Невозможно открыть депозит на данный срок !" << endl;
	}
	else cout << "У вас уже есть открытый депозит !" << endl;
}

void Depozit::infodp(const ProcCenter& p) {
	if (p.base[t_i].check == 1)
		cout << "У вас открыт депозит на сумму: " << p.base[t_i].sumdp << " ; под " << p.base[t_i].proc << " % годовых, сроком на "
		<< p.base[t_i].timedp << " месяц(а/ев)" << endl;
	else cout << "У вас нет открытого депозита !" << endl;
}

void Depozit::getproc(const ProcCenter& p) {
	if (p.base[t_i].check == 0)
		cout << " У вас нет открытого депозита !" << endl;
	else {
		p.base[t_i].sum += p.base[t_i].proc / 100 * p.base[t_i].sumdp;
		cout << "Проценты переведены на ваш счет !" << endl;
	}
}

void Depozit::closedp(const ProcCenter& p) {
	if (p.base[t_i].check == 0)
		cout << "У вас нет открытого депозита !" << endl;
	else {
		p.base[t_i].check = 0;
		p.base[t_i].sum += p.base[t_i].sumdp;
		p.base[t_i].sumdp = 0;
		p.base[t_i].proc = 0;
		p.base[t_i].timedp = 0;
		cout << "Ваш депозит закрыт, все деньги переведены на ваш счет !" << endl;
	}
}