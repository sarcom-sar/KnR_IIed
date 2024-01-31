#ifndef RPN
#define RPN

#define MAXVAL 100
#define NUMBER '0'
#define BUFSIZE 100

void push(double f);
double pop(void);
int getch(void);
void ungetch(int c);

#endif
