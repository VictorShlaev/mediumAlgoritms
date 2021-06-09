/*
* Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
* Input: nums = [1,2,3]
* Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*
* Constraints:
*    1 <= nums.length <= 6
*   -10 <= nums[i] <= 10
*    All the integers of nums are unique.

*/
#include <iostream>
#include <vector>

void rec(size_t idx, std::vector<int>& nums, std::vector<bool>& used, std::vector<int> &temp,std::vector<std::vector<int>>&res){
    if(idx == nums.size()){
        res.push_back(temp);
        return ;
    }
    for(size_t i = 0; i< nums.size(); ++i){
        if(used[i]) continue;
        temp[idx] = nums[i];
        used[i] = true;
        rec(idx+1, nums, used, temp,res);
        used[i] = false;
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<bool> used(nums.size());
    std::vector<int> temp(nums.size());
    std::vector<std::vector<int>> res;
    rec(0,nums, used, temp,res);
    return res;
}

void print(std::vector<std::vector<int>> vals){
    for(auto val: vals){
        for(auto v: val){
            std::cout<<v<<" ";
        }
        std::cout<<std::endl;
    }
}

void test(){
    std::vector<int> t1{};
    std::vector<int> t2{1};
    std::vector<int> t3{1,2};
    std::vector<int> t4{-1,0,1};
    std::vector<int> t5{1,2,3,};
    std::vector<int> t6{1,2,3,4};
    std::vector<int> t7{1,2,3,4,5};
    std::vector<int> t8{1,2,3,4,5,6};
    std::vector<std::vector<int>> tests{t1,t2,t3,t4,t5,t6,t7,t8};
    for( auto& test:tests){
        auto res = permute(test);
        print(res);
        std::cout<<std::endl;
    }
}
int main()
{
    test();
    return 0;
}
