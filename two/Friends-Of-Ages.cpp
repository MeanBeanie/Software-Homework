#include <vector>
#include <iostream>
using namespace std;

/*
age[y] <= 0.5 * age[x] + 7
age[y] > age[x]
age[y] > 100 && age[x] < 100
*/

// THIS DOESNT MAKE SENSE HOW DO [16, 16] MAKE 2, THEY ARE THE SAME AGE MEANING age[y]  is not less than or equal to 0.5 * age[x] + 7

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
		int requests = 0;
       	for(int i = 0; i < ages.size(); i++){
			for(int j = 0; j < ages.size(); j++){
				if(ages.at(j) > 0.5 * ages.at(i) + 7 && ages.at(j) < ages.at(i)){
					return -1;
				}
				else{
					cout << ages.at(i) << ", " << ages.at(j) << "\n";
					requests++;
					i++;
				}
			}		
		}
		return requests;
    }
};


int main(){
	Solution s;
	vector<int> v;
	v.push_back(16);
	v.push_back(17);
	v.push_back(18);
	cout << s.numFriendRequests(v) << "\n";
	return 0;
}
