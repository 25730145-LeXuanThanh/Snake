// ================== MỒI ==================
// Bài Tập Nhóm game Snake
// Ma so sinh vien: Duong Ngoc Thanh Khoi
// Ho va ten sinh vien: 25730117
// Ngay sinh: 27/05
// Lop: CN1.K2025.2.CNTT

Point moi;

void TaoMoi(){
    moi.x = rand()%(width-2) + 1;
    moi.y = rand()%(height-2) + 1;
}

void VeMoi(){
    gotoxy(moi.x,moi.y);
    cout<<"*";
}
int main{

            // 🍎 ăn mồi
            if(r.A[0].x == moi.x && r.A[0].y == moi.y){
                r.TangDoDai();
                score += 10;
                TaoMoi();
            }

            r.Ve();
            VeMoi();
}
