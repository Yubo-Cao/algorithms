for wave in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    def find_largest_subarray(a):
        max_sum = float("-inf")
        max_subarrays = []
        for i in range(len(a)):
            for j in range(i, min(i + 15, len(a))):
                subarray_sum = sum(a[i : j + 1])
                while a[i] == 0 and i < j:
                    i += 1
                while a[j] == 0 and i < j:
                    j -= 1
                if subarray_sum > max_sum:
                    max_sum = subarray_sum
                    max_subarrays = [(i, j)]
                elif subarray_sum == max_sum:
                    max_subarrays.append((i, j))
        return max_subarrays

    def pad_arrays(target):
        left_0, right_0 = 0, 0
        while (target[1] - target[0]) < 14 and target[0] > 0:
            target = (target[0] - 1, target[1])
            left_0 += 1
        while (target[1] - target[0]) < 14 and target[1] < len(a) - 1:
            target = (target[0], target[1] + 1)
            right_0 += 1
        return (target, right_0 - left_0)

    def pick(targets):
        targets = [pad_arrays(target) for target in targets]
        return sorted(sorted(targets, key=lambda x: x[1]), key=lambda x: x[0])[-1][0]

    shot = 1
    while a:
        print(f"Wave #{wave + 1} --- Shot #{shot}")
        print(f"Elements in wave: {' '.join(map(str, a))}")
        print(f"Current size of wave: {len(a)}")
        print(f"Total threat value of wave: {sum(a)}")
        target = pick(find_largest_subarray(a))
        print(f"Targeted range: Elements {target[0]} to {target[1]}")
        print(
            f'Eliminated elements: {" ".join(map(str, a[target[0] : target[1] + 1]))}'
        )
        print(f"Number of elements destroyed: {target[1] - target[0] + 1}")
        print(f"Total threat value eliminated: {sum(a[target[0] : target[1] + 1])}")
        del a[target[0] : target[1] + 1]
        shot += 1
        print()
