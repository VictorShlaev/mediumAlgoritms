/*
* Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
*
*    0 <= a, b, c, d < n
*   a, b, c, and d are distinct.
*  nums[a] + nums[b] + nums[c] + nums[d] == target
*
* You may return the answer in any order.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
{
    std::set<std::vector<int>> setRes;
    std::sort(nums.begin(), nums.end());
    int l = 0;
    int r = nums.size() - 1;
    for (; l < r; ++l)
    {
        for (; r > l; --r)
        {
            int l1 = l + 1;
            int r1 = r - 1;
            int a = nums[l];
            int b = nums[r];
            while (l1 < r1)
            {
                int c = nums[l1];
                int d = nums[r1];
                if (c + d + a + b == target)
                {
                    std::vector<int> tmp{a, b, c, d};
                    std::sort(tmp.begin(), tmp.end());
                    setRes.insert(tmp);
                    l1++;
                }
                else if (a + b + c + d > target)
                {
                    r1--;
                }
                else
                {
                    l1++;
                }
            }
        }
        r = nums.size() - 1;
    }

    std::vector<std::vector<int>> res;
    std::copy(setRes.begin(), setRes.end(), std::back_inserter(res));
    return res;
}

void printTest(std::vector<std::vector<int>> &res, size_t testNum)
{
    std::cout << "start print  test " << testNum << " results" << std::endl;
    for (const auto &row : res)
    {
        for (const auto &ceill : row)
        {
            std::cout << ceill << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "End print test " << testNum << " results! " << std::endl;
}

void tests()
{
    std::vector<int> nums{1, 0, -1, 0, -2, 2};
    std::vector<int> nums1{2, 2, 2, 2, 2, 2};
    std::vector<int> nums2{-3, -1, 0, 2, 4, 5};

    std::vector<std::vector<int>> tests{nums, nums1, nums2};
    int target = 0;
    for (size_t i = 0; i < tests.size(); ++i)
    {
        auto res = fourSum(tests[i], target);
        printTest(res, i);
    }
}
int main()
{
    tests();
    return 0;
}
