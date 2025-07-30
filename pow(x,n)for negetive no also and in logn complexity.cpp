class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        if (n < 0) {
            return 1 / (x * myPow(x, -(n + 1))); 
        }
        double res=myPow(x,n/2);
        res*=res;
        if(n%2!=0){
            res*=x;
        }
        return res;
    }
};
