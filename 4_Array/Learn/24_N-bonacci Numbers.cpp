#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"
#define rep(i,a,b) for(int i=a; i<b; i++)

//struct Values{
//int x;
//};

using namespace std;

/*
    You are given two integers N and M, and print all the terms of the series up to M-terms of the N-bonacci Numbers. For example, when N = 2, the sequence becomes Fibonacci, when n = 3, sequence becomes Tribonacci.

    In general, in N-bonacci sequence, we use sum of preceding N numbers from the next term. For example, a 3-bonacci sequence is the following: 
    0, 0, 1, 1, 2, 4, 7, 13, 24, 44, 81

    In N-bonacci sequence, the first N-1 terms are 0 and Nth term is 1

    The Fibonacci sequence is a set of numbers that starts with one or zero, followed by a one, and proceeds based on the rule that each number is equal to the sum of preceding two numbers 0, 1, 1, 2, 3, 5, 8….

    We can use the sliding technique to solve this problem.
*/
// Time Complexity : O(N*(M-N)) = O(N*M - N*N) = O(N*M)
// Auxillary Space : O(M)
void N_Bonacci_naive(int N, int M){
    int arr[M] = {0};
    arr[N-1] = 1;

    for(int i = N; i<M; i++){
        for(int j = 0; j<N; j++)
            arr[i]+=arr[i-(1+j)];
    }

    for(int i = 0; i<M; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return;
}


// Time Complexity : O(M)
// Auxillary Space : O(N)
void N_Bonacci_efficient(int N, int M){
    int arr[N+1] = {0};
    arr[N-1] = 1;
    arr[N] = 1;

    for(int i = 0; i<=N; i++)
        cout<<arr[i]<<" ";

    int current_window = 1;
    for(int i = N+1; i<M; i++){
        current_window = 2*current_window - arr[i%(N+1)];
        arr[i%(N+1)] = current_window;
        cout<<current_window<<" ";
    }
    cout<<endl;
    
    return;
}


int main(){

    fastio;

    N_Bonacci_naive(3, 20);
    N_Bonacci_efficient(3, 20);


    N_Bonacci_naive(5, 20);
    N_Bonacci_efficient(5, 20);

    return 0;
}