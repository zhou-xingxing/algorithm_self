// �޽��״������� 


class Solution {
public:
    // dp[i][k][0]����i�죬�Ѿ�����k�Σ�Ŀǰû�й�Ʊʱ���е�Ǯ
    // dp[i][k][1]����i�죬�Ѿ�����k�Σ�Ŀǰ�й�Ʊʱ���е�Ǯ
    
    // dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
    // dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
    // ����ֻ����һ���й�ϵ���������ռ��Ͽ����Ż�

    int maxProfit(vector<int>& prices) {
        int dp_i0=0,dp_i1=INT_MIN;
        int tmp;
        for(int i=0;i<prices.size();i++){
            tmp=dp_i0;
            dp_i0=max(dp_i0,dp_i1+prices[i]);
            dp_i1=max(dp_i1,tmp-prices[i]);
        }
        return dp_i0;
    }
};
