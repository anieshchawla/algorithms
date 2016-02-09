/*
You are given five integers: N, S, P, Q. You will use them in order to create the sequence a with 
the following pseudo-code.

a[0] = S (modulo 2^31)
for i = 1 to N-1
    a[i] = a[i-1]*P+Q (modulo 2^31) 

Your task is to calculate the number of distinct integers in the sequence a.

Input Format
Four space separated integers on a single line, N, S, P, and Q respectively.

Output Format
A single integer that denotes the number of distinct integers in the sequence a.

Constraints
1≤N≤108
0≤S,P,Q<231

Sample Input
3 1 1 1

Sample Output
3

Explanation

a=[1,2,3]

Hence, there are 3 different integers in the sequence.

*/




#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cassert>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <iostream>

#define pb push_back
#define all(x) (x).begin(), (x).end()

#ifdef KAZAR
  #define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
  #define eprintf(...) 0
#endif

using namespace std;

template<class T> inline void umax(T &a,T b){if(a < b) a = b;}
template<class T> inline void umin(T &a,T b){if(a > b) a = b;}
template<class T> inline T abs(T a){return a > 0 ? a : -a;}

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 1e9 + 143;
const ll longinf = 1e18 + 143;

inline int read(){int x;scanf(" %d",&x);return x;}

const unsigned M = (1ll << 31) - 1;
const int MAX = 1 << 26;
const int K = 16;
const int MSK = (1 << K) - 1;

int kb[1 << K];
unsigned f[MAX];

int main(){

#ifdef KAZAR
  freopen("f.input","r",stdin);
  freopen("f.output","w",stdout);
  freopen("error","w",stderr);
#endif

  int n = read();
  unsigned s, p, q;
  cin >> s >> p >> q;

  f[s >> 5] |= 1u << (s & 31);
  for (int i = 1; i < n; i++) {
    s = (s * p + q) & M;
    f[s >> 5] |= 1u << (s & 31);
  }

  for (int i = 0; i < (1 << K); i++) {
    kb[i] = kb[i >> 1] + (i & 1);
  }

  int res = 0;
  for (int i = 0; i < MAX; i++) {
    res += kb[f[i] >> 16] + kb[f[i] & MSK];
  }
  printf("%d\n", res);

  return 0;
}