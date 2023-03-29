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

template <typename T>
void input(vector<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.push_back(temp);
}

template <typename T>
void output(vector<T> arr) {
  for(auto x:arr) cout<<x<<" ";
  cout<<endl;
}


template <typename T>
void input_set(set<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.insert(temp);
}

lli mul(lli a, lli b) {
  return (a%MOD*b%MOD)%MOD;
}

lli power(lli a,lli b) {
  lli ans = 1;
  while(b > 0) {
    if(b&1)
      ans = mul(ans, a);
    a = mul(a,a);;
    b >>= 1;
  }
  return ans;
}

void split(const string &s, char delim, vector<string> &elems) {
  stringstream ss;
  ss.str(s);
  string item;
  while (getline(ss, item, delim)) {
    elems.push_back(item);
  }
}

vector<string> split(const string &s, char delim) {
  vector<string> elems;
  split(s, delim, elems);
  return elems;
}

bool toBool(std::string const& s) {
     return s != "0";
}

void findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr)
{
    size_t pos = data.find(toSearch);
    while( pos != std::string::npos)
    {
        data.replace(pos, toSearch.size(), replaceStr);
        pos =data.find(toSearch, pos + replaceStr.size());
    }
}

int T, N, K;
string cows;

int main() {
  cin >> T;
  while (T--) {
    cin >> N >> K >> cows;
    // Initialize the result with the number of cows
    int res = N;
    for (int i = 0; i < N; i++) {
      // Count the number of contiguous patches of grass of the same breed
      // as the current cow that can reach the current cow
      int count = 0;
      while (i + count < N && cows[i + count] == cows[i] && count <= K) count++;
      // If there is at least one patch that can reach the current cow,
      // decrease the result by one as we don't need to plant a patch for the current cow
      if (count > 0) res--;
      // Move to the next cow after the last patch that can reach the current cow
      i += count - 1;
    }
    cout << res << endl;
    // Print the configuration that uses the minimum amount of patches
    for (int i = 0; i < N; i++) {
      // If the current cow is within K positions of a patch of the same breed,
      // print a dot to indicate that there is no patch at the current position
      if (i > 0 && cows[i] == cows[i - 1] && i <= K) {
        cout << '.';
      } else if (i < N - 1 && cows[i] == cows[i + 1] && i + K + 1 < N) {
        cout << '.';
      } else {
        // Otherwise, print the breed of the patch at the current position
        cout << cows[i];
      }
    }
    cout << endl;
  }
  return 0;
}
