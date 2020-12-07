#include <iostream>
#include <cstring>
#include <unistd.h>
using namespace std;
#define E(c) int(c>='A'&&c<='Z'?(c-'A'):(c-'a'+26))
#define C {cout<<"\x1B[2J\x1B[H";}
int main() {
    C
    const char *s="gthXABhCZOaDWHcDYIbDXEaDWIZIWDjCBBiCWNaDWHcDYIbDXEaDWHcDYEbDXDgCCBjCXMaDWHcDYJcDYCZDZIcDYLhCDBgCYLaDWCbDXCcDYKZGYJcDYMiCABhCZKaDWBaFYBcDYJcDYCZDZIcDYDaEXGjCBBiCWKbFZBZFXJbDXEaDWHcDYEbDXHgCCBjCXKcDYDaDWKbDXEaDWIZIWJhCDBgCYfXhiCABhCZKaDWIZHZJZIWKbDXGjCBBiCWHc
WHcDYDaDWHcDYEbDXIaDWIgCCBjCXIaDWHcDYDaDWNaDWIZDZBZDZGhCDBgCYHaDWHcDYDaDWLcDYJcDYCZDZHiCABhCZGaDWHcDYDaDWJaDWKbLXGjCBBiCWFaDWHcDYDaDWIZDZRZDZJgCCBjCXCcHYGZHZIcKXLZDZKhCDBgeimAB";
    int l=strlen(s);
    while(1){
        static int k=0;
        int cur=0;
        for(int i=0;s[i];i+=2){
            char c=E(s[i])+10-cur%4;
            int t=E(s[i+1]);
            for(int j=0;j<t;++j)cout<<(c=='#'?char(((0x01&k)<<4)|42):c);
            cur+=t;
        }
        cout<<"cntl+C to exit\n";
        usleep(500000);
        C
        k++;
    }
    return 0;
}
