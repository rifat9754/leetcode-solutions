class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cnt=0;
        for(int i=0;i<=digits.size()-1;i++){
            if(digits[i]==9) cnt++;
        }
        if(cnt==digits.size()){
            vector<int>v(digits.size()+1,0);
            v[0]=1;
            return v;
        }
        else if(digits[digits.size()-1]<9){
             digits[digits.size()-1]=digits[digits.size()-1]+1;
             return digits;
        }


        for(int i= digits.size()-1;i>=0;i--){
            if(digits[i]==9){
                digits[i]=0;
            }
            else{
                digits[i]=digits[i]+1;
                break;
            }
        }

         return digits;

    }  
};