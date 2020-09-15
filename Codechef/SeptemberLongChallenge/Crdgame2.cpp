#include <iostream>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
 //Now sorting a vector looks like sort(all(vec)) 
//instead of sort(vec.begin(), vec.end()).

typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<string> vs;

#define ios                         ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fori(n) for(int i=0; i<int(n); i++)
#define cins(s) string s; cin>>s;
#define cini(i) int i; cin>>i;
#define cind(d) double d; cin>>d;
#define cinai(a, n) vi a(n); fori(n) { cin>>a[i]; }
#define cinas(s, n) vs s(n); fori(n) { cin>>s[i]; }
#define cinad(a, n) vd a(n); fori(n) { cin>>a[i]; }
#define watch(x) cout << (#x) << " is " << (x) << endl
#define see(x) cout << (x) << " ";
#define hh cout << "\n";
typedef long long int ll;
#define mod 1000000007
#define vll vector < ll > 
#define fo(i, n) for(i=0; i<n; i++)
#define Fo(i, k, n) for(i=k; i>=n; i--)
ll t;
ll minimum(ll a, ll b)	{
	return a<b?a:b;
}

ll raise2(ll x, ll y)	{
	if(y == 0)
		return 1;
	ll sol = raise2(x, y/2)%mod;
	sol = (sol*sol)%mod;
	if(y%2!=0)
		sol = (sol*x)%mod;
	return sol;
}

ll division(ll x, ll y)	{
	return (x%mod*(raise2(y, mod-2)%mod))%mod;
}

ll subCal(ll N, ll R)	{
	ll sol = 1;
	ll k = minimum(R, N-R);
	for(ll i=0;i<k;i++)	{
		sol = (sol%mod*(N-i)%mod)%mod;
		sol = division(sol, i+1);
	}
	return sol%mod;
}

void solve()	{
	ll n,c= 0, c2 = 0;
	cin >> n;
	ll a[n];
	ll sol;
	for(ll i=0;i<n;i++)
		cin >> a[i];
	
	for(ll i=0;i<n;i++)
		if(c < a[i])
			c= a[i];
	for(ll i=0;i<n;i++)
		if(c == a[i])
			c2++;
	if(n == 1)	{
		cout << 2;
		return;
	}
	if(c2%2!=0)
		sol = raise2(2, n)%mod;
	else
		sol = raise2(2, n)%mod-((raise2(2, n-c2)%mod)*subCal(c2, c2/2)%mod)%mod;
	if(sol < 0)
		sol = (sol+mod)%mod;
	cout << sol%mod;
}

int main()	{
	cin >> t;
	while(t--)	{
		solve();

		cout << endl;
	}	
	return 0;
}
