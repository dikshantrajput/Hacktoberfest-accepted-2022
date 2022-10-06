import java.util.*; 
public class SegmentedSieve {

    public static void sieve(int n, Vector<Integer> prime){
        boolean[] isPrime = new boolean[n+1];
        for(int i = 2; i <= n; i++){
            isPrime[i] = true;
        }
        for(int i = 2; i <= n; i++){
            if(isPrime[i]){
                prime.add(i);
                for(int j = i*i; j <= n; j += i){
                    isPrime[j] = false;
                }
            }
        }
    }

    public static void segSieve(int l, int h){
        Vector<Integer> prime = new Vector<Integer>();
        int sq = (int)Math.sqrt(h);
        sieve(sq, prime);
        boolean[] isPrime = new boolean[h-l+1];
        Arrays.fill(isPrime, true);

        for(int p: prime){
            int start = (l/p)*p;
            if(start < l)
                start += p;
            for(int i = start; i <= h; i += p){
                isPrime[i-l] = false;
            }
        }

        for(int i=l; i<=h; i++){
            if(isPrime[i-l])
                System.out.print(i + " ");
        }
    }
    public static void main(String[] args) {
        segSieve(5, 9);
    }
}
