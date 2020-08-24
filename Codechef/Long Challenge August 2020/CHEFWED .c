#include <iostream>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
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
int arr1[999][999] = {0};
ll gcost(int s,int e,long long int f[],int k){
    if(s==e){
        return k;
    }
    ll h[101] = {0};
    ll cost = k;
    for(int i=s;i<=e;i++){
       h[f[i]]++;
    }
    for(int i=0;i<=100;i++){
        if(h[i]>1){
            cost+=h[i];
        }
    }
    return cost;
}
ll recur(int s,int e,long long int f[],int k){
    if(s>e)
        return 0;
    if(s==e)
        return k;
    if(arr1[s][e]!=0)
        return arr1[s][e];
    
    ll min_c = INT_MAX;
    for(ll i=s;i<=e;i++){
        min_c = min(min_c,gcost(s,i,f,k) + recur(i+1,e,f,k));
    }
    arr1[s][e] = min_c;
    return arr1[s][e];
}
int main() {
    cin>>t;
    while(t--){
       ll n,k;
       cin>>n>>k;
       ll f[n];
       int fam[101] = {0};
       ll cost =k;
       for(ll i=0;i<999;i++){
           for(ll j=0;j<999;j++){
               arr1[i][j] = 0;
           }
       }
       for(ll i=0;i<n;i++){
           cin>>f[i];
       }
       cout<<recur(0,n-1,f,k)<<endl;
    }
  return 0;
}
