int Lower(vector<int>& a, int x){
    int l = -1, r = a.size();
    while(l + 1 < r){
        int m = (l + r) / 2;
        if(a[m] <= x) l = m;
        else r = m;
    }
    return l;
}
int Upper(vector<int>& a, int x){
    int l = -1, r = a.size();
    while(l + 1 < r){
        int m = (l + r) / 2;
        if(a[m] >= x) r = m;
        else l = m;
    }
    return r;
}