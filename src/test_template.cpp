#include "catch.hpp"
#include "run.h"
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include "utils.h"

#if RUN==XXXX || defined RUN_ALL

// https://leetcode.com/problems/XXXXXX/
//
namespace leet_XXXX {
    class Solution {
    public:
        std::vector<std::vector<int>> criticalConnections(int n, std::vector<std::vector<int>>& connections) {
            std::vector<std::vector<int>> result;
            return result;
        }
    };
}

constexpr const char* const TEST_01 = "XXXX_01";

TEST_CASE(TEST_01) {
    using namespace leet_XXXX;
    using namespace leet;
    std::cout << sep(TEST_01);

}

constexpr const char* const TEST_02 = "XXXX_02";

TEST_CASE(TEST_02) {
    using namespace leet_XXXX;
    using namespace leet;
    std::cout << sep(TEST_02);
}

#endif