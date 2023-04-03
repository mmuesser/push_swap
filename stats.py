#!/usr/bin/python3

import sys
from collections import Counter, deque
from itertools import zip_longest
from random import randint, sample, seed
from subprocess import list2cmdline, run


class System:
    def __init__(self, a, b) -> None:
        self.a = deque(a)
        self.b = deque(b)
        self.buffer = []

    def sa(self) -> None:
        if len(self.a) < 2:
            return
        self.a[-1], self.a[-2] = self.a[-2], self.a[-1]
        self.buffer.append("sa")

    def sb(self) -> None:
        if len(self.b) < 2:
            return
        self.b[-1], self.b[-2] = self.b[-2], self.b[-1]
        self.buffer.append("sb")

    def ss(self) -> None:
        if len(self.a) < 2:
            return
        self.a[-1], self.a[-2] = self.a[-2], self.a[-1]

        if len(self.b) < 2:
            return
        self.b[-1], self.b[-2] = self.b[-2], self.b[-1]
        self.buffer.append("ss")

    def pa(self) -> None:
        if not self.b:
            return
        self.a.append(self.b.pop())
        self.buffer.append("pa")

    def pb(self) -> None:
        if not self.a:
            return
        self.b.append(self.a.pop())
        self.buffer.append("pb")

    def ra(self) -> None:
        self.a.rotate()
        self.buffer.append("ra")

    def rb(self) -> None:
        self.b.rotate()
        self.buffer.append("rb")

    def rr(self) -> None:
        self.a.rotate()
        self.b.rotate()
        self.buffer.append("rr")

    def rra(self) -> None:
        self.a.rotate(-1)
        self.buffer.append("rra")

    def rrb(self) -> None:
        self.b.rotate(-1)
        self.buffer.append("rrb")

    def rrr(self) -> None:
        self.a.rotate(-1)
        self.b.rotate(-1)
        self.buffer.append("rrr")

    def apply_moves(self, moves) -> None:
        for move in moves:
            move_func = getattr(self, move)
            move_func()

    def get_longest_number_len(self):
        len_filter = lambda n: len(str(n))
        longest_a = len(str(max(self.a, key=len_filter))) if self.a else 0
        longest_b = len(str(max(self.b, key=len_filter))) if self.b else 0
        return max(longest_a, longest_b)

    def print(self) -> None:
        max_len = self.get_longest_number_len()
        for a, b in zip_longest(reversed(self.a), reversed(self.b), fillvalue=""):
            print(f"{a:>{max_len}} {b:>{max_len}}")
        print("_" * max_len, "_" * max_len)
        print("a" * max_len, "b" * max_len)
        print("")


def get_stats(program: str, number_of_tests: int, lists_size: int):
    stats = []
    for _ in range(number_of_tests):
        numbers = sample(range(-99999, 99999), lists_size)
        output = run([program] + list(map(str, numbers)), capture_output=True)
        moves = output.stdout.decode().split()
        system = System(reversed(numbers), [])
        system.apply_moves(moves)
        assert list(reversed(system.a)) == list(sorted(map(int, numbers)))
        counter = Counter(moves)
        print(len(moves), end=" ")
        print(counter)
        stats.append(len(moves))

    print(f"MIN: {min(stats)}")
    print(f"MAX: {max(stats)}")
    print(f"AVG: {round(sum(stats)/len(stats))}")


def main() -> None:
    if len(sys.argv) != 5:
        print("Usage: ./stats [PROGRAM] [NUMBER_OF_TESTS] [LISTS_SIZE] [SEED]")
        sys.exit(0)
    program, number_of_tests, lists_size, input_seed = (
        sys.argv[1],
        sys.argv[2],
        sys.argv[3],
        sys.argv[4],
    )
    final_seed = randint(0, 999999)
    if input_seed != "-1":
        final_seed = int(input_seed)
    seed(final_seed)
    print("SEED:", final_seed)

    get_stats(program, int(number_of_tests), int(lists_size))


if __name__ == "__main__":
    main()