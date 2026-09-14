class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        /*
            rec1[0]->x1,rec1[1]->y1,rec1[2]->x2,rec1[3]->y2
            rec2[0]->p1,rec2[1]->q1,rec2[2]->p2,rec2[3]->q2
        */

       if(rec1[0] >= rec2[2] || rec2[0] >= rec1[2] || rec1[1] >= rec2[3] || rec2[1] >= rec1[3]) return false;
       return true;
    }
};