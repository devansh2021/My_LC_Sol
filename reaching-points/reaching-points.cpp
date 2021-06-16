class Solution {
//     https://sites.math.rutgers.edu/~ajl213/CLRS/Ch31.pdf
    public:
      bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx >= sx && ty >= sy){
            if(tx > ty){
                if(sy == ty) return (tx - sx) % ty == 0;
                tx %= ty;
            }else{
                if(sx == tx) return (ty - sy) % tx == 0;
                ty %= tx;
            }
        }   
        
        return false;
    }
//     bool helper(int sx, int sy, int tx, int ty){
//         if(sx==tx&&sy==ty)
//             return 1;
//         if(tx<sx||ty<sy)
//             return 0;
//         return helper(sx, sy, tx-ty, ty)||helper(sx, sy, tx, ty-tx);
//     }
// public:
//     bool reachingPoints(int sx, int sy, int tx, int ty) {
//         return helper(sx, sy, tx, ty);
//     }
};
