/*
ID: paulo.t1
PROG: fence
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>
#define ll long long
#ifdef local
#define fin cin
#define fout cout
#endif

using namespace std;

#ifndef local
ofstream fout ("fence.out");
ifstream fin ("fence.in");
#endif

int n;
map<int, vector<int> > graph;
stack<int> ans;
int deg[2000];

void print() {
  cout << endl;
  for (auto &i : graph) {
    cout << i.first << ": ";
    for (auto &j : i.second)
      cout << j << ' ';
    cout << endl;
  }
}

void tour(int s) {
  if (graph[s].size() == 0) {
    ans.push(s); return;
  }
  while (graph[s].size() > 0) {
    auto it = min_element(graph[s].begin(),graph[s].end());
    int val = *it;
    graph[s].erase(it);
    graph[val].erase(find(graph[val].begin(),graph[val].end(), s));
    tour(val);
  }
  ans.push(s);
}

int main() {
  fin >> n;
  int first = 5000;
  for (int i = 0; i < n; i++) {
    int a, b; fin >> a >> b;
    first = min(first, a);
    first = min(first, b);
    graph[a].push_back(b); graph[b].push_back(a);
    deg[a]++, deg[b]++;
  }

  for (auto &it : graph) {
    sort(it.second.begin(), it.second.end());
  }

  int f = 1;
  for(; f < 501; f++) if (deg[f] % 2) { break; }
  if (f == 501) tour(first);
  else tour(f);

  while (not ans.empty()) {
    fout << ans.top() << '\n';
    ans.pop();
  }

  return 0;
}
