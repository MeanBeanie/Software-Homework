#include <vector>
using namespace std;


class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int> result;
		for(int i = 0; i < nums.size(); i++){
			int count = 0;
			for(int j = 0; j < nums.size(); j++){
				if(nums.at(i) > nums.at(j)){
					count++;	
				}	
			}
			result.push_back(count);
		}
		return result;
    }
};
