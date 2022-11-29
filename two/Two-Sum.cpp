#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		int index1 = 0, index2 = 0;
	   	for(; index1 < nums.size(); index1++){
		   	for(index2 = 0; index2 < nums.size(); index2++){
				if(index1 != index2 && nums.at(index1) + nums.at(index2) == target){
					result.push_back(index1);
					result.push_back(index2);
					return result;
				}
			}
	   	}
		return result; // Leetcode causing error if this wasnt there
    }
};
