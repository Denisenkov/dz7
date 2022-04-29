#ifndef HHT_H
#define HHT_H
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct Goods {
	string name;
	double price;
	static int percent;
	void coutg() const;
	void cing();
};
class krug {
public:
	double r;
	krug(double i) :r(i) {
		
		cout << "constr\n";
	}
	krug() {
		r = 0; cout << "constr\n";
	}
	krug(const krug& d) {
		r= d.r;
		cout << "copy\n";
	}
	~krug() {
		cout << "destr\n";
	}
	double lokr();
	double skrug();
	double dkrug();
	void cink();
};
double opred(int, int, int*, double**);
class vkr {
public:
	double* x;
	int y;
	vkr(int j)  {
		if (j > 2) { vkr::x = new double[j]; vkr::y = j; }
		else { vkr::x = new double[3];  vkr::y = 3; }
		x = new double[y];
		for (int i = 0; i < y; i++) x[i]=0;
		cout << "constr\n";
	}
	vkr() {
		y = 3; 
		x = new double[y];
		for (int i = 0; i < y; i++) x[i] = 0;
		cout << "constr\n";
	}
	vkr(char a) {
		cout << "vvedite razmernost vektora\n";
		int j;
		cin >> j;
		cout << "vvedite vektor\n";
		if (j > 2) { vkr::x = new double[j]; vkr::y = j; }
		else { vkr::x = new double[3]; vkr::x[0] = 0; vkr::x[1] = 0; vkr::x[2] = 0; vkr::y = 3; }
		for (int i = 0; i < j; i++) cin >> vkr::x[i];
	}
	vkr(const vkr& d) {
		y = d.y;
		x = new double[y];
		for(int i = 0; i < y; i++)
		x[i] = d.x[i];
		cout << "copy\n";
	}
	~vkr() {
		delete[] x;
		cout << "destr\n";
	}
	double modv();
	void cinv();
	void del();
	void coutv();
	void invrd(int);
	double skal(vkr);
	vkr vekp(int, vkr*);
	vkr sumv(vkr);
	vkr umnv(double);
};

class comp {
	double r;
	double m;
public:
	comp(double a, double b) :r(a), m(b) {
		cout << "constr\n";
	}
	comp() {
		r = 0;
		m = 0;
		cout << "constr\n";
	}
	comp(const comp& d) {
		r = d.r;
		m = d.m;
		cout << "copy\n";
	}
	~comp() {
		cout << "destr\n";
	}
	comp operator+(const comp  a) {
		return comp(r + a.r, m + a.m);
	}
	comp operator-(const comp  a) {
		return comp(r - a.r, m - a.m);
	}
	comp operator*(const comp  a) {
		return comp(r * a.r - m * a.m, r * a.m + m * a.r);
	}
	comp operator*(double a) {
		return comp(r * a, m * a);
	}
	comp operator/(double a) {
		return comp(r / a, m / a);
	}
	comp operator/(const comp a) {
		double d;
		d = a.r * a.r + a.m * a.m;
		return comp((r * a.r + m * a.m) / d, (-r * a.m + m * a.r) / d);
	}


	friend std::istream& operator>>(std::istream& in, comp& a) {

		cout << "vvedite real i im chasti chisla z\n";
		in >> a.r;
		in >> a.m;
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, const comp& a) {
		cout << a.r << setw(6);
		if (a.m >= 0) cout << "+" << a.m << "i\n";
		if (a.m < 0) cout << a.m << "i\n";
		return out;
	}
};



#endif