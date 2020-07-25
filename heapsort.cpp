#include<iostream>
#include<algorithm>
using namespace std;

void Heapify(int arr[],int n,int pos)
{
	int largest = pos;
	int left = (2*pos)+1;
	int right = (2*pos)+2;

	if(left<n && arr[largest]<arr[left])
		largest = left;

	if(right<n && arr[largest]<arr[right])
		largest = right;

	if(largest!=pos)
	{
		swap(arr[largest],arr[pos]);
		Heapify(arr,n,largest);
	}

}

void HeapSort(int a[],int n)
{
	for(int i=(n/2)-1;i>=0;i--)
		Heapify(a,n,i);

	for(int i=n-1;i>=0;i--)
	{
		swap(a[0],a[i]);
		Heapify(a,i,0);
	}
}

int main()
{
	int a[] = {3,5,6,2,3,10,7};

	int n = sizeof(a)/sizeof(a[0]);

	HeapSort(a,n);

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
