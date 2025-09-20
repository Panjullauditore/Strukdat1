#ifndef STACK_H
#define STACK_H

/* Program   : stack.h */
/* Deskripsi : file HEADER modul stack untuk aplikasi */
/* Kelompok  : */
/* Tanggal   : */
/***********************************/

#include "boolean.h"

/* DEFINISI TIPE DATA STACK */
/* Stack untuk karakter (untuk parentheses checker dan infix-postfix) */
typedef struct {
    char *data;
    int top;
    int capacity;
} CharStack;

/* Stack untuk string (untuk undo-redo) */
typedef struct {
    char **data;
    int top;
    int capacity;
} StringStack;

/* Stack untuk double (untuk evaluasi postfix) */
typedef struct {
    double *data;
    int top;
    int capacity;
} DoubleStack;

/* ============= KONSTRUKTOR STACK ============= */
/* procedure createCharStack(output stack: CharStack, input capacity: integer)
   {I.S.: - }
   {F.S.: Stack karakter terdefinisi dengan kapasitas tertentu}
   {Proses: membuat stack kosong untuk menyimpan karakter} */
CharStack* createCharStack(int capacity);

/* procedure createStringStack(output stack: StringStack, input capacity: integer)
   {I.S.: - }
   {F.S.: Stack string terdefinisi dengan kapasitas tertentu}
   {Proses: membuat stack kosong untuk menyimpan string} */
StringStack* createStringStack(int capacity);

/* procedure createDoubleStack(output stack: DoubleStack, input capacity: integer)
   {I.S.: - }
   {F.S.: Stack double terdefinisi dengan kapasitas tertentu}
   {Proses: membuat stack kosong untuk menyimpan bilangan real} */
DoubleStack* createDoubleStack(int capacity);

/* ============= PREDIKAT STACK ============= */
/* function isCharStackEmpty(stack: CharStack) -> boolean
   {mengembalikan True jika stack karakter kosong} */
boolean isCharStackEmpty(CharStack *stack);

/* function isCharStackFull(stack: CharStack) -> boolean
   {mengembalikan True jika stack karakter penuh} */
boolean isCharStackFull(CharStack *stack);

/* function isStringStackEmpty(stack: StringStack) -> boolean
   {mengembalikan True jika stack string kosong} */
boolean isStringStackEmpty(StringStack *stack);

/* function isDoubleStackEmpty(stack: DoubleStack) -> boolean
   {mengembalikan True jika stack double kosong} */
boolean isDoubleStackEmpty(DoubleStack *stack);

/* ============= OPERASI STACK KARAKTER ============= */
/* procedure pushChar(input/output stack: CharStack, input item: char)
   {I.S.: stack terdefinisi, item terdefinisi}
   {F.S.: item ditambahkan ke top stack jika tidak penuh}
   {Proses: menambahkan karakter ke stack} */
void pushChar(CharStack *stack, char item);

/* function popChar(input/output stack: CharStack) -> char
   {mengembalikan dan menghapus elemen teratas dari stack}
   {mengembalikan '\0' jika stack kosong} */
char popChar(CharStack *stack);

/* function peekChar(stack: CharStack) -> char
   {mengembalikan elemen teratas tanpa menghapusnya}
   {mengembalikan '\0' jika stack kosong} */
char peekChar(CharStack *stack);

/* ============= OPERASI STACK STRING ============= */
/* procedure pushString(input/output stack: StringStack, input item: string)
   {I.S.: stack terdefinisi, item terdefinisi}
   {F.S.: item ditambahkan ke top stack jika tidak penuh}
   {Proses: menambahkan string ke stack} */
void pushString(StringStack *stack, const char *item);

/* function popString(input/output stack: StringStack) -> string
   {mengembalikan dan menghapus elemen teratas dari stack}
   {mengembalikan NULL jika stack kosong} */
char* popString(StringStack *stack);

/* procedure clearStringStack(input/output stack: StringStack)
   {I.S.: stack terdefinisi}
   {F.S.: stack menjadi kosong}
   {Proses: menghapus semua elemen dari stack string} */
void clearStringStack(StringStack *stack);

/* ============= OPERASI STACK DOUBLE ============= */
/* procedure pushDouble(input/output stack: DoubleStack, input item: double)
   {I.S.: stack terdefinisi, item terdefinisi}
   {F.S.: item ditambahkan ke top stack jika tidak penuh}
   {Proses: menambahkan bilangan real ke stack} */
void pushDouble(DoubleStack *stack, double item);

/* function popDouble(input/output stack: DoubleStack) -> double
   {mengembalikan dan menghapus elemen teratas dari stack}
   {mengembalikan 0.0 jika stack kosong} */
double popDouble(DoubleStack *stack);

/* ============= APLIKASI STACK ============= */
/* function isValidKurung(kata: string) -> boolean
   {mengembalikan True jika pasangan kurung dalam kata valid}
   {menggunakan stack untuk mengecek keseimbangan kurung} */
boolean isValidKurung(const char *kata);

/* procedure textEditor()
   {I.S.: - }
   {F.S.: - }
   {Proses: menjalankan simulasi text editor dengan fitur undo-redo} */
void textEditor();

/* function infixToPostfix(infix: string) -> string
   {mengkonversi ekspresi infix menjadi postfix menggunakan stack}
   {mengembalikan string hasil konversi} */
char* infixToPostfix(const char *infix);

/* function evaluatePostfix(postfix: string) -> double
   {mengevaluasi ekspresi postfix dan mengembalikan hasilnya}
   {menggunakan stack untuk menyimpan operand} */
double evaluatePostfix(const char *postfix);

/* function getPrecedence(op: char) -> integer
   {mengembalikan prioritas operator untuk konversi infix-postfix} */
int getPrecedence(char op);

/* ============= UTILITAS ============= */
/* procedure destroyCharStack(input/output stack: CharStack)
   {I.S.: stack terdefinisi}
   {F.S.: memori stack dibebaskan}
   {Proses: menghapus stack dan membebaskan memori} */
void destroyCharStack(CharStack *stack);

/* procedure destroyStringStack(input/output stack: StringStack)
   {I.S.: stack terdefinisi}
   {F.S.: memori stack dibebaskan}
   {Proses: menghapus stack dan membebaskan memori} */
void destroyStringStack(StringStack *stack);

/* procedure destroyDoubleStack(input/output stack: DoubleStack)
   {I.S.: stack terdefinisi}
   {F.S.: memori stack dibebaskan}
   {Proses: menghapus stack dan membebaskan memori} */
void destroyDoubleStack(DoubleStack *stack);

#endif