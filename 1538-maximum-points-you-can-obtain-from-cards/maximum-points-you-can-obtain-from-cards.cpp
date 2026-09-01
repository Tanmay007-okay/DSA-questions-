class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int lS=0,rS=0,maxS=0;
        for(int i=0;i<k;i++){ //picking first k cards;
            lS=lS+cardPoints[i];
            maxS=lS;
        }
        int rInd=n-1;
        for(int i=k-1;i>=0;i--){//adding from back and removing the elements from front 
            lS=lS-cardPoints[i];
            rS=rS+cardPoints[rInd];
            rInd=rInd-1;
            maxS=max(maxS,lS+rS);
        }
        return maxS;
        
    }
};