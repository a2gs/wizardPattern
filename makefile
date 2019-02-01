CC = cc
AR = ar
RANLIB = ranlib

SRCDIR = ./src
INCDIR = ./inc
BINDIR = ./bin

CFLAGS = -g -Wall -std=c11

RM = /bin/rm -f

OBJL  = $(BINDIR)/liba2gs_ToolBox_Wizard_by_list.o
OBJJT = $(BINDIR)/liba2gs_ToolBox_Wizard_by_jumptable.o

LIBL  = $(BINDIR)/liba2gs_ToolBox_Wizard_by_list.a
LIBJT = $(BINDIR)/liba2gs_ToolBox_Wizard_by_jumptable.a

SOURCESL = $(SRCDIR)/wizard_by_list.c
SOURCESJT = $(SRCDIR)/wizard_by_jumptable.c

all: $(SOURCES)
	$(CC) -c -o$(OBJL)  -I$(INCDIR) $(SOURCESL)  $(CFLAGS)
	$(CC) -c -o$(OBJJT) -I$(INCDIR) $(SOURCESJT) $(CFLAGS)

	$(AR) rc $(LIBJT) $(OBJJT)
	$(AR) rc $(LIBL) $(OBJL)

	$(RANLIB) $(LIBJT)
	$(RANLIB) $(LIBL)

	-$(RM) $(BINDIR)/*.o

clean:
	-$(RM) $(BINDIR)/*