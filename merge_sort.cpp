#include<iostream>
using namespace std;
void Merge(int a[],int l,int m,int r)
{
  int n1=m-l+1;
  int n2=r-m;
  int a1[n1],a2[n2],i,j,k;
  for(i=0;i<n1;i++)
    a1[i]=a[l+i];
  for(i=0;i<n2;i++)
    a2[i]=a[m+1+i];
  i=0;
  j=0;
  k=l;
  while(i<n1 && j<n2)
  {
    if(a1[i]>a2[j])
    {
      a[k]=a2[j];
      j++;
    }
    else
    {
      a[k]=a1[i];
      i++;
    }
    k++;
  }
  while(i<n1)
  {
    a[k]=a1[i];
    i++;
    k++;
  }
  while(j<n2)
  {
    a[k]=a2[j];
    j++;
    k++;
  }
}
void Merge_sort(int a[],int l,int r)
{
  if(l<r)
  {
    int mid=(l+r)/2;
    Merge_sort(a,l,mid);
    Merge_sort(a,mid+1,r);
    Merge(a,l,mid,r);
  }
}
int main()
{
  int a[]={1,2,0,3,4,0},i;
  int n = sizeof(a)/sizeof(a[0]);
  Merge_sort(a,0,n-1);
  for(i=0;i<n;i++)
    cout<<a[i]<<" ";
  cout<<endl;
}
