grumpy = [
    "don't even", "are you serious?", "terrible", "go die in a hole", "worse",
    "no way"
]
normal = ["great!", "don't think so", "not bad", "don't touch me!", "cool"]

for i in [5, 9, 8, 1, 2, 3, 6]:
    print(i, flush=True)
    s = input()
    if s in grumpy:
        print('grumpy')
        break
    elif s in normal:
        print('normal')
        break