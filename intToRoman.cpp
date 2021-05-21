/* 
    Given an integer, convert it to a roman numeral.
 */


#include <iostream>
#include <vector>
#include <cassert>

std::vector<std::pair<int, std::string>> alph{
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"}
};

std::string intToRoman(int num)
{
    std::string res = "";
    int cnt;
    for (const auto &digit : alph)
    {
        cnt = num / digit.first;
        for (auto i = 0; i < cnt; ++i)
            res += digit.second;
        num -= cnt * digit.first;
    }
    return res;
}

void tests(){
    assert(intToRoman(1) == "I");
    assert(intToRoman(10) == "X");
    assert(intToRoman(9) == "IX");
    assert(intToRoman(11) == "XI");
    assert(intToRoman(51) == "LI");
    assert(intToRoman(1996) == "MCMXCVI");
    assert(intToRoman(2021) == "MMXXI");
    assert(intToRoman(1861) == "MDCCCLXI");
    assert(intToRoman(111) == "CXI");
    assert(intToRoman(666) == "DCLXVI");
    assert(intToRoman(228) == "CCXXVIII");

}
int main()
{
    tests();
    return 0;
}
