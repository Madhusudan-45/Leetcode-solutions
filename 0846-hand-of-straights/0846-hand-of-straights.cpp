// class Solution {
// public:
//     bool isNStraightHand(vector<int>& hand, int groupSize) {

//         if(hand.size() % groupSize != 0)
//             return false;

//         unordered_map<int, int> freq;
//         priority_queue<int, vector<int>, greater<int>> pq;

//         for(int card : hand) {
//             freq[card]++;
//         }

//         for(auto it : freq) {
//             pq.push(it.first);
//         }

//         while(!pq.empty()) {

//             int curr = pq.top();

//             for(int i = 0; i < groupSize; i++) {

//                 if(freq[curr + i] == 0)
//                     return false;

//                 freq[curr + i]--;

//                 if(freq[curr + i] == 0) {
//                     if(curr + i == pq.top())
//                         pq.pop();
//                 }
//             }
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if(n % groupSize != 0)
            return false;

        map<int, int> mp;

        for(int card : hand)
            mp[card]++;

        while(!mp.empty()) {

            int curr = mp.begin()->first;

            for(int i = 0; i < groupSize; i++) {

                if(mp[curr + i] == 0)
                    return false;

                mp[curr + i]--;

                if(mp[curr + i] == 0)
                    mp.erase(curr + i);
            }
        }

        return true;
    }
};