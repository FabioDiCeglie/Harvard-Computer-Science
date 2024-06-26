from cs50 import get_int

# Prompt user for a valid height
while True:
    height = get_int("Height: ")
    if 1 <= height <= 8:
        break

for i in range(height):
    height -= 1
    hashes = i + 1
    print(" " * height + "#" * hashes + "  " + "#" * hashes)