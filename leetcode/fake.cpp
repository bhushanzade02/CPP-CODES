#include <iostream>
#include <vector>
#include <algorithm> // For sort()

int main() {
    int n; 
    std::cout << "Enter the number of elements: ";
    std::cin >> n; // Read the size of the array

    std::vector<int> height(n); // Vector to store the heights
    std::cout << "Enter the elements of the height array: ";
    for (int i = 0; i < n; i++) {
        std::cin >> height[i]; // Read each element into the height array
    }

    // Create a copy of the height array for comparison
    std::vector<int> expected = height;

    // Sort the expected array
    std::sort(expected.begin(), expected.end());

    int ans = 0;
    
    // Compare each element of the height array with the sorted expected array
    for (int i = 0; i < n; i++) {
        if (height[i] != expected[i]) {
            ans++; // Increment ans if there is a difference
        }
    }

    // Output the result
    std::cout << "Number of elements out of order: " << ans << std::endl;

    return 0;
}
