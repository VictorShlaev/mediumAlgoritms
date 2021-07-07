/*
* You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. 
* Each list of intervals is pairwise disjoint and in sorted order.
* Return the intersection of these two interval lists.
* A closed interval [a, b] (with a < b) denotes the set of real numbers x with a <= x <= b.
* The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval.
* For example, the intersection of [1, 3] and [2, 4] is [2, 3].
* Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
* Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
*/
#include <iostream>
#include <vector>
std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>>& firstList, std::vector<std::vector<int>>& secondList) {
	int i1 =0;
	int i2 =0;
	std::vector<std::vector<int>> res;
	while(i1 <firstList.size() and i2 < secondList.size()){
		int l = -1;
		if(firstList[i1][0] <= secondList[i2][0] and firstList[i1][1] >= secondList[i2][0]){
			l = secondList[i2][0];
		}else if(firstList[i1][0] >= secondList[i2][0] and firstList[i1][0] <= secondList[i2][1]){
			l = firstList[i1][0];
		}
		if(l != -1){
			int r = 0;
			if(firstList[i1][1] <= secondList[i2][1]){
				r = firstList[i1][1];
				i1++;
			}else{
				r = secondList[i2][1];
				i2++;
			}
			res.push_back({l,r});
		}else{
			if(firstList[i1][1] <= secondList[i2][1]) i1++;
			else i2++;
		}
	
	}
	return res;
}
int main(){
	std::vector<std::vector<int>> t1{{0,2},{5,10},{13,23},{24,25}};
	std::vector<std::vector<int>> t2{{1,5},{8,12},{15,24},{25,26}};
	auto res = intervalIntersection(t1, t2);
	for(const auto& interval: res){
		std::cout<<"["<<interval[0]<<";"<<interval[1]<<"] ";
	}
	std::cout<<std::endl;
	return 0;
}
