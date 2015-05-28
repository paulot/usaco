/*
ID: paulo.t1
PROG: butter
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <limits.h>
#define ll long long
#ifdef local
#define fin cin
#define fout cout
#endif

using namespace std;
typedef pair<int,int> ii;


map <int, int> occupied;
map <int, vector<ii> > graph;
unsigned int dist[801];
int n, p, c;

void dijkstra(int source) {
  for (int i = 1; i <= p; i++) dist[i] = INT_MAX;
  set<ii> Q;
  dist[source] = 0;
  Q.insert(ii(0, source));

  while (not Q.empty()) {
    ii top = *Q.begin();
    Q.erase(Q.begin());
    int v = top.second;
    int d = top.first;

    for (auto &it : graph[v]) {
      int v2 = it.first;
      int cost = it.second;
      if (dist[v2] > dist[v] + cost) {
        if (dist[v2] != INT_MAX) {
          Q.erase(Q.find(ii(dist[v2], v2)));
        }
        dist[v2] = dist[v] + cost;
        Q.insert(ii(dist[v2], v2));
      }
    }
  }
}

int main() {
#ifndef local
  ofstream fout ("butter.out");
  ifstream fin ("butter.in");
#endif
  fin >> n >> p >> c;
  for (int i = 0; i < n; i++) {
    int pp;
    fin >> pp;
    occupied[pp]++;
  }
  for (int i = 0; i < c; i++) {
    int v1, v2, d;
    fin >> v1 >> v2 >> d;
    graph[v1].push_back(ii(v2, d));
    graph[v2].push_back(ii(v1, d));
  }

  ll ans = UINT_MAX;
  for (int i = 1; i <= p; i++) {
    dijkstra(i);
    ll csum = 0;
    for (auto &it : occupied) {
      csum += dist[it.first] * it.second;
    }
    ans = min(csum, ans);
  }

  fout << ans << endl;
      
  return 0;
}
