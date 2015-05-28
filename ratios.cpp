/*
ID: paulo.t1
PROG: ratios
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <limits.h>
#ifdef local
#define fin cin
#define fout cout
#endif

using namespace std;

int a[4], b[4], c[4];

int get_n(int A, int B, int C) {
  int n[3], s[3], g[3] = { a[0],b[0],c[0] };
  s[0] = A*a[1]+B*a[2]+C*a[3];
  s[1] = A*b[1]+B*b[2]+C*b[3];
  s[2] = A*c[1]+B*c[2]+C*c[3];
  // cout << ta << ' ' << tb << ' ' << tc << endl;
  int comp = 0;
  for (int i = 0; i < 3; i++) {
    // cout << s[i] << ' ';
    if (g[i] == 0)
      if (s[i] != 0) return -1;
      else n[i] = 0;
    else if (s[i] == 0) return -1;
    else { n[i] = s[i] / g[i]; comp = n[i]; }
  }
  // cout << endl;


  for (int i = 0; i < 3; i++)
    if (n[i] != 0 and n[i] != comp) return -1;

  for (int i = 0; i < 3; i++)
    if (n[i] * g[i] != s[i]) return -1;
  

  return n[0];
}

bool is_valid(int A, int B, int C) {
  int n = get_n(A,B,C);
  if (n == -1) return false;
  return true;
}

int main() {
#ifndef local
  ofstream fout ("ratios.out");
  ifstream fin ("ratios.in");
#endif

  for (int i = 0; i < 4; i++)
    fin >> a[i] >> b[i] >> c[i];

  // cout << get_n(0,1,0) << endl;
  int fa = -1, fb, fc, n, m = INT_MAX;
  for (int A = 0; A <= 100; A++) {
    for (int B = 0; B <= 100; B++) {
      for (int C = 0; C <= 100; C++) {
        if (is_valid(A, B, C) and A+B+C < m) {
          m = A+B+C;
          n = get_n(A,B,C);
          fa = A, fb = B, fc = C;
        }
      }
    }
  }

  if (fa != -1)
    fout << fa << ' ' << fb << ' ' << fc << ' ' << n << endl;
  else
    fout << "NONE" << endl;

  return 0;
}
