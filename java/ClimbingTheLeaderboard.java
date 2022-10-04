import java.util.*;

class Solution {
	static ArrayList<Integer> findPosition(ArrayList<Integer> ls, int n, ArrayList<Integer> ps, int m ){
        TreeSet<Integer> set = new TreeSet<>((a, b) -> b - a);
        for (Integer i : ls) {
            set.add(i);
        }
        
        ArrayList<Integer> list = new ArrayList<>(set);
        ArrayList<Integer> res = new ArrayList<>();
        
//         System.out.println(list);
        
        for (int x : ps) {
            int r = binarySearchIndex(list, x);
//             System.out.println(r);
            res.add(r);
        }
        
        return res;
    }
    
    private static int binarySearchIndex(ArrayList<Integer> arr, int x) {
        int n = arr.size();
        int l = 0, h = n-1;
        while (l < h) {
//             System.out.println(l + " " + h + " " + x);
            int m = l + (h - l)/2;
            if (arr.get(m) == x) {
                return m + 1;
            }
            if (arr.get(m) > x) {
                l = m + 1;
            } else {
                h = m;
            }
        }
        if (arr.get(l) > x) {
            l++;
        }
        return l + 1;
    }
}
