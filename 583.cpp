#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int NMAX = 101;
vector<int> graf[NMAX], graf_transpus[NMAX];
stack<int> stiva;
bool vizitat[NMAX];
int n, m, nr;

void DFS(int nod) {
  
    vizitat[nod] = true;
    for (int vecin : graf[nod]) {
        if (!vizitat[vecin]) {
            DFS(vecin);
        }
    }
    stiva.push(nod);
}

void DFS_transpus(int nod) {
  
    vizitat[nod] = false; 
    for (int vecin : graf_transpus[nod]) {
        if (vizitat[vecin]) {
            DFS_transpus(vecin);
        }
    }
}

int main() {
  
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        graf[x].push_back(y);
        graf_transpus[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (!vizitat[i]) {
            DFS(i);
        }
    }

    while (!stiva.empty()) {
        int nod = stiva.top();
        stiva.pop();
        if (vizitat[nod]) {
            DFS_transpus(nod);
            nr++;
        }
    }

    cout << nr << endl;
    return 0;
}
