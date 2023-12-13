// 20. Valid Parentheses

#include <Windows.h>
#include <iostream>
#include <stack>

#include "Timer.h"

using namespace std;

// Для решения задачи использован символьный стек.
//  Будем двигаться последовательно по символам входной строки:
//  - если текущий символ является открывающейся скобкой, то заносим его в стек.
//  - если текущий символ является закрывающейся скобкой,
//    то на вершине стека должна находиться соответствующая ему открывающаяся скобка.
//    Если это не так, или если стек пуст, то скобочное выражение не является правильным.
//
// По окончанию обработки правильной строки стек должен оказаться пустым.
//
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++)
        {
            if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{'))
                st.push(s[i]);
            else
            {
                if (st.empty())
                    return false;
                if ((s[i] == ')') && (st.top() != '('))
                    return false;
                if ((s[i] == ']') && (st.top() != '['))
                    return false;
                if ((s[i] == '}') && (st.top() != '{'))
                    return false;
                //
                st.pop();
            }
        }
        //
        return st.empty();
    }
};


/* Driver Function to test other function */
int main()
{
    SetConsoleOutputCP(CP_UTF8);

    Solution S;
    // true / true / false
    const string s1 {"()"}, s2{"()[]{}"}, s3 {"(]"};
    Timer T(s1);
    cout << boolalpha << S.isValid (s1) << endl;
    T.print();

    T.start(s2);
    cout << boolalpha << S.isValid (s2) << endl;
    T.print();

    T.start(s3);
    cout << boolalpha << S.isValid (s3) << endl;
    T.print();

    return 0;
}
