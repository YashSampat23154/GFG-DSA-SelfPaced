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
    Find output of the following code : 
*/
void fun1(int n){
    if(n==0) return;
    cout<<n<<endl;
    fun1(n-1);
    cout<<n<<endl;
}


/*
    Find output of the following code : 
*/
void fun2(int n){
    if(n==0) return;
    fun2(n-1);
    cout<<n<<endl;
    fun2(n-1);
}


/*
    Find output of the following code : 
*/
int fun3(int n){
    if(n==1) return 0;
    else return 1+fun3(n/2);
}


/*
    Find output of the following code : 
*/
int fun4(int n){
    if(n==0) return 0;
    fun4(n/2); 
    cout<<n%2;
    return 0;
}



int main(){

    fastio;

    fun1(3);
/*
    Output : 
    3
    2
    1
    1
    2
    3   
*/

    fun2(3);
/*
    Output : 
    1
    2
    1
    3
    1
    2
    1   
*/

    cout<<fun3(16)<<endl;
/*
    Output : 
    4

    This function calculates floor(log2(n))
*/

    fun4(7);
/*
    Output : 
    111

    This function prints the binary representation of a number.
*/


    return 0;
}