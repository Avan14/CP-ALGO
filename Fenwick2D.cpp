#include <iostream>
#include <vector>
using namespace std;


class FenwickTree2D{
    private :
        int n;
        int m;
        vector <vector<int>> fenw;
    public :
        FenwickTree2D(vector <vector<int>> &matrix){
            n = matrix.size();
            m = matrix[0].size();
            fenw.resize(n+1, vector<int>(m+1,0));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    update(i,j,matrix[i][j]);
                }
            }
        }
        void update(int x, int y, int val){
            x++; y++; // 1-based indexing
            for(int i=x;i<=n;i+=i&(-i)){
                for(int j=y;j<=m;j+=j&(-j)){
                    fenw[i][j] += val;
                }
            }
        }
        int sum(int x, int y){
            x++; y++; // 1-based indexing
            int s = 0;
            for(int i=x;i>=1;i-=i&(-i)){
                for(int j=y;j>=1;j-=j&(-j)){
                    s += fenw[i][j];
                }
            }
            return s;
        }
        int rangeSum(int x1, int y1, int x2, int y2){
            return sum(x2,y2) - sum(x1-1,y2) - sum(x2,y1-1) + sum(x1-1,y1-1);
        }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

  

    return 0;
}