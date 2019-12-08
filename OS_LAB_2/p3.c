#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int partition(int arr[],int l,int r)
{
 int i,j,temp,pivot;
 pivot=arr[l];
 i=l;
 j=r+1;
 
 do
 {
  do
   i++;
  while(arr[i]<pivot && i<=r);
  
  do
   j--;
  while(arr[j]>pivot);

  if(i<j)
  {
   temp=arr[i];
   arr[i]=arr[j];
   arr[j]=temp;  
  }
 }
 while(i<j);
 
 arr[l]=arr[j];
 arr[j]=pivot;
 
 return j;
}

void quickSort(int arr[],int l,int r)
{
 int pivot;
 if(l<r)
 {
  pivot = partition(arr,l,r);
  quickSort(arr,l,pivot-1);
  quickSort(arr,pivot+1,r);  
 }
}



void merge(int arr[],int l1,int r1,int l2,int r2)
{
 int temp[51];
 int i,j,k;
 i=l1;
 j=l2;
 k=0;

 while(i<=r1 && j<=r2)
 {
  if(arr[i]<arr[j])
   temp[k++]=arr[i++];
  else
   temp[k++]=arr[j++];
 } 

 while(i<=r1)
  temp[k++]=arr[i++];

 while(j<=r2)
  temp[k++]=arr[j++];
 
 for(i=l1,j=0;i<=r2;i++,j++)
  arr[i]=temp[j];
}


void mergeSort(int arr[],int l,int r)
{
 int m;
 if(l<r)
 {
  m=(l+r)/2;
  mergeSort(arr,l,m);
  mergeSort(arr,m+1,r);
  merge(arr,l,m,m+1,r);
 } 
}



int main()
{
 int n,pid;
 int arr[100]; //Max size 100

 printf("\nEnter the number of elements :");
 scanf("%d",&n);
 int i;

 printf("\nEnter the %d elements :",n);
 for(i=0;i<n;i++)
 { 
  scanf("%d",&arr[i]);
 }

 pid=fork();

 if(pid==0)
 {
  printf("\nI am a child process (PID=%d). I will perform quick sort. \n",pid);
  quickSort(arr,0,n-1);
  printf("\nSorted Array is : ");  
  int i;
  for(i=0;i<n;i++)
   printf(" %d ",arr[i]);
 }
 else
 {
 
  wait(0);
  printf("\nI am a Parent process (PID=%d). I was waiting for my child process. Now i will execute merge sort. \n", pid);
  mergeSort(arr,0,n-1);
  printf("\nSorted Array is : ");  
  for(i=0;i<n;i++)
   printf(" %d ",arr[i]);
 }
 
 printf("\n\n");
 return 0;
}








