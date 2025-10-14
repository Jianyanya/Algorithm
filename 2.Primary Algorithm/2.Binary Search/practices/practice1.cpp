//蓝桥杯c++16届c组第六题<https://www.lanqiao.cn/problems/20529/learning/>
//二分答案
/*
1.从答案方向来看,我的水装的越多越好,水越多就能满足更多的水瓶,但是我要找到最小的那个符和条件的值,答案有单调性
2.看答案的范围,直接二分搜,然后写check函数,贪心的实现差不多1300分,加上二分差不多1500以上
tip:二分答案最直接关键信息(最小的最大可能),所以这道题最多1400分,蓝桥确实水
*/
#include <iostream>
using namespace std;
const int N = 1e5+10;
int n,m;
int arr[N];
bool check(int mid){
    for(int i = 0;i<m;i++){
        int t = 0;
        for(int j = i;j<n;j+=m){
            if(arr[j]+t>=mid) t = arr[j]+t-mid;
            else return false;
        }
    }
    return true;
}
int main()
{
  cin>>n>>m;
  for(int i = 0;i<n;i++){
      cin>>arr[i];
  }
  int left = 1,right = 1e5;
  int ans = 0;
  while(left<=right){
      int mid = (left+right)/2;
      if(check(mid)) left = mid+1,ans = mid;
      else right = mid-1;
  }
  cout<<ans;
  return 0;
};