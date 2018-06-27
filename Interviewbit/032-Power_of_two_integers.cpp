/*
Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.

Example

Input : 4
Output : True  
as 2^2 = 4. 

*/
bool Solution::isPower(int A) {
    if(A==1){
        return true;
    }
    if(A==0){
        return false;
    }
    int pred;
    int pred1 = (A/2);
    int pred2 = (A/2);
    int power;
    for(int i=2; i<=pred1; i++){
        pred = i;
        power = 1;
        while((pred<A)&&(power<pred2)){
            pred *= i;
            power++;
            if(pred == A){
                return true;
            }
        }
        pred2 = power;
        if(pred2 ==1){
            break;
        }
    }
    return false;
}
