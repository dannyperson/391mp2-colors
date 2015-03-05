EXENAME = colorguide

COMPILER = g++
WARNINGS = -Wchar-subscripts -Wparentheses -Wreturn-type -Wmissing-braces -Wundef -Wshadow
COMPILER_OPTS = -c -g -Os -march=native -Wfatal-errors -Werror $(WARNINGS)
LINKER = g++

MAIN_OBJS = colorguide.o png.o rgbapixel.o text.o
MAIN_DEPS = list.h list.cpp list_given.h list_given.cpp png.o rgbapixel.o colorguide.cpp

CODE_CLN = *.o $(EXENAME)


all: $(EXENAME)

$(EXENAME) : $(MAIN_OBJS)
	$(LINKER) $(MAIN_OBJS) -lpng -o $(EXENAME)

%.o : %.cpp $(MAIN_DEPS)
	$(COMPILER) $(COMPILER_OPTS) -o $@ $<

clean:
	-rm -f $(CODE_CLN)
