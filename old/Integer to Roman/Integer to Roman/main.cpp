//
//  main.cpp
//  Integer to Roman
//
//  Created by liang on 6/21/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/integer-to-roman/
//Given an integer, convert it to a roman numeral.
//
//Input is guaranteed to be within the range from 1 to 3999.
//
// http://baike.baidu.com/link?url=lAeqpZ-WUTiL_zxeSFyZ1lKaiQNWyWRVYMvkyL1tNl5XTnzQMvcKyRYyJxft5QFm2scIot9wsBq-KXdeeruftK
//基本字符
//
//I
//
//V
//
//X
//
//L
//
//C
//
//D
//
//M
//相应的阿拉伯数字表示为
//
//1
//
//5
//
//10
//
//50
//
//100
//
//500
//
//1000
//1、相同的数字连写，所表示的数等于这些数字相加得到的数，如：Ⅲ = 3；
//2、小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数， 如：Ⅷ = 8；Ⅻ = 12；
//3、小的数字，（限于Ⅰ、X 和C）在大的数字的左边，所表示的数等于大数减小数得到的数，如：Ⅳ= 4；Ⅸ= 9；
//4、正常使用时，连写的数字重复不得超过三次。（表盘上的四点钟“IIII”例外）
//5、在一个数的上面画一条横线，表示这个数扩大1000倍。
//、基本数字Ⅰ、X 、C 中的任何一个，自身连用构成数目，或者放在大数的右边连用构成数目，都不能超过三个；放在大数的左边只能用一个。
//2、不能把基本数字V 、L 、D 中的任何一个作为小数放在大数的左边采用相减的方法构成数目；放在大数的右边采用相加的方式构成数目，只能使用一个。
//3、V 和X 左边的小数字只能用Ⅰ。
//4、L 和C 左边的小数字只能用X。
//5、D 和M 左边的小数字只能用C。
//
//个位数举例
//Ⅰ,1 】Ⅱ，2】 Ⅲ，3】 Ⅳ，4 】Ⅴ，5 】Ⅵ，6】Ⅶ，7】 Ⅷ，8 】Ⅸ，9 】
//十位数举例
//Ⅹ，10】 Ⅺ，11 】Ⅻ，12】 XIII,13】 XIV,14】 XV,15 】XVI,16 】XVII,17 】XVIII,18】 XIX,19】 XX,20】 XXI,21 】XXII,22 】XXIX,29】 XXX,30】 XXXIV,34】 XXXV,35 】XXXIX,39】 XL,40】 L,50 】LI,51】 LV,55】 LX,60】 LXV,65】 LXXX,80】 XC,90 】XCIII,93】 XCV,95 】XCVIII,98】 XCIX,99 】
//百位数举例
//C,100】 CC,200 】CCC,300 】CD,400】 D,500 】DC,600 】DCC,700】 DCCC,800 】CM,900】 CMXCIX,999】
//千位数举例
//M,1000】 MC,1100 】MCD,1400 】MD,1500 】MDC,1600 】MDCLXVI,1666】 MDCCCLXXXVIII,1888 】MDCCCXCIX,1899 】MCM,1900 】MCMLXXVI,1976】 MCMLXXXIV,1984】 MCMXC,1990 】MM,2000 】MMMCMXCIX,3999】
//千位数以上举例
//
//，65,259 】
//，134945584】
//， 183650】

#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string result;
        string unit[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string decade[] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hundred[] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string kilobit[] = {"M", "MM", "MMM"};
        
        int index = 1;
        while (num) {
            int n = num % 10;
            if (n > 0) {
                string s;
                if (index == 1 && n > 0) {
                    s = unit[n - 1];
                } else if (index == 2) {
                    s = decade[n - 1];
                } else if (index == 3) {
                    s = hundred[n - 1];
                } else {
                    s = kilobit[n - 1];
                }
                result.insert(0, s);
            }
            index++;
            num = num / 10;
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    cout << s.intToRoman(3999) << endl;
    
    cout << s.intToRoman(2000) << endl;
    
    cout << s.intToRoman(1990) << endl;
    
    cout << s.intToRoman(1987) << endl;
    
    cout << s.intToRoman(999) << endl;
    
    cout << s.intToRoman(400) << endl;
    
    cout << s.intToRoman(10) << endl;
    
    cout << s.intToRoman(65) << endl;
    
    cout << s.intToRoman(93) << endl;
    
    cout << s.intToRoman(98) << endl;
    
    return 0;
}
