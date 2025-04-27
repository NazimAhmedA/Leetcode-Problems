#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int left = 0; // Pointer for the position to place the next non-val element

        for (int right = 0; right < nums.size(); ++right)
        {
            if (nums[right] != val)
            {
                nums[left] = nums[right]; // Move non-val element to the left
                left++;                   // Increment the left pointer
            }
        }

        return left; // The new length of the array without val elements
    };

};

int main()
{
    Solution sol;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    int newLength = sol.removeElement(nums, val);

    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}