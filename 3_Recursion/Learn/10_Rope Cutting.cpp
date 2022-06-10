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
    Given a rope of length N, we want to divide the rope into maximum number of pieces such that the lenght of the smallest rope is either a, b, or c. 
    Incase such a division is not possible return -1
*/

// My soln will be wrong if the no of divisions exceed INT_MIN
int rope_cutting(int n, int a, int b, int c){
    if(n<0) return INT_MIN;
    if(n == 0) return 0;
    // int x = 1 + rope_cutting(n-a, a, b, c);
    // int y = 1 + rope_cutting(n-b, a, b, c);
    // int z = 1 + rope_cutting(n-c, a, b, c);
    // int maxi = max(max(x,y),z);
    // return maxi>0?maxi:-1;
    return max(max(1+ rope_cutting(n-a,a,b,c), 1 + rope_cutting(n-b,a,b,c)), 1 + rope_cutting(n-c,a,b,c))>0?max(max(1+ rope_cutting(n-a,a,b,c), 1 + rope_cutting(n-b,a,b,c)), 1 + rope_cutting(n-c,a,b,c)):-1;
}

/*
    Another soln
*/
int rope_cutting2(int n, int a ,int b, int c){
    if(n<0) return -1;
    if(n == 0) return 0;

    int maxi  = max(max(rope_cutting2(n-a,a,b,c), rope_cutting2(n-b,a,b,c)), rope_cutting2(n-c,a,b,c));

    if(maxi == -1) return -1;
    return maxi+1;
}

/*
    Time Complexity : O(3^n)
*/

int main(){

    fastio;

    cout<<rope_cutting(5, 2, 5, 1)<<endl;
    cout<<rope_cutting(23, 12, 9, 11)<<endl;
    cout<<rope_cutting2(5, 4, 2, 6)<<endl;
    cout<<rope_cutting2(9, 2, 2, 2)<<endl;

    return 0;
}