#include<iostream>
#include<algorithm>
using namespace std;

void Merge(int arr[],int start,int mid,int end)
{
    int n1 = mid-start+1;
    int n2 = end-mid;
    
    int a[n1],b[n2];
    
    for(int i=0;i<n1;i++)
    a[i]=arr[start+i];
    
    for(int i=0;i<n2;i++)
    b[i] = arr[mid+i+1];
    
    int i=0,j=0,k=start;
    
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k] = a[i];
            i++;
        }
        else
        {
            arr[k] = b[j];
            j++;
        }
        
        k++;
    }
    
    while(i<n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    
    while(j<n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
}


void Merge_Sort(int arr[],int start,int end)
{
    if(start<end)
    {
        int mid = (start+end)/2;
        
        Merge_Sort(arr,start,mid);
        Merge_Sort(arr,mid+1,end);
        
        Merge(arr,start,mid,end);
    }
}

int main()
{
    int a[] = {6,8,2,1,3,9};
    
    int n = sizeof(a)/sizeof(a[0]);
    
    Merge_Sort(a,0,n-1);
    
    for(int i=0;i<n;i++)
    std::cout << a[i] << std::endl;
    
}
