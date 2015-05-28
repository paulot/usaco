/*
ID: paulo.t1
PROG: skidesign
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#define ll long long
#define square(x) ((x)*(x))
#define thresh 17

#ifdef local
#define fin cin
#define fout cout
#endif

using namespace std;

int n;
int hills[1001];

int main() {
#ifndef local
  ofstream fout ("skidesign.out");
  ifstream fin ("skidesign.in");
#endif

  fin >> n;
  for (int i = 0; i < n; i++)
    fin >> hills[i];

  ll smallest = 100000000000;
  for (int i = 0; i <= 100-17; i++) {
    int j = i+17;
    ll ans = 0;
    for (int h = 0; h < n; h++) {
      if (hills[h] <= j and hills[h] >= i)
        continue;
      int diff = min(abs(hills[h]-i), abs(hills[h]-j));
      ans += square(diff);
    }
    smallest = min(smallest, ans);
  }

  fout << smallest << endl;

  return 0;
}
