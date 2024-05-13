
#include <iostream>
#include <bits/stdc++.h>
// #include "utilities.cpp"
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define forn(i, x, n) for (int i = x; i < n; i++)
#define vi vector<int>
#define vpp vector<pair<int,int>>
#define vs vector<string>
#define vll vector<long long>
#define ss second
#define ff first
int row[] = {1,0,-1,0};
int col[] = {0,1,0,-1};
const int mod = 1e9 + 7;


void solve(){  

    vector<string> a(10);
    forn(i,0,10) cin>>a[i];
    int sm = 0;

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){

        if(a[i][j] == 'X'){

            if(i == 0 || i == 9 || j == 0 || j == 9) sm += 1;
            else if(i == 1 || i == 8 || j == 1 || j == 8) sm += 2;
            else if(i == 2 || i == 7 || j == 2 || j == 7) sm += 3;
            else if(i == 3 || i == 6 || j == 3 || j == 6) sm += 4;
            else if(i == 4 || i == 5 || j == 4 || j == 5) sm += 5;
        }
    }
    }
    cout<<sm<<'\n';
}



signed main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;

}