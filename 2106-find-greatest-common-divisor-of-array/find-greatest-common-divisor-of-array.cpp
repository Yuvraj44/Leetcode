class Solution {
public:
    int findMin(vector<int> a)
    {
        int m = a[0];
        for (auto i : a)
        {
            m = min(m, i);
        }
        return m;
    }
    int findMax(vector<int> a)
    {
        int m = a[0];
        for (auto i : a)
        {
            m = max(m, i);
        }
        return m;
    }
    int gcd(int a, int b)
    {
        while(a>0 && b>0)
        {
            if(a>b)
            a=a%b;
            else
            b=b%a;

            if(a==0)
            return b;
            if(b==0)
            return a;
        }
        return 1;
    }
    int findGCD(vector<int>& nums) {
        int n1 = findMin(nums);
        int n2 = findMax(nums);
        return gcd(n1, n2);
    }
};