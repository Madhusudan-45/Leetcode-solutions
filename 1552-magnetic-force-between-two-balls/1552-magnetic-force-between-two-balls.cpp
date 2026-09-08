class Solution {
public:

    bool isPossible(vector<int>& position, int m, int distance) {

        int cows = 1;
        int lastCow = position[0];

        for(int i = 1; i < position.size(); i++) {

            if(position[i] - lastCow >= distance) {
                cows++;
                lastCow = position[i];
            }

            if(cows == m) {
                return true;
            }
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(), position.end());

        int low = 1;
        int high = position[position.size() - 1] - position[0];

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(isPossible(position, m, mid)) {

                // distance possible hai
                // aur bada distance try karo
                low = mid + 1;
            }
            else {

                // distance possible nahi hai
                // chhota distance try karo
                high = mid - 1;
            }
        }

        return high;
    }
};