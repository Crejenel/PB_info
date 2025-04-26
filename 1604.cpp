#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

ifstream fin("dmin.in");
ofstream out("dmin.out");

int nr_noduri;
int nr_muchii;
int matrice[101][101];


int DrumMinim(int start, int final) {

	int distante[101]{ 0 };
	queue<int> coada;
	distante[start] = 1;
	coada.push(start);
	while(!coada.empty()) {

		int nod = coada.front();
		coada.pop();

		for (int i = 1; i <= nr_noduri; i++) {

			if (matrice[nod][i] == 1 && distante[i] == 0) {
				coada.push(i);
				distante[i] = distante[nod] + 1;
			}
		}
	}
	
	if (distante[final] == 0) {
		return -1;
	}
	else {
		return distante[final] - 1;
	}

}

int main() {

	fin >> nr_noduri;
	fin >> nr_muchii;

	for (int i = 1,x,y; i <= nr_muchii; i++) {

		fin >> x >> y;
		matrice[x][y] = matrice[y][x] = 1;
	
	}

	int k;
	fin >> k;
	for (int i = 1, x, y; i <= k; i++) {

		fin >> x >> y;
		out << DrumMinim(x, y);
		out << endl;
	}
	
	return 0;
}

