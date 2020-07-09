# Program to find next optimal move checking the condition of board in a Tic Tac toe game using minimax algorithm

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
                return 10 - depth
            if(arr[0][j] == 'o'):
                return -10
    if(arr[0][0] == arr[1][1] == arr[2][2]):
        if(arr[0][0] == 'x'):
            return 10 - depth
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
    if(score == 10):
        return 10 - depth
    if(score == -10):
        return -10+depth
    if(noleft(arr)):
        return 0
    if(ismax):
        for i in range(3):
            for j in range(3):
                if(arr[i][j]=='_'):
                    best = -1000
                    arr[i][j] = 'x'
                    best = max(best,minimax(arr,depth+1,!ismax))
                    arr[i][j]='_'
        return best
    else:
        for i in range(3):
            for j in range(3):
                if(arr[i][j]=='_'):
                    best = 1000
                    arr[i][j] = 'o'
                    best = min(best,minimax(arr,depth+1,!ismax))
                    arr[i][j]='_'
        return best


def bestmove(arr):
    best = -1000
    xin = -1
    yin = -1
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
    print(xin + ' ' + yin)
