/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.


*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> ans;
    int n = intervals.size();
    if(n==0){
        ans.push_back(newInterval);
        return ans;
    }
    int newi=n;
    int first =0;
    int last = 0;
    int min = intervals[0].start;
    int max = intervals[0].end;
    bool done = false;
    
    for(int i=0; i<n; i++){
        if(intervals[i].start>newInterval.start){
            newi = i;
            break;
        }
    }
    // cout<<"newi "<<newi<<endl;
    if(newi==0){
        max = newInterval.end;
        // ans.push_back(newInterval);
        bool flag = true;
        for(int i=0; i<n; i++){
            if(intervals[i].start>max){
                Interval inter(newInterval.start, max);
                ans.push_back(inter);
                flag = false;
                for(int j=i; j<n; j++){
                    ans.push_back(intervals[j]);
                }
                break;
            }
            else{
                if(intervals[i].end>max){
                    max = intervals[i].end;
                }
            }
        }
        if(flag){
            Interval inter(newInterval.start, max);
            ans.push_back(inter);
        }
        return ans;
    }
    for(int i=0; i<(newi-1); i++){
        ans.push_back(intervals[i]);
    }
    if(intervals[newi-1].end>newInterval.start){
        first = newi-1;
        min = intervals[newi-1].start;
        if(intervals[newi-1].end>newInterval.end){
            max = intervals[newi-1].end;
            last = newi -1;
        }
        else{
            max = newInterval.end;
            last = -2;
        }
    }
    else{
        ans.push_back(intervals[newi-1]);
        first = -2; // to denote newInterval is first
        last = -2;
        min = newInterval.start;
        max = newInterval.end;
    }
    int newi2=-1;
    for(int i=(newi); i<n; i++){
        if(intervals[i].start>max){
            int newstart, newend;
            if(first==-2){
                newstart = newInterval.start;
            }
            else{
                newstart = intervals[first].start;
            }
            if(last == -2){
                newend = newInterval.end;
            }
            else{
                newend = intervals[last].end;
            }
            Interval inter(newstart, newend);
            ans.push_back(inter);
            newi2 = i;
            break;
        }
        else{
            if(intervals[i].end>max){
                last = i;
                max = intervals[i].end;
            }
        }
    }
    
    if(newi2==-1){
        int newstart, newend;
        if(first==-2){
            newstart = newInterval.start;
        }
        else{
            newstart = intervals[first].start;
        }
        if(last == -2){
            newend = newInterval.end;
        }
        else{
            newend = intervals[last].end;
        }
        Interval inter(newstart, newend);
        ans.push_back(inter);
        return ans;
    }
    else{
        for(int i=newi2; i<n; i++){
            ans.push_back(intervals[i]);
        }
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
