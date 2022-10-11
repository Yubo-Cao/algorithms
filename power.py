cache = {}

def _pow(x, n):
    if (result := cache.get(n)) is not None:
        return result
    if n == 0:
        return 1
    if n == 1:
        return x
    if n == 2:
        return x * x
    result = cache[n] = _pow(x, n >> 1) * _pow(x, n >> 1) * (x if n & 1 else 1)
    return result


def my_pow(x, n):
    cache.clear()
    if n < 0:
        return 1 / _pow(x, -n)
    return _pow(x, n)


print(my_pow(8.88023, 3))
