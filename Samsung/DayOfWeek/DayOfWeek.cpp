#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    string getDayOfWeek(int d, int m, int y) {
        vector<string> days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        vector<int> monthOddDays = {3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3};
        int oddDays = 0;
        
        y--;
        int leftOddYears = y % 400;
        if(leftOddYears >= 300){
            leftOddYears -= 300;
            oddDays += 1;
        } else if(leftOddYears >= 200) {
            leftOddYears -= 200;
            oddDays += 3;
        } else if(leftOddYears >= 100) {
            leftOddYears -= 100;
            oddDays += 5;
        }
        oddDays += (leftOddYears/4) * 2 + (leftOddYears - leftOddYears/4);

        m--;
        y++;
        for(int i=0; i<m; i++){
            if(i==1 && (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)))
                oddDays++;
            oddDays += monthOddDays[i];
        }
        
        oddDays += d;
        
        return days[oddDays%7];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d,m,y;
        
        cin>>d>>m>>y;

        Solution ob;
        cout << ob.getDayOfWeek(d,m,y) << endl;
    }
    return 0;
}


// int day_of_the_week(int y, int m, int d){
//     // array with leading number of days values
//     int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
     
//     // if month is less than 3 reduce year by 1
//     if (m < 3)
//         y -= 1;
     
//     return ((y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7);
// }