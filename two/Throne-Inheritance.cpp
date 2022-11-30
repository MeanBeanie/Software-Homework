#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
	public:
		string name;
		Person* parent;
		vector<Person> children;
		Person(){};
		Person(Person* parentName, string _name):parent(parentName), name(_name){};
		bool operator==(const Person& other){
			return this->name == other.name && this->parent == other.parent && this->children.size() == other.children.size();
		}
};

class ThroneInheritance {
public:
	vector<Person> people;
	Person king;
    ThroneInheritance(string kingName) {
       king.name = kingName;
	   king.parent = NULL;
    }
    
    void birth(string parentName, string childName) {
       Person child(&findByName(parentName), childName);
	   findByName(parentName).children.push_back(child);
	   people.push_back(child);
    }
    
    void death(string name){
		people.erase(find(people.begin(), people.end(), findByName(name))); 
    }
    
    vector<string> getInheritanceOrder() {
		vector<string> curOrder;
		/*
		*Successor(x, curOrder):
   	 		*if x has no children or all of x's children are in curOrder:
        		*if x is the king return null
        		*else return Successor(x's parent, curOrder)
    		*else return x's oldest child who's not in curOrder
		 */ 
		for(Person person : people){
			bool childrenPossible = true;
			int oldestChild;
			while(childrenPossible){
				for(int i = 0; i < person.children.size(); i++){
					Person child = person.children.at(i);
					if(find(curOrder.begin(), curOrder.end(), child.name) == curOrder.end()){
						childrenPossible = true;
						oldestChild = i;
					}
					else{
						childrenPossible = false;
					}
				}
				if(childrenPossible){
					curOrder.push_back(person.children.at(oldestChild).name);
				}
			}

		}
		return curOrder;
    }
private:
	Person& findByName(string name){
		for(int i = 0; i < people.size(); i++){
			if(people.at(i).name == name){
				return people.at(i);
			}
		}
	}
};

/**
 * Y	our ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

int main(){
	ThroneInheritance t("king");
	t.birth("king", "andy");
	t.birth("king", "bob");
	t.birth("king", "catherine");
	t.birth("andy", "matthew");
	t.birth("bob", "alex");
	t.birth("bob", "asha");
	for(string n : t.getInheritanceOrder()){
		cout << n << ", ";
	}
	cout << endl;
	t.death("bob");
	for(string n : t.getInheritanceOrder()){
		cout << n << ", ";
	}
	cout << endl;
	return 0;
}
