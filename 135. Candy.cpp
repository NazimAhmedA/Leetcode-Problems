#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        if (n == 1)
            return 1; // If there's only one child, they get one candy

        int result = 0;

        vector<int> candies(n, 1); // Initialize candies array with 1 candy for each child

        if (ratings[0] > ratings[1] && candies[0] <= candies[1])
        {
            candies[0]++;
        }

        // First pass: left to right
        for (int i = 1; i < n; ++i)
        {
            if (ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }

        if (ratings[n - 1] > ratings[n - 2] && candies[n - 1] <= candies[n - 2])
        {
            candies[n - 1]++;
        }

        result += candies[n - 1];

        // Second pass: right to left
        for (int i = n - 2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
            {
                candies[i] = candies[i + 1] + 1;
            }
            result += candies[i];
        }

        return result; // Initialize total candies with the first child's candies
    }
};

int main()
{
    Solution sol;
    vector<int> ratings = {1, 0, 2}; // Example ratings
    int result = sol.candy(ratings); // Call the function

    cout << "Minimum candies needed: " << result << endl; // Output the result
    return 0;
}