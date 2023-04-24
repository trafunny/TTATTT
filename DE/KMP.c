// #include<stdio.h>
// #include<string.h>

// void prefixSuffixArray(char* pat, int M, int* pps) {
//    int length = 0;
//    pps[0] = 0;
//    int i = 1;
//    while (i < M) {
//       if (pat[i] == pat[length]) {
//          length++;
//          pps[i] = length;
//          i++;
//       } else {
//          if (length != 0)
//          length = pps[length - 1];
//          else {
//             pps[i] = 0;
//             i++;
//          }
//       }
//    }
// }
// void KMPAlgorithm(char* text, char* pattern) {
//    int M = strlen(pattern);    // P:
//    int N = strlen(text);       //Text
//    int pps[M];        
//    prefixSuffixArray(pattern, M, pps);
//    int i = 0;
//    int j = 0;
//    while (i < N) {
//       if (pattern[j] == text[i]) {
//          j++;
//          i++;
//       }
//       if (j == M) {
//          printf("Vi tri thu %d", i - j);
//          break;
//          j = pps[j - 1];
//       }
//       else if (i < N && pattern[j] != text[i]) {
//          if (j != 0)
//          j = pps[j - 1];
//          else
//          i = i + 1;
//       }
//    }
// }
// int main() {
//    char text[] = "hom nay la thu bay";
//    char pattern[] = "ay";
   
//    KMPAlgorithm(text, pattern);
//    return 0;
// }

#include <stdio.h>
#include <string.h>
int soSanhChuoi(char P[], int j, int i){
    int check = 0;
    for (int x = 0; x < i; x++)   // kiểm tra chuỗi tiền tố với hậu tố
        if (P[x] == P[j - i + x]) // kiểm tra từng kí tự lần lượt của chuỗi tiền tố với hậu tố
            check++;
    if (check == i)
        return 1;
    return 0;
}
int kiemTra(char P[], int j){   // kích thước của tiền tố = hậu tố
    for (int i = j - 1; i >= 0; i--)
        if (soSanhChuoi(P, j, i) == 1)
            return i;
    return 0;
}
void failureFunction(char P[], int F[]){
    F[0] = -1;
    for (int j = 1; j < strlen(P); j++)
        F[j] = kiemTra(P, j);
}
int main(){
    char T[1000]; char P[1000];
    gets(T); gets(P);
    int F[strlen(P)];
    failureFunction(P, F);
    int i = 0, j = 0, check = 0;
    while(i <= strlen(T)-strlen(P)){    // khi i chưa chạy hết độ dài của T-P
        int inew = i+j;
        if(T[inew] == P[j]){
            inew++; j++;
            if(j == strlen(P)){     //j tăng đến hết P
                printf("P co xuat hien trong T, tai vi tri %d", i);
                check=1;
                break;
            }
        }  
        else{   //cập nhật gtri mới của i và j
            i = i + j - F[j]; 
            j = F[j] == -1 ? 0 : F[j];
        }
    }
    if(check == 0) printf("P khong xuat hien trong T!!");
}