#include <stdio.h>
#include <string.h>

void getShiftTable(int shiftTable[], char pattern[], int pattern_length) {
    for(int i = 0;i < pattern_length-1;i++){
        shiftTable[(int)pattern[i]] = pattern_length -1 - i;
    }
}

int horspool(char text[], char pattern[], int text_length, int pattern_length, int *comparisons) {
    int shiftTable[127];
    for (int i = 0;i < 127;i++){
        shiftTable[i] = pattern_length;
    }
    getShiftTable(shiftTable,pattern,pattern_length);

    int i  = pattern_length - 1;
    while (i<text_length) {
        int j = 0;
        while (j < pattern_length && pattern[pattern_length-1-j] == text[i - j]){
            j++;
        }
        *comparisons = *comparisons + j + 1;
        if (j == pattern_length) return (i-pattern_length+1);
        else i += shiftTable[(int)text[i]];
    }
    return -1;
}

void main() {
    int res, comparisons = 0;
    char text[100], pattern[100];
    printf("Enter the text :");
    scanf("%[^\n]",text);
    printf("Enter the pattern :");
    scanf(" %s",pattern);

    res = horspool(text, pattern, strlen(text), strlen(pattern), &comparisons);
    if (res == -1){
        printf("Pattern not found.\n");
    }
    else{
        printf("Pattern found at index %d.\n",res);
    }
    printf("Number of key comparisons: %d",comparisons);
}