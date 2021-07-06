/*
* There is an integer array nums sorted in ascending order (with distinct values).
* Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
* Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
* You must write an algorithm with O(log n) runtime complexity.
* Input: nums = [4,5,6,7,0,1,2], target = 0
* Output: 4
*/

#include <iostream>
#include <vector>
#include <algorithm>
//search with stl, O(n)
int naive(std::vector<int>&nums, target){
  auto res = std::find(nums.begin(), nums.end(), target);
  if(res != nums.end()) return std::distance(nums.begin(), res);
  return -1;
}

//find k O(logn)
int searchK(std::vector<int>& nums){
	int l = 0;
	int r = nums.size()-1;
	int m = 0;
	while(l < r){
		int m = (l+r)/2;
		if(l == m) return m;
		if(nums[l] < nums[m]){
			l = m;
		}else{
			r = m;
		}
	}	
	return m;
}
//binary search O(logn)
int binSearch(std::vector<int>& nums, int target, int left, int right){
	int l = left;
	int r = right;
	int m = 0;
	while(l<=r){
		m = (l+r)/2;
		if(nums[m] == target) return m;
		if(nums[m] > target) r = m-1;
		else l = m+1;
	}
	return -1;
}
//find k, then binSearch [0,k] and [k+1, n);
int search(std::vector<int>& nums, int target) {
	int k = searchK(nums);
	int first = binSearch(nums, target, 0, k);
	if(first != -1) return first;
	int second = binSearch(nums, target, k+1, nums.size()-1);
	if(second != -1) return second;
	return -1;
}

int main(){

	std::vector<int> test1{4,5,6,7,0,1,2};
	std::cout<<searchK(test1)<<"\n";
	for(const auto& v: test1){
		std::cout<<v<<" ";
	}
	std::cout<<std::endl;
	int target = 0;
	while(true){
		std::cin>>target;
		std::cout<<target<<": "<<search(test1, target)<<std::endl;
	}
	return 0;
}
