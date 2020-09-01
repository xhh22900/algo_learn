#include<iostream>
#include "algo_xhh_cpp.h"

int main(){
    std::vector<int> arr={5,2,4,6,1,3};
    algo al;
    al.merge_sort(arr);
    for(auto c:arr)
        std::cout<<c<<" ";
    std::cout<<std::endl;

    return 0;
}