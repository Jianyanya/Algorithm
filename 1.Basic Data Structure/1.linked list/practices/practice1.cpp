//题目来源<https://www.luogu.com.cn/problem/P1160>
//模拟题,看到要插入删数据反应链表
//一定要先尝试自己做,因为你第一次做绝对会超时
//提示:在任何位置进行插入和删除的操作时间都为O(1);
//链表不能进行随机访问,那我们就预先储存好每一个数据的迭代器位置
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
list<int>::iterator pos[N];
bool erased[N];
int main(){
    list<int> lt = {1};
    pos[1] = lt.begin();
    int n;cin>>n;
    for(int i = 2;i<=n;i++){
        int a,b;cin>>a>>b;
        //auto it = find(lt.begin(),lt.end(),a);用find是随机访问时间为O(n),必然超时
        if(b) pos[i] = lt.insert(next(pos[a]),i);
        else pos[i] = lt.insert(pos[a],i);
    }
    int m;cin>>m;
    while(m--){
        int p;cin>>p;
        //lt.remove(p);remove是删除所有值为p的点,会遍历整个链表,超时
        if(!erased[p]) lt.erase(pos[p]);
        erased[p] = true;
    }
    for(auto it = lt.begin();it!=lt.end();++it){
        cout<<*it<<" ";
    }
    return 0;
}