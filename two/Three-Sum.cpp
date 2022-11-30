#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
		vector<vector<int> > result;
		sort(nums.begin(), nums.end());
		if(nums.size() < 3){return {};}
		for(int i = 0; i < nums.size(); i++){
			for(int j = 0; j < nums.size(); j++){
				for(int k = 0; k < nums.size(); k++){
					if(i != j && i != k && j != k){
						if(nums.at(i) + nums.at(j) + nums.at(k) == 0){
							vector<int> v = {nums.at(i), nums.at(j), nums.at(k)};
							for(vector<int> vec : result){
								sort(vec.begin(), vec.end());
							}
							sort(v.begin(), v.end());
							if(find(result.begin(), result.end(), v) == result.end()){
								result.push_back(v);	
							}
						}
					}
				}
			}
		}
		return result;
    }
};
