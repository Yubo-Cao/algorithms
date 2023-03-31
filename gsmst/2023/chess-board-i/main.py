board_string = [
    list(input())
    for _ in range(8)
] 

def traverse_board(chess_board):
    king_pos = None
    for i in range(8):
        for j in range(8):
            if chess_board[i][j] == 'x':
                king_pos = (i, j)
                break
        if king_pos:
            break

    # Check for knight
    knight_moves = [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]
    for move in knight_moves:
        i, j = king_pos[0] + move[0], king_pos[1] + move[1]
        if 0 <= i < 8 and 0 <= j < 8 and chess_board[i][j] == 'k':
            return True
        
    for i, j in zip(range(king_pos[0] - 1, -1, -1), range(king_pos[1] + 1, 8)):
        if chess_board[i][j] == 'b' or chess_board[i][j] == 'q':
            return True

    # Check for bishop or queen
    for i, j in zip(range(king_pos[0] - 1, -1, -1), range(king_pos[1] - 1, -1, -1)):
        if chess_board[i][j] == 'b' or chess_board[i][j] == 'q':
            return True
        elif chess_board[i][j] != '.':
            pass 
    
     # Check for rook or queen
    for i in range(king_pos[0] - 1, -1, -1):
        if chess_board[i][king_pos[1]] == 'r' or chess_board[i][king_pos[1]] == 'q':
            return True
        elif chess_board[i][king_pos[1]] != '.':
            break

    for i in range(king_pos[0] + 1, 8):
        if chess_board[i][king_pos[1]] == 'r' or chess_board[i][king_pos[1]] == 'q':
            return True
        elif chess_board[i][king_pos[1]] != '.':
            break

    for j in range(king_pos[1] - 1, -1, -1):
        if chess_board[king_pos[0]][j] == 'r' or chess_board[king_pos[0]][j] == 'q':
            return True
        elif chess_board[king_pos[0]][j] != '.':
            break

    for j in range(king_pos[1] + 1, 8):
        if chess_board[king_pos[0]][j] == 'r' or chess_board[king_pos[0]][j] == 'q':
            return True
        elif chess_board[king_pos[0]][j] != '.':
            break

print(traverse_board(board_string) and 'TRUE' or 'FALSE')