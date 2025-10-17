#include <iostream>
using namespace std;

int const MAX = 1e5;
int segtree[4 * MAX];
int arr[MAX];

void buildTree(int idx, int left, int right)
{
    if (left == right)
    {
        segtree[idx] = arr[left];
        return;
    }
    int mid = (left + right) / 2;
    buildTree(2 * idx + 1, left, mid);
    buildTree(2 * idx + 2, mid + 1, right);

    segtree[idx] = segtree[2 * idx + 1] + segtree[2 * idx + 2];
}

void updateTree(int updateVal, int targetIdx, int idx, int left, int right)
{
    if (left == right)
    {
        segtree[idx] = updateVal;
        return;
    }
    int mid = left + (right - left) / 2;

    if (targetIdx <= mid)
    {
        updateTree(updateVal, targetIdx, 2 * idx + 1, left, mid);
    }
    else
    {
        updateTree(updateVal, targetIdx, 2 * idx + 2, mid + 1, right);
    }
    segtree[idx] = segtree[2 * idx + 1] + segtree[2 * idx + 2];
}

int rangeSumQuery(int start , int end , int idx , int left , int right){
    if(start > right || end < left){
        return 0;
    }
    if(start <= left && end >= right){
        return segtree[idx];
    }
    int mid = left + (right - left) / 2;
    int leftSum = rangeSumQuery(start, end , 2*idx +1 , left , mid);
    int rightSum = rangeSumQuery(start, end , 2*idx +2 ,  mid + 1  , right);

    return leftSum + rightSum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}