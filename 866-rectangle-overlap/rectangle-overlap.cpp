class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int left1=rec1[0];
        int bottom1=rec1[1];
        int right1=rec1[2];
        int top1=rec1[3];

        
        int left2=rec2[0];
        int bottom2=rec2[1];
        int right2=rec2[2];
        int top2=rec2[3];
        
        return !(bottom1>=top2||right1<=left2||top1<=bottom2||left1>=right2);
    }
};