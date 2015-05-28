/*
ID: paulo.t1
PROG: agrinet
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#define ll long long
#ifdef local
#define fin cin
#define fout cout
#endif

using namespace std;

int graph[101][101];
set<int> selected;

int main() {
#ifndef local
  ofstream fout ("agrinet.out");
  ifstream fin ("agrinet.in");
#endif
  int n;
  fin >> n;
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      fin >> graph[i][j];

  // Do kruskal-ish algorithm
  ll ans = 0;
  selected.insert(0);
  while (selected.size() < n) {
    int mi, m = 999999999;
    for (auto &it : selected) {
      for (int i=0; i<n; i++) {
        if (i != it and selected.find(i) == selected.end()) {
          if (graph[it][i] < m) {
            m = graph[it][i];
            mi = i;
          }
        }
      }
    }
    selected.insert(mi);
    ans += m;
  }

  fout << ans << '\n';

  return 0;
}
