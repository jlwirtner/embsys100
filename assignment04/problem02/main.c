void outer(int a, int b);

void inner(int a, int b, int c, int d, int e, int f, int g, int h);

void outer(int a, int b) {
    a++;
    b++;
    inner(1,2,3,4,5,6,7,8);
}

void inner(int a, int b, int c, int d, int e, int f, int g, int h) {
    a++;
    b++;
    c++;
    d++;
    e++;
    f++;
    g++;
    h++;
}

int main(void) {
    outer(1,2);
    return 0;
}