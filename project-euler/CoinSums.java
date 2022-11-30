public class CoinSums {
    public static int[] coinArr = {1, 2, 5, 10, 20, 50, 100, 200};
    public static int count = 0;
    public static void main(String[] args) {
        changer(coinArr.length-1, 200);
        System.out.println(count); // Prints 73682
    }
    
    public static void changer(int idx, int val) {
        int currentCoin = coinArr[idx];
        if (idx == 0) {
            if (val % currentCoin == 0)
            count++;
            return;
        }
        while (val >= 0) {
            changer(idx-1, val);
            val -= currentCoin;
        }
    }
}