class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int low = 0;
        int high = 0;

        // Find minimum capacity and total weight
        for(int i = 0; i < weights.size(); i++) {
            low = max(low, weights[i]);
            high += weights[i];
        }

        while(low <= high) {

            int mid = low + (high - low) / 2;

            int daysNeeded = 1;
            int currentWeight = 0;

            // Check how many days are needed
            // with capacity = mid
            for(int i = 0; i < weights.size(); i++) {

                if(currentWeight + weights[i] <= mid) {
                    currentWeight += weights[i];
                }
                else {
                    daysNeeded++;
                    currentWeight = weights[i];
                }
            }

            // Current capacity works
            if(daysNeeded <= days) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};