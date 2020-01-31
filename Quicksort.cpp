#include<iostream>
#include <algorithm> 
using namespace std;
int partesion(int a[],int start,int end)
{
	int pivot=a[end],pindex=start;
	for(int i=start;i<end;i++)
	{
		if(a[i]>=pivot)
		{
			swap(a[i],a[pindex]);
			pindex++;
		}
	}
	swap(a[pindex],a[end]);
	return pindex;
}
void Quicksort(int a[],int start,int end)
{
	int pindex;
	if(start<end)
	{
		pindex=partesion(a,start,end);
		Quicksort(a,start,pindex-1);
		Quicksort(a,pindex+1,end);
	}
}
int main()
{
	int a[]={1,4,3,8,9,6};
	Quicksort(a,0,5);
	for(int i=0;i<6;i++)
	{
		cout<<a[i]<<endl;
	}
}
