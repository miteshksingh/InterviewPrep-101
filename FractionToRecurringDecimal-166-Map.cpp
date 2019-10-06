class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        if(numerator == 0) {
            return "0";
        }
        
        string fraction = "";
        if(numerator < 0 ^ denominator < 0) {
            fraction = "-";
        }
        
        long long dividend = abs((long long)numerator);
        long long divisor = abs((long long)denominator);
        fraction = fraction + to_string(dividend/divisor);
        
        long long remainder = dividend % divisor;
        if(remainder == 0) {
            return fraction;
        }
        fraction = fraction + ".";
        map<long long, int> m;
        
        while(remainder != 0) {
            
            if(m.find(remainder) != m.end()) {
                fraction.insert(m[remainder], "(");
                fraction = fraction + ")";
                break;
            }
            
            m[remainder] = fraction.length();
            remainder = remainder * 10;
            fraction = fraction + to_string(remainder/divisor);
            remainder = remainder % divisor;
        }
        
        return fraction;
    }
};
