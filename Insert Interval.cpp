/*
* Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
* You may assume that the intervals were initially sorted according to their start times.
* Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
* Output: [[1,5],[6,9]]
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& nI) {
    intervals.push_back(nI);
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

void test(){
   std::vector<std::vector<int>> vals{{1,3}, {6,9}};
    std::vector<int> newInterval {2,5};
    auto res = InsInterval::insert(vals, newInterval);
    InsInterval::printVec(res);
}
int main()
{
    test();
    return 0;
}
