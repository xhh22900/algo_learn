#ifndef __ALGO_XHH_CPP
#define __ALGO_XHH_CPP

#include <vector>
#include<climits>       //INT_MAX
//cpp版本的算法实现
class algo{
public:
    void insertion_sort(std::vector<int> &A);//插入排序，用vector来和体现和C语言的差别
    void merge_sort(std::vector<int>&A);
private:
    void merge(std::vector<int>&A,int p,int q,int r);//这些中间步骤都放在内部，作为私有成员
    void merge_s(std::vector<int>&A,int p,int r);
};

void algo::insertion_sort(std::vector<int> &A){
    for(int j=1;j<A.size();j++){
        int key=A[j],i=j-1;
        while(i>=0 &&A[i]>key){
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=key;
    }
}
void algo::merge(std::vector<int>&A,int p,int q,int r){
    int n1=q-p+1,n2=r-q;
    std::vector<int>L,R;
    int i,j,k;
    for(i=p;i<=q;i++)
        L.push_back(A[i]);
    for(j=q+1;j<=r;j++)
        R.push_back(A[j]);
    L.push_back(INT_MAX);
    R.push_back(INT_MAX);
    for(i=0,j=0,k=p;k<=r;k++)
        if(L[i]<=R[j])A[k]=L[i++];
        else A[k]=R[j++];
}
void algo::merge_s(std::vector<int>&A,int p,int r){
    if(p<r){
        int q=(p+r)/2;
        merge_s(A,p,q);
        merge_s(A,q+1,r);
        merge(A,p,q,r);
    }
}
void algo::merge_sort(std::vector<int>&A){
    merge_s(A,0,A.size()-1);
}

#endif