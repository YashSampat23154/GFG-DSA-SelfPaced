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
    Right shift the number until it becomes zero

    Time Compexity : O(Total bits in n)
*/

ll count_set_bits_naive(ll n){
    ll count = 0;
    while(n!=0){
        count+=n&1;
        n = n>>1;
    }
    return count;
}

/*
    Brain Kernighan's Algorithm : 
    The idea is to only consider the set bits of an integer by turning off its rightmost set bit (after counting it), so the next iteration of the loop considers the next rightmost bit.
    The expression n & (n-1) can be used to turn off the rightmost set bit of a number n. This works as the expression n-1 flips all the bits after the rightmost set bit of n, including the rightmost set bit itself. Therefore, n & (n-1) results in the last bit flipped of n.

    Time Complexity : O(Set Bit Count)
*/
ll count_set_bits_efficient1(ll n){
    ll count = 0;
    while(n!=0){
        n = n&(n-1);
        count++;
    }
    return count;
}


/*
    Lookup Table Method for 32 bit numbers

    Time Complexity : O(1), however some preprocessing has to be done.
*/
int table[256];

void initialize_table(){
    table[0] = 0;
    for(int i = 1; i<256; i++){
        table[i] = i&1 + table[i>>1];
    }
}

ll count_set_bits_efficient2(ll n){
    ll count = 0;
    for(int i=0; i<4; i++){
        count+= table[n&0xff];
        n=n>>8;
    }
    return count;
}


int main(){

    fastio;

    cout<<count_set_bits_naive(2)<<endl;
    cout<<count_set_bits_efficient1(12)<<endl;
    initialize_table();
    cout<<count_set_bits_efficient2(7)<<endl;
    cout<<count_set_bits_efficient2(31)<<endl;

    return 0;
}