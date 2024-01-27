#ifndef A405
#define A405

#define MAXVAL 100
#define NUMBER '0'
#define BUFSIZE 100
#define IDENTIFIER '1'

int getop(char s[]);
void push(double num);
double pop(void);
int getch(void);
void ungetch(int c);
void handle_math(char s[]);

#endif
