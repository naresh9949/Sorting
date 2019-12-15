#include<stdio.h>
#include<stdlib.h>
void swap(int* x,int* y)
{
    int z=*x;
    *x=*y;
    *y=z;
}
void Heapify(int arr[],int n,int i)
{
    int largest,l,r;
    largest=i;
    l=(2*i)+1;
    r=(2*i)+2;
    if(l<n && arr[l]>arr[largest])
        largest=l;
    if(r<n && arr[r]>arr[largest])
        largest=r;
    if(i!=largest)
    {
        swap(&arr[i],&arr[largest]);
        Heapify(arr,n,largest);
    }
}
void HeapSort(int arr[],int n)
{
    int i;
    for(int i=(n/2)-1;i>=0;i++)
        Heapify(arr,n,i);
    for(i=n-1;i>=0;i--)
    {
        swap(&arr[i],&arr[0]);
        Heapify(arr,i,0);
    }
}
int main()
{
    int l[]={3,5,6,2,3,10,7},i;
    HeapSort(l,7);
    for(i=0;i<7;i++)
        printf("%d ",l[i]);
}