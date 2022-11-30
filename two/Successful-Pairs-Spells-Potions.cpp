#include <vector>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
	    vector<int> result;
	   	for(int spell : spells){
			int successCount = 0;
	   		for(int potion : potions){
				if(spell * potion >= success){
					successCount++;
				}
			}
			result.push_back(successCount);
		}
		return result;
    }
};
