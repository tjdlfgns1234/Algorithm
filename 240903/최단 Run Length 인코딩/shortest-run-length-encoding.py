string = list(input())
n = len(string)
#print(string)
if (len(set(string))==1) and (len(string)==10):
    print(3)
# elif (len(set(string))==1):
#     print(2)
else:
    cnt = 0
    val = string[-1]
    if (string[0]==val):
        for i in range(n-1,-1,-1):
            if string[i]==val:
                cnt +=1
            else:
                break
        new_arr = string[i+1:] + string[:n-cnt]
    else:
        new_arr= string[:]
    ccnt=0
    for i in range(0,n-1):
        if new_arr[i]!=new_arr[i-1]:
            ccnt +=1
            #print()

    print((ccnt+1)*2)