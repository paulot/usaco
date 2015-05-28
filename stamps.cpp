/*
ID: paulo.t1
PROG: stamps
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <limits.h>
#define ll long long
#define max_m  2222222
#define local
#ifdef local
#define fin cin
#define fout cout
#endif

using namespace std;
int k, n;
int stamps[51];
int needed[max_m];

bool dfs(int val, int nstamps) {
  if (nstamps < 0) return false;
  if (nstamps >= 0 and val == 0) {
    needed[val] = min(k-nstamps, needed[val]);
    return true;
  }
  if (needed[val] != INT_MAX) return nstamps >= needed[val];
  if (nstamps == 0 and val > 0) return false;
  if (val < 0) return false;

  bool found = false;
  for (int i = 0; i < n; i++) {
    if (stamps[i] <= val) {
      bool c = dfs(val-stamps[i], nstamps-1);
      if (c) {
        needed[val] = min(needed[val], needed[val-stamps[i]] + 1);
        found = true;
      }
    }
  }
  return found;
}


int main() {
  fill_n(needed, max_m, INT_MAX);
  needed[0] = 0;
  needed[1] = 1;
#ifndef local
  ofstream fout ("stamps.out");
  ifstream fin ("stamps.in");
#endif
  int min_stamp = 2;
  fin >> k >> n;
  for (int i = 0; i < n; i++) {
    fin >> stamps[i];
    min_stamp = min(min_stamp, stamps[i]);
  }

  if (min_stamp > 1) {
    fout << 0 << endl;
    return 0;
  }

  int i = k+1;
  /*
  dfs(i, k);
  cout << "val " << i << " needed " << needed[i] << endl;
  */
  while (dfs(i, k)) i++;

  fout << i-1 << '\n';

  return 0;
}
