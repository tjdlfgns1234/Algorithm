n, m = tuple(map(int, input().split()))

arr = [
    list(map(int, input().split()))
    for i in range(n)
]

max_val = 0

def get_val(row, col): #여기서 어떤 직사각형인지 정해줌
    global n
    global m
    global arr
    s_max_val = 0
    max_n, max_m = 1, -1

    for i in range(row, n):     
        for j in range(col, m): 
            val, d2_n, d2_m = get_val2(row, i, col, j) 

            if val>= s_max_val: 
                max_n, max_m = d2_n, d2_m

                s_max_val = val
    return s_max_val, max_n, max_m

def get_val2(row, row_e, col, col_e): #여기서 직사각형 합계를 계산
    val = 0
    global arr
    for i in range(row, row_e+1):
        for j in range(col, col_e+1):
            val += arr[i][j]

            if arr[i][j] <= 0: #음수 검사
                return 0, 1, -1
    d2_n, d2_m = row_e+1 - row , col_e+1 - col

    return val, d2_n, d2_m


max_garo, max_sero = 1,-1
for row in range(n):  #기준점 잡기
    for col in range(m):
        val, max_n2, max_m2 = get_val(row, col)
        
        if val >= max_val:
            max_val = val
            if max_n2*max_m2 >= max_garo*max_sero:
                max_garo, max_sero = max_n2,max_m2
print(max_garo*max_sero)