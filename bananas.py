import sys

UNREACHABLE_OUTPUT = -1   # try 0 if -1 is rejected


def main():
    lines = [ln.strip() for ln in sys.stdin.read().split('\n') if ln.strip()]
    if len(lines) < 2:
        return
    q = lines.pop().split()
    if len(q) < 2 and lines:
        q = lines.pop().split() + q
    start, dest = q[-2], q[-1]

    states = set()      # (spot, tree)
    edges = []          # (from_state, to_state, cost)
    tree = 0
    for ln in lines[1:]:
        tk = ln.split()
        if tk[0].lower() == "break":
            tree += 1
            continue
        states.add((tk[0], tree))
        for c in tk[1:]:
            states.add((c, tree))
            edges.append(((tk[0], tree), (c, tree), 1))   # climb up
            edges.append(((c, tree), (tk[0], tree), 0))   # climb down

    by_spot = {}
    for s in states:
        by_spot.setdefault(s[0], []).append(s)
    for sts in by_spot.values():                          # switch trees
        for x in sts:
            for y in sts:
                if x != y:
                    edges.append((x, y, 1))

    INF = float('inf')
    dist = {s: INF for s in states}
    for s in by_spot.get(start, []):
        dist[s] = 0

    # brute force: keep relaxing every edge until nothing improves
    changed = True
    while changed:
        changed = False
        for u, v, w in edges:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                changed = True

    ans = min((dist[s] for s in by_spot.get(dest, [])), default=INF)
    if start == dest and start in by_spot:
        ans = 0
    print(UNREACHABLE_OUTPUT if ans == INF else ans)


main()