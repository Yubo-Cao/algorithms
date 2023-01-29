#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<cstring>
#include<string>
#include<numeric>
#include<sstream>
#include<iterator>
#include<bitset>
#include<climits>
#include<cmath>
#include<queue>

using namespace std;
typedef long long int lli;

#define all(arr) arr.begin(),arr.end()
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define space ' '
#define kick(t) cout << "Case #" << t+1 << ":" << endl;

typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;

const int N = 105;
int t, n, m;
struct Input {
  int b[N];
  int output;
} inputs[N];

bool check(int output) {
  // Check if the given output can be produced by the program for all inputs
  for (int i = 0; i < m; i++) {
    bool ok = false;
    for (int j = 0; j < n; j++) {
      if (inputs[i].b[j] == 1 && output == inputs[i].output) {
        ok = true;
        break;
      }
    }
    if (output != inputs[i].output && !ok) {
      return false;
    }
  }
  return true;
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < n; j++) {
        inputs[i].b[j] = s[j] - '0';
      }
      cin >> inputs[i].output;
    }
    bool ok = true;
    for (int i = 0; i < m; i++) {
      bool match = false;
      for (int j = 0; j < m; j++) {
        bool b_match = true;
        for (int k = 0; k < n; k++) {
          if (inputs[i].b[k] != inputs[j].b[k]) {
            b_match = false;
            break;
          }
        }
        if (b_match && inputs[i].output == inputs[j].output) {
          match = true;
          break;
        }
      }
      if (!match) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "OK" : "LIE") << endl;
  }
  return 0;
}
