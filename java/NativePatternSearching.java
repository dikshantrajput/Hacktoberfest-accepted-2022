public class NativePatternSearching {
 
    static void search(String patt, String text)
    {
        int l1 = patt.length();
        int l2 = text.length();
        int i = 0, j = l2 - 1;
 
        for (i = 0, j = l2 - 1; j < l1;) {
 
            if (text.equals(patt.substring(i, j + 1))) {
                System.out.println("Pattern found at index "
                                   + i);
            }
            i++;
            j++;
        }
    }
     
      // Driver's code
    public static void main(String args[])
    {
        String pat = "AABAACAADAABAAABAABBABBBAABA";
        String txt = "AABA";
     
     
        search(pat, txt);
    }
}