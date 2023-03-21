import random, sys, itertools

def list_generator(start: int, end: int) -> list:
    array = list(range(start, end + 1))
    random.shuffle(array)
    return (array)

if __name__ == "__main__":
    array = list_generator(int(sys.argv[1]), int(sys.argv[2]))
    [print(f"{i} ", end='') for i in array]