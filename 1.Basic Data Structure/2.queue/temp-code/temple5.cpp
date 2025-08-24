//把hdu-p1003题改一下
//从不定问题变为限定子数组长度问题,就是在题目中加上返回m长度的子数组最大和
//这个时候可以用定长滑窗和单调队列来做
//说实话滑窗太简单了...

//定长滑窗模板
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    vector<int> arr(n+1);
    for(int i = 1;i<=n;i++) cin>>arr[i];
    int start = 1,end = 1,mx = arr[1];
    int sum = 0;
    for(int right = 1;right<=n;right++){
        sum += arr[right];//进窗
        int k = right-m+1;
        if(k<1) continue;//处理第一个窗口
        if(sum>mx){//窗内处理(答案条件)
            start = k;
            end = right;
            mx = sum;
        }
        sum -= arr[k];//出窗
    }
    cout<<mx<<endl;
    cout<<left<<endl;
    cout<<right<<endl;
    return 0;
}