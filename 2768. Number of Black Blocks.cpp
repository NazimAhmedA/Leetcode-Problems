#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>> &coordinates)
    {
        unordered_map<long long, int> blockCounts;
        vector<long long> result(5, 0);

        // For hash key encoding
        auto hash = [&](int x, int y) -> long long {
            return static_cast<long long>(x) * n + y;
        };

        // Each black cell affects up to 4 2x2 blocks
        for (const auto& coord : coordinates)
        {
            int x = coord[0], y = coord[1];

            for (int dx = -1; dx <= 0; ++dx)
            {
                for (int dy = -1; dy <= 0; ++dy)
                {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && ny >= 0 && nx < m - 1 && ny < n - 1)
                    {
                        blockCounts[hash(nx, ny)]++;
                    }
                }
            }
        }

        long long totalBlocks = static_cast<long long>(m - 1) * (n - 1);
        for (const auto& pair : blockCounts) {
            auto key = pair.first;
            auto count = pair.second;
            result[count]++;
        }

        // The rest are zero-black-cell blocks
        result[0] = totalBlocks - (result[1] + result[2] + result[3] + result[4]);

        return result;
    }
};

int main()
{
    Solution sol;
    int m = 5;                                  // Example value for m
    int n = 4;                                  // Example value for n
    vector<vector<int>> coordinates = {{0, 2}, {1, 1}, {2, 3}, {3, 0}, {3, 2}, {4, 1}, {4, 2}}; // Example coordinates

    vector<long long> result = sol.countBlackBlocks(m, n, coordinates); // Call the function

    // Print the result
    for (long long count : result)
    {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}