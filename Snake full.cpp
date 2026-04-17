#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

// ================== HÀM PHỤ ==================
void gotoxy(int x, int y){
    COORD c;
    c.X = x;
    c.Y = y + 2; // tránh đè dòng lệnh
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void AnConTro(){
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &cursorInfo);
}

// ================== POINT ==================
struct Point{
    int x,y;
};

// ================== CON RẮN ==================
class CONRAN{
public:
    Point A[200];
    int DoDai;

    CONRAN(){
        DoDai = 3;
        A[0]={10,10};
        A[1]={9,10};
        A[2]={8,10};
    }

    void Ve(){
        for(int i=0;i<DoDai;i++){
            gotoxy(A[i].x,A[i].y);
            cout<<"O";
        }
    }

    void XoaDuoi(Point duoi){
        gotoxy(duoi.x, duoi.y);
        cout<<" ";
    }

    void DiChuyen(int Huong){
        Point duoi = A[DoDai-1];

        for(int i=DoDai-1;i>0;i--)
            A[i]=A[i-1];

        if(Huong==0) A[0].x++;
        if(Huong==1) A[0].y++;
        if(Huong==2) A[0].x--;
        if(Huong==3) A[0].y--;

        XoaDuoi(duoi);
    }

    void TangDoDai(){
        A[DoDai] = A[DoDai-1];
        DoDai++;
    }

    // 💀 đâm thân
    bool TuDamThan(){
        for(int i=1;i<DoDai;i++){
            if(A[0].x==A[i].x && A[0].y==A[i].y)
                return true;
        }
        return false;
    }
};

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

// ================== MỒI ==================
Point moi;

void TaoMoi(){
    moi.x = rand()%(width-2) + 1;
    moi.y = rand()%(height-2) + 1;
}

void VeMoi(){
    gotoxy(moi.x,moi.y);
    cout<<"*";
}

// ================== MAIN ==================
int main(){
    srand(time(0));
    AnConTro();

    while(true){ // restart loop
        system("cls");

        CONRAN r;
        int Huong = 0;
        char t;
        int score = 0;

        VeKhung();
        TaoMoi();

        bool gameOver = false;

        while(!gameOver){
            if(kbhit()){
                t=getch();

                // 🚫 không quay đầu
                if(t=='a' && Huong!=0) Huong=2;
                if(t=='d' && Huong!=2) Huong=0;
                if(t=='w' && Huong!=1) Huong=3;
                if(t=='s' && Huong!=3) Huong=1;

                if(t=='q') return 0;
            }

            r.DiChuyen(Huong);

            // 💀 đâm tường
            if(r.A[0].x==0 || r.A[0].x==width ||
               r.A[0].y==0 || r.A[0].y==height){
                gameOver = true;
            }

            // 🧠 đâm thân
            if(r.TuDamThan()){
                gameOver = true;
            }

            // 🍎 ăn mồi
            if(r.A[0].x == moi.x && r.A[0].y == moi.y){
                r.TangDoDai();
                score += 10;
                TaoMoi();
            }

            r.Ve();
            VeMoi();

            // 🏆 hiển thị score
            gotoxy(0, height+1);
            cout<<"Score: "<<score<<"   ";

            Sleep(100);
        }

        // 💀 GAME OVER
        gotoxy(width/2 - 5, height/2);
        cout<<"GAME OVER";

        gotoxy(width/2 - 10, height/2 + 1);
        cout<<"R: Replay | Q: Quit";

        // chờ input
        while(true){
            if(kbhit()){
                t=getch();
                if(t=='r') break;
                if(t=='q') return 0;
            }
        }
    }
}