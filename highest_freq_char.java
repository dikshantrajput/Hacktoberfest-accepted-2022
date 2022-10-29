import java.util.*;
//Question : Suppose String = "abracadabra" , we need to find the string having highest frequency , suppose in this case ,'a'
public class highestFreqString {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a String : ");
        String s= sc.next();
        HashMap<Character,Integer> hm = new HashMap<>();

        for(int i = 0 ; i < s.length() ; i++){
            char word = s.charAt(i);
            if(hm.containsKey(word)){
                int oldFreq = hm.get(word);
                int newFreq = oldFreq + 1;
                hm.put(word , newFreq);
            }else{
                hm.put(s.charAt(i) , 1);
            }
            
        }
       
       char max = s.charAt(0);
       for(char key : hm.keySet()){
           if(hm.get(key) > hm.get(max)){
             max = key;
           }
       }
       System.out.println(max);
       
       

        
    }
}
