import sys

def process_case(N, A, B, grid):
    if A == 0 and B == 0:
        count = 0
        for row in grid:
            count += row.count('B')
            count += row.count('G')
        return count
    elif A == 1 and B == 0:
        total = 0
        for row in grid:
            dp_prev = {}
            if len(row) < 1:
                continue
            # Process j=1 (0-based in string)
            c = row[0]
            if c == 'B':
                return -1
            elif c == 'W':
                dp_prev[False] = 0
            else:  # 'G'
                dp_prev[True] = 1
            # Process j >=2 (1-based in the row)
            for j in range(2, N+1):
                c = row[j-1]
                dp_current = {}
                for prev_in, stars_so_far in dp_prev.items():
                    if c == 'W':
                        if prev_in:
                            continue
                        # current_in must be False
                        key = False
                        if key not in dp_current or stars_so_far < dp_current.get(key, float('inf')):
                            dp_current[key] = stars_so_far
                    elif c == 'B':
                        if not prev_in:
                            continue
                        # current_in must be True
                        key = True
                        new_stars = stars_so_far + 1
                        if key not in dp_current or new_stars < dp_current.get(key, float('inf')):
                            dp_current[key] = new_stars
                    elif c == 'G':
                        # case a: prev_in False, current_in True
                        if not prev_in:
                            key = True
                            new_stars = stars_so_far + 1
                            if key not in dp_current or new_stars < dp_current.get(key, float('inf')):
                                dp_current[key] = new_stars
                        # case b: prev_in True, current_in False
                        if prev_in:
                            key = False
                            new_stars = stars_so_far
                            if key not in dp_current or new_stars < dp_current.get(key, float('inf')):
                                dp_current[key] = new_stars
                if not dp_current:
                    return -1
                dp_prev = dp_current
            if not dp_prev:
                return -1
            total += min(dp_prev.values())
        return total
    else:
        return -1

def main():
    input = sys.stdin.read().split()
    ptr = 0
    T = int(input[ptr])
    ptr +=1
    for _ in range(T):
        N = int(input[ptr])
        A = int(input[ptr+1])
        B = int(input[ptr+2])
        ptr +=3
        grid = []
        for _ in range(N):
            row = input[ptr]
            ptr +=1
            grid.append(row)
        res = process_case(N, A, B, grid)
        print(res)

if __name__ == "__main__":
    main()