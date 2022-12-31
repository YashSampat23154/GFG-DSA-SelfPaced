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
    Searching in an Array

    Searching for an element in an array means to check if a given element is present in the array or not. This can be done by accessing elements of the array one by one starting from the first element and checking whether any of the elements matches with the given element.

    We can use loops to perform the above operation of array traversal and access the elements, using indexes.

    Suppose the array is named arr[] with size N and the element to be searched is referred to as key. Below is the algorithm to perform the search operation in the given array.

    Time Complexity of this search operation will be O(N) in the worst case as we are checking every element of the array from 1st to last, so the number of operations is N.
*/
int searching(int* arr, int N, int key){
    for(int i = 0; i < N; i++)
        if(arr[i] == key)
            return i;
    return -1;
}

/*
    Insert an element in the Fixed Sized Array at a particular position say pos

    Time complexity : O(N)
    Insert at the end : O(1)
    Insert at the beginning : O(N)

    Insert at the end for Dynamic Sized Array : 

    Time complexity of every insert for first n inserts : O(1)

    Average time complexity for (n+1) inserts at the end = (O(1) + O(1) + .......+ O(N))/(N+1) = O(1)
    Explanation of avg : O(1) for first N operations and O(N) for N+1th operation

    
    Fun Fact : Dynamic Sized Arrays pre-allocate some extra memory and that is how they ensure that average time complexity or amortized time complexity for insert operation is constant.

    However please remember that if you have any real time application where you do not want any insert to be costly, you should NOT use dynamic size arrays because there can be one insert which can be really really costly.

    To insert at end in vector we use : push_back();
*/
void insert(int* arr, int N , int pos, int no){
    int i = N-1;

    for(; i>0; i--){
        if(i+1 == pos) break;
        arr[i] = arr[i-1];
    }
    
    arr[i] = no;
    return;
    
}

/*
    Delete operation in an Fixed Sized array : 

    1) Given an array and an element to be deleted, we wish to delete that element from the array.

    2) Return new size of array after deleting the element

    Time Complexity : O(N)
*/
void delete_element(int* arr, int N, int element){
    int i = 0;
    for(; i<N; i++)
        if(arr[i] == element) break;

    while(i<(N-1)){
        // IMP Note

        //This works
        arr[i] = arr[i+1];
        i++;

        //But this doesn't
        // arr[i] = arr[++i];        
    }

    return;
}


int delete_return_size(int* arr, int N, int element){
    int i = 0;
    for(; i<N; i++)
        if(arr[i] == element) break;

    if(i == N) return N;

    while(i<(N-1)){
        arr[i] = arr[i+1];
        i++;
    }

    return N-1;
}

/*
    General overview of all complexity : 

    Insert : O(N) 
    Insert at beginning : O(N)
    Insert at end : O(1)

    Delete : O(N)
    Delete at beginning : O(N)
    Delete at end : O(1)

    Search : 
    Unsorted Array : O(N)
    Sorted Array : O(N)

    Get ith element : O(1)

    Update ith element : O(1)

    Note : Insert at the end and delete from the end can be one in O(1)
*/

int main(){

    fastio;

    int arr[10] = {20, 5, 7, 25};
    cout<<"Index : "<<searching(arr, 4, 5)<<"\n";
    cout<<"Index : "<<searching(arr, 4, 15)<<"\n";



    cout<<"Insertions :"<<endl;

    insert(arr,10,2,7);
    for(int i = 0; i<10; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    insert(arr,10,2,3);
    for(int i = 0; i<10; i++)
        cout<<arr[i]<<" ";
    cout<<endl;



    cout<<"Deletions :"<<endl;

    delete_element(arr, 10, 5);
    for(int i = 0; i<10; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    cout<<delete_return_size(arr, 10, 7)<<endl;
    for(int i = 0; i<10; i++)
        cout<<arr[i]<<" ";
    cout<<endl;


    return 0;
}