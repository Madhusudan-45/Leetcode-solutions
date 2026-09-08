class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Frequency count
        vector<int> freq(26, 0);

        for(char task : tasks) {
            freq[task - 'A']++;
        }

        // Max Heap
        priority_queue<int> pq;

        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                pq.push(freq[i]);
            }
        }

        // {remaining frequency, available time}
        queue<pair<int, int>> q;

        int time = 0;

        while(!pq.empty() || !q.empty()) {

            time++;

            // Cooldown se task wapas available
            if(!q.empty() && q.front().second == time) {

                pq.push(q.front().first);

                q.pop();
            }

            // Agar koi task available hai
            if(!pq.empty()) {

                int count = pq.top();
                pq.pop();

                count--;

                // Task abhi completely finish nahi hua
                if(count > 0) {

                    q.push({count, time + n + 1});
                }
            }
        }

        return time;
    }
};