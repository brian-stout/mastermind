mastermind:
clean:
	rm mastermind
    
CPPFLAGS+=-Wall -Wextra -Wpedantic -Wwrite-strings -Wstack-usage=1024 -Wfloat-equal -Waggregate-return -Winline

CFLAGS+=-std=c11 

