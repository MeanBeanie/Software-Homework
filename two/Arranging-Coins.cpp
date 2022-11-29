class Solution {
public:
    int arrangeCoins(int n) {
    	int startingRow = (n / 2) + (n & 1);
		int count = 0;
	   	while(n > 0 || startingRow > 0){
			n -= startingRow;
			startingRow--;
			count++;
	   	}
		if(count - 1 != 0){
			return count-1;
    
		}
		else{
			return count;
		}
	}
};
