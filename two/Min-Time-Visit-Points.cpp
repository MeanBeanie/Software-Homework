#include <vector>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int> >& points) {
		vector<int> target = {points.at(1).at(0), points.at(1).at(1)};
		vector<int> current = {points.at(0).at(0), points.at(0).at(1)};
		int time = 0;
		int iter = 1;
		while(iter < points.size()){
			while(current.at(0) != target.at(0) || current.at(1) != target.at(1)){
				if(target.at(0) - current.at(0) >= 1){current.at(0)++;}
    			if(target.at(1) - current.at(1) >= 1){current.at(1)++;}
				if(target.at(0) - current.at(0) <= -1){current.at(0)--;}
				if(target.at(1) - current.at(1) <= -1){current.at(1)--;}
				time++;
			}
			current = target;
			iter++;
			if(iter < points.size()){
				target = points.at(iter);
			}
		}
		return time;
	}
};


