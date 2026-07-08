class Solution {
    /**
     * @param {character[][]} board
     * @return {boolean}
     */
    findSubgrid(x,y) {
        if(x<=2) {
            if(y<=2) return 0;
            else if(y<=5)return 1;
            return 2;
        } else if(x<=5) {
            if(y<=2) return 3;
            else if(y<=5)return 4;
            return 5;
        }
        if(y<=2) return 6;
        else if(y<=5)return 7;
        return 8;
    }
    isValidSudoku(board) {
        const subgrid=Array.from({length: 9}, () => new Set() );
        const row=Array.from({length: 9}, () => new Set() );
        const col=Array.from({length: 9}, () => new Set() );
        for(let i=0;i<9;i++) {
            for(let j=0;j<9;j++) {
                if(board[i][j]==='.') continue;
                let x=this.findSubgrid(i,j);
                // console.log(i+" "+j+" "+x+"\n");
                if(subgrid[x].has(board[i][j]) ||
                    row[i].has(board[i][j]) ||
                    col[j].has(board[i][j])) return false;
                
                subgrid[x].add(board[i][j]);
                row[i].add(board[i][j]);
                col[j].add(board[i][j]);
            }
        }
        return true;
    }
}
