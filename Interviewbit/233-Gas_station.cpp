/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the minimum starting gas station’s index if you can travel around the circuit once, otherwise return -1.

You can only travel in one direction. i to i+1, i+2, ... n-1, 0, 1, 2..
Completing the circuit means starting at i and ending up at i again.

Example :

Input :
      Gas :   [1, 2]
      Cost :  [2, 1]

Output : 1 

If you start from index 0, you can fill in gas[0] = 1 amount of gas. Now your tank has 1 unit of gas. But you need cost[0] = 2 gas to travel to station 1. 
If you start from index 1, you can fill in gas[1] = 2 amount of gas. Now your tank has 2 units of gas. You need cost[1] = 1 gas to get to station 0. So, you travel to station 0 and still have 1 unit of gas left over. You fill in gas[0] = 1 unit of additional gas, making your current gas = 2. It costs you cost[0] = 2 to get to station 1, which you do and complete the circuit. 


*/

int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    int n = gas.size(); 
    int i=0;
    for(i=0; i<n; i++){
        int curr=0;
        int j=i;
        while(true){
            curr += (gas[j]-cost[j]);
            if(curr<0){
                break;
            }
            j++;
            if(j==n){
                j=0;
            }
            if(j==i){
                return i;
            }
        }
    }
    return -1;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
