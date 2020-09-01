#ifndef  __ALGO_XHH     
#define __ALGO_XHH

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>//INT_MAX
void insertion_sort(int A[],int len);//快速排序算符  
//最好情况的时间花费：n，最坏情况为n^2
//归并排序，分治法
void merge(int A[],int p,int q,int r);//合并步骤
void merge_sort(int* A,int p, int r);//归并排序


void insertion_sort(int *A,int len){
    for(int j=1;j<len;j++){
        int key=A[j];
        int i=j-1;
        while(i>=0 && A[i]>key){
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=key;
    }
}

void merge(int *A,int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;
    int *L=(int*) calloc(n1+1,sizeof(int));
    int *R=(int*)calloc(n2+1,sizeof(int));
    int i,j,k;
    for(i=0;i<n1;i++)
        L[i]=A[p+i];
    for(i=0;i<n2;i++)
        R[i]=A[q+i+1];
    L[n1]=INT_MAX;
    R[n2]=INT_MAX;
    for(i=0,j=0,k=p;k<=r;k++)
        if(L[i]<=R[j])A[k]=L[i++];
        else A[k]=R[j++];
    free(L);
    free(R);
}
void merge_sort(int *A,int p,int r){
    if(p<r){
        int q=(p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
    }
}



#endif