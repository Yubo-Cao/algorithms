from typing import List


def hamming_distance(s1: str, s2: str) -> int:
    if len(s1) != len(s2):
        return float("inf")
    return sum(c1 != c2 for c1, c2 in zip(s1, s2))


def autocorrect(
    dictionary: List[str],
    misspelled: List[str],
):
    for word in misspelled:
        distances = [hamming_distance(word, d) for d in dictionary]
        print(dictionary[distances.index(min(distances))])


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        D, W = map(int, input().split())
        dictionary = [input().strip() for _ in range(D)]
        misspelled = [input().strip() for _ in range(W)]
        result = autocorrect(dictionary, misspelled)
