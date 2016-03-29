import java.util.Scanner;
class MoneyDecomposer {
    // available coins
    private static int[] coins = {2000, 1000, 500, 200, 100, 50, 20, 10, 5, 1};

    public static int[] decompose(int money) {
        /*
         *  Decompose money into coins repetitions.
         */
        int[] coin_repetitions = new int[10];

        for (int coin = 0; coin < 10 && money > 0; ++coin) {
            while (money - coins[coin] >= 0) {
                money -= coins[coin];
                coin_repetitions[coin] += 1;
            }
        }
        return coin_repetitions;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the amount of money: ");
        int money = input.nextInt();
        int[] decomposed = decompose(money);

        // outputing result
        System.out.printf("%d decomposed is: \n", money);
        for (int i = 0; i < 10; ++i) {
            if (decomposed[i] > 0)
                System.out.printf("%d * %d\n", decomposed[i], coins[i]);
        }
    }
}
