# 📚 TUGAS STRUKTUR DATA - APLIKASI STACK

> **Implementasi 4 Aplikasi Stack dalam Bahasa C**

---

## 📁 **Struktur File**

```
📦 Tugas_Stack/
├── 📄 boolean.h          # Header file tipe boolean
├── 📄 stack.h            # Header file ADT Stack
├── 📄 stack.c            # Implementasi ADT Stack
├── 📄 mstack.c           # Program driver utama
├── 📄 README.md          # Dokumentasi ini
└── 📄 notasi_algoritmik.md  # Notasi algoritmik lengkap
```

---

## ⚙️ **Cara Kompilasi & Menjalankan**

### **Kompilasi:**
```bash
gcc -o mstack mstack.c stack.c
```

### **Menjalankan:**
```bash
./mstack
```

### **Sistem Operasi:**
- ✅ **Linux/Unix**
- ✅ **Windows** (dengan MinGW/MSYS2)
- ✅ **macOS**

---

## 🚀 **Fitur Program**

### **Menu Interaktif:**
```
=== MENU TESTING APLIKASI STACK ===
1. Test Parentheses Checker
2. Test Text Editor (Undo-Redo)
3. Test Konversi Infix ke Postfix
4. Test Evaluasi Postfix Expression
5. Test Semua (Demo Lengkap)
0. Keluar
```

### **1. 🔗 Parentheses Checker**
- **Fungsi:** Mengecek keseimbangan kurung `()`, `{}`, `[]`
- **Input:** String dengan tanda kurung
- **Output:** `VALID` atau `TIDAK VALID`

**Test Cases:**
```
✅ {[(A+B) * (C+D)] - (7*D)}     → VALID
❌ {[(A+B) * (C+D)] - (7*D)      → TIDAK VALID (kurung { tidak tertutup)
❌ {[(A+B) * (C+D]) - (7*D)}     → TIDAK VALID (kurung ( ditutup dengan ])
❌ {[(A+B) * (C+D)] - (7*D))}    → TIDAK VALID (kurung { ditutup dengan ))
```

### **2. ↩️ Text Editor (Undo-Redo)**
- **Fitur:** Simulasi text editor dengan stack-based undo/redo
- **Commands:** 
  - Ketik perintah → disimpan di undo stack
  - `undo` → batalkan perintah terakhir
  - `redo` → kembalikan perintah yang dibatalkan
  - `exit` → keluar dari editor

**Contoh Penggunaan:**
```
Editor> tulis hello
Perintah dijalankan: tulis hello

Editor> edit file
Perintah dijalankan: edit file

Editor> undo
Undo: edit file

Editor> redo  
Redo: edit file
```

### **3. 🔄 Infix to Postfix**
- **Fungsi:** Konversi ekspresi infix ke postfix
- **Algoritma:** Shunting Yard dengan stack untuk operator
- **Precedence:** `*`, `/` > `+`, `-`

**Test Cases:**
```
3 + ( 4 * 3 ) / 4    →    3 4 3 * 4 / +
3 * ( 4 + 5 ) / 2    →    3 4 5 + * 2 /  
3 + ( 4 * 5 ) - 2    →    3 4 5 * + 2 -
```

### **4. 🧮 Postfix Evaluator**
- **Fungsi:** Mengevaluasi ekspresi postfix
- **Algoritma:** Stack-based evaluation
- **Output:** Hasil numerik (double)

**Test Cases:**
```
3 4 3 * 4 / +        →    6.00
3 4 5 + * 2 /        →    13.50
9 3 4 * 8 + 4 / -    →    4.00
```

---

## 🏗️ **Struktur Data**

### **CharStack** (untuk kurung & operator)
```c
typedef struct {
    char *data;      // Array karakter
    int top;         // Index top element
    int capacity;    // Kapasitas maksimum
} CharStack;
```

### **StringStack** (untuk undo-redo)
```c
typedef struct {
    char **data;     // Array pointer string
    int top;         // Index top element  
    int capacity;    // Kapasitas maksimum
} StringStack;
```

### **DoubleStack** (untuk evaluasi)
```c
typedef struct {
    double *data;    // Array bilangan real
    int top;         // Index top element
    int capacity;    // Kapasitas maksimum
} DoubleStack;
```

