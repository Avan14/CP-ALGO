#include <iostream>
#include <vector>
using namespace std;

class SegementTree
{

private:
    int size;
    vector<int> segtree;

public:

    SegementTree( vector<int> nums ){
        int n = nums.size();
        size = n;
        segtree.resize(4*n);
    }


    void buildRangeMinTree( int idx , int left , int right , vector<int > & nums ){
        if( left == right ){
            segtree[idx] = nums[left];
            return;
        }

        int mid =  (left+ right)/2;

        buildRangeMinTree(idx , left , mid , nums);
        buildRangeMinTree(idx , mid + 1 , right , nums);

        segtree[idx] = min(segtree[2*idx +1 ] , segtree[2*idx +2 ]);
    }

    
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}