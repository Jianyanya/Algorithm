//把j>i的且颜色与i相同的数尽量小
//把i均分给后面所有的i+nk
//因为重复所以其实只需要思考第一个k范围内的值
//8 2 4  ->5 5 4
//5 2 ->4 3
//5 3 -> 4 4
//4 16 1 1  ->4 6 6 6
#include <iostream>
using namespace std;
//二分答案
/*

*/
class Solution{
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
}
};
//直接取最小平均前缀
/*

*/
class Solution{
    const int N = 1e5+10;
int n,k;
int arr[N];
int main(){
    cin>>n>>k;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int ans =INT_MAX ;
    for(int i = 0;i<k;i++){
        int sum = 0;
        int cnt = 0;
        for(int j = i;j<n;j+=k){
            sum += arr[j];
            cnt++;
            ans = min(ans,sum/cnt);
        }
    }
    cout<<ans;
    return 0;
}
};