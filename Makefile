CC      := clang++
IFLAGS 	:= -I include/
CFLAGS	:= -Wall -Wextra -Wno-unused-parameter -std=c++98 -pedantic -O2
DFLAGS	:= -g -DDEBUG -O0

LNFLAGS	:= -lm
EXE 	:= drit

.SUFFIXES=.cpp

SRC 	:= $(shell find 'src' -name '*.cpp' )
OBJ 	:= $(SRC:.cpp=.o)

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(IFLAGS) $(LNFLAGS) -o$(EXE)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(EXE)
	rm -f src/*.o

debug:
	@$(MAKE) $(MFLAGS) CFLAGS="$(CFLAGS) $(DFLAGS)"

.PHONY= clean
