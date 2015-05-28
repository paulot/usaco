/*
ID: paulo.t1
PROG: shopping
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#define ll long long
#ifdef local
#define fin cin
#define fout cout
#endif

using namespace std;
typedef pair<int, int> ii;
#ifndef local
ofstream fout ("shopping.out");
ifstream fin ("shopping.in");
#endif

struct offer {
  vector<ii> products; // k, c
  int price;
};

int getp(ii &p) { return p.second; }
int getc(ii &p) { return p.second; }
int getk(ii &p) { return p.first; }

int no, nb;
offer offers[99];
int dp[6][6][6][6][6];
int quantity[5];
map<int, int> code;
int price[5];

bool can_apply_offer(int o, int a1, int a2, int a3, int a4, int a5) {
  if (o == -1) return true;
  int state[5] = {a1,a2,a3,a4,a5};
  for (int i = 0; i < offers[o].products.size(); i++) {
    int needed = getk(offers[o].products[i]);
    int c = getc(offers[o].products[i]);
    if (needed > state[code[c]]) return false;
  }
  return true;
}

int get_price(int arr[5]) {
  int ans = 0;
  for (int i = 0; i < 5; i++)
    ans += arr[i] * price[i];
  return ans;
}

int get_val(int arr[5]) {
  return dp[arr[0]][arr[1]][arr[2]][arr[3]][arr[4]];
}

void set_val(int arr[5], int val) {
  dp[arr[0]][arr[1]][arr[2]][arr[3]][arr[4]] = val;
}

void apply_offer(int o, int a1, int a2, int a3, int a4, int a5) {
  int os[5] = {a1,a2,a3,a4,a5};
  int s[5] = {a1,a2,a3,a4,a5};
  if (o == -1) { set_val(os, get_price(os)); return; }

  for (int i = 0; i < offers[o].products.size(); i++) {
    int needed = getk(offers[o].products[i]);
    int c = getc(offers[o].products[i]);
    s[code[c]] -= needed;
  }
  int new_val = get_val(s) + offers[o].price;
  if (get_val(os) > new_val) {
    set_val(os, new_val);
  }
}

int main() {
  fin >> no;
  for (int i = 0; i < no; i++) {
    int n;
    fin >> n;
    for (int j = 0; j < n; j++) {
      int c, k;
      fin >> c >> k;
      offers[i].products.push_back(make_pair(k, c));
    }
    fin >> offers[i].price;
  }
  fin >> nb;
  for (int i = 0; i < nb; i++) {
    int c;
    fin >> c >> quantity[i] >> price[i];
    code[c] = i;
  }

  for (int o = -1; o < no; o++)
  for (int a1 = 0; a1 <= 5; a1++)
  for (int a2 = 0; a2 <= 5; a2++)
  for (int a3 = 0; a3 <= 5; a3++)
  for (int a4 = 0; a4 <= 5; a4++)
  for (int a5 = 0; a5 <= 5; a5++)
    if (a1 <= quantity[0] and a2 <= quantity[1]
        and a3 <= quantity[2] and a4 <= quantity[3]
        and a5 <= quantity[4]) {
      if (can_apply_offer(o,a1,a2,a3,a4,a5)) {
        apply_offer(o,a1,a2,a3,a4,a5);
      }
    }

  fout << dp[quantity[0]][quantity[1]][quantity[2]][quantity[3]][quantity[4]]
    << endl;

  return 0;
}

  /*
  for (int a1 = 0; a1 <= 5; a1++)
  for (int a2 = 0; a2 <= 5; a2++)
  for (int a3 = 0; a3 <= 5; a3++)
  for (int a4 = 0; a4 <= 5; a4++)
  for (int a5 = 0; a5 <= 5; a5++)
    if (a1 <= quantity[0] and a2 <= quantity[1]
        and a3 <= quantity[2] and a4 <= quantity[3]
        and a5 <= quantity[4]) {
      cout << a1 << ' ' << a2 << ' ' << a3 << ' ' << a4 << ' ' 
        << a5 << ": " << dp[a1][a2][a3][a4][a5] << endl;
    }
  */
