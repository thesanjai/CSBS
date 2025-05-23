def matrix_multiplication(matrix1,matrix2):
    if len(matrix1[0]) != len(matrix2):
        print("The matrices cannot be multiplied")
        return None
    return [[sum(matrix1[i][k]*matrix2[k][j] for k in range(len(matrix2))) for j in range(len(matrix2[0]))] for i in range(len(matrix1))]

rowA = int(input("Enter the row A:"))
colA = int(input("Enter the column A:"))

print("Enter the elements of the first matrix: ")
matrix1 = [[int(input(f"Enter the elements A[{i}][{j}]:")) for j in range(colA)] for i in range(rowA)]

rowB = int(input("Enter the row B:"))
colB = int(input("Enter the column A:"))

print("Enter the elements of the second matrix: ")
matrix2 = [[int(input(f"Enter the elements B[{i}][{j}]:")) for j in range(colB)] for i in range(rowB)]


result = matrix_multiplication(matrix1, matrix2)

[print (row) for row in result] if result is not None else None

