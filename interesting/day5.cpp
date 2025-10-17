bool check(long long time,vector<vector<int>> &arr){
    long long cnt = 0;
    for(int i = 0;i<n;i++){
        long long t = arr[i][0], l = arr[i][1], w = arr[i][2];
        
        // 计算一个完整周期的时间
        long long cycle_time = t * l + w;
        
        // 完整周期数量
        long long full_cycles = time / cycle_time;
        long long items_from_cycles = full_cycles * l;
        
        // 剩余时间
        long long remaining_time = time % cycle_time;
        
        // 关键修复：在剩余时间内能打印的物品
        // 如果剩余时间 >= t * l，那么能打印 l 个物品
        // 否则能打印 remaining_time / t 个物品
        long long add;
        if (re >= t * l) {
            add = l;
        } else {
            add = re / t;
        }
        
        cnt += items_from_cycles + additional_items;
        if(cnt >= k) return true;
    }
    return false;
}