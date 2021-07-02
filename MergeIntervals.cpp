/*
* Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
* Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
* Output: [[1,6],[8,10],[15,18]]
*Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    std::vector<std::vector<int>> res{}; 
    std::sort(intervals.begin(), intervals.end(), [=](std::vector<int>& l, std::vector<int>& r){
        return l[0]< r[0];
    });
    for(const auto& interval: intervals){
        if(!res.empty() and interval[0] <= res[res.size()-1][1]){
            res[res.size()-1][1] = std::max(res[res.size()-1][1], interval[1]);
        }else{
            res.push_back(interval);
        }
    }
    return res;
}

void printVec(const std::vector<std::vector<int>>& vec){
    for(const auto& line: vec){
        std::cout<<"[";
        for(const auto& val: line){
            std::cout<<val<<",";
        }
        std::cout<<'\b'<<"] ,";
    }
}

int main()
{
    std::vector<std::vector<int>> vals{{1,3}, {6,9}};
    std::vector<int> newInterval {2,5};
    auto res = merge(vals, newInterval);
    printVec(res);
    return 0;
}
