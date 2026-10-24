#include <unistd.h>

// ASCII: 0 = 48, 1 = 49, etc.
int atoi(char *str) {
  int acc = 0;
  for (int i=0; str[i] != 0; i++) {
    if (str[i] < 48 || str[i] > 57) {
      return 0;
    }
    acc = acc * 10 + (str[i] - 48);
  }
  return acc;
}

int strlength(char *str) {
  int i=0;
  for (; str[i] != 0; i++) {}
  return i;
}

// -1 means first less
int strcompare(char *str1, char *str2) {
  for (int i=0;;i++) {
    if (str1[i] == str2[i]) continue;
    return str1[i] < str2[i] ? -1 : 1;
  }
  return 0;
}

const int MAX_NAME_LEN = 256;

int main() {
  char number[256];
  int number_len = read(0, number, 256);
  number[number_len-1] = 0;

  int parsed_number = atoi(number);
  for (int i=0; i < parsed_number; i++) {
    write(1, "*", 1);
  }

  return 0;
}
