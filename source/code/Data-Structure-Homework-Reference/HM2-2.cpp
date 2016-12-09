#include <cstdio>
const int MAXN = 200;

bool Num[MAXN];
char Op[MAXN];
int numCnt, opCnt;

void calc() {
  switch (Op[--opCnt]) {
  case '|':
    Num[numCnt - 2] |= Num[numCnt - 1];
    numCnt--;
    break;
  case '&':
    Num[numCnt - 2] &= Num[numCnt - 1];
    numCnt--;
    break;
  case '!':
    Num[numCnt - 1] = !Num[numCnt - 1];
    break;
  }
}

int priority(char op) {
  switch (op) {
  case '(':
    return 0;
  case '!':
    return 4;
  case '&':
    return 3;
  case '|':
    return 2;
  default:
    return -1;
  }
}
// 1 for right asso
// 0 for left asso
bool associativity(char op) {
  switch (op) {
  case '!':
    return 1;
  default:
    return 0;
  }
}

int main() {
  int kase = 1;
  char ch;
  bool isRegal = true;
  bool isEmptyLine = true;
  while ((ch = getchar()) != EOF) {
    if (ch == ' ') {
      continue;
    } else if (ch == '\n') {
      if (isEmptyLine) {
        continue;
      }
      isEmptyLine = true;
      while (opCnt) {
        calc();
      }
      if (numCnt != 1) {
        isRegal = false;
        numCnt = 0;
      }
      printf("Expression %d: %s\n", kase++,
             isRegal ? (Num[--numCnt] ? "V" : "F") : "Iregal");
      fflush(stdout);
      isRegal = true;
    } else {
      isEmptyLine = false;
      if (ch == 'V') {
        Num[numCnt++] = true;
      } else if (ch == 'F') {
        Num[numCnt++] = false;
      } else {
        // operator
        if (ch == '(') {
          Op[opCnt++] = ch;
        } else if (ch == ')') {
          while (opCnt) {
            if (Op[opCnt - 1] == '(') {
              opCnt--;
              break;
            }
            calc();
          }
        } else {
          // operator
          int p = priority(ch);
          while (opCnt) {
            if (priority(Op[opCnt - 1]) < p) {
              break;
            }
            if (associativity(ch)) {
              break;
            }
            calc();
          }
          Op[opCnt++] = ch;
        }
      }
    }
  }
  return 0;
}
