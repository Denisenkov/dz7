#include "hht.h"

void Goods::coutg() const {

	cout << "\nName - " << Goods::name;
	cout << "Price - " << long(Goods::price * (1.0 + Goods::percent / 100.0));

}
void Goods::cing() {
	cout << "\nEnter name ";
	cin >> Goods::name;
	cout << "\nEnter price ";
	cin >> Goods::price;
}
double krug::lokr() {
	return 2 * 3.14 * r;
}
double krug::skrug() {
	return  3.14 * r * r;
}
double krug::dkrug() {
	return  2 * r;
}
void krug::cink() {
	cout << "\nEnter R ";
	cin >> krug::r;
}
double vkr::modv() {
	double s = 0;
	for (int i = 0; i < y; i++) {
		s = s + pow(x[i], 2);
	}
	return sqrt(s);
}
void vkr::del() {
	delete[] x;

}

void vkr::cinv() {
	cout << "vvedite vektor\n";
	
	for (int i = 0; i < y; i++) cin >> vkr::x[i];
}
void vkr::coutv() {


	for (int i = 0; i < vkr::y; i++) cout << vkr::x[i] << setw(6);
	cout << "\n";
}
void vkr::invrd(int i) {
	
	if (i > 2) { vkr::x = new double[i]; vkr::y = i; }
	else { vkr::x = new double[3];  vkr::y = 3; }
	x = new double[y];
	
	for (int i = 0; i < y; i++) vkr::x[i] = rand() % 5;
}
double vkr::skal(vkr p) {
	double s = 0;
	for (int i = 0; i < y; i++) {
		s = s + x[i] * (p.x[i]);
	}
	return s;
}
double opred(int a, int y, int* c, double** b) {
	double s = 0;
	int q = 0, n = 0;
	if (a >= y - 2) {
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < y - 1; j++) {
				if (c[j] == i) q = 1;
			}
			if (q == 0) return b[a][i];
			q = 0;
		}
	}
	else {
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < a + 1; j++) {
				if (c[j] == i) { q = 1; }


			}

			if (q == 0) {
				n = n + 1;
				c[a + 1] = i;
				s = s + b[a][i] * pow(-1, 1 + n) * opred(a + 1, y, c, b);
				c[a + 1] = -1;
			}
			q = 0;
		}

		return s;
	}
}
vkr vkr::vekp(int y, vkr* t) {
	double** b = new double* [y - 1];
	int* c = new int[y];
	for (int i = 0; i < y - 1; i++) {
		b[i] = new double[y];
	}
	for (int i = 0; i < y - 1; i++) {
		for (int j = 0; j < y; j++) {
			b[i][j] = t[i].x[j];
			c[j] = -1;

		}
	}
	vkr p(y);
	

	for (int j = 0; j < y; j++) {
		c[0] = j;
		p.x[j] = pow(-1, j + 2) * opred(0, y, c, b);
		c[0] = -1;
	}
	for (int i = 0; i < y - 1; i++) {
		delete[] b[i];
	}
	delete[] c;

	return p;
}
vkr vkr::sumv(vkr t) {
	vkr p(y);
	for (int i = 0; i < y; i++) {
		p.x[i] = x[i] + t.x[i];
	}
	return p;
}
vkr vkr::umnv(double a) {
	vkr p(y);
	for (int i = 0; i < y; i++) {
		p.x[i] = x[i] * a;
	}
	return p;
}
