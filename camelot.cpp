/*
ID: paulo.t1
PROG: camelot
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
#define local
#ifdef local
#define fin cin
#define fout cout
#endif

using namespace std;
#ifndef local
ofstream fout ("camelot.out");
ifstream fin ("camelot.in");
#endif
typedef pair<short, short> ii;

struct node {
  ii k; int d;
};

short board[30][30];
short mink[30][30][30][30];
map <ii, vector<ii> > graph;
ii king;
vector<ii> knights;

int n,m;

void make_graph() {
  for (short i = 0; i < n; i++) {
    for (short j = 0; j < m; j++) {
      if (i-2 >= 0 and j-1 >= 0) graph[make_pair(i,j)].push_back(make_pair(i-2, j-1));
      if (i-1 >= 0 and j-2 >= 0) graph[make_pair(i,j)].push_back(make_pair(i-1, j-2));
      if (i-2 >= 0 and j+1 < m) graph[make_pair(i,j)].push_back(make_pair(i-2, j+1));
      if (i-1 >= 0 and j+2 < m) graph[make_pair(i,j)].push_back(make_pair(i-1, j+2));
      if (i+2 < n and j-1 >= 0) graph[make_pair(i,j)].push_back(make_pair(i+2, j-1));
      if (i+1 < n and j-2 >= 0) graph[make_pair(i,j)].push_back(make_pair(i+1, j-2));
      if (i+2 < n and j+1 < m) graph[make_pair(i,j)].push_back(make_pair(i+2, j+1));
      if (i+1 < n and j+2 < m) graph[make_pair(i,j)].push_back(make_pair(i+1, j+2));
    }
  }
}

void bfsknight() {
  for (auto &knight : knights) {
    set<ii> visited;
    queue<node> Q;
    node n;
    n.k = knight; n.d = 0;
    Q.push(n);
    while (not Q.empty()) {
      node n = Q.front();
      Q.pop();
      visited.insert(n.k);
      mink[knight.first][knight.second][n.k.first][n.k.second] = n.d;
      for (auto &neigh : graph[n.k]) {
        if (visited.find(neigh) == visited.end()) {
          node nn; nn.k = neigh; nn.d = n.d+1;
          Q.push(nn);
        }
      }
    }
  }
}





int main() {
  fin >> n >> m;
  make_graph();

  char a, b;
  fin >> a >> b;
  king = make_pair(n-(b-'0'), (a-'A'));

  while(fin >> a >> b) knights.push_back(make_pair(n-(b-'0'), (a-'A')));

  bfsknight();

  for (auto &it : knights) {
    cout << it.first << ' ' << it.second << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cout << mink[it.first][it.second][i][j] << ' ';
      cout << endl;
    }
  }


  /*
  for (auto &it : graph) {
    cout << it.first.first << ' ' << it.first.second << ": ";
    for (auto &e : it.second) cout << e.first << ' ' << e.second << ", ";
    cout << endl;
  }
  */


  return 0;
}
