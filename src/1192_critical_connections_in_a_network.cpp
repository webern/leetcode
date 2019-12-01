#include "catch.hpp"
#include "run.h"
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <pair>
#include "utils.h"

#if RUN==1192 || defined RUN_ALL

// https://leetcode.com/problems/critical-connections-in-a-network/
// There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network
// where connections[i] = [a, b] represents a connection between servers a and b. Any server can reach any other server
// directly or indirectly through the network.
//
// A critical connection is a connection that, if removed, will make some server unable to reach some other server.
//
namespace leet_1192 {
    class Solution {
    public:
        std::vector<std::vector<int>> criticalConnections(int n, std::vector<std::vector<int>>& connections) {
            std::vector<std::vector<int>> result;
            return result;
        }
    private:
        struct TarjanNode {
        public:
            int index;
            int lowlink;
            bool isOnStack;
        };

        void tarjan( std::vector<std::vector<std::pair<int,int>>>& sccs)
    };


}

constexpr const char* const TEST_01 = "critical_connection_01";

TEST_CASE(TEST_01) {
    using namespace leet_1192;
    using namespace leet;
    std::cout << sep(TEST_01);
    std::vector<std::vector<int>> input = {{0,1},{1,2},{2,0},{1,3}};
    const std::vector<std::vector<int>> expected = {{1,3}};
    Solution s;
    const auto actual = s.criticalConnections(input.size(), input);
    CHECK( expected == actual );
}

constexpr const char* const TEST_02 = "critical_connection_02";

TEST_CASE(TEST_02) {
    using namespace leet_1192;
    using namespace leet;
    std::cout << sep(TEST_02);
    std::vector<std::vector<int>> input = {{0,1},{0,2},{0,7},{0,8},{1,2},{1,3},{2,3},{2,4},{2,8},{3,4},{4,5},{5,6},{7,8}};
    const std::vector<std::vector<int>> expected = {{5,6},{4,5}};
    Solution s;
    const auto actual = s.criticalConnections(input.size(), input);
    CHECK( expected == actual );
}

#endif