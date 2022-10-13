import java.util.HashMap;

public class Save_your_Life {
    public static void main(String[] args) {
        String str="oK";
        int n=2;
        char[] x={'K','o'};
        int[] b={-880,53};
        System.out.println(maxSum(str,x,b,n));
    }
    static String maxSum(String w,char x[],int b[], int n){
        //code here
        HashMap<Character,Integer> map=new HashMap<>();
        for(int i=0;i<n;i++) {
            map.put(x[i],map.getOrDefault(x[i],0)+b[i]);
        }
        //Traversing the String
        StringBuilder sb=new StringBuilder();
        String ans="";
        int max=0,curr=0;
        for(int i=0;i<w.length();i++) {
            char ch=w.charAt(i);
            int ascii;
            if(map.containsKey(ch)) {
                ascii=map.get(ch);
            }
            else {
                ascii=findAscii(ch);
            }
            curr+=ascii;
            if(curr<0) {
                curr=0;
                max=0;
                ans=sb.toString();
                sb.setLength(0);
            }
            else {
                sb.append(ch);
                max=Math.max(max,curr);
            }
        }
        return ans;
    }
    static int findAscii(char ch) {
        int ascii=ch;
        return ascii;
    }
}
