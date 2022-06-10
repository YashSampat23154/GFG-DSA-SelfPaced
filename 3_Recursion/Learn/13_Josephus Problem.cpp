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
    In computer science and mathematics, the Josephus Problem (or Josephus permutation) is a theoretical problem. Following is the problem statement:

    There are n people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom. Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.

    For example, if n = 5 and k = 2, then the safe position is 3. Firstly, the person at position 2 is killed, then person at position 4 is killed, then person at position 1 is killed. Finally, the person at position 5 is killed. So the person at position 3 survives. 

    If n = 7 and k = 3, then the safe position is 4. The persons at positions 3, 6, 2, 7, 5, 1 are killed in order, and person at position 4 survives.

    Recurrence Relation : 
    T(n) = T(n-1) + O(1)

    Time Complexity : O(n)
    Space Complexity : O(1)
*/
ll Josephus_start_0(ll n, ll k){
    if(n == 0) return 0;
    return (Josephus_start_0(n-1, k)+k)%n;
}


ll Josephus_start_1(ll n, ll k){
    return Josephus_start_0(n,k) + 1;
}

int main(){

    fastio;

    cout<<Josephus_start_0(8, 5)<<endl;
    cout<<Josephus_start_1(8, 5)<<endl;

    return 0;
}