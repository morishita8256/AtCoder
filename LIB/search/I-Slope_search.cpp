#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define int long long
typedef long long ll;
#define double long double
typedef double ld;
const double EPS = 1e-9;

/*
  凸関数fに対し argmax/min f(x) を返す。
  引数は、(傾き正, 傾き負)の順に与える(minのとき注意)。
  このとき右側の点は+1しておく（開区間）

  傾きが0の点を探せばよいので、傾きで2分探索をする

  ※極値を挟んだ値を渡していることを確認
  　intのまま扱うのでmod計算もできる
  　極値以外に傾き0の部分があるとダメ
  　intの問題でもdoubleに焼き直した方が良い場合もある
  　inc, decはそれぞれ「1つ前に比べて増加, 減少している点」を表す
  　極値が平らな場合、デフォルトでは
  　　・max...最も左の点
  　　・min...最も右の点
  　を返す。入れ替えるにはfの差の部分の不等号に等号を加える。
 */

#pragma region golden_search
const double Golden = 2.0 / (3.0 + sqrt(5));

int f(int trial);
int slope_search(int inc, int dec) {
  bool isMax = inc < dec;
  while (abs(dec - inc) > 1) {
    int mid = (inc + dec) / 2;
    (f(mid) - f(mid - 1) > 0 ? inc : dec) = mid;
  }
  return isMax ? inc : dec;
}
#pragma endregion

/*
https://yukicoder.me/problems/no/198
*/

int B, N;
vector<int> C;

int f(int trial) {
  int cnt = 0;
  rep(i, N) {
    cnt += abs(trial - C[i]);
  }
  return cnt;
}

signed main() {
  cin >> B >> N;
  C = vector<int>(N);
  int mx = B;
  rep(i, N) {
    cin >> C[i];
    mx += C[i];
  }
  mx /= N;


  int c = slope_search(mx + 1, 0);  // mx側は開区間で。
  int ans = f(c);
  cout << ans << endl;
}