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
    Majority element is an element that appears more than n/2 times in an array of size n.
    We want to return the index of the majority element.
*/
// Time Complexity : O(n)
// Auxillary Space : O(1)
int majority_naive(int arr[], int n){
    int count;

    for(int i= 0; i<n ; i++){
        count = 1;
        for(int j = i+1; j<n; j++)
            if(arr[i] == arr[j]) count++;
        
        if(count>n/2) return i;
    }
    return -1;
}

/*
Boyer-Moore Majority Voting Algorithm

This algorithm works on the fact that if an element occurs more than N/2 times, it means that the remaining elements other than this would definitely be less than N/2. So let us check the proceeding of the algorithm.

First, choose a candidate from the given set of elements if it is the same as the candidate element, increase the votes. Otherwise, decrease the votes if votes become 0, select another new element as the new candidate.


Intuition Behind Working :
When the elements are the same as the candidate element, votes are incremented when some other element is found not equal to the candidate element. We decreased the count. This actually means that we are decreasing the priority of winning ability of the selected candidate, since we know that if the candidate is a majority it occurs more than N/2 times and the remaining elements are less than N/2. We keep decreasing the votes since we found some different element than the candidate element. When votes become 0, this actually means that there are the same number of different elements, which should not be the case for the element to be the majority element. So the candidate element cannot be the majority, so we choose the present element as the candidate and continue the same till all the elements get finished. The final candidate would be our majority element. We check using the 2nd traversal to see whether its count is greater than N/2. If it is true, we consider it as the majority element.

Steps to implement the algorithm :
Step 1 – Find a candidate with the majority –

Initialize a variable say i ,votes = 0, candidate =-1 
Traverse through the array using for loop
If votes = 0, choose the candidate = arr[i] , make votes=1.
else if the current element is the same as the candidate : increment votes
else : decrement votes.

Step 2 – Check if the candidate has more than N/2 votes –

Initialize a variable count =0 and increment count if it is the same as the candidate.
If the count is >N/2, return the candidate.
else return -1.

Time Complexity : O(n)
Auxillary Space : O(1)
*/
int majority_efficient(int arr[], int n){
    
    int ans = 0, count = 1;
    
    // Find candidate element
    for(int i= 1; i<n ;i++){
        if(arr[ans] == arr[i]) count++;
        else count--;
        if(count == 0){
            ans = i;
            count = 1;
        }
    }

    // Check if candidate is actually major or not.
    count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == arr[ans]) count++;
    }

    if(count>n/2) return ans;
    else return -1;
}

int main(){

    fastio;

    int arr1[] = {8, 3, 4, 8, 8};
    int arr2[] = {3, 7, 4, 7, 7, 5};
    int arr3[] = {20, 30, 40, 50 , 50, 50, 50};

    cout<<majority_naive(arr1, 5)<<endl;
    cout<<majority_efficient(arr2, 6)<<endl;
    cout<<majority_efficient(arr3, 7)<<endl;

    return 0;
}