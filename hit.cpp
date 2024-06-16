#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

int longestSubarrayWithLimit(const std::vector<int> &performances, int delta)
{
    std::deque<int> maxDeque, minDeque;
    int left = 0, right = 0, maxLength = 0;
    int n = performances.size();

    while (right < n)
    {
        // Maintain the maxDeque and minDeque for the current window
        while (!maxDeque.empty() && performances[maxDeque.back()] <= performances[right])
        {
            maxDeque.pop_back();
        }
        maxDeque.push_back(right);

        while (!minDeque.empty() && performances[minDeque.back()] >= performances[right])
        {
            minDeque.pop_back();
        }
        minDeque.push_back(right);

        // Check the current window if it satisfies the condition
        while (!maxDeque.empty() && !minDeque.empty() && (performances[maxDeque.front()] - performances[minDeque.front()] > delta))
        {
            // If the condition is violated, move the left pointer to shrink the window
            left++;
            if (left > maxDeque.front())
                maxDeque.pop_front();
            if (left > minDeque.front())
                minDeque.pop_front();
        }

        // Update the maximum length of the subarray found
        maxLength = std::max(maxLength, right - left + 1);

        // Move the right pointer to expand the window
        right++;
    }
    return maxLength;
}

int main()
{
    std::vector<int> performances = {5, 4, 2, 10, 1, 5, 5};
    int delta = 5;

    int result = longestSubarrayWithLimit(performances, delta);
    std::cout << "The length of the longest subarray is: " << result << std::endl;

    return 0;
}
