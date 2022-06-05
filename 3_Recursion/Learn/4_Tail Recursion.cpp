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
    A recursive function is called tail recursive when the parent function has nothing more to do when the child function has finished. 

    Or in simple words, a function is called tail recursive when the last thing that happens in the function is the recursive call. 

    In tail recursion, the caller doesn't have to save the state hence it becomes faster.
*/


/*
    Print all integers from N to 1

    Time Complexity : O(n)
    T(n) = T(n-1) + O(1)
    Auxillary Space : O(n)

    Takes less time than OnetoN when run for slightly large input.
    It takes less time on modern compilers because it is tail recursive.
*/
void Nto1(int n){
    if(n == 0) return;
    cout<<n<<" ";
    Nto1(n-1);
}

/*
    Internally the compiler will execute : 

    void Nto1(int n){
        start :
        if(n == 0) return;
        cout<<n<<" ";
        n = n-1;
        goto start;
    }

    The changes that the compiler will make are called tail call elimination. 
    Modern compiler do tail call elimination to optimise the code.
*/


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

// Tail recusive version of the above function
void Tail_recusive_version_of_OnetoN(int n , int k){
    if(n == 0) return;
    cout<<k<<" ";
    Tail_recusive_version_of_OnetoN(n-1, k+1);
}

/*
    Can we convert every non - tail recursive function into tail recursive function?

    The answer is NO. We can't simply convert every non-tail recursive function to tail recursive function. 
    Eg : MergerSort and Quicksort
    QuickSort is tail recursive and MergeSort is not. 
    This is one of the reasons why quicksort is faster than mergesort.
*/


/*
    Is the following function tail recursive?
*/
int fact(int n){
    if(n==0 || n==1) return 1;
    return n * fact(n-1);
}
/*
    No this function is not tail recursive. The reason is that the recursion call is not the last thing that happens in this function.
    When we call factorial n-1, we need to know the result of factorial n-1 and then only you can mulitply this result with n and finally return. 
    So the parent call cannot finish immediately after the child call. 

    Equivalent tail recusive function 
*/
int fact_tail_recursion(int n, int k){
    if(n == 0 || n == 1) return k;
    return fact_tail_recursion(n-1, k*n);
}


int main(){

    fastio;


    return 0;
}