#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // Initialize pointers for nums1, nums2, and the merged array
        int i = m - 1; // Pointer for the last initialized element in nums1
        int j = n - 1; // Pointer for the last element in nums2
        int k = m + n - 1; // Pointer for the last position in nums1 (where the merged array will be)

        // Merge nums1 and nums2 from the end to the beginning
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--]; // Place the larger element at the end of nums1
            }
            else
            {
                nums1[k--] = nums2[j--]; // Place the larger element at the end of nums1
            }
        }

        // If there are remaining elements in nums2, copy them to nums1
        while (j >= 0)
        {
            nums1[k--] = nums2[j--]; // Copy remaining elements from nums2 to nums1
        }

        // If there are remaining elements in nums1, they are already in the correct position
        // No need to copy them since they are already in place
    }

};

int main()
{
    Solution sol;
    vector<int> nums1 = {0};                // Example nums1 with extra space for merging
    vector<int> nums2 = {1};                // Example nums2
    int m = 0;                              // The number of initialized elements in nums1
    int n = 1;                              // The number of elements in nums2

    sol.merge(nums1, m, nums2, n);          // Call the merge function
    return 0;
}