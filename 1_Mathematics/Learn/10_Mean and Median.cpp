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
    Mean = The mean is found by adding up all the given data and dividin by the number of data entries.

    Median : The middle number : found by ordering all data points and picking out the one in the middle (or if there are two middle numbers, taking the mean of those two numbers)
*/

double Mean(int a[], int n){
    double result = 0;
    for(int i = 0; i<n; i++){
        result += a[i];
    }
    return result/n;
}

double Median(int a[], int n){
    sort(a, a+n);
    if(n%2 == 0)
        return (double)(a[n/2-1] + a[n/2])/2;
    else return a[n/2];
}

int main(){

    fastio;

    int arr[5] = {2,3,1,5,4};

    cout<<Mean(arr, 5)<<endl;
    cout<<Median(arr, 5)<<endl;

    return 0;
}
