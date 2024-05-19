all: final

final: mainmenu.c checkout.h
    gcc -o final mainmenu.c -I

clean:
    rm final