int mostBooked(int n, vector<vector<int>>& meetings) {
    // Sort meetings by their start time
    sort(meetings.begin(), meetings.end());

    // Min-heap of available room indices
    priority_queue<int, vector<int>, greater<>> available;
    for (int i = 0; i < n; ++i) {
        available.push(i);
    }

    // Min-heap of ongoing meetings {endTime, roomIndex}
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> ongoing;

    // Count of meetings held by each room
    vector<int> count(n, 0);

    for (auto& m : meetings) {
        long long start = m[0], end = m[1];

        // Free up rooms where meetings have ended
        while (!ongoing.empty() && ongoing.top().first <= start) {
            available.push(ongoing.top().second);
            ongoing.pop();
        }

        if (!available.empty()) {
            int room = available.top(); available.pop();
            count[room]++;
            ongoing.emplace(end, room);
        } else {
            auto [endTime, room] = ongoing.top(); ongoing.pop();
            count[room]++;
            ongoing.emplace(endTime + (end - start), room);
        }
    }

    // Find the room with the most meetings
    int maxMeetings = 0, result = 0;
    for (int i = 0; i < n; ++i) {
        if (count[i] > maxMeetings) {
            maxMeetings = count[i];
            result = i;
        }
    }

    return result;
}