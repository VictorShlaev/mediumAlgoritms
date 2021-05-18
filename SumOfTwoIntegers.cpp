/*
 *Given two integers a and b, return the sum of the two integers without using the operators + and -.
 *
 *
 *
*/

#include <iostream>
#include <bitset>
#include <cassert>
std::bitset<32> addTwoNumbers(std::bitset<32> a, std::bitset<32> b){
    int8_t remainder = 0;
    std::bitset<32> res(0);
    for(size_t i = 0; i <a.size(); ++i){
        int val = a[i]^b[i];
        if(remainder == 0){
            if(val == 1){
                res.set(i);
            }else{
                if(a[i] == 1){
                    remainder = 1;
                }
            }
        }
        else{
            if(val == 1){
                remainder = 1;
            }else{
                res.set(i);
                remainder = a[i] == 1? 1:0;
            }
        }
    }
    return res;
}

int add(int a, int b){
   std::bitset<32> bitsA(a);
   std::bitset<32> bitsB(b);
   return int(addTwoNumbers(bitsA, bitsB).to_ulong());
}
void Tests(){
    assert(add(-100, 1000) == 900);
    assert(add(100, 1000) == 1100);
    assert(add(-100, -1000) == -1100);
    assert(add(100, -1000) == -900);
    assert(add(0, -1000) == -1000);
    assert(add(0, 0) == 0);
}
int main()
{
    Tests();
    return 0;
}
