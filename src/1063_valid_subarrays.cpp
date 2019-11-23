#include "catch.hpp"
#include "run.h"
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>

#if RUN==1063 || defined RUN_ALL

// https://leetcode.com/problems/number-of-valid-subarrays/
// Given an array A of integers, return the number of non-empty continuous subarrays that satisfy the following
// condition:
// The leftmost element of the subarray is not larger than other elements in the subarray.
//
// The intuiting behind this algorithm is extremely difficult to understand.
//
namespace valid_subarrays_1063 {

    inline std::string printPosition(const std::vector<int>& values, int position) {
        std::stringstream valueString;
        std::stringstream arrowHead;
        int idx = 0;
        bool isFirst = true;
        for(const auto& v : values) {
            if(isFirst) {
                valueString << "[";
                arrowHead << " ";
                isFirst = false;
            } else {
                valueString << ", ";
                arrowHead << "  ";
            }
            std::stringstream temp;
            temp << v;
            const auto tempStr = temp.str();
            const int sz = static_cast<int>(tempStr.size());
            valueString << tempStr;
            if(idx < position) {
                for(int i = 0; i < sz; ++i) {
                    arrowHead << " ";
                }
            } else if (idx == position) {
                arrowHead << "^";
            }
            ++idx;
        }
        valueString << "]";
        const std::string output = valueString.str() + "\n" + arrowHead.str();
        return output;
    }

    inline std::string printStack(std::stack<int> stk) {
        std::vector<int> values;
        while(!stk.empty()) {
            values.push_back(stk.top());
            stk.pop();
        }
        std::stringstream ss;
        bool isFirst = true;
        ss << "[";
        for(const auto& x : values) {
            if(!isFirst) {
                ss << ",";
            }
            ss << x;
            isFirst = false;
        }
        ss << "]";
        return ss.str();
    }

    class Solution {
    public:
        int validSubarrays(std::vector<int> &nums) {
            std::stack<int> stk;
            int res = 0;
            int idx = 0;
            for(int n : nums) {
                std::cout << "----------------------------------------------" << std::endl;
                std::cout << "outer loop: idx=" << idx << ", n=" << n << ", stack: " << printStack(stk) << std::endl;
                std::cout << printPosition(nums, idx) << std::endl;
                while(!stk.empty() && stk.top() > n) {
                    stk.pop();
                    std::cout << "idx: "<< idx << ", n: " << n << ", stack popped: " << printStack(stk) << std::endl;
                }
                stk.push(n);
                std::cout << "idx: "<< idx << ", n: " << n << ", stack pushed: " << printStack(stk) << std::endl;
                res += stk.size();
                ++idx;
            }
            return res;
        }
    };
}

TEST_CASE("valid_subarrays_01") {
    using namespace valid_subarrays_1063;
    Solution s;
    std::vector<int> nums = {1, 4, 2, 5, 3};
    const auto expected = 11;
    const auto actual = s.validSubarrays(nums);
    CHECK( expected == actual );
}

TEST_CASE("valid_subarrays_02") {
    using namespace valid_subarrays_1063;
    Solution s;
    std::vector<int> nums = {5, 4, 1, 3, 2};
    const auto expected = 7;
    const auto actual = s.validSubarrays(nums);
    CHECK( expected == actual );
}

#endif