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
    We can solve this problem using left shift operator or right shift operator. 

    Both take Time Complexity : O(log n)
*/

bool check_kth_bit_rightshift(ll n, ll k){
    return (n>>(k-1) & 1);
}

bool check_kth_bit_leftshift(ll n, ll k){
    return (1<<(k-1) & n);
}

int main(){

    fastio;
    
    cout<<check_kth_bit_leftshift(5, 1)<<endl;
    cout<<check_kth_bit_leftshift(8, 2)<<endl;
    cout<<check_kth_bit_leftshift(5, 3)<<endl;

    cout<<check_kth_bit_rightshift(5, 1)<<endl;
    cout<<check_kth_bit_rightshift(8, 2)<<endl;
    cout<<check_kth_bit_rightshift(13, 3)<<endl;

    return 0;
}