---

## 📊 **Kompleksitas Algoritma**

| **Aplikasi** | **Time Complexity** | **Space Complexity** | **Deskripsi** |
|--------------|--------------------|--------------------|---------------|
| Parentheses Checker | O(n) | O(n) | n = panjang string |
| Infix to Postfix | O(n) | O(n) | n = jumlah token |
| Postfix Evaluator | O(m) | O(m) | m = jumlah token |
| Undo-Redo | O(1) | O(k) | k = jumlah perintah |

---

## 🎯 **Algoritma Utama**

### **Parentheses Checker:**
1. Push kurung buka `(`, `{`, `[` ke stack
2. Untuk kurung tutup, pop dan bandingkan dengan pasangannya
3. Stack harus kosong di akhir untuk valid

### **Infix to Postfix:**
1. Operand → langsung ke output
2. Operator → cek precedence, pop yang prioritas ≥, push operator baru
3. `(` → push ke stack
4. `)` → pop sampai ketemu `(`

### **Postfix Evaluator:**
1. Operand → push ke stack
2. Operator → pop 2 operand, hitung hasil, push kembali
3. Hasil akhir = elemen terakhir di stack

### **Undo-Redo:**
1. Perintah baru → push ke undo stack, clear redo stack  
2. Undo → pop dari undo, push ke redo
3. Redo → pop dari redo, push ke undo

---

## 🧪 **Testing & Validasi**

### **Unit Testing:**
- ✅ Semua test case dari soal diimplementasi
- ✅ Edge cases dihandle (stack kosong, pembagian nol)
- ✅ Memory management yang aman
- ✅ Input validation

### **Integration Testing:**
- ✅ Menu interaktif bekerja dengan baik
- ✅ Semua modul terintegrasi dengan benar
- ✅ Demo lengkap menjalankan semua aplikasi

---

## 🔧 **Fitur Tambahan**

### **Memory Management:**
- Dynamic memory allocation untuk fleksibilitas
- Proper cleanup dengan `destroy` functions
- No memory leaks

### **Error Handling:**
- Stack overflow/underflow protection
- Input validation
- Graceful error messages

### **User Experience:**
- Menu interaktif yang user-friendly
- Output informatif dengan step-by-step process
- Custom input support untuk testing

---

## 📝 **Cara Penggunaan**

### **Quick Start:**
```bash
# 1. Clone/download files
# 2. Compile
gcc -o mstack mstack.c stack.c

# 3. Run
./mstack

# 4. Pilih menu yang diinginkan
# 5. Follow instructions
```

### **Demo Lengkap:**
- Pilih **Menu 5** untuk menjalankan semua test case sekaligus
- Program akan otomatis menjalankan semua 4 aplikasi dengan test data

### **Custom Testing:**
- **Menu 1-4** menyediakan opsi input custom
- Masukkan data sendiri untuk testing tambahan

---

## 🐛 **Troubleshooting**

### **Compilation Errors:**
```bash
# Jika ada error tentang boolean
# Pastikan boolean.h ada di directory yang sama

# Jika ada warning tentang gets()
# Program menggunakan fgets() yang lebih aman
```

### **Runtime Issues:**
```bash
# Jika program crash
# Check input format (spasi antara operator dan operand)

# Jika hasil evaluasi salah  
# Pastikan ekspresi postfix valid
```

---

## 📚 **Referensi**

### **Algoritma:**
- Shunting Yard Algorithm (Dijkstra)
- Stack-based Expression Evaluation
- Parentheses Matching Algorithm

### **Struktur Data:**
- Abstract Data Type (ADT) Stack
- Dynamic Array Implementation
- LIFO (Last In, First Out) Principle

---

## 🎓 **Learning Outcomes**

Setelah mengerjakan tugas ini, mahasiswa diharapkan dapat:

1. ✅ **Memahami konsep ADT Stack** dan implementasinya
2. ✅ **Mengaplikasikan stack** untuk berbagai problem solving
3. ✅ **Menganalisis kompleksitas** algoritma berbasis stack
4. ✅ **Mengimplementasikan** program modular dalam bahasa C
5. ✅ **Menerapkan** best practices dalam programming

---

**⭐ Happy Coding! ⭐**