//Given two binary strings a and b, return their sum as a binary string.
/*Example
Input: a = "1010", b = "1011"
Output: "10101"
*/


class Solution {
    public String addBinary(String a, String b) {
        int carry=0;
        int sum=0;
        Map<Character, Integer> r = new HashMap<>();
        r.put('1', 1);
        r.put('0', 0);
        if(a.length()<b.length()){
            int diff=b.length()-a.length();
            for(int i=0;i<diff;i++){
                a="0"+a;
            }
        }
        else{
            int diff=a.length()-b.length();
            for(int i=0;i<diff;i++){
                b="0"+b;
            }
        }
        StringBuilder str=new StringBuilder("");
        int n=a.length();
        for(int i=n-1;i>=0;i--){
            sum=r.get(a.charAt(i))+r.get(b.charAt(i))+carry;
            if(sum==2){
                str.append("0");
                carry=1;
            }
            else if(sum==1){
                str.append("1");
                carry=0;
            }
            else if(sum==3){
                str.append("1");
                carry=1;
            }
            else{
                str.append("0");
                carry=0;
            }
        }if(carry==1){
        str.append("1");
        }
            str.reverse();
         String ss = str.toString();
        return ss;
    }
}
