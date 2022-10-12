import java.util.regex.*;
class Regex1{
    public static void main(String args[]){
        Pattern pat=Pattern.compile(" Java");
        Matcher mat=pat.matcher("java");
        boolean found=mat.matches(); // checks for a match

        System.out.println("Testing Java against java");
        if(found){
        System.out.println("Matched");}
        else
        System.out.println("Not matched");

        System.out.println();
        System.out.println("Testing Java against Java");
        if(found){
            System.out.println("Matched");}
            else
            System.out.println("Not matched");
    
        
    }
}