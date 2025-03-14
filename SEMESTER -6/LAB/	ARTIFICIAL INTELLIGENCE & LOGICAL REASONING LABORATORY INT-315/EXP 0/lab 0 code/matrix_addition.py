
def add_matrix(matrix1, matrix2):
    if len(matrix1) != len(matrix2) or len(matrix1[0]) != len(matrix2[0]):
        print("The matrices are not of the same size")
        return None
    
    return [[matrix1[i][j]+matrix2[i][j] for j in range(len(matrix1[0]))]for i in range(len(matrix1))]
    
    # result = [[0 for i in range(len(matrix1))] for j in range(len(matrix1))]
    # for i in range(len(matrix1)):
    #     for j in range(len(matrix1)):
    #         result[i][j] = matrix1[i][j] + matrix2[i][j]
    # return result

    

rowA = int(input("Enter the row A: "))
colA = int(input("Enter the column A: "))

print("Enter the elements of the first matrix: ")
matrix1 = [[int(input(f"Enter the element A[{i}][{j}]:")) for i in range(colA)] for j in range(rowA)]

rowB = int(input("Enter the row B: "))
colB = int(input("Enter the column B: "))

print("Enter the elements of the second matrix: ")
matrix2 = [[int(input(f"Enter the element B[{i}][{j}]:")) for i in range(colB)] for j in range(rowB)]

result = add_matrix(matrix1, matrix2)


if result is not None:
    print("The sum of the two matrices is: ")
    for row in result:
     print(row)