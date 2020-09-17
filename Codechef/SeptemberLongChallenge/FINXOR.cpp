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
#define vll vector < ll > 
#define fo(i, n) for(i=0; i<n; i++)
#define Fo(i, k, n) for(i=k; i>=n; i--)
ll t;

int subMain()	{
	long long n, answer = 0;
	cin >> n;
	vector<long long>xorsum;
	long long x;
	for(long long i=1;i<=20;i++)	{
		cout << 1 << " " << (1ul<<i) << endl;
		cout.flush();
		cin >> x;
		xorsum.push_back(x);
	}
	reverse(xorsum.begin(), xorsum.end());
	long long sum = xorsum[0]-n*(1ul<<20);
	for(long long i=1;i<xorsum.size();i++)	{
		if(xorsum[i] >= sum)	{
			xorsum[i] = ((n-(xorsum[i]-sum)/(1ul<<(xorsum.size()-i)))/2);
		}
		else
			xorsum[i] = (n+(sum-xorsum[i])/(1ul<<(xorsum.size()-i)))/2;
	}
	for(int i=1;i<xorsum.size();i++)
		if(xorsum[i]%2 != 0)
			answer+=1ul<<(xorsum.size()-i);
	if(sum%2!=0)
		answer++;
	cout << 2 << " " << answer << endl;
	cout.flush();
	int result;
	cin >> result;
	return result;
}

int main()	{
	cin >> t;
	while(t--)	{
		if(!subMain())
			break;
		cout << endl;
		cout.flush();
	}	
	return 0;
}
