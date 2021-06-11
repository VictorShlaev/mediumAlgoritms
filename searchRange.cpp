/*
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 * If target is not found in the array, return [-1, -1].
 */

#include <iostream>
#include <vector>


std::vector<int> searchRange(std::vector<int>& nums, int target) {
    if(nums.empty()) return {-1,-1};
    int l = 0;
    int r = nums.size()-1;
    while(l<r){
        if(nums[l] != target) l++;
        if (nums[r] != target) r--;
        if(nums[l] == target and nums[r] == target) break;
    }
    if(nums[l] != target and nums[r] != target) return {-1,-1};
    return {l,r};
}

void printRes(std::vector<int>& r){
    for(const auto& v: r){
        std::cout<<v<<' ';
    }
    std::cout<<std::endl;
}

void test(){
    std::vector<int> t1 {1,2,5,5,5,5,7,7,8,8,10};
    std::vector<int> t2 {5};
    std::vector<int> t3 {};
    std::vector<int> t4 {1,2};
    std::vector<std::vector<int>> tests{t1,t2,t3,t4};
    for(auto& t:tests){
        auto res = searchRange(t, 5);
        printRes(res);
    }
}
int main(){
    test();
}
