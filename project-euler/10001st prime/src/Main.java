 // 10001st prime; Algorithm used: "Sieve of Eratosthenes"
public class Main {
    public static void main(String args []){
        long numberOfPrimes = 0;
        int number = 1;
        int maxLimit = 10000000;
        boolean[] sieve = new boolean[maxLimit];
        for (int i = 2; i < maxLimit; i++) {
            if (sieve[i] == true) 
            	continue;
            numberOfPrimes++;
            if ( numberOfPrimes == 10001 ) {
                number = i;
                break;
            }
            for (int j = i+i; j < maxLimit; j += i)
                sieve[j] = true;
        }
        System.out.println("10001st prime: "+ number); // prints 10001st prime: 104743
    }
}