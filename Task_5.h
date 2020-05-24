#pragma once
#include <iostream>
using namespace std;

class client {
public:
	string num;
	string name;
	int  sum;
	string pass;
	bool check;
	double proc;
	int sumdp;
	int timedp;

	client();
	client(const client& c);
	client(string _num, string _name, int _sum, string _pass, double _proc, int _sumdp, int _timedp, bool _check);
	~client();
	client& operator=(const client& c);
};

class ProcCenter {
public:
	client* base;
	int kol;
	int buf;

	ProcCenter();
	ProcCenter(int count_client);
	ProcCenter(const ProcCenter& p);
	~ProcCenter();
	ProcCenter& operator=(const ProcCenter& p);
	friend ostream& operator << (ostream& out, const ProcCenter& c);
	friend istream& operator >> (istream& in, ProcCenter& c);
};

class Depozit {
public:

	int  t_i;

	Depozit();
	Depozit(int _t_i);
	Depozit(const Depozit& d);
	~Depozit();

	void signin(const ProcCenter& p);
	void info(const ProcCenter& p);
	void check1(const ProcCenter& p);
	void opendp(const ProcCenter& p);
	void infodp(const ProcCenter& p);
	void getproc(const ProcCenter& p);
	void closedp(const ProcCenter& p);
};