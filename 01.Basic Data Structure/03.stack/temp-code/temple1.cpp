//反转字符串-hdu-1062,题目链接<https://acm.hdu.edu.cn/showproblem.php?pid=1062>
//相信知道栈的先进后出关系这道题应该很好理解
//栈的基础操作
/*
stack<Type> s;
s.push()入栈
s.pop()出栈
s.top()返回头顶元素
s.size()栈大小
s.empty()是否为空
*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<char> s;
int main(){
    int n;cin>>n; getchar();//读取数字后的'\n'
    while(n--){
        string str;
        getline(cin,str);//读取整行
        for(char c:str){//对行进行操作
            if(c==' '||c=='\n'){
                while(!s.empty()){cout<<s.top();s.pop();}
                cout<<' ';
            }else s.push(c);
        }
        while(!s.empty()){cout<<s.top();s.pop();}//处理未释放的,因为getline读不到最后面的'\n',会自动抛弃她
        cout<<endl;
    }
    return 0;
}