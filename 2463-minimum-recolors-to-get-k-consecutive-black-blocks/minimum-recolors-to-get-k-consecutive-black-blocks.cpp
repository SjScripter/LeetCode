class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int n = blocks.size();
        int mw = 0;

        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W')
                mw++;
        }

        int msum = mw;

        for (int i = k; i < n; i++) {

            if (blocks[i - k] == 'W')
                mw--;

            if (blocks[i] == 'W')
                mw++;

            msum = min(msum, mw);
        }

        return msum;
    }
};