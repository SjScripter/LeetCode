class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // Set to track available servers
        set<int> availableServers;
        for (int i = 0; i < k; ++i) {
            availableServers.insert(i);
        }
      
        // Min heap to track busy servers (sorted by end time)
        // Pair: {end_time, server_id}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busyServers;
      
        // Count of requests handled by each server
        vector<int> requestCount(k);
      
        // Process each incoming request
        for (int i = 0; i < arrival.size(); ++i) {
            int startTime = arrival[i];
            int endTime = startTime + load[i];
          
            // Free up servers that have completed their tasks
            while (!busyServers.empty() && busyServers.top().first <= startTime) {
                availableServers.insert(busyServers.top().second);
                busyServers.pop();
            }
          
            // Skip this request if no servers are available
            if (availableServers.empty()) {
                continue;
            }
          
            // Find the next available server using round-robin starting from (i % k)
            auto iterator = availableServers.lower_bound(i % k);
            if (iterator == availableServers.end()) {
                // Wrap around to the beginning if no server >= (i % k) is found
                iterator = availableServers.begin();
            }
          
            // Assign the request to the selected server
            int selectedServer = *iterator;
            ++requestCount[selectedServer];
            busyServers.emplace(endTime, selectedServer);
            availableServers.erase(selectedServer);
        }
      
        // Find the maximum number of requests handled
        int maxRequests = *max_element(requestCount.begin(), requestCount.end());
      
        // Collect all servers that handled the maximum number of requests
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (requestCount[i] == maxRequests) {
                result.push_back(i);
            }
        }
      
        return result;
    }
};
