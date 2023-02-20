package leaders;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Main {
    private static int n;
    private static char[] cowTypes;
    private static int[] e;

    private static int countH;
    private static int countG;

    // count or finite difference
    private static int[] countHs;
    private static int[] countGs;

    // all cows
    private static Cow[] cows;
    private static Set<Cow> leadersH = new HashSet<>();
    private static Set<Cow> leadersG = new HashSet<>();

    public static void main(String[] args) {
        IO();

        // basic counting
        // N = 10e5
        for (int i = 0; i < cowTypes.length; i++) {
            if (cowTypes[i] == 'H')
                countH++;
            else
                countG++;
            countHs[i] = countH;
            countGs[i] = countG;
        }

        // N = 10e5
        for (int i = 0; i < n; i++) {
            cows[i] = new Cow(i, cowTypes[i], e[i] - i + 1,
                    (cowTypes[i] == 'H' ? countHs[e[i]] - countHs[i] : countGs[e[i]] - countGs[i]) + 1);
        }

        // N = 10e5
        for (Cow cow : cows) {
            if (cow.hasAllSameType()) {
                if (cow.type == 'H')
                    leadersH.add(cow);
                else
                    leadersG.add(cow);
            }
        }

        int result = 0;
        result += leadersH.size() * leadersG.size();

        // finite difference of each locations
        // cow that has x
        int[] hasFriendH = new int[n + 1];
        int[] hasFriendG = new int[n + 1];

        for (Cow cow : cows) {
            if (cow.hasAllSameType())
                continue;
            if (cow.type == 'H') {
                hasFriendH[cow.index]++;
                hasFriendH[cow.index + cow.friendsCount]--;
            } else {
                hasFriendG[cow.index]++;
                hasFriendG[cow.index + cow.friendsCount]--;
            }
        }

        // construct prefix sum
        for (int i = 1; i <= n; i++) {
            hasFriendH[i] += hasFriendH[i - 1];
            hasFriendG[i] += hasFriendG[i - 1];
        }

        for (Cow gLeader : leadersG) {
            result += hasFriendH[gLeader.index];
        }
        for (Cow hLeader : leadersH) {
            result += hasFriendG[hLeader.index];
        }

        System.out.println(result);
    }

    private static void IO() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            n = Integer.parseInt(br.readLine());
            cowTypes = br.readLine().toCharArray();

            String[] eStr = br.readLine().split(" ");
            e = new int[n];
            for (int i = 0; i < n; i++) {
                e[i] = Integer.parseInt(eStr[i]) - 1;
            }

            countHs = new int[n];
            countGs = new int[n];
            cows = new Cow[n];
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    private static class Cow {
        private int index;
        private char type;
        private int friendsCount;
        private int sameTypeFriendsCount;

        public Cow(int index, char type, int friendsCount, int sameTypeFriendsCount) {
            this.index = index;
            this.type = type;
            this.friendsCount = friendsCount;
            this.sameTypeFriendsCount = sameTypeFriendsCount;
        }

        // leader check
        public boolean hasFriend(int idx) {
            return idx >= index && idx <= index + friendsCount;
        }

        public boolean hasAllSameType() {
            // has all
            if (type == 'H')
                return sameTypeFriendsCount == countH;
            else
                return sameTypeFriendsCount == countG;
        }

        @Override
        public String toString() {
            return "Cow [index=" + index + ", type=" + type + ", friendsCount=" + friendsCount
                    + ", sameTypeFriendsCount=" + sameTypeFriendsCount + "]";
        }
    }
}