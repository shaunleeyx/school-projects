def readfile(wordfile):
    wordfile = wordfile
    file = open(wordfile, "r")
    n = int((file.readline()))
    A = []
    for x in range(n):
        row = [int(x) for x in file.readline().strip().split(" ")]
        A.append(row)
    B = []
    for x in range(n):
        row = [int(x) for x in file.readline().strip().split(" ")]
        B.append(row)
    return A, B, n


def Join(A, B, C, D, N):
    result = [[0 for j in range(0, int(N))] for i in range(0, int(N))]
    for i in range(0, int(N/2)):
        for j in range(0, int(N/2)):
            result[i][j] = A[i][j]
            result[i][j + int(N/2)] = B[i][j]
            result[i + int(N/2)][j] = C[i][j]
            result[i + int(N/2)][j + int(N/2)] = D[i][j]
    return result


def divide(M, N):
    sMatrix1 = []
    sMatrix2 = []
    sMatrix3 = []
    sMatrix4 = []

    for row in range(int(N/2)):
        list = []
        for col in range(int(N/2)):
            list.append(M[row][col])
        sMatrix1.append(list)

    for row in range(int(N/2)):
        list = []
        for col in range(int(N/2), int(N)):
            list.append(M[row][col])
        sMatrix2.append(list)

    for row in range(int(N/2), int(N)):
        list = []
        for col in range(int(N/2)):
            list.append(M[row][col])
        sMatrix3.append(list)

    for row in range(int(N/2), int(N)):
        list = []
        for col in range(int(N/2), int(N)):
            list.append(M[row][col])
        sMatrix4.append(list)

    return sMatrix1, sMatrix2, sMatrix3, sMatrix4


def MM(A, B, N):
    print("N", N)
    if N <= 2:
        return Strassen(A, B)
    else:
        a11, a12, a21, a22 = divide(A, N)
        b11, b12, b21, b22 = divide(B, N)
        print("dada")
        printArray(a11)
        c11 = Add(MM(a11, b11, int(N/2)), MM(a12, b21, N/2), int(N))
        c12 = Add(MM(a11, b12, int(N/2)), MM(a12, b22, N/2), int(N))
        c21 = Add(MM(a21, b11, int(N/2)), MM(a22, b21, N/2), int(N))
        c22 = Add(MM(a21, b12, int(N/2)), MM(a22, b22, N/2), int(N))
    return(Join(c11, c12, c21, c22, N))


def Add(A, B, N):
    n = len(A)
    C = [[0 for j in range(0, n)] for i in range(0, n)]
    for i in range(0, n):
        for j in range(0, n):
            C[i][j] = A[i][j] + B[i][j]
    return C


def Strassen(A, B):
    i = 1  # because array starts at 0 and matrices start at 1
    S1 = B[1 - i][2 - i] - B[2 - i][2 - i]
    S2 = A[1 - i][1 - i] + A[1 - i][2 - i]
    S3 = A[2 - i][1 - i] + A[2 - i][2 - i]
    S4 = B[2 - i][1 - i] - B[1 - i][1 - i]
    S5 = A[1 - i][1 - i]+A[2 - i][2 - i]
    S6 = B[1 - i][1 - i]+B[2 - i][2 - i]
    S7 = A[1 - i][2 - i]-A[2 - i][2 - i]
    S8 = B[2 - i][1 - i]+B[2 - i][2 - i]
    S9 = A[1 - i][1 - i]-A[2 - i][1 - i]
    S10 = B[1 - i][1 - i]+B[1 - i][2 - i]
    print("S1:", S1)
    print("S2:", S2)
    print("S3:", S3)
    print("S4:", S4)
    print("S5:", S5)
    print("S6:", S6)
    print("S7:", S7)
    print("S8:", S8)
    print("S9:", S9)
    print("S10:", S10)
    P1 = A[1 - i][1 - i] * S1
    P2 = S2 * B[2 - i][2 - i]
    P3 = S3 * B[1 - i][1 - i]
    P4 = A[2 - i][2 - i] * S4
    P5 = S5 * S6
    P6 = S7 * S8
    P7 = S9 * S10
    C11 = P5 + P4 - P2 + P6
    C12 = P1+P2
    C21 = P3 + P4
    C22 = P5 + P1 - P3 - P7
    C = [[C11, C12], [C21, C22]]
    return C


def printArray(M):
    for item in M:
        print(item)


def writeFile(string, M, N):
    f = open(string, "w")
    nstring = str(N) + "\n"
    f.write(nstring)
    for item in M:
        for x in item:
            f.writelines(str(x) + " ")
        f.write("\n")
    f.close()


def main():
    A, B, N = readfile("input.txt")
    C = MM(A, B, N)
    writeFile("output.txt", C, N)


if __name__ == '__main__':
    main()
