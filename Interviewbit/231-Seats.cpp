/*
There is a row of seats. Assume that it contains N seats adjacent to each other. There is a group of people who are already seated in that row randomly. i.e. some are sitting together & some are scattered.

An occupied seat is marked with a character 'x' and an unoccupied seat is marked with a dot ('.')

Now your target is to make the whole group sit together i.e. next to each other, without having any vacant seat between them in such a way that the total number of hops or jumps to move them should be minimum.

Return minimum value % MOD where MOD = 10000003

Example

Here is the row having 15 seats represented by the String (0, 1, 2, 3, ......... , 14) -

              . . . . x . . x x . . . x . .

Now to make them sit together one of approaches is -
                  . . . . . . x x x x . . . . .

Following are the steps to achieve this -
1 - Move the person sitting at 4th index to 6th index -  
    Number of jumps by him =   (6 - 4) = 2

2 - Bring the person sitting at 12th index to 9th index - 
    Number of jumps by him = (12 - 9) = 3

So now the total number of jumps made = 
    ( 2 + 3 ) % MOD = 
    5 which is the minimum possible jumps to make them seat together.

There are also other ways to make them sit together but the number of jumps will exceed 5 and that will not be minimum.

For example bring them all towards the starting of the row i.e. start placing them from index 0. 
In that case the total number of jumps will be 
    ( 4 + 6 + 6 + 9 )%MOD 
    = 25 which is very costly and not an optimized way to do this movement


*/

long long findMedian(string s) {
    long long count1 = 0;
    char c;
    long long n = s.length();
    for (long long i=0; i<n; i++) {
        c= s[i];
        if (c == 'x') {
            count1++;
        }
    }
    if (count1 == 0) {
        return -1;
    }
    count1 = (count1 + 1) / 2;
    long long count2 = 0;
    for (long long i = 0; i < s.length(); ++i) {
        if (s[i] == 'x') {
            count2++;
            if (count2 == count1) {
                return i;
            }
        }
    }
    return -1;
}
long long shift(string s, long long i) {
    long long count = 0;
    long long j = 0;
    long long k = i;
    while (j < k) {
        if (s[j] == '.') {
            j++;
        }
        else if (s[k] == 'x') {
            k--;
        }
        else {
            s[k] = s[j];
            s[j] = '.';
            count += k-j;
            count %= 10000003;
            j++;
            k--;
        }
    }
    j = s.length() - 1;
    k = i;
    while (j > k) {
        if (s[j] == '.') {
            j--;
        }
        else if (s[k] == 'x') {
            k++;
        }
        else {
            s[k] = s[j];
            s[j] = '.';
            count += j-k;
            count %= 10000003;
            j--;
            k++;
        }
    }
    return count;
}
int Solution::seats(string A) {
    long long i = findMedian(A);
        if (i == -1) {
            return 0;
        }
    return shift(A, i);
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
