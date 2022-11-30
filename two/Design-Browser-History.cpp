#include <string>
#include <vector>
using namespace std;

class BrowserHistory {
public:
	string currentWebpage;
	int index;
	vector<string> previousWebpages; 
    BrowserHistory(string homepage) {
		if(homepage.size() > 20){return;}
       	currentWebpage = homepage; 
    }
    
    void visit(string url) {
		if(url.size() > 20){return;}
	    previousWebpages.push_back(currentWebpage);
		currentWebpage = url;
    }
    
    string back(int steps) {
		if(steps <= 0 || previousWebpages.empty()){
			return "n/a";
		}
        if(steps > previousWebpages.size()){
			currentWebpage = previousWebpages.at(0);
			index = 0;
			return previousWebpages.at(0);
		}
		else{
			currentWebpage = previousWebpages.at(previousWebpages.size()-steps);
			index = previousWebpages.size()-steps;
			return previousWebpages.at(previousWebpages.size()-steps);
    	}
	}
    
    string forward(int steps) {
		if(steps <= 0 || previousWebpages.empty()){return "n/a";}
		if(index+steps > previousWebpages.size() && index != previousWebpages.size()-1){
			// return most recent webpage
			index = previousWebpages.size()-1;
			currentWebpage = previousWebpages.at(previousWebpages.size()-1);
			return previousWebpages.at(previousWebpages.size()-1); 
		}
		else if(index == previousWebpages.size()-1){
			index = previousWebpages.size()-1;
			return currentWebpage;
		}
    	else{
			currentWebpage = previousWebpages.at(index+steps);
			index += steps;
			return previousWebpages.at(index+steps);
		}	
	}
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
