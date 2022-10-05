def real_path_finder(map1,i,j):
    pathL=False
    pathR=False
    pathU=False
    pathD=False
    if(i<0 or j<0 or i>=len(map1) or j>=len(map1[0])):
        return False

    elif('G' in map1[i][j]):
        return True
    
    else:
        if('L' in map1[i][j]):
            pathL = real_path_finder(map1,i,j-1)
        if('R' in map1[i][j]):
            pathR = real_path_finder(map1,i,j+1)
        if('U' in map1[i][j]):
            pathU = real_path_finder(map1,i-1,j)
        if('D' in map1[i][j]):
            pathD = real_path_finder(map1,i+1,j)
    return pathL or pathR or pathU or pathD
        


def path_finder(map1):
    return real_path_finder(map1,2,0)

    
    
map1 = [['L','R','G'],
        ['U','UR','R'],
        ['R','U','D']]

map2 = [['L','R','G'],
        ['U','R','R'],
        ['UR','R','RD']]


if(path_finder(map1)==True):
    print("Path exists")
else:
    print("No such path existed")

if(path_finder(map2)==True):
    print("Path exists")
else:
    print("No such path existed")
