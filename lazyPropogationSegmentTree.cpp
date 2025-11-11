#include <iostream>
#include < vector >

using namespace std;

class LazyPropagationSegmentTree
{
private:
    int size;
    vector<int> segTree;
    vector<int> lazy;

public:
    LazyPropagationSegmentTree(vector<int> nums)
    {
        int n = nums.size();
        size = n;
        segTree.resize(4 * n);
        lazy.resize(4 * n, 0);
    }

    void buildTree(int idx, int left, int right, vector<int> &nums)
    {
        if (left == right)
        {
            segTree[idx] = nums[left];
            return;
        }

        int mid = (left + right) / 2;

        buildTree(2 * idx + 1, left, mid, nums);
        buildTree(2 * idx + 2, mid + 1, right, nums);

        segTree[idx] = segTree[2 * idx + 1] + segTree[2 * idx + 2];
    }

    
    void rangeUpdate(int idx, int start, int end, int Qstart, int Qend, int val) {
    // Step 1: Resolve any pending lazy updates at this node
    if (lazy[idx] != 0) {
        segTree[idx] += (end - start + 1) * lazy[idx];  // apply pending

        if (start != end) {  // not a leaf node → push to children
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }

        lazy[idx] = 0;  // clear lazy value at this node
    }

    // Step 2: No overlap
    if (start > Qend || end < Qstart)
        return;

    // Step 3: Complete overlap
    if (start >= Qstart && end <= Qend) {
        segTree[idx] += (end - start + 1) * val;

        if (start != end) {  // if not a leaf node
            lazy[2 * idx + 1] += val;
            lazy[2 * idx + 2] += val;
        }
        return;
    }

    // Step 4: Partial overlap → recurse to both children
    int mid = (start + end) / 2;

    rangeUpdate(2 * idx + 1, start, mid, Qstart, Qend, val);
    rangeUpdate(2 * idx + 2, mid + 1, end, Qstart, Qend, val);

    // Step 5: Recalculate the current node’s value
    segTree[idx] = segTree[2 * idx + 1] + segTree[2 * idx + 2];
}

int lazyQuery( int idx ,  int start , int end , int Qstart , int Qend ){
    // resolve any pending lazy upodates;
    if(lazy[idx]!=0){
        segTree[idx] += (end - start + 1 )*lazy[idx];
        if( start != end){
            lazy[2*idx + 1] += lazy[idx];
            lazy[2*idx + 2] += lazy[idx];
        }
        lazy[idx] = 0 ;
    }

    // no overlap

    if( start > Qend || end  < Qstart){
        return 0;
    }
    // complete overlap

    if( start >= Qstart && end <=Qend){
        return segTree[idx];
    }

    int mid = ( start + end )/2;

    int leftSum = lazyQuery( 2*idx +1 , start , mid , Qstart , Qend);
    int rightSum = lazyQuery( 2*idx +2 , mid +1 , end , Qstart , Qend);
    return leftSum + rightSum;
    
}
       
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}