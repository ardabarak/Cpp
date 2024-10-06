// Arda Barak
// 300129340

#include <iostream>
#include <vector>
using namespace std;

int trapRainWater(vector<int>& height) {
    int sol = 0; //left
    int sag = height.size() - 1; //right
    int solMax = 0, sagMax = 0; //left&right max
    int trappedWater = 0;

    while (sol < sag) {
        if (height[sol] < height[sag]) {
            if (height[sol] >= solMax) {
                solMax = height[sol]; //update left
            } 
            else {
                trappedWater += solMax - height[sol]; //amount of trapped water
            } sol++; //left pointer -> right
        } 
        else {
            if (height[sag] >= sagMax) {
                sagMax = height[sag]; //update right max
            } else {
                trappedWater += sagMax - height[sag]; //amount of trapped water
            } sag--; //right pointer -> left
        }
    }
    return trappedWater;
}

int main() {
    // vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1}; //6
    vector<int> height = {0,1,0,2,1,1,1,2,2,2,3}; //4
    cout << "Trapped water:     " << trapRainWater(height) << endl;
    return 0;
}
