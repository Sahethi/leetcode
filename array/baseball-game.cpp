class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        stack<int> res;

        for(auto op : operations){
            if(op == "C"){
                res.pop();
            }else if (op == "D"){
                res.push(2 * res.top());
            }else if (op == "+"){
                int top1 = res.top(); 
                res.pop();
                int top2 = res.top();
                res.push(top1); 
                res.push(top1+top2);
            }else{
                res.push(stoi(op));
            }
        }

        int sum=0;
        while(!res.empty()){
            sum += res.top();
            res.pop();
        }

        return sum;
    }
};