/*
ID: paulo.t1
PROG: spin
LANG: C++11
*/
#include <iostream>
#include <fstream>
#define ll long long
#define MAXW 5
#ifdef local
#define fin cin
#define fout cout
#endif
using namespace std;
#ifndef local
ofstream fout ("spin.out");
ifstream fin ("spin.in");
#endif

short wedges[MAXW][5][2], nwedges[MAXW], speed[MAXW];

void move() {
  for (int i = 0; i < MAXW; i++) {
    for (int j = 0; j < nwedges[i]; j++) {
      wedges[i][j][0] += speed[i];
      wedges[i][j][0] %= 360;
    }
  }
}

bool aligns(int d) {
  int n = 0;
  for (int i = 0; i < MAXW; i++) {
    for (int j = 0; j < nwedges[i]; j++) {
      int a = 0, b = wedges[i][j][1], 
          c = (d >= wedges[i][j][0]) ? d-wedges[i][j][0]:
            360-(wedges[i][j][0]-d);
      if (c >= a and c <= b) {
        n++;
        break;
      }
    }
  }
  return n == MAXW;
}

int main() {
  for (int i = 0; i < MAXW; i++) {
    fin >> speed[i] >> nwedges[i];
    for (int j = 0; j < nwedges[i]; j++)
      fin >> wedges[i][j][0] >> wedges[i][j][1];
  }

  for (int i = 0; i <= 360; i++, move()) {
    for (int d = 0; d < 360; d++) {
      if (aligns(d)) { fout << i << endl; return 0; }
    }
  }

  fout << "none" << endl;

  /*
  gap[0] = 1, gap[1] = 1;
  cout << shorten_gap(0, 1) << endl;
  cout << gap[0] << ' ' << gap[1] << endl;
  cout << shorten_gap(1, 1) << endl;
  cout << gap[0] << ' ' << gap[1] << endl;
  cout << shorten_gap(0, 0) << endl;
  cout << gap[0] << ' ' << gap[1] << endl;
  */

  return 0;
}



/*
 *
bool shorten_gap(int ws, int we) {
  // Normalize and make ws=0
  int a = 0, b = we, c = (gap[0] < ws) ? gap[0]-ws + 360 : (gap[0]-ws) % 360;
  int d = (c+gap[1])%360;
  cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
  if (c == b) {
    gap[0] = (c+ws)%360;
    gap[1] = 0;
    return true;
  } else if (c < b) {
    gap[0] = (c+ws)%360;
    gap[1] = (d <= b) ? d-c : b-c;
    return true;
  } else if (d < c) {
    gap[0] = a + ws, gap[1] = min(b,d);
    return true;
  }
  return false;
}


bool align(int s) {
  // cout << "s " << s << ' ' << gap[0] << ' ' << gap[1] << endl; 
  if (s == MAXW)
    return true;

  for (int j = 0; j < nwedges[s]; j++) {
    int g0 = gap[0], g1 = gap[1];
    cout << "gaps are: " << g0 << ' ' << g1 << endl;
    if (shorten_gap(wedges[s][j][0], wedges[s][j][1])) {
      cout << "shortened gaps " << wedges[s][j][0] << ' ' << wedges[s][j][1] << endl;
      if (align(s+1)) return true;
      else gap[0] = g0, gap[1] = g1;
    }
  }
  return false;
}
*/
