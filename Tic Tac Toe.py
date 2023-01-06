def row_position(board):
    for i in board:
        row="".join(i)
        if row=="" or len(row)>3 :
            continue
        elif row.count("O")==3 or row.count("X")==3:
            return True
    return False
def coloum_position(board):
    for i in list(zip(*board)):
        coloum="".join(i)
        if coloum=="" or len(coloum)>3 :
            continue
        elif coloum.count("O")==3 or coloum.count("X")==3:
            return True
    return False
def diagonal_position(l):
    R_L=[l[0][0],l[1][1],l[2][2]]
    L_R=[l[0][2],l[1][1],l[2][0]]
    R_L,L_R="".join(R_L),"".join(L_R)
    if R_L!="" and R_L.count("O")==3 or R_L.count("X")==3:
        return True
    elif L_R!="" and L_R.count("O")==3 or L_R.count("X")==3:
        return True
    return False
def take(board):
    while True:
        try:
            row,coloum=[int(x) for x in input("Enter your location: ").split()]
        except:
            print("Try again")
        else:
            if row>2 or coloum>2 or row<0 or coloum<0:
                print("please Enter correct location")
            elif board[row][coloum]=="":
                return row,coloum
            else:
                print("Position Already Taken\nTry Again")
def show(board):
    for i in board:
        for j in i:
            if j=="":
                j="_"
            print(j,end="\t")
        print("\n")
board=[
    ["","",""],
    ["","",""],
    ["","",""],
]
player_1,player_2="O","X"
show(board)
for i in range(9):
    r,c=take(board)
    if i%2==0:
        print(player_1,"Turn\n")
        board[r][c]=player_2
    else:
        print(player_2,"Turn\n")
        board[r][c]=player_1
    if i>3:
        condition=[row_position(board),coloum_position(board),diagonal_position(board)]
        if any(condition):
            if i%2==0:
                print("X won")
            else:
                print("O won")
            show(board)
            break
    show(board)
else:
    print("DRAW")
