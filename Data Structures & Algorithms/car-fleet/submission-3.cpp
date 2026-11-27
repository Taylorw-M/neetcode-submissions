class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> q;
        vector<pair<int, int>> cars;

        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend()); // Descending position

        for (const auto& [pos, spd] : cars) {
            double turns = static_cast<double>(target - pos) / spd;

            if (q.empty() || turns > q.top()) {
                q.push(turns);
            }
        }
        return q.size();
    }
};
