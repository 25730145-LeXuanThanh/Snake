// HỌ VÀ TÊN : TRẦN HUỲNH UYỂN NHI
// MSSV : 25730129
// LỚP : SS004.F21.CN1.CNTT
// PROJECT : Snake Game

// ================== KHUNG ==================
int width = 50, height = 20;

void VeKhung(){
    for(int i=0;i<=width;i++){
        gotoxy(i,0); cout<<"#";
        gotoxy(i,height); cout<<"#";
    }
    for(int i=0;i<=height;i++){
        gotoxy(0,i); cout<<"#";
        gotoxy(width,i); cout<<"#";
    }
}
int main{
    // 💀 đâm tường
            if(r.A[0].x==0 || r.A[0].x==width ||
               r.A[0].y==0 || r.A[0].y==height){
                gameOver = true;
            }

            // 🧠 đâm thân
            if(r.TuDamThan()){
                gameOver = true;
            }
}