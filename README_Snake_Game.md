# 🐍 Snake Game (C++ Console)

![C++](https://img.shields.io/badge/Language-C++-blue)
![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

---

## 📌 Giới thiệu
Đây là game **Snake (Rắn săn mồi)** viết bằng **C++**, chạy trên **Command Prompt (CMD)**.  
Game sử dụng xử lý bàn phím real-time và hiển thị trực tiếp trên console.

---

## 👥 Thành viên nhóm

### 👑 Lê Xuân Thạnh - 25730145 (Trưởng nhóm)
- Xử lý tọa độ
- Điều khiển di chuyển (W/A/S/D)
- Hiển thị & cập nhật điểm số
- Xử lý logic:
  - Rắn ăn thân
  - Đâm tường
  - Game Over
  - Reset game

---

### 🧱 Trần Huỳnh Uyển Nhi - 25730129
- Vẽ khung game
- Xác định giới hạn biên

---

### 🍎 Dương Ngọc Thanh Khôi - 25730117
- Sinh mồi (*)
- Hiển thị mồi
- Xử lý ăn mồi

---

## 🎮 Gameplay

### 🎯 Điều khiển
| Phím | Chức năng |
|------|----------|
| W | Lên |
| S | Xuống |
| A | Trái |
| D | Phải |
| Q | Thoát |

⚠️ Không thể quay đầu trực tiếp.

---

### 📜 Luật chơi
- Rắn di chuyển liên tục
- Ăn mồi (*) → +10 điểm
- Game Over khi:
  - Đâm tường
  - Cắn chính mình

---

### 🔁 Sau khi thua
- `R` → chơi lại
- `Q` → thoát

---

## ⚙️ Cách chạy

### 🔹 Compile
```bash
g++ snake.cpp -o snake
```

### 🔹 Run
```bash
snake
```

---

## 🧠 Logic game

```
Loop:
1. Nhận input
2. Di chuyển rắn
3. Check va chạm
4. Check ăn mồi
5. Vẽ lại
6. Delay
```

---

## 📁 Cấu trúc

- `Point` → tọa độ
- `CONRAN` → xử lý rắn
- `VeKhung()` → vẽ khung
- `TaoMoi()` → sinh mồi
- `main()` → game loop

---

## 🚀 Hướng phát triển
- Tăng tốc theo điểm
- High score
- Chướng ngại vật
- Màu sắc console
- GUI (SDL/SFML)

---

## 📌 Ghi chú
- Dùng `windows.h`, `conio.h`
- Chỉ chạy trên Windows CMD

---

## 🎉 Demo (Console)
```
##################
#        *       #
#    OOO         #
#                #
##################
Score: 10
```

---

⭐ Project giúp luyện:
- Mảng & tọa độ
- Game loop
- OOP cơ bản
