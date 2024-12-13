#include<iostream>
using namespace std;

template <class T>
void Sort(T *arr, int n){
    for(int i=0; i<n-1; i++) {
            int min = i;
            for(int j=i+1; j<n; j++) {
                if(arr[min] > arr[j]){
                    min = j;
                }
            }
            swap(arr[i], arr[min]);
        }
}

int main() {
    
    int arr[] = {5,8,1,3,7};
    int n = sizeof(arr)/sizeof(int);
    Sort(arr, n);

    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    float arr2[] = {5.7,1.8,1.59,10.3,1.7};
    int m = sizeof(arr)/sizeof(float);
    Sort(arr2, m);

    for(int i=0; i<m; i++) {
        cout<<arr2[i]<<" ";
    }


    return 0;
}