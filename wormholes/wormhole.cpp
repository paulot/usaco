/*
ID: paulo.t1
PROG: wormhole
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#define N 12

#ifdef local
#define fin cin
#define fout cout
#endif

using namespace std;

int X[N+1], Y[N+1], pairs[N+1], nextx[N+1];
int ans = 0;
int n;

bool has_cicles() {
  for (int i = 1; i <= n; i++) {
    int cworm = i;
    for (int j = 1; j <= n; j++) {
      cworm = nextx[cworm];
      cworm = pairs[cworm];
    }
    if (cworm != 0) {
      /*
      for (int i = 1; i <= n; i++) {
        fout << i << ':' << pairs[i] << ' ';
      }
      cout << endl;
      */
      return true;
    }
  }
  return false;
}

int next_free() {
  for (int i = 1; i <= n; i++) {
    if (pairs[i] == 0)
      return i;
  }
  return -1;
}


void dfs() {
  int cfree = next_free();
  if (cfree == -1) {
    if (has_cicles())
      ans++;
    return;
  }

  // For each unpaired, make a pair
  for (int i = cfree+1; i <= n; i++) {
    if (pairs[i] != 0)
      continue;
    pairs[i] = cfree;
    pairs[cfree] = i;
    dfs();
    pairs[cfree] = pairs[i] = 0;
  }
}



int main() {
#ifndef local
  ofstream fout ("wormhole.out");
  ifstream fin ("wormhole.in");
#endif
  fin >> n;
  for (int i = 1; i <= n; i++) {
    fin >> X[i] >> Y[i];
  }

  // Initialize nextx array
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (Y[i] == Y[j] and X[j] > X[i])
        if (nextx[i] == 0 or X[j] - X[i] < X[nextx[i]] - X[i])
          nextx[i] = j;
    }
  }

  dfs();

  fout << ans << endl;

  return 0;
}
