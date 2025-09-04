//Bound Found-poj-2566,题目链接<http://poj.org/problem?id=2566>
//很难弄的一个题,双指针
/*
解题思路:
1.求范围总和,要使用前缀和处理数组,变成求两个数相差最接近s
2.由于前缀处理后并没有出现明确的增或减(右窗口增加,左窗口减小),所以要排序
3.要得到上下界,要记录原有的下标,然后与数值一起排序
4.求与s最近的数就是求范围总和a与s的绝对值差尽量小,就越接近
5.用双指针来找符合相差的条件
题目细节问题
1.求最接近的数,若有多个解,似乎要求长度最短的那个
输入:
5 1
-10 -5 0 5 10
3
10 2
-9 8 -7 6 -5 4 -3 2 -1 0
5 11
15 2
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
15 100
0 0
预期输出:
5 4 4 
5 2 8
9 1 1
15 1 15
15 1 15
目前遇到的问题
1.不知道题目到底要怎样的顺序,如果多解一模一样,到底输出谁,第一组中明明可以输出5 2 2,为什么是4 4
2.若最短,那么第二组中查询5可以是-5啊,长度为1,绝对值最接近
这个题就是依托答辩
*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
//0,-9,-1,-8,-2,-7,-3,-6,-4,-5,0;
//0,1,2,3,4,5,6,7,8,9,10
//-9,-8,-7,-6,-5,-4,-3,-2,-1,0,0;
//0,-10,-15,-15,-10,0
//-15,-15,-10,-10,0,0
int main(){
        while(cin>>n>>m&&n!=0&&m!=0){
            vector<pair<int,int>> arr;
            arr.push_back({0,0});
            for(int i = 1;i<=n;i++){
                int p;cin>>p;
                arr.push_back({arr[i-1].first+p,i});
            }
            sort(arr.begin(),arr.end(),[&](const auto &a,const auto &b){
                return a.first<b.first;
            });
            while(m--){
                int s;cin>>s;
                int t = s;
                int left = 0,right  = INT_MAX,ans = 0;
                for(int i = 1,j = 0;i<=n;i++){
                    int a = arr[i].first - arr[j].first;
                    while(j<i&&a>s){
                        j++;
                        a = arr[i].first - arr[j].first;
                    }
                    if(abs(a-s)<t||(abs(a-s)==t&&abs(arr[i].second-arr[j].second)<right-left)){
                        t = abs(a-s);
                        left = arr[i].second<arr[j].second?arr[i].second:arr[j].second;
                        right = arr[i].second<arr[j].second?arr[j].second:arr[i].second;
                        ans = a;
                    }
                }
                cout<<ans<<" "<<left<<" "<<right<<endl;
            }
        }
    return 0;
}