//hdu-p1062,手写栈
//因为栈实在太简单,你可以自己试试手写相关的方法
#include<iostream>
#include<string>
using namespace std;
const int N = 100100;
struct mystack{
    char chars[N];//根据题目改变栈的数据类型和大小
    int t = 0;//顶,有的视频里是-1,不过无所谓,自己造的想怎么定义怎么定义
    void push(char c){chars[++t] = c;}//入栈,自己理解为什么是++t
    char top(){return chars[t];};
    void pop(){t--;};
    bool empty(){return t==0;}
}s;
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