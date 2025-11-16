Denominations = [2000, 500, 200, 100, 50, 20, 10, 5, 2, 1]

k = int(input("Enter the count:"))
k %= len(Denominations)

print(f"Original Array : {Denominations}")

Denominations = Denominations[::-1]

left_rotation = Denominations.copy()
left_rotation[:k] = left_rotation[:k][::-1]
left_rotation[k:] = left_rotation[k:][::-1]
print(f"Left Rotation : {left_rotation}")

right_rotation = Denominations.copy()
right_rotation[:-k] = right_rotation[:-k][::-1]
right_rotation[-k:] = right_rotation[-k:][::-1]
print(f"Right Rotation : {right_rotation}")