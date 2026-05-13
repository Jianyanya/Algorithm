//把hdu-p1003题改一下
//从不定问题变为限定子数组长度问题,就是在题目中加上返回m长度的子数组最大和
//这个时候可以用定长滑窗和单调队列来做
//说实话滑窗太简单了...
//那如何用单调队列做呢,我们记住,无论怎么操作,我们都可以给单调队列定义队头为最值,队列的作用就是维护一个固定的窗口,并把最小值放在最左边以便取出
//既然最小值在队列左边,那我枚举最大值不就完了吗,要得到范围内的值,使用前缀和
//单调队列
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    vector<int> arr(n+1);
    for(int i = 0;i<n;i++){
        int m;cin>>m;
        arr[i+1] = arr[i]+m;//预处理前缀和
    }
    deque<int> dq;
    dq.push_back(0);//初始化;
    int ans = 0;
    for(int i = 1;i<=n;i++){
        while(!dq.empty()&&dq.front()<i-m) dq.pop_front();//思考为什么这里不是<=,因为有个0在前面
        ans = max(ans,arr[i]-arr[dq.front()]);//答案条件
        while(!dq.empty()&&arr[i]<=arr[dq.back()]) dq.pop_back();//比我大的闪开
        dq.push_back(i);
    }
    cout<<ans;
    return 0;
}
//定长滑窗模板
/*
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
*/    