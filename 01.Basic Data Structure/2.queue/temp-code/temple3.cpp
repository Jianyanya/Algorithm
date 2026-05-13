//滑动窗口/单调队列-洛谷-p1886,题目链接<https://www.luogu.com.cn/problem/P1886>;
//双端队列就是一个很不规矩的队列,前面能进后面也能进,前面能出,后面也能出
//主要说单调队列问题,单调队列中的元素是单调有序的,且元素在队列当中的顺序和原来在序列中的顺序是一样的;
//灵活的运用单调队列能够使很多问题的求解得到优化.他的原理就是
//序列中中的n个元素,用单调队列处理时,每个元素只需要进出队列一次,复杂度为O(n);
//以题目为列,做完后再来看这句话
//主要用stl中的deque来实现
/*
dq.front队头
dq.back()返回队尾元素
dq.pop_back()删除队尾
dq.pop_front()删除队头
dq.push_back()入队尾
dq.push_front()入队头
*/
//首先先分析题目,就是一个滑窗在一组数据上滑,记录每次窗口内的最大值和最小值;
//先用常规思路看,用两个变量记录变化过程中的最大值和最小值就行,可是在左边删除滑窗内元素的时候删除了最大或者最小值了怎么办
//其实再添加两个变量记录第二大或者第二小的就行(开玩笑),这么做就是每次暴力搜索复杂度为O(nk);k为滑动次数
//那么用单调队列呢,在单调队列中,数据是按照原来的顺序形成的,也就是说在队列中,队首为最大值,队尾为最小值,也可以反过来
//那么在一个数据进队的时候,我一定要把在我前面比我大的数给踢掉,这样我就成了最大数,那么每次这样操作,这个队列就单调了,由于每次把队尾的数踢掉了,所以只能输出一个最值,写两个;
//在实现时由于顺序被打乱了,不知道下标还在不在窗口内,所有实现时进队的是元素的下标而非元素本身

#include<bits/stdc++.h>
using namespace std;
deque<int> dq;
int main(){
    int n,m;cin>>n>>m;
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    //最小
    for(int i = 0;i<n;i++){
        while(!dq.empty()&&arr[dq.back()]>arr[i]) dq.pop_back();//比我大的都闪开
        dq.push_back(i);
        if(i>=m-1){//注意窗口大小
            while(!dq.empty()&&dq.front()<=i-m) dq.pop_front();//把不在窗口范围内的都出队
            cout<<arr[dq.front()]<<" ";//输出队首最值
        }
    }
    cout<<"\n";
    dq.clear();//清空
    //最大
    for(int i = 0;i<n;i++){
        while(!dq.empty()&&arr[dq.back()]<arr[i]) dq.pop_back();//比我还小的不用排队了
        dq.push_back(i);
        if(i>=m-1){
            while(!dq.empty()&&dq.front()<=i-m) dq.pop_front();
            cout<<arr[dq.front()]<<" ";
        }
    }
    return 0;
}