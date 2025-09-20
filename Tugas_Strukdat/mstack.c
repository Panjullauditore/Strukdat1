/* Program   : mstack.c */
/* Deskripsi : driver ADT stack untuk aplikasi struktur data */
/* Kelompok  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "boolean.h"

int main() {
    /*kamus*/
    int pilihan;
    char input[256];
    char *postfixResult;
    double evalResult;
    
    /*algoritma*/
    printf("TUGAS STRUKTUR DATA - APLIKASI STACK\n");
    printf("=====================================\n");
    printf("NIM/Nama : 24060122140146 - Ahmad Fahrezi\n");
    printf("Tanggal  : 20 September 2025\n\n");
    
    do {
        printf("\n=== MENU TESTING APLIKASI STACK ===\n");
        printf("1. Test Parentheses Checker\n");
        printf("2. Test Text Editor (Undo-Redo)\n");
        printf("3. Test Konversi Infix ke Postfix\n");
        printf("4. Test Evaluasi Postfix Expression\n");
        printf("5. Test Semua (Demo Lengkap)\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar(); // consume newline
        
        switch(pilihan) {
            case 1:
                printf("\n=== TEST PARENTHESES CHECKER ===\n");
                printf("Test Case 1: {[(A+B) * (C+D)] - (7*D)}\n");
                isValidKurung("{[(A+B) * (C+D)] - (7*D)}");
                
                printf("\nTest Case 2: {[(A+B) * (C+D)] - (7*D)\n");
                isValidKurung("{[(A+B) * (C+D)] - (7*D)");
                
                printf("\nTest Case 3: {[(A+B) * (C+D]) - (7*D)}\n");
                isValidKurung("{[(A+B) * (C+D]) - (7*D)}");
                
                printf("\nTest Case 4: {[(A+B) * (C+D)] - (7*D))}\n");
                isValidKurung("{[(A+B) * (C+D)] - (7*D))}");
                
                printf("\n--- CUSTOM INPUT ---\n");
                printf("Masukkan string untuk dicek: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // hapus newline
                
                boolean result = isValidKurung(input);
                printf("Hasil: %s\n", result ? "VALID ✓" : "TIDAK VALID ✗");
                break;
                
            case 2:
                printf("\n=== TEST TEXT EDITOR (UNDO-REDO) ===\n");
                printf("Akan membuka text editor interaktif...\n");
                printf("Tekan Enter untuk melanjutkan...\n");
                getchar();
                textEditor();
                break;
                
            case 3:
                printf("\n=== TEST KONVERSI INFIX KE POSTFIX ===\n");
                
                printf("Test Case 1: 3 + ( 4 * 3 ) / 4\n");
                postfixResult = infixToPostfix("3 + ( 4 * 3 ) / 4");
                printf("Hasil: %s\n", postfixResult);
                free(postfixResult);
                
                printf("\nTest Case 2: 3 * ( 4 + 5 ) / 2\n");
                postfixResult = infixToPostfix("3 * ( 4 + 5 ) / 2");
                printf("Hasil: %s\n", postfixResult);
                free(postfixResult);
                
                printf("\nTest Case 3: 3 + ( 4 * 5 ) - 2\n");
                postfixResult = infixToPostfix("3 + ( 4 * 5 ) - 2");
                printf("Hasil: %s\n", postfixResult);
                free(postfixResult);
                
                printf("\n--- CUSTOM INPUT ---\n");
                printf("Masukkan ekspresi infix: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // hapus newline
                
                postfixResult = infixToPostfix(input);
                printf("Hasil postfix: %s\n", postfixResult);
                free(postfixResult);
                break;
                
            case 4:
                printf("\n=== TEST EVALUASI POSTFIX EXPRESSION ===\n");
                
                printf("Test Case 1: 3 4 3 * 4 / +\n");
                evalResult = evaluatePostfix("3 4 3 * 4 / +");
                printf("Hasil evaluasi: %.2f\n", evalResult);
                
                printf("\nTest Case 2: 3 4 5 + * 2 /\n");
                evalResult = evaluatePostfix("3 4 5 + * 2 /");
                printf("Hasil evaluasi: %.2f\n", evalResult);
                
                printf("\nTest Case 3: 9 3 4 * 8 + 4 / -\n");
                evalResult = evaluatePostfix("9 3 4 * 8 + 4 / -");
                printf("Hasil evaluasi: %.2f\n", evalResult);
                
                printf("\n--- CUSTOM INPUT ---\n");
                printf("Masukkan ekspresi postfix: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // hapus newline
                
                evalResult = evaluatePostfix(input);
                printf("Hasil evaluasi: %.2f\n", evalResult);
                break;
                
            case 5:
                printf("\n=== DEMO LENGKAP SEMUA APLIKASI ===\n");
                
                // Demo Parentheses Checker
                printf("\n1. DEMO PARENTHESES CHECKER:\n");
                char *testCases[] = {
                    "{[(A+B) * (C+D)] - (7*D)}",
                    "{[(A+B) * (C+D)] - (7*D)",
                    "{[(A+B) * (C+D]) - (7*D)}",
                    "{[(A+B) * (C+D)] - (7*D))}"
                };
                
                for (int i = 0; i < 4; i++) {
                    boolean result = isValidKurung(testCases[i]);
                    printf("Hasil: %s\n\n", result ? "VALID" : "TIDAK VALID");
                }
                
                // Demo Infix to Postfix dan Evaluasi
                printf("2. DEMO KONVERSI & EVALUASI:\n");
                char *infixExpressions[] = {
                    "3 + ( 4 * 3 ) / 4",
                    "3 * ( 4 + 5 ) / 2",
                    "3 + ( 4 * 5 ) - 2"
                };
                
                for (int i = 0; i < 3; i++) {
                    printf("\n--- Ekspresi %d ---\n", i+1);
                    postfixResult = infixToPostfix(infixExpressions[i]);
                    evalResult = evaluatePostfix(postfixResult);
                    printf("Infix: %s\n", infixExpressions[i]);
                    printf("Postfix: %s\n", postfixResult);
                    printf("Hasil: %.2f\n", evalResult);
                    free(postfixResult);
                }
                
                // Demo Text Editor (brief)
                printf("\n3. TEXT EDITOR DEMO:\n");
                printf("Simulasi perintah undo-redo:\n");
                printf("Perintah 1: tulis hello\n");
                printf("Perintah 2: edit file\n");
                printf("Undo -> batalkan 'edit file'\n");
                printf("Redo -> kembalikan 'edit file'\n");
                printf("(Text Editor interaktif tersedia di Menu 2)\n");
                
                printf("\n4. DEMO EVALUASI POSTFIX:\n");
                
                // Test evaluasi postfix langsung
                printf("\nTest Case Evaluasi 1: 3 4 3 * 4 / +\n");
                evalResult = evaluatePostfix("3 4 3 * 4 / +");
                printf("Hasil: %.2f\n", evalResult);
                
                printf("\nTest Case Evaluasi 2: 3 4 5 + * 2 /\n");
                evalResult = evaluatePostfix("3 4 5 + * 2 /");
                printf("Hasil: %.2f\n", evalResult);
                
                printf("\nTest Case Evaluasi 3: 9 3 4 * 8 + 4 / -\n");
                evalResult = evaluatePostfix("9 3 4 * 8 + 4 / -");
                printf("Hasil: %.2f\n", evalResult);
                
                printf("\n=== DEMO LENGKAP SELESAI ===\n");
                printf("Semua 4 aplikasi stack telah berhasil didemonstrasikan!\n");
                break;
                
            case 0:
                printf("\n=== PROGRAM SELESAI ===\n");
                printf("Terima kasih telah menggunakan program ini!\n");
                break;
                
            default:
                printf("Pilihan tidak valid! Silakan pilih menu yang tersedia.\n");
        }
        
        if (pilihan != 0) {
            printf("\nTekan Enter untuk kembali ke menu...");
            getchar();
        }
        
    } while(pilihan != 0);
    
    return 0;
}