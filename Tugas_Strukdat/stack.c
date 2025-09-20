/* Program   : stack.c */
/* Deskripsi : file BODY modul stack untuk aplikasi */
/* Kelompok  : */
/* Tanggal   : 20 September 2025 */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"
#include "boolean.h"

/* ============= KONSTRUKTOR STACK ============= */
CharStack *createCharStack(int capacity)
{
    /*kamus lokal*/
    CharStack *stack;

    /*algoritma*/
    stack = (CharStack *)malloc(sizeof(CharStack));
    stack->data = (char *)malloc(capacity * sizeof(char));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

StringStack *createStringStack(int capacity)
{
    /*kamus lokal*/
    StringStack *stack;

    /*algoritma*/
    stack = (StringStack *)malloc(sizeof(StringStack));
    stack->data = (char **)malloc(capacity * sizeof(char *));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

DoubleStack *createDoubleStack(int capacity)
{
    /*kamus lokal*/
    DoubleStack *stack;

    /*algoritma*/
    stack = (DoubleStack *)malloc(sizeof(DoubleStack));
    stack->data = (double *)malloc(capacity * sizeof(double));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

/* ============= PREDIKAT STACK ============= */
boolean isCharStackEmpty(CharStack *stack)
{
    /*kamus lokal*/
    /* tidak ada variabel lokal tambahan */

    /*algoritma*/
    return stack->top == -1;
}

boolean isCharStackFull(CharStack *stack)
{
    /*kamus lokal*/
    /* tidak ada variabel lokal tambahan */

    /*algoritma*/
    return stack->top == stack->capacity - 1;
}

boolean isStringStackEmpty(StringStack *stack)
{
    /*kamus lokal*/
    /* tidak ada variabel lokal tambahan */

    /*algoritma*/
    return stack->top == -1;
}

boolean isDoubleStackEmpty(DoubleStack *stack)
{
    /*kamus lokal*/
    /* tidak ada variabel lokal tambahan */

    /*algoritma*/
    return stack->top == -1;
}

/* ============= OPERASI STACK KARAKTER ============= */
void pushChar(CharStack *stack, char item)
{
    /*kamus lokal*/
    /* tidak ada variabel lokal tambahan */

    /*algoritma*/
    if (!isCharStackFull(stack))
    {
        stack->data[++stack->top] = item;
    }
}

char popChar(CharStack *stack)
{
    /*kamus lokal*/
    char result;

    /*algoritma*/
    if (!isCharStackEmpty(stack))
    {
        result = stack->data[stack->top--];
        return result;
    }
    return '\0';
}

char peekChar(CharStack *stack)
{
    /*kamus lokal*/
    /* tidak ada variabel lokal tambahan */

    /*algoritma*/
    if (!isCharStackEmpty(stack))
    {
        return stack->data[stack->top];
    }
    return '\0';
}

/* ============= OPERASI STACK STRING ============= */
void pushString(StringStack *stack, const char *item)
{
    /*kamus lokal*/
    int itemLength;

    /*algoritma*/
    if (stack->top < stack->capacity - 1)
    {
        itemLength = strlen(item);
        stack->data[++stack->top] = (char *)malloc((itemLength + 1) * sizeof(char));
        strcpy(stack->data[stack->top], item);
    }
}

char *popString(StringStack *stack)
{
    /*kamus lokal*/
    char *result;

    /*algoritma*/
    if (!isStringStackEmpty(stack))
    {
        result = stack->data[stack->top--];
        return result;
    }
    return NULL;
}

void clearStringStack(StringStack *stack)
{
    /*kamus lokal*/
    char *tempString;

    /*algoritma*/
    while (!isStringStackEmpty(stack))
    {
        tempString = popString(stack);
        free(tempString);
    }
}

/* ============= OPERASI STACK DOUBLE ============= */
void pushDouble(DoubleStack *stack, double item)
{
    /*kamus lokal*/
    /* tidak ada variabel lokal tambahan */

    /*algoritma*/
    if (stack->top < stack->capacity - 1)
    {
        stack->data[++stack->top] = item;
    }
}

double popDouble(DoubleStack *stack)
{
    /*kamus lokal*/
    double result;

    /*algoritma*/
    if (!isDoubleStackEmpty(stack))
    {
        result = stack->data[stack->top--];
        return result;
    }
    return 0.0;
}

/* ============= APLIKASI STACK ============= */

/* SOAL 1: PARENTHESES CHECKER */
boolean isValidKurung(const char *kata)
{
    /*kamus lokal*/
    int i;
    char ch;
    char top;
    CharStack *stack;
    boolean result;

    /*algoritma*/
    printf("\n=== PARENTHESES CHECKER ===\n");
    printf("Mengecek: %s\n", kata);

    stack = createCharStack(strlen(kata));

    for (i = 0; kata[i] != '\0'; i++)
    {
        ch = kata[i];

        // Jika ketemu kurung buka, push ke stack
        if (ch == '(' || ch == '{' || ch == '[')
        {
            pushChar(stack, ch);
            printf("Push '%c' ke stack\n", ch);
        }
        // Jika ketemu kurung tutup
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            // Kalau stack kosong, berarti ada kurung tutup tanpa pasangan
            if (isCharStackEmpty(stack))
            {
                printf("Error: Kurung tutup '%c' tanpa pasangan!\n", ch);
                destroyCharStack(stack);
                return false;
            }

            top = popChar(stack);
            printf("Pop '%c' dari stack, bandingkan dengan '%c'\n", top, ch);

            // Cek apakah pasangan kurung cocok
            if ((top == '(' && ch != ')') ||
                (top == '{' && ch != '}') ||
                (top == '[' && ch != ']'))
            {
                printf("Error: Kurung tidak cocok!\n");
                destroyCharStack(stack);
                return false;
            }
        }
        // Karakter lain diabaikan
    }

    // Stack harus kosong di akhir
    result = isCharStackEmpty(stack);
    if (result)
    {
        printf("Semua kurung valid dan seimbang!\n");
    }
    else
    {
        printf("Masih ada kurung yang tidak tertutup!\n");
    }

    destroyCharStack(stack);
    return result;
}

/* SOAL 2: UNDO-REDO TEXT EDITOR */
void textEditor()
{
    /*kamus lokal*/
    StringStack *undoStack;
    StringStack *redoStack;
    char input[256];
    char *command;

    /*algoritma*/
    printf("\n=== TEXT EDITOR DENGAN UNDO-REDO ===\n");
    printf("Perintah:\n");
    printf("1. Ketik perintah (contoh: 'tulis hello')\n");
    printf("2. 'undo' - batalkan perintah terakhir\n");
    printf("3. 'redo' - ulangi perintah yang dibatalkan\n");
    printf("4. 'exit' - keluar\n\n");

    undoStack = createStringStack(100);
    redoStack = createStringStack(100);

    while (1)
    {
        printf("Editor> ");
        fgets(input, sizeof(input), stdin);

        // Hapus newline dari input
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0)
        {
            break;
        }
        else if (strcmp(input, "undo") == 0)
        {
            if (!isStringStackEmpty(undoStack))
            {
                command = popString(undoStack);
                pushString(redoStack, command);
                printf("Undo: %s\n", command);
            }
            else
            {
                printf("Tidak ada yang bisa di-undo!\n");
            }
        }
        else if (strcmp(input, "redo") == 0)
        {
            if (!isStringStackEmpty(redoStack))
            {
                command = popString(redoStack);
                pushString(undoStack, command);
                printf("Redo: %s\n", command);
            }
            else
            {
                printf("Tidak ada yang bisa di-redo!\n");
            }
        }
        else
        {
            // Perintah baru
            pushString(undoStack, input);
            clearStringStack(redoStack); // Kosongkan redo stack
            printf("Perintah dijalankan: %s\n", input);
        }
    }

    // Bersihkan memori
    destroyStringStack(undoStack);
    destroyStringStack(redoStack);
}

/* SOAL 3: INFIX TO POSTFIX */
int getPrecedence(char op)
{
    /*kamus lokal*/
    /* tidak ada variabel lokal tambahan */

    /*algoritma*/
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

char *infixToPostfix(const char *infix)
{
    /*kamus lokal*/
    int len, postfixIndex, i;
    char *postfix;
    CharStack *stack;
    char ch;
    char op;

    /*algoritma*/
    printf("\n=== KONVERSI INFIX KE POSTFIX ===\n");
    printf("Infix: %s\n", infix);

    len = strlen(infix);
    postfixIndex = 0;
    postfix = (char *)malloc((len * 2 + 1) * sizeof(char));
    stack = createCharStack(len);

    for (i = 0; i < len; i++)
    {
        ch = infix[i];

        if (ch == ' ')
            continue; // Skip spasi

        // Jika operand (angka), tambahkan ke output
        if (isdigit(ch))
        {
            postfix[postfixIndex++] = ch;
            postfix[postfixIndex++] = ' ';
            printf("Tambah operand '%c' ke output\n", ch);
        }
        // Jika kurung buka, push ke stack
        else if (ch == '(')
        {
            pushChar(stack, ch);
            printf("Push '(' ke stack\n");
        }
        // Jika kurung tutup, pop sampai ketemu kurung buka
        else if (ch == ')')
        {
            while (!isCharStackEmpty(stack) && peekChar(stack) != '(')
            {
                op = popChar(stack);
                postfix[postfixIndex++] = op;
                postfix[postfixIndex++] = ' ';
                printf("Pop operator '%c' ke output\n", op);
            }
            if (!isCharStackEmpty(stack))
            {
                popChar(stack); // Pop kurung buka
                printf("Pop '(' dari stack\n");
            }
        }
        // Jika operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (!isCharStackEmpty(stack) && peekChar(stack) != '(' &&
                   getPrecedence(peekChar(stack)) >= getPrecedence(ch))
            {
                op = popChar(stack);
                postfix[postfixIndex++] = op;
                postfix[postfixIndex++] = ' ';
                printf("Pop operator '%c' ke output (precedence)\n", op);
            }
            pushChar(stack, ch);
            printf("Push operator '%c' ke stack\n", ch);
        }
    }

    // Pop semua operator yang tersisa
    while (!isCharStackEmpty(stack))
    {
        op = popChar(stack);
        postfix[postfixIndex++] = op;
        postfix[postfixIndex++] = ' ';
        printf("Pop operator terakhir '%c' ke output\n", op);
    }

    if (postfixIndex > 0)
        postfixIndex--; // Hapus spasi terakhir
    postfix[postfixIndex] = '\0';

    printf("Postfix: %s\n", postfix);

    destroyCharStack(stack);
    return postfix;
}

/* SOAL 4: EVALUASI POSTFIX */
double evaluatePostfix(const char *postfix)
{
    /*kamus lokal*/
    DoubleStack *stack;
    char *postfixCopy;
    char *token;
    double num, a, b, result, finalResult;

    /*algoritma*/
    printf("\n=== EVALUASI POSTFIX EXPRESSION ===\n");
    printf("Postfix: %s\n", postfix);

    stack = createDoubleStack(100);
    postfixCopy = (char *)malloc((strlen(postfix) + 1) * sizeof(char));
    strcpy(postfixCopy, postfix);

    token = strtok(postfixCopy, " ");

    while (token != NULL)
    {
        // Jika token adalah angka
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
        {
            num = atof(token);
            pushDouble(stack, num);
            printf("Push operand %.2f ke stack\n", num);
        }
        // Jika token adalah operator
        else if (strlen(token) == 1 && strchr("+-*/", token[0]))
        {
            if (stack->top < 1)
            {
                printf("Error: Tidak cukup operand!\n");
                destroyDoubleStack(stack);
                free(postfixCopy);
                return 0;
            }

            b = popDouble(stack);
            a = popDouble(stack);

            switch (token[0])
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                if (b == 0)
                {
                    printf("Error: Pembagian dengan nol!\n");
                    destroyDoubleStack(stack);
                    free(postfixCopy);
                    return 0;
                }
                result = a / b;
                break;
            default:
                result = 0;
                break;
            }

            pushDouble(stack, result);
            printf("Operasi %.2f %c %.2f = %.2f\n", a, token[0], b, result);
        }
        else
        {
            printf("Error: Token tidak valid '%s'!\n", token);
        }

        token = strtok(NULL, " ");
    }

    finalResult = popDouble(stack);
    printf("Hasil akhir: %.2f\n", finalResult);

    destroyDoubleStack(stack);
    free(postfixCopy);
    return finalResult;
}

/* ============= UTILITAS ============= */
void destroyCharStack(CharStack *stack)
{
    /*kamus lokal*/
    /* tidak ada variabel lokal tambahan */

    /*algoritma*/
    if (stack != NULL)
    {
        free(stack->data);
        free(stack);
    }
}

void destroyStringStack(StringStack *stack)
{
    /*kamus lokal*/
    /* tidak ada variabel lokal tambahan */

    /*algoritma*/
    if (stack != NULL)
    {
        clearStringStack(stack);
        free(stack->data);
        free(stack);
    }
}

void destroyDoubleStack(DoubleStack *stack)
{
    /*kamus lokal*/
    /* tidak ada variabel lokal tambahan */

    /*algoritma*/
    if (stack != NULL)
    {
        free(stack->data);
        free(stack);
    }
}