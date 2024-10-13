#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Line{
public:
    Line(int n);
    int re_line(stack<char>, int, int);

private:
    string init, dest;
};

Line::Line(int n){
    for (int i = 0; i < n; i++)
    {
        char temp;
        cin >> temp;
        init += temp;
    }
    for (int i = 0; i < n; i++)
    {
        char temp;
        cin >> temp;
        dest += temp;
    }
}

/// @brief 重排队函数
/// @param S 存储已入栈小蓝鲸
/// @param i_pos 初始队列处理位置下标
/// @param d_pos 目标队列匹配下标
/// @return 重排队方法数
int Line::re_line(stack<char> S, int i_pos, int d_pos)
{
    int ans = 0;
    //未处理结束
    if (i_pos < init.length())
    {
        //优先进行入栈操作
        S.push(init[i_pos]);
        ans += re_line(S, i_pos + 1, d_pos);
        S.pop();
        //可进行出栈操作
        if(!S.empty() && S.top() == dest[d_pos])
        {
            S.pop();
            ans += re_line(S, i_pos, d_pos + 1);
        }
    }
    else
    //全部元素已处理完成，检测是否合规
    {
        while(!S.empty())
            if (S.top() == dest[d_pos++])
                S.pop();
            else
                return 0;
        return 1;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    Line l(n);
    const stack<char> S;
    cout << l.re_line(S, 0, 0);
    return 0;
}