num_test_cases = int(input())

for i in range(num_test_cases):
    d, e = map(int, input().split())
    dependencies: dict[str, list[str]] = {}
    for j in range(d):
        dependency, dependent = input().split()
        dependencies.setdefault(dependency, []).append(dependent)

    for j in range(e):
        failed_program = input().strip()
        restart_order = []
        visited = set()

        def find_restart_order(program):
            if program in visited:
                return
            visited.add(program)
            if program in dependencies:
                for dependent in dependencies[program]:
                    find_restart_order(dependent)
            restart_order.append(program)

        find_restart_order(failed_program)

        for program in restart_order:
            print("restart " + program)
        print("exit")
