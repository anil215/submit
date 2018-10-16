int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long ret = 1;
    long long x1 = x;
    while(n!=0){
        ret = ret%d;
        x1 = x1%d;
        if(n&1)
            ret = ((ret*x1)%d+d)%d;
        x1 = ((x1*x1)%d+d)%d;
        n >>= 1;
    }
    return (int)(ret%d+d)%d;
}
