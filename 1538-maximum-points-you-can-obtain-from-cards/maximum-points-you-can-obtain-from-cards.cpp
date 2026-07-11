class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int lsum=0;
        int rsum =0;
        int sum =0;
        int msum=0;
        int n= cardPoints.size();

        for(int i =0;i<=k-1;i++){
            lsum=lsum+cardPoints[i];
            msum = lsum;
        }
        int rind = n-1;
        for(int j=k-1;j>=0;j--){
            lsum = lsum -cardPoints[j];
            rsum= rsum + cardPoints[rind];
            rind--;
            msum = max(msum,lsum+rsum);
        }

        //msum = max(msum,lsum+rsum);

        return msum;
        
    }
};