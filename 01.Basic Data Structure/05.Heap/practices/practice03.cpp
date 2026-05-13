//最大平均通过率-leetcode-1792,题目链接<https://leetcode.cn/problems/maximum-average-pass-ratio>
//就是看谁增的多就给谁加,因为好学生加入必然增加通过率(除了100%)
//记录增加的值,再把增加的值和对应的分子和分母放入堆中,谁增的多就给谁加,循环e次,取堆中最大的加
#include<bits/stdc++.h>
using namespace std;
//1.用浮点数
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        using dr = tuple<double,int,int>;
        auto cam = [](const dr&a,const dr&b){
            return get<0>(a) < get<0>(b);
        };
        priority_queue<dr,vector<dr>,decltype(cam)> pq;
        for(auto &c:classes){
            int a = c[0],b = c[1];
            pq.emplace(1.0*(b-a)/(1LL*b*(b+1)),a,b);
        }
        while(extraStudents--){
            auto [_,a,b] = pq.top();
            pq.pop();
            a++;
            b++;
            pq.emplace(1.0*(b-a)/(1LL*b*(b+1)),a,b);
        }
        double ans = 0;
        int len = classes.size();
        while(!pq.empty()){
            auto [_,a,b] = pq.top();
            pq.pop();
            ans += 1.0*a/b;
        }
        return ans/len;
    }
};
//不用浮点数,因为浮点数不精确
//比较前后差a/b>c/d等同于ad>bc
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        struct dr {int a, b;};
        auto cam = [](const dr&a,const dr&b){
            return 1LL*(a.b-a.a)*b.b*(b.b+1)<1LL*(b.b-b.a)*a.b*(a.b+1);
        };
        priority_queue<dr,vector<dr>,decltype(cam)> pq;
        for(auto &c:classes){
            int a = c[0],b = c[1];
            pq.emplace(a,b);
        }
        while(extraStudents--){
            auto [a,b] = pq.top();
            pq.pop();
            a++;
            b++;
            pq.emplace(a,b);
        }
        double ans = 0;
        int len = classes.size();
        while(!pq.empty()){
            auto [a,b] = pq.top();
            pq.pop();
            ans += 1.0*a/b;
        }
        return ans/len;
    }
};