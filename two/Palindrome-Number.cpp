#include <string>
#include <algorithm>

class Solution {
public:
    bool isPalindrome(int x) {
		std::string xAsString = std::to_string(x);
		std::string revXAsString = xAsString;
		std::reverse(revXAsString.begin(), revXAsString.end());
		if(xAsString == revXAsString){
			return true;
		}
		else{
			return false;
		}
	}
};


