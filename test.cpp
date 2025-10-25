#include <iostream>
#include <vector>
using namespace std;

class SegmentTree
{
private:
    int size;
    vector<int> segt;

public:
    SegmentTree(vector<int> &nums)
    {
        size = nums.size();
        segt.resize(4 * size);
        buildTree(nums, 0, 0, size - 1);
    }

    void buildTree(vector<int> &nums, int idx, int start, int end)
    {
        if (start == end)
        {
            segt[idx] = nums[start];
            return;
        }

        int mid = (start + end) / 2;

        buildTree(nums, 2 * idx + 1, start, mid);
        buildTree(nums, 2 * idx + 2, mid + 1, end);

        segt[idx] = segt[2 * idx + 1] + segt[2 * idx + 2];
    }

    int query(int idx, int start, int end, int qstart, int qend)
    {
        if (qstart > end || start > qend)
        {
            return 0;
        }

        if (qstart <= start && end <= qend)
        {
            return segt[idx];
        }

        int mid = (start + end) / 2;

        int leftsum = query(2 * idx + 1, start, mid, qstart, qend);
        int rightsum = query(2 * idx + 2, mid + 1, end, qstart, qend);

        return leftsum + rightsum;
    }
    void updateTree(vector<int> &nums, int idx, int start, int end, int targetidx, int val)
    {
        if (start == end)
        {
            segt[idx] = val;
            nums[targetidx] = val;
            return;
        }

        int mid = (start + end) / 2;
        if (targetidx <= mid)
            updateTree(nums, 2 * idx + 1, start, mid, targetidx, val);
        else
            updateTree(nums, 2 * idx + 2, mid + 1, end, targetidx, val);

        segt[idx] = segt[2 * idx + 1] + segt[2 * idx + 2];
    }
};

class SegmentTreeLazy
{
private:
    int size;
    vector<int> segt;
    vector<int> lazy;

public:
    SegmentTreeLazy(vector<int> &nums)
    {
        size = nums.size();
        segt.resize(4 * size);
        lazy.resize(4 * size, 0);
        buildTree(nums, 0, 0, size - 1);
    }

    void buildTree(vector<int> &nums, int idx, int start, int end)
    {
        if (start == end)
        {
            segt[idx] = nums[start];
            return;
        }

        int mid = (start + end) / 2;

        buildTree(nums, 2 * idx + 1, start, mid);
        buildTree(nums, 2 * idx + 2, mid + 1, end);

        segt[idx] = segt[2 * idx + 1] + segt[2 * idx + 2];
    }

    int query(int idx, int start, int end, int qstart, int qend)
    {
        // check pending propogations
        if (lazy[idx] != 0)
        {
            segt[idx] += (end - start + 1) * lazy[idx];
            if (start != end)
            {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }

        if (qstart > end || start > qend)
        {
            return 0;
        }

        if (qstart <= start && end <= qend)
        {
            return segt[idx];
        }

        int mid = (start + end) / 2;

        int leftsum = query(2 * idx + 1, start, mid, qstart, qend);
        int rightsum = query(2 * idx + 2, mid + 1, end, qstart, qend);

        return leftsum + rightsum;
    }
    void updateTreePoint(vector<int> &nums, int idx, int start, int end, int targetidx, int val)
    {
        if (start == end)
        {
            segt[idx] = val;
            nums[targetidx] = val;
            return;
        }

        int mid = (start + end) / 2;
        if (targetidx <= mid)
            updateTreePoint(nums, 2 * idx + 1, start, mid, targetidx, val);
        else
            updateTreePoint(nums, 2 * idx + 2, mid + 1, end, targetidx, val);

        segt[idx] = segt[2 * idx + 1] + segt[2 * idx + 2];
    }

    void rangeUpdate(int idx, int start, int end, int qstart, int qend, int val)
    {
        // check pending propogations
        if (lazy[idx] != 0)
        {
            segt[idx] += (end - start + 1) * lazy[idx];
            if (start != end)
            {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }

        if (qstart > end || start > qend)
        {
            return;
        }

        if (qstart <= start && end <= qend)
        {
            segt[idx] += (end - start + 1) * val;
            if (start != end)
            {
                lazy[2 * idx + 1] += val;
                lazy[2 * idx + 2] += val;
            }
            return;
        }

        int mid = (start + end) / 2;

        rangeUpdate(2 * idx + 1, start, mid, qstart, qend, val);
        rangeUpdate(2 * idx + 2, mid + 1, end, qstart, qend, val);

        segt[idx] = segt[2 * idx + 1] + segt[2 * idx + 2];
    }
};

class fenwickTree
{
private:
    int size;
    vector<int> fenw;

public:
    fenwickTree(vector<int> &nums)
    {
        size = nums.size();
        fenw.resize(size + 1, 0);

        for (int i = 0; i < size; i++)
        {
            update(i, nums[i]);
        }
    }

    void update(int idx, int val)
    {
        idx++;
        while (idx <= size)
        {
            fenw[idx] += val;
            idx += idx & (-idx);
        }
    }

    int sum(int idx)
    {
        idx++;
        int s = 0;
        while (idx > 0)
        {
            s += fenw[idx];
            idx -= idx & (-idx);
        }

        return s;
    }
    int rangeUpdate(int l, int r, int val)
    {
        update(l, val);
        update(r + 1, -val);
    }
    int query(int l, int r)
    {
        return sum(r) - (l > 0 ? sum(l - 1) : 0);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    SegmentTree st(nums);

    cout << "Sum of [1, 3] = " << st.query(0, 0, nums.size() - 1, 1, 3) << "\n"; // 3+5+7 = 15

    st.updateTree(nums, 0, 0, nums.size() - 1, 1, 10);
    cout << "After update: Sum of [1, 3] = " << st.query(0, 0, nums.size() - 1, 1, 3) << "\n"; // 10+5+7 = 22

    return 0;
}