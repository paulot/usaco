/*
ID: paulo.t1
PROG: range
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#define ll long long
#ifdef local
#define fin cin
#define fout cout
#endif

using namespace std;
#ifndef local
ofstream fout ("range.out");
ifstream fin ("range.in");
#endif

bool area[251][251];
int hsum[251][251], vsum[251][251];
int n, dps;

int sum(int col, int row, int s) {
  int r = 0;
  for (int i = 0; i < s; i++)
    r += hsum[col++][row];
  return r;
}

void make_sums(int s) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < dps-1; j++)
      hsum[i][j] += area[i][j+(s-1)];

  for (int i = 0; i < dps-1; i++)
    for (int j = 0; j < dps; j++)
      vsum[i][j] = sum(i, j, s);

  dps--;
}

int main() {
  fin >> n;
  dps = n;
  for (int i = 0; i < n; i++) {
    string s;
    fin >> s;
    for (int j = 0; j < n; j++) {
      area[i][j] = s[j] - '0';
      hsum[i][j] = area[i][j];
      vsum[i][j] = hsum[i][j];
    }
  }

  for (int s = 2; s <= n; s++) {
    int area = s*s, count = 0;
    make_sums(s);
    for (int i = 0; i < dps; i++) {
      for (int j = 0; j < dps; j++) {
        if (vsum[i][j] == area) count++;
      }
    }
    if (count) fout << s << ' ' << count << endl;
  }

  return 0;
}

/*
  for (int i = 0; i < dps; i++) {
    for (int j = 0; j < dps; j++) {
      cout << hsum[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
  for (int i = 0; i < dps; i++) {
    for (int j = 0; j < dps; j++) {
      cout << vsum[i][j] << ' ';
    }
    cout << endl;
  }


  
*/
