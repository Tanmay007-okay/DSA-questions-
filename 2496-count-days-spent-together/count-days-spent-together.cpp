class Solution {
public:
    // Days in each month (non-leap year)
    vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    /**
     * Calculate the number of days when both Alice and Bob are in the city together
     * @param arriveAlice - Alice's arrival date in "MM-DD" format
     * @param leaveAlice - Alice's departure date in "MM-DD" format
     * @param arriveBob - Bob's arrival date in "MM-DD" format
     * @param leaveBob - Bob's departure date in "MM-DD" format
     * @return Number of days both are present in the city
     */
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // Find the overlapping period
        // Start of overlap: latest arrival date
        string overlapStart = arriveAlice < arriveBob ? arriveBob : arriveAlice;
      
        // End of overlap: earliest departure date
        string overlapEnd = leaveAlice < leaveBob ? leaveAlice : leaveBob;
      
        // Convert dates to day of year
        int startDay = convertDateToDayOfYear(overlapStart);
        int endDay = convertDateToDayOfYear(overlapEnd);
      
        // Calculate overlap days (inclusive), return 0 if no overlap
        return max(0, endDay - startDay + 1);
    }

private:
    /**
     * Convert a date string to the day number of the year
     * @param dateString - Date in "MM-DD" format
     * @return Day number of the year (1-365)
     */
    int convertDateToDayOfYear(string dateString) {
        int month, day;
      
        // Parse month and day from the date string
        sscanf(dateString.c_str(), "%d-%d", &month, &day);
      
        // Calculate total days from January 1st
        int totalDays = 0;
      
        // Add days from all previous months
        for (int i = 0; i < month - 1; ++i) {
            totalDays += daysInMonth[i];
        }
      
        // Add days in the current month
        totalDays += day;
      
        return totalDays;
    }
};
