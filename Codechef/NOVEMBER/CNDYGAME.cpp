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
#define M 1000000007
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
cin>>t;
while(t--)
{
ll n,i,j,q,index=-1,start=0,mid=0;
 cin>>n;
 ll a[n];
 ll x[n+1];
 for(i=0;i<n;i++)
 cin>>a[i];
 x[0]=0;
 for(i=0;i<n;i++)
 {
     if(a[0]==1)
     {
         start=1;
          x[i+1]=1;
     }
     else if(a[i+1]==1&&(i<n-2))
     {
                mid=1;

                index=i;
                if(a[i]%2==0)
                    x[i+1]=(x[i]+a[i]-1)%M;
                else{
                    
                    x[i+1]=(x[i]+(a[i]))%M;
                }
            }
            else
            {
                if(i!=n-1)
                {
                    if(a[i]%2==0)
                        x[i+1]=(x[i]+a[i])%M;
                    else
                        x[i+1]=(x[i]+(a[i]-1))%M;
                }
                else
                {
                    if(a[n-1]%2!=0)
                        x[i+1]=(x[i]+a[i])%M;
                    else
                        x[i+1]=(x[i]+a[i]-1)%M;

                }
            }
 }
 cin>>q;
 int r,ans=0;	      
    for(i=1;i<=q;i++)
    {
        ans=0;
         cin>>r;
         ll numt=r/n;
         ll l=r%n;
         ans=(numt*x[n])%M;
         if(start==1){
                if(numt==0)
                    ans=1;
                else
                {
                    if(l>1)
                        ans=(numt+1)%M;
                    else
                        ans=numt;
                }
}
               else if(l==0)
               {
                   if(a[n-1]%2==0)
                   ans=(ans+1)%M;
               }
               else if(l!=0){
                   if(l-1==index && mid==1)
                   {
                    if(a[l-1]%2==0)
                    {
                        ans=(ans+x[l]+1)%M;
                    }
                    else
                    {
                        ans=(ans+x[l])%M;
                    }
                }
                else if(l-1==index+1&&mid==1)
                {

                        if(a[l-2]%2==0)
                            ans=(ans+x[l]+2)%M;
                        else
                            ans=(ans+x[l])%M;
                }
                else if(a[l-1]%2!=0)
                    ans=(ans+x[l]+1)%M;
                else if(a[l-1]%2==0)
                {
                    ans=(ans+x[l])%M;
                }
            }
            cout<<ans<<endl;
    }
}
}
