/*
* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
* The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
* How many possible unique paths are there?
* Input: m = 3, n = 7
* Output: 28
*/

#include <iostream>
#include <cassert>
int uniquePaths(int m, int n) {
    int paths[n][m];
    for(int i = 0; i < n; ++i){
        paths[i][0] = 1;
    }
    for(int i= 0; i < m; ++i){
        paths[0][i] = 1;
    }
    for(int i = 1; i < n; ++i){
        for(int j = 1; j< m; ++j){
            paths[i][j] = paths[i-1][j]+paths[i][j-1];
        }
    }
    return paths[n-1][m-1];
}

void testUnique(){
    std::cout<<"Start tests! "<<std::endl;
    assert(uniquePaths(3,7)==28);
    assert(uniquePaths(7,3)==28);
    assert(uniquePaths(3,3)==6);
    assert(uniquePaths(2,3)==3);
    assert(uniquePaths(3,2)==3);
    assert(uniquePaths(3,0)==1);
    assert(uniquePaths(0,3)==1);
    assert(uniquePaths(0,0)==1);
    std::cout<<"All tests completed successfully!"<<std::endl;
}
int main()
{
    testUnique();
    return 0;
}
