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

int itoa(int number, char *string) {
  int i = 0;
  for (; number != 0; i++) {
    string[i] = number % 10 + 48;
    number = number / 10;
  }
  string[i] = 0;
  for (int a = 0, b = i - 1; a < b; a++, b--) {
    char t = string[a]; string[a] = string[b]; string[b] = t;
  }
  return i + 1;
}

void print_number(int number) {
  char print_buffer[256];
  int print_len;
  print_len = itoa(number, print_buffer);
  write(1, print_buffer, print_len);
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
  char read_buffer[256];
  int read_len = read(0, read_buffer, 256);
  read_buffer[read_len-1] = 0;

  int number = atoi(read_buffer);

  char print_buffer[256];

  write(1, "Entered number ", 15);
  print_number(number);

  write(1, ", its half is ", 14);
  print_number(number/2);

  write(1, ", square ", 9);
  print_number(number*number);

  return 0;
}
