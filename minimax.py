# Program to find next optimal move checking the condition of board in a Tic Tac toe game using minimax algorithm
# We use if __name__ == '__main__' to run the functions in an order
# we use depth to find the more optimal solution from two given solutions

def valboard(arr):
    for i in range(3):
        if(arr[i][0] == arr[i][1] ==arr[i][2]):
            if(arr[i][0] == 'x'):
                return 10
            if(arr[i][0] == 'o'):
                return -10
    for j in range(3):
        if(arr[0][j] == arr[1][j] == arr[2][j]):
            if(arr[0][j] == 'x'):
                return 10
            if(arr[0][j] == 'o'):
                return -10
    if(arr[0][0] == arr[1][1] == arr[2][2]):
        if(arr[0][0] == 'x'):
            return 10
        if(arr[0][0] == 'o'):
            return -10
    return 0

def noleft(arr):
    for i in range(3):
        for j in range(3):
            if(arr[i][j] == '_'):
                return False
    return True
                

def minimax(arr,depth,ismax):
    score = valboard(arr)
    if(score != 0):
        if(score>0):
            return score - depth
        if(score<0):
            return score + depth
    if(noleft(arr)):
        return 0
    if(ismax):
        best = -1000
        for i in range(3):
            for j in range(3):
                if(arr[i][j]=='_'):
                    arr[i][j]='x'
                    tem = minimax(arr,depth+1,not ismax)
                    best = max(best,tem)
                    arr[i][j]='_'
        return best
    else:
        best = 1000
        for i in range(3):
            for j in range(3):
                if(arr[i][j]=='_'):
                    arr[i][j] = 'o'
                    tem = minimax(arr,depth+1,not ismax)
                    best = min(best,tem)
                    arr[i][j]='_'
        return best

xin = 1
yin = 1
def bestmove(arr):
    best = -1000
    global xin
    global yin
    for i in range(3):
        for j in range(3):
            if(arr[i][j] == '_'):
                arr[i][j] = 'x'
                bestval = minimax(arr,0,False)
                arr[i][j] = '_'
                if(bestval > best):
                    xin = i
                    yin = j
                    best = bestval
    return xin,yin

def main():
    t = int(input())
    while(t>0):
        arr = []
        for i in range(3):
                mat = list(map(str,input().split()))
                arr.append(mat)
        bestmove(arr)
        print(xin, end =' ')
        print(yin)
        t = t - 1
        
if(__name__ == '__main__'):
    main()



    
    
        