package air_conditioning;

import java.util.Scanner;

public class Main {
    private static int nCow;
    private static int nAir;
    private static Cow[] cows;
    private static AirConditioner[] airConditioners;

    private static int cost;
    private static int minCost = Integer.MAX_VALUE;
    private static int[] cooledDifference = new int[100];
    private static int[] cooled = new int[100];

    private static void constructCooled() {
        cooled[0] = cooledDifference[0];
        for (int i = 1; i < 100; i++) {
            cooled[i] = cooled[i - 1] + cooledDifference[i];
        }
    }

    public static void main(String[] args) {
        IO();
        System.out.println(solve());
    }

    private static int solve() {
        dfs(0);
        return minCost;
    }

    private static void dfs(int idx) {
        if (idx == nAir) {
            constructCooled();
            boolean flag = true;
            for (Cow cow : cows) {
                if (!cow.isCooled()) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                minCost = Math.min(minCost, cost);
            }
            return;
        }
        airConditioners[idx].open();
        dfs(idx + 1);
        airConditioners[idx].close();
        dfs(idx + 1);
    }

    private static void IO() {
        try (Scanner scan = new Scanner(System.in)) {
            nCow = scan.nextInt();
            nAir = scan.nextInt();
            cows = new Cow[nCow];
            airConditioners = new AirConditioner[nAir];
            for (int i = 0; i < nCow; i++) {
                int start = scan.nextInt() - 1;
                int end = scan.nextInt() - 1;
                int cooling = scan.nextInt();
                cows[i] = new Cow(start, end, cooling);
            }
            for (int i = 0; i < nAir; i++) {
                int start = scan.nextInt() - 1;
                int end = scan.nextInt() - 1;
                int cooling = scan.nextInt();
                int cost = scan.nextInt();
                airConditioners[i] = new AirConditioner(start, end, cost, cooling);
            }
        }
    }

    private static class AirConditioner {
        private int start;
        private int end;
        private int c;
        private int cooling;

        public AirConditioner(int start, int end, int cost, int cooling) {
            this.start = start;
            this.end = end;
            this.c = cost;
            this.cooling = cooling;
        }

        private void open() {
            cooledDifference[start] += cooling;
            cooledDifference[end + 1] -= cooling;
            cost += c;
        }

        private void close() {
            cooledDifference[start] -= cooling;
            cooledDifference[end + 1] += cooling;
            cost -= c;
        }

        @Override
        public String toString() {
            return "AirConditioner [start=" + start + ", end=" + end + ", cost=" + c + ", cooling=" + cooling + "]";
        }
    }

    private static class Cow {
        int start;
        int end;
        int cooling;

        public Cow(int start, int end, int cooling) {
            this.start = start;
            this.end = end;
            this.cooling = cooling;
        }

        public boolean isCooled() {
            boolean flag = true;
            for (int i = start; i <= end; i++) {
                if (cooled[i] < cooling) {
                    flag = false;
                    break;
                }
            }
            return flag;
        }

        @Override
        public String toString() {
            return "Cow [start=" + start + ", end=" + end + ", cooling=" + cooling + "]";
        }
    }
}
