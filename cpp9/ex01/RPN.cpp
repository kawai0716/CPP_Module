#include "RPN.hpp"

#include <stack>
#include <list>
#include <sstream>
#include <cctype>

RPN::RPN() {}
RPN::RPN(const RPN& other) { (void)other; }
RPN& RPN::operator=(const RPN& other) { (void)other; return *this; }
RPN::~RPN() {}

static bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::evaluate(const std::string& expr, long long& result) {
    std::stack<long long, std::list<long long> > st;
    std::istringstream iss(expr);
    std::string token;

    while (iss >> token) {
        if (token.size() == 1 && std::isdigit(token[0])) {
            st.push(token[0] - '0');
        } else if (token.size() == 1 && isOperator(token[0])) {
            if (st.size() < 2) {
                return false;
            }
            long long b = st.top();
            st.pop();
            long long a = st.top();
            st.pop();
            long long res = 0;
            if (token[0] == '+') {
                res = a + b;
            } else if (token[0] == '-') {
                res = a - b;
            } else if (token[0] == '*') {
                res = a * b;
            } else if (token[0] == '/') {
                if (b == 0) {
                    return false;
                }
                res = a / b;
            }
            st.push(res);
        } else {
            return false;
        }
    }

    if (st.size() != 1) {
        return false;
    }
    result = st.top();
    return true;
}
