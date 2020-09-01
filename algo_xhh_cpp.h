#ifndef __ALGO_XHH_CPP
#define __ALGO_XHH_CPP

#include <vector>
//cpp版本的算法实现
void insertion_sort(std::vector<int> &A);//插入排序，用vector来和体现和C语言的差别



void insertion_sort(std::vector<int> &A){
    for(int j=1;j<A.size();j++){
        int key=A[j],i=j-1;
        while(i>=0 &&A[i]>key){
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=key;
    }
}

#endif