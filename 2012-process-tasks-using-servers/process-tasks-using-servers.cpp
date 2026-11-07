class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using ServerInfo = pair<int, int>;
        using BusyServer = array<long long, 3>;

        priority_queue<
            ServerInfo,
            vector<ServerInfo>,
            greater<ServerInfo>
        > idleServers;

        priority_queue<
            BusyServer,
            vector<BusyServer>,
            greater<BusyServer>
        > busyServers;

        for (int i = 0; i < servers.size(); i++) {
            idleServers.push({servers[i], i});
        }

        vector<int> result(tasks.size());
        long long currentTime = 0;

        for (int i = 0; i < tasks.size(); i++) {
            currentTime = max(currentTime, (long long)i);

            while (!busyServers.empty() &&
                   busyServers.top()[0] <= currentTime) {
                auto server = busyServers.top();
                busyServers.pop();

                idleServers.push({
                    (int)server[1],
                    (int)server[2]
                });
            }

            if (idleServers.empty()) {
                currentTime = busyServers.top()[0];

                while (!busyServers.empty() &&
                       busyServers.top()[0] <= currentTime) {
                    auto server = busyServers.top();
                    busyServers.pop();

                    idleServers.push({
                        (int)server[1],
                        (int)server[2]
                    });
                }
            }

            auto [weight, index] = idleServers.top();
            idleServers.pop();

            result[i] = index;

            busyServers.push({
                currentTime + tasks[i],
                weight,
                index
            });
        }

        return result;
    }
};