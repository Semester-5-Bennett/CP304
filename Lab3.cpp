#include <iostream>
#include <vector>

using namespace std;

int findPeak(const vector<int>& nums) {
int low = 0, high = nums.size() - 1;

while (low < high) {
int mid = low + (high - low) / 2;

// Check if mid is the peak
if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
return nums[mid];
}

// If mid is less than next element, then peak is on right side
if (nums[mid] < nums[mid + 1]) {
low = mid + 1;
} else {
high = mid - 1;
}
}

return nums[low];  // In case the list is strictly increasing
}

int main() {
int n;
cin >> n;

vector<int> nums(n);
for (int i = 0; i < n; i++) {
cin >> nums[i];
}

cout << findPeak(nums) << endl;
return 0;
}
