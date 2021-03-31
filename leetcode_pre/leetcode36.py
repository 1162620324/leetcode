


class Solution:
    def isValidSudoku(self, board):
        """
        :param board: : List[List[str]]
        :return: bool
        """


        columDictlist = []
        for i in range(9):
            columDictlist.append({})
        rowDictlist = []
        for i in range(9):
            rowDictlist.append({})
        tangleDictlist = []
        for i in range(3):
            temp = []
            for i in range(3):
                temp.append({})
            tangleDictlist.append(temp)
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j] == ".":
                    continue
                print(board[i][j])
                if board[i][j] not in columDictlist[i].keys():
                    columDictlist[i].update({board[i][j]: 1})
                else:
                    return False

                if board[i][j] not in rowDictlist[j].keys():
                    rowDictlist[j].update({board[i][j]: 1})
                else:
                    return False

                if board[i][j] not in tangleDictlist[i//3][j//3].keys():
                    tangleDictlist[i // 3][j // 3].update({board[i][j]: 1})
                else:
                    return False

        return True




if __name__ == "__main__":
    s = Solution()
    board = [["5", "3", ".", ".", "7", ".", ".", ".", "."],
             ["6", ".", ".", "1", "9", "5", ".", ".", "."],
             [".", "9", "8", ".", ".", ".", ".", "6", "."],
             ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
             ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
             ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
             [".", "6", ".", ".", ".", ".", "2", "8", "."],
             [".", ".", ".", "4", "1", "9", ".", ".", "5"],
             [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
    s.isValidSudoku(board)
