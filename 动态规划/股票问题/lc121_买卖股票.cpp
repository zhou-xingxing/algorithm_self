//������Ʊ������һ��

class Solution {
public:
    int maxProfit(vector<int>& prices) {                //����minprice,maxprofit
        if(prices.empty()){
            return 0;
        }
        int min,max;
        min=prices[0];
        max=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<min){
                min=prices[i];
            }
            else{
                if(max<prices[i]-min){
                    max=prices[i]-min;
                }
            }
        }
        return max;
    }
}; 
