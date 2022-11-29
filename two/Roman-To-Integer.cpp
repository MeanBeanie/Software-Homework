#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
    	int result = 0;
		for(int i = 0; i < s.size(); i++){
			char c = s.at(i);
			if(i != s.size()-1 && charToNum(c) < charToNum(s.at(i+1))){
				int sub = 0;
				int add = 0;
				switch(c){
					case 'I':{sub++; break;}
					case 'V':{sub += 5; break;}
					case 'X':{sub += 10; break;}
					case 'L':{sub += 50; break;}
					case 'C':{sub += 100; break;}
					case 'D':{sub += 500; break;}
					case 'M':{sub += 1000; break;}
				}
				switch(s.at(i+1)){
					case 'I':{add++; break;}
					case 'V':{add += 5; break;}
					case 'X':{add += 10; break;}
					case 'L':{add += 50; break;}
					case 'C':{add += 100; break;}
					case 'D':{add += 500; break;}
					case 'M':{add += 1000; break;}
				}
				result += add-sub;
				i++;
			}
			else{
				switch(c){
					case 'I':{result++; break;}
					case 'V':{result += 5; break;}
					case 'X':{result += 10; break;}
					case 'L':{result += 50; break;}
					case 'C':{result += 100; break;}
					case 'D':{result += 500; break;}
					case 'M':{result += 1000; break;}
				}
			}
		}	
		
	   	return result;
    }

private:
	int charToNum(char c){
		switch(c){
			case 'I':{return 1; break;}
			case 'V':{return 5; break;}
			case 'X':{return 10; break;}
			case 'L':{return 50; break;}
			case 'C':{return 100; break;}
			case 'D':{return 500; break;}
			case 'M':{return 1000; break;}
		}
		return 0;
	}
};


