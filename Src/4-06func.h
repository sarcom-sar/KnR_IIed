#ifndef A406
#define A406

#define MAXVAL 100
#define NUMBER '0'
#define BUFSIZE 100
#define IDENTIFIER '1'
#define VARIABLE '2'

int getop(char s[]);
void push(double num);
double pop(void);
int getch(void);
void ungetch(int c);
void handle_math(char s[]);

#endif
