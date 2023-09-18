#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        priority_queue<int> fuel_avail;

        int cur_pos = 0;
        int n = stations.size();
        int next_station_idx = 0;

        int num_refuel = 0;

        fuel_avail.push(startFuel);

        // we are at 0 with {startFuel} available

        // strech to the max
        while (cur_pos < target && fuel_avail.size() > 0)
        {
            // you have not reached target and you have some fuel avail
            // currently cur_pos is the maximum position you can reach.

            // pick the biggest fuel among fuel_avail and accordingly change
            // cur_pos
            // fuel_avail
            // next_station_idx
            // num_refuel

            int cur_fuel = fuel_avail.top();
            fuel_avail.pop();

            num_refuel++;
            cur_pos += cur_fuel;

            while (next_station_idx < n && stations[next_station_idx][0] <= cur_pos)
            {
                fuel_avail.push(stations[next_station_idx][1]);
                next_station_idx++;
            }
        }

        if (cur_pos < target)
            return -1;
        else
            return num_refuel - 1;
    }
};

int main()
{
    int n, target, x;
    cin >> n >> target >> x;

    vector<vector<int>> station(n, vector<int>(2, 0));

    for (int i = 0; i < n; i++)
    {
        cin >> station[i][0] >> station[i][1];
    }

    Solution ob;

    int ans = ob.minRefuelStops(target, x, station);

    cout << ans << endl;
}