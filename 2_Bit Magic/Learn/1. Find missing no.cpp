/*
    Given an array of n number that has values in range [1...n+1]. Every no. appears exactly once. However one no. is missing. Find the missing no.

    Eg: 
    I/P : arr[] = [1, 4, 3]
    O/P : 2

    I/P : arr[] = [1, 5, 3, 2]
    O/P : 4
*/

#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define rep(i,a,b) for(int i=a; i<b; i++)

//struct Values{
//int x;
//};

using namespace std;

int main(){

    fastio;

    int n; 
    cin>>n;

    int ans = 0, xorvalue = 0;
    for(int i = 0; i<n; i++){
        int no;
        cin>>no;
        xorvalue^=no;
        ans ^= i+1;
    }
    ans^=n+1;

    cout<<(xorvalue^ans)<<endl;

    return 0;
}