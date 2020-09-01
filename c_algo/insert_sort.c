#include<stdio.h>
#include "algo_xhh.h"

int main(void){
    int arr[]={5,2,4,6,1,3};
    int len=sizeof(arr)/sizeof(int);
    //insertion_sort(arr,len);
    merge_sort(arr,0,len-1);

    for(int i=0;i<len;i++)
        printf("%d ",arr[i]);
    putchar('\n');

    return 0;
}