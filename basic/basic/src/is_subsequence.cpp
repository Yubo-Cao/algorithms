/**
 * Given a sequence of ints, a_1, a_2, ..., a_n, and a sequence of ints, b_1, b_2, ..., b_m, determine if b is a subsequence of a.
 * A subsequence of a sequence is a new sequence which is formed from the original sequence by deleting some (can be none) of the
 * of the elements without disturbing the relative positions of the remaining elements. (ie, "ace" is a subsequence of "abcde" while
 * "aec" is not).
 *
 * Input format:
 * - The first line contains two integers, n, m, the size of the two sequences.
 * - The next line contains n integers, a_1, a_2, ..., a_n, the elements of the first sequence.
 * - The next line contains m integers, b_1, b_2, ..., b_m, the elements of the second sequence.
 *
 * Output format:
 * - Yes if b is a subsequence of a, No otherwise.
 */

#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int i = 0;
    
    /**
     * If for all number in a, we find a corresponding number in b, then a is a
     * subsequence of b.
    */
    for (int j = 0; j < m; j++)
        if (i < n && a[i] == b[j]) i++;

    if (i == n)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}