#include <stdio.h>
#include <unistd.h>

int main() {
    // We already simplified the code to live in only a one-dimensonal array.
    // Going down a line then just consists of adding 80 to the index
    char program[2000]; // Sourcecode
    char *p = program;  // Instruction pointer
    int d = 1;          // Direction of control flow, -1 = left, 1 = right,
                        // 80 = down, -80 = up

    // We read the sourecode from stdin
    read(0, program, 2000);

    // We need a stack. We use a fixed array here, together with a stackindex
    // We let stack[i] always be the top of the stack (this simplifies our code
    // a little)
    int stack[2000];
    int i = -1; // Since the stack is empty. Pushing the first element will
                // make it end up at index 0

    int a, b; // Temporary variables to hold popped values

    // And loop through it
    while (1) {
        switch (*p) {
            case '@':
                // End our program
                return 0;
            case '.':
                // Pop top of stack and print it
                printf("%d\n", stack[i--]);
                break;
            case 'v':
                d = 80;
                break;
            case '^':
                d = -80;
                break;
            case '>':
                d = 1;
                break;
            case '<':
                d = -1;
                break;
            case '|':
                // If top of stack is zero, go down, else up
                if (stack[i--] == 0) {
                    d = 80;
                } else {
                    d = -80;
                }
                break;
            case '_':
                // If top of stack is zero, go right, else left
                if (stack[i--] == 0) {
                    d = 1;
                } else {
                    d = -1;
                }
                break;
            case '+':
                a = stack[i--];
                b = stack[i--];
                stack[++i] = b + a;
                break;
            case '-':
                a = stack[i--];
                b = stack[i--];
                stack[++i] = b - a;
                break;
            case '/':
                a = stack[i--];
                b = stack[i--];
                stack[++i] = b / a;
                break;
            case '*':
                a = stack[i--];
                b = stack[i--];
                stack[++i] = b * a;
                break;
            case ' ':
                break;
            default:
                // We just assume this is a number and push it
                stack[++i] = *p - '0'; // Converts an ASCII-Digit into an int
                break;
        }
        // Step
        p += d;
    }
}
