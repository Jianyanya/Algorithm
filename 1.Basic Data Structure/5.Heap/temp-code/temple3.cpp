//SPOJ-Running Median Again,题目链接<https://www.spoj.com/problems/RMID2/>
//经典题目类型:需要维护前 k 大/小的题目
//题目很简单,就是维护一个有序序列,求其中的中位数
//我们每次放入和删除数据的时候都要保证数组的有序性,那么就要请出优先队列帮我们来排序
//但中位数怎么办,优先队列是不支持随机访问的,只能访问头
//既然只能访问头,那我就让这个中位数为头不就行了,怎么让它为头
//中位数的前面是小于他的数,对于前半部分,中位数是最大值在堆顶,为最大堆
//中位数的后面是大于他的数,对于后半部分,中位数是最小值在堆顶,为最小堆
//要两个堆(最大和最小)实现的就是对顶堆
//1,2,5   9,10,18
//要取中位数,首先要保证左右堆长度,左堆长度要大右长度1个
//这样取中位数就是left的堆顶
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    while(n--){
        priority_queue<int,vector<int>> left;
        priority_queue<int,vector<int>,greater<int>> right;
        int m;
        while(cin>>m&&m!=0){
            if(m!=-1) left.push(m);
            else{
                cout<<left.top();
                left.pop();
            }
            while(left.size()<right.size()) left.push(right.top()),right.pop();
            while(left.size()-right.size()>1) right.push(left.top()),left.pop();
        }

    }
    return  0;
}
