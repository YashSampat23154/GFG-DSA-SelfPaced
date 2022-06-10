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
    Find sum of digits
*/

/*
    Time Complexity : O(d) where d are the no of digits

    Auxillary Space : O(d)
*/
ll sum_of_digits(int n){
    if(n == 0) return 0;
    return n%10 + sum_of_digits(n/10);
}

int main(){

    fastio;

    cout<<sum_of_digits(9987)<<endl;

    return 0;
}