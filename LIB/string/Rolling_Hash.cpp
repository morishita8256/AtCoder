#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define sz(x) ((int)(x).size())

/* ------------------------------------- */

typedef unsigned long long ull;
const int MAX_LENGTH = 500000;
const ull MASK30 = (1ULL << 30) - 1;
const ull MASK31 = (1ULL << 31) - 1;
const ull MODrh = (1ULL << 61) - 1;
const ull POSITIVIZER = MODrh * ((1ULL << 3) - 1);
unsigned int Base;
vector<ull> powMemo(MAX_LENGTH + 1);

ull Mul(ull l, ull r) {
  ull lu = l >> 31;
  ull ld = l & MASK31;
  ull ru = r >> 31;
  ull rd = r & MASK31;
  ull middleBit = ld * ru + lu * rd;
  return ((lu * ru) << 1) + ld * rd + ((middleBit & MASK30) << 31) +
         (middleBit >> 30);
}

ull CalcMod(ull val) {
  val = (val & MODrh) + (val >> 61);
  if (val > MODrh)
    val -= MODrh;
  return val;
}

void init_RH() {
  srand(time(NULL));
  Base = rand() % RAND_MAX + 129;
  powMemo[0] = 1;
  repp(i, 1, sz(powMemo) - 1) {
    powMemo[i] = CalcMod(Mul(powMemo[i - 1], Base));
  }
}

struct RollingHash {
  vector<ull> hash;

  RollingHash(string s) {
    hash = vector<ull>(sz(s) + 1);
    rep(i, sz(s)) {
      hash[i + 1] = CalcMod(Mul(hash[i], Base) + s[i]);
    }
  }

  ull Slice(int begin, int length) {
    return CalcMod(hash[begin + length] + POSITIVIZER -
                   Mul(hash[begin], powMemo[length]));
  }
};

/*
https://yukicoder.me/problems/no/430
*/
int main() {
  init_RH();  // 必須

  string S;
  int M;
  cin >> S >> M;
  vector<string> C(M);
  rep(i, M) cin >> C[i];

  RollingHash RS(S);
  int ans = 0;
  rep(i, M) {
    RollingHash RC(C[i]);
    int size = sz(C[i]);
    ull Chash = RC.Slice(0, size);  // ullを使う

    rep(j, sz(S) - size + 1) {
      if (RS.Slice(j, size) == Chash)
        ans++;
    }
  }
  cout << ans << endl;
}