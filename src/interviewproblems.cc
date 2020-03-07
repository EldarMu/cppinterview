class InterviewSolutions{
public:
// Given a number, find the number of steps required to bring that number to 0
// the only steps allowed are division by two and subtraction by one.
// Solution 1, the most obvious one, still as fast as it gets (0 ms).
 int numberOfSteps (int num) {
        int cnt = 0;
        while(num>0){
            if(num%2==0){
                num/=2;
                cnt++;
            } else {
                num -= 1;
                cnt++;
            }
        }
        return cnt;
    }
// Solution 2, same thing but with binary operations, no difference since 0 ms.
 int numberOfStepsTwo (int num){
     int cnt = 0;
     while(num>0){
        if(num%2==0){
            num >>= 1;
            cnt++;
        } else {
            num ^= 1;
            cnt++;
        }
     }
     return cnt;
    }
};