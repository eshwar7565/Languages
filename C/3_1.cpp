#include <iostream>
#include <vector>

using namespace std; 

void swap(int* V1, int* V2) 
{ 
    int temp = *V1;                          //function declaration which can swap array elemnts
    *V1 = *V2; 
    *V2 = temp; 
} 
  

int partition (int arr[], int l, int h)    //Taking inputs into array 
{ 
    int pivot = arr[h]; 
    int i = (l - 1); 
    for (int j = l; j <= h - 1; j++) 
    { 
        
        if (arr[j] < pivot) 
        { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[h]); 
    return (i + 1); 
} 
  

void Quicksort(int arr[], int l, int h)      //Quicksortfunction decalration
{ 
    if (l < h) 
    { 
        
        int index = partition(arr, l, h); 
        Quicksort(arr, l, index - 1); 
        Quicksort(arr, index + 1, h); 
    } 
} 

void printvect(vector<int> &v) 
{ 
    for(auto i:v){
        cout<<i<<" ";
    }
}

int Minimumdiff(int a[],int n){
    int diff = a[1]-a[0];
    for (int i = 0; i < n-1; i++)
    {
        if(a[i+1]-a[i]<diff){
            diff = a[i+1]-a[i];
        }
    }
    return diff;
}


int main() 
{ 
    int n;
    cout<<"Enter no of elemnts in array"<<endl;
    cin>>n;
    if(n<2 || n>2000){
        cout<<"ERROR: n not within constraint"<<endl;
        return 0;
    }
    int arr[n];
    cout<<"Input array Elements"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    Quicksort(arr, 0, n - 1); 
    bool t = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>1000 || arr[i]< -1000){
            t=1;
            cout<<"ERROR: Element not within constraint"<<endl;
            
        }
        else if(arr[i]==arr[i+1]){
            t=1;
            cout<<"ERROR: All Elements are not unique"<<endl;
        }
    }

    if(t){
        return 0;
    }
    
    vector<int> v;

    int mindiff = Minimumdiff(arr,n);
    int counter = 0;
    
    for (int i = 0; i < n-1; i++)
    {
        int diff = arr[i+1]-arr[i];
        if(diff==mindiff){
            counter++;
            v.push_back(arr[i]);
            v.push_back(arr[i+1]);
        }
    }

    cout<<"Minimumdiff = "<<mindiff<<endl;
    cout<<"Number of MinDiff pairs = "<<counter<<endl;
    cout<<"OutArr"<<endl;
    printvect(v);
    cout<<endl;
    return 0; 
}