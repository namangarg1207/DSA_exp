#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>




int binarysearch(int data,int n,int arr[]){
    int l=0,r=n-1;
   
     for (int i = 0; i <= n-1; i++)
    {
        int min = INT_MAX;
        int mindx = -1;
        for (int j = i; j <= n-1; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                mindx = j;
            }
        }
        int temp = arr[mindx];
        arr[mindx] = arr[i];
        arr[i] = temp;
    }
   
while(l<r){
     int mid=(l+r)/2;
    if(data==arr[mid]){
        return mid;}
    else if(data<arr[mid]){
        r=mid-1;   
    }
    else if(data>arr[mid]){
        l=mid+1;  
    }
}if(l>r){return -1;}
}


void main(){
      int arr[]={23,45,67,34,98,2,45,7,0};
      int index=binarysearch(2,9, arr);

      printf("index is:%d",index);







    
}