
int a[100005], seg[4*100005] , lazy[4*100005];

void build(int idx, int low, int high){

    if(low == high){
        seg[idx] = a[low];
        return;
    }

    int mid = (low+high)/2;
    build(2*idx+1,low,mid);
    build(2*idx+2,mid+1,high);
    seg[idx] = max(seg[2*idx+1],seg[2*idx+2]);
    seg[idx] = __gcd(seg[2*idx+1],seg[2*idx+2]);
}
int query(int idx, int low, int high, int l, int r){
    if(low >= l && high <= r){
        return seg[idx];
    }
    if(high < l || low > r) return INT_MIN;
    int mid = (low+high)/2;
    int left = query(2*idx+1,low,mid,l,r);
    int right = query(2*idx+2,mid+1,high,l,r);
    return max(left,right);
}
