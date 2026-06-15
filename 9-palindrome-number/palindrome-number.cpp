class Solution {
public:
    bool isPalindrome(int x) {
        int r;
        if(x<0)
        return 0;
        vector<int>v;
        vector<int>s;
        while(x){
            v.push_back(x%10);
            x=x/10;
        }
        s=v;
        reverse(v.begin(),v.end());
        if(s==v)
        return 1;
        return 0;

        
    }
};