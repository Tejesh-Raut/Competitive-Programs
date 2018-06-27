/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1
 NOTE : If you are using your own declared global variables, make sure to clear them out in the constructor. 

*/

stack<int> S;
stack<int> Smin;

MinStack::MinStack() {
    // cout<<"* constructor"<<endl;
    while(!S.empty()){
        S.pop();
    }
    while(!Smin.empty()){
        Smin.pop();
    }
}

void MinStack::push(int x) {
    // cout<<"* push "<<x<<endl;
    S.push(x);
    if(!Smin.empty()){
        if(Smin.top()>=x){
            Smin.push(x);
        }
    }
    else{
        Smin.push(x);
    }
}

void MinStack::pop() {
    // cout<<"* pop"<<endl;
    if(!S.empty()){
        if(!Smin.empty()){
            if(Smin.top()==S.top()){
                Smin.pop();
            }
        }
        S.pop();
    }
}

int MinStack::top() {
    // cout<<"* top"<<endl;
    if(S.empty()){
        return -1;
    }
    return S.top();
}

int MinStack::getMin() {
    // cout<<"* getmin"<<endl;
    if(Smin.empty()){
        return -1;
    }
    return Smin.top();
}

