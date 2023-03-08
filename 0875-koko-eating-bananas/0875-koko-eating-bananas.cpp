class Solution {
public:
  long long int black(long long int mid,vector<int>& piles)
    {
      long long int sum = 0;
    for(auto i:piles){
        sum += ceil((double)i/mid);
    }
    return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
         int high=*max_element(piles.begin(),piles.end());
        
        while(low<=high)
        {
           long long int mid=(low + high) /2;
            if(black(mid,piles) <=h)
            {
                high=mid-1;
                
            }
            else
            {
                low=mid+1;
            }
        }
        
        return low;
    }
};