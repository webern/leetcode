#pragma once

#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <sstream>

namespace leet {

    // Prints your current position in a vector of anything that can be streamed using the << operator.
    template<typename STREAMABLE>
    inline std::string printPosition(const std::vector<STREAMABLE>& values, int position) {
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

    // Prints any stack of streamable payload type.
    template<typename STACK_TYPE>
    inline std::string printStack(STACK_TYPE stk) {
        std::vector<typename STACK_TYPE::value_type> values;
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

    static constexpr const int DEFAUJLT_SEP_SIZE = 100;

    // Creates a separator of size n, with any text
    inline std::string sep(int size, const std::string& message) {
        std::stringstream ss;
        ss << "\n";
        for(int i = 0; i < size; ++i) {
            ss << "-";
        }
        ss << "\n";
        if(!message.empty()) {
            ss << "-- " << message;
            ss << "\n";
            for(int i = 0; i < size; ++i) {
                ss << "-";
            }
            ss << "\n";
        }
        ss << "\n";
        return ss.str();
    }

    inline std::string sep(int size) {
        return sep(size, "");
    }

    inline std::string sep() {
        return sep(DEFAUJLT_SEP_SIZE);
    }

    inline std::string sep(const std::string& message) {
        return sep(DEFAUJLT_SEP_SIZE, message);
    }

    template <typename T>
    inline bool operator==(const std::vector<T>& left, const std::vector<T>& right) {
        if(left.size() != right.size()) {
            return false;
        }
        for(size_t i = 0; i < left.size(); ++i) {
            if(left[i] != right[i]) {
                return false;
            }
        }
        return true;
    }

    template <typename T>
    inline bool operator!=(const std::vector<T>& left, const std::vector<T>& right) {
        return !(left == right);
    }
}