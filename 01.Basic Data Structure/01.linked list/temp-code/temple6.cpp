//利用库函数预先定义的数据结构来解决问题
//在编程时,我们往往不需要自己定义一个链表,可以直接调用库里的代码
//对于java,python,c++都是差不多的,我这里只用c++中的
//具体用法自行搜索,这里不过多展示
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    list<int> nodes;
    for(int i =1;i<=n;i++) nodes.push_back(i);
    auto it = nodes.begin();//迭代器用法
    while(nodes.size()>1){
        for(int i = 1;i<m;i++){
            it++;
            if(it==nodes.end()) it = nodes.begin();//首尾相连成环
        }
        cout<<*it<<" ";
        //因为it要向右移,再到上面for里面又要右移,连续移动了两次,会越界,所以判断
        auto next = ++it;
        if(next==nodes.end()) next = nodes.begin();
        nodes.erase(--it);
        it = next;
    }
    cout<<*it;
    return 0;
}