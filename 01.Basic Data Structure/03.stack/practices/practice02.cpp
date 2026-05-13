//后缀表达式-洛谷-p1449,题目链接<https://www.luogu.com.cn/problem/P1449>
/*
非常经典的栈应用题,就是计算机计算的原理
3,5,2入栈,-号,使入栈的两数5-2=3,再把3压入栈中,此时栈为3,3;遇到*,使栈上中两数3*3=9,再把9压入
7入栈,遇到+,再把两数相加9+7=16,@结束;
知道了规则就是模拟了
提示:用手写的栈模拟最好,可以直接获取栈顶和栈第二个元素
*/
#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int main(){
    char c;
    int n = 0;
    while((c=getchar())!='@'){
        if(c>='0'&&c<='9') n = n*10+c-'0';
        else if(c=='.') s.push(n),n = 0;
        else if(c=='+'){
            int a = s.top();
            s.pop();
            int b = a+s.top();
            s.pop();
            s.push(b);
        }else if(c=='-'){
            int a = s.top();
            s.pop();
            int b = s.top()-a;
            s.pop();
            s.push(b);
        }else if(c=='*'){
            int a = s.top();
            s.pop();
            int b = a*s.top();
            s.pop();
            s.push(b);
        }else if(c=='/'){
            int a = s.top();
            s.pop();
            int b = s.top()/a;
            s.pop();
            s.push(b);
        }
    }
    cout<<s.top();
    return 0;
}