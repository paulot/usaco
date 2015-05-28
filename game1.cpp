/*
ID: paulo.t1
PROG: game1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#define ll long long
#define uint unsigned int
#ifdef local
#define fin cin
#define fout cout
#endif

using namespace std;
typedef pair<int, int> ii;

int n;
int arr[200];
map<ii, int> dp;

int dfs(int s, int e, bool take) {
  // cout << s << ' ' << e << endl;
  ii p = make_pair(s, e);

  
  if (take and dp.find(p) != dp.end()) {
    return dp[p];
  } else if (s == e) {
    dp[p] = arr[s];
    return (take) ? arr[s] : 0;
  } else if (e - s == 1) {
    dp[p] = max(arr[s], arr[e]);
    return (take) ? max(arr[s], arr[e]) : min(arr[s], arr[e]);
  }

  // Either take s or take e
  if (take) {
    int ts = arr[s] + dfs(s+1, e, false);
    int te = arr[e] + dfs(s, e-1, false);
    dp[p] = max(ts, te);
    return max(ts, te);
  } else {
    int ts = dfs(s+1, e, true);
    int te = dfs(s, e-1, true);
    return  min(ts, te);
  }
}

int main() {
#ifndef local
  ofstream fout ("game1.out");
  ifstream fin ("game1.in");
#endif
  fin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    fin >> arr[i]; sum += arr[i];
  }

  int f = dfs(0, n-1, true);
  int s = sum - f;
  fout << f << ' ' << s << endl;

  /*
  cout << endl;
  for (auto &it : dp) {
    cout << get<0>(it.first) << ' ' << get<1>(it.first) << ": " <<
         it.second << endl;
  }
  */

  return 0;
}
