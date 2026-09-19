class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        auto calculateDistanceToRange = [](int minVal, int maxVal, int point) -> int {
            if (minVal <= point && point <= maxVal) {
                return 0;  
            }

            return point < minVal ? minVal - point : point - maxVal;
        };

        int horizontalDistance = calculateDistanceToRange(x1, x2, xCenter);

        int verticalDistance = calculateDistanceToRange(y1, y2, yCenter);

        return horizontalDistance * horizontalDistance + verticalDistance * verticalDistance <= radius * radius;
    }
};
