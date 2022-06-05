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

/*
    Print all integers from N to 1

    Time Complexity : O(n)
    T(n) = T(n-1) + O(1)
    Auxillary Space : O(n) 
*/
void Nto1(int n){
    if(n == 0) return;
    cout<<n<<" ";
    Nto1(n-1);
}

/*
    Print all integers from 1 to N

    Time Complexity : O(n)
    T(n) = T(n-1) + O(1)
    Auxillary Space : O(n)
*/
void OnetoN(int n){
    if(n == 0) return;
    OnetoN(n-1);
    cout<<n<<" ";
}

int main(){

    fastio;

    Nto1(5);
    cout<<endl;

    OnetoN(5);
    cout<<endl;

    return 0;
}