/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Example 3:

Input: haystack = "", needle = ""
Output: 0
 

Constraints:

0 <= haystack.length, needle.length <= 5 * 104
haystack and needle consist of only lower-case English characters.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        unsigned short size_needle = needle.size();
        unsigned short size_haystack = haystack.size();
        
        if (size_needle == 0) return 0;
        if (size_haystack == 0 && size_needle > size_haystack) return -1;
        
        unsigned short _index_ = 0;
        unsigned short inner_index = 0;
        while (_index_ < size_haystack)
        {
            //printf("%c, %c\n", haystack[_index_], needle[0]);
            if (haystack[_index_] == needle[0]) 
            {
                inner_index = 0;
                while (inner_index < size_needle) 
                {
                    if (haystack[_index_ + inner_index] == needle[inner_index]) ++inner_index;
                    else break;
                }
                if (inner_index == size_needle) return _index_;
            }
            {
                ++_index_;
                if (size_haystack - _index_ < size_needle) return -1;
            }
        }
        return -1;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement strStr().
Memory Usage: 7.1 MB, less than 5.24% of C++ online submissions for Implement strStr().
*/
