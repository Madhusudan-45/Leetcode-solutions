class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        if(1LL * m * k > bloomDay.size()) {
            return -1;
        }

        int low = 1;
        int high = 0;

        for(int i = 0; i < bloomDay.size(); i++) {
            high = max(high, bloomDay[i]);
        }

        while(low <= high) {

            int mid = low + (high - low) / 2;

            int bouquets = 0;
            int flowers = 0;

            for(int i = 0; i < bloomDay.size(); i++) {

                if(bloomDay[i] <= mid) {
                    flowers++;

                    if(flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                }
                else {
                    flowers = 0;
                }
            }

            if(bouquets >= m) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};