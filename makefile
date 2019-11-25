COMPILER=g++
COMMONPATH=~/Documents/Code/C/simple_Phone
LIBDIR=$(COMMONPATH)/lib
INCLUDE=$(COMMONPATH)/include
BINDIR=$(COMMONPATH)/bin
SRCDIR=$(COMMONPATH)/src
CFLAGS=-c -Wall
BINFILE=cPhone

all:
	cd $(LIBDIR) && $(COMPILER) $(SRCDIR)/*.c $(CFLAGS) -I $(INCLUDE)
	cd $(BINDIR) && $(COMPILER) $(LIBDIR)/*.o -o $(BINFILE) && echo "Files updated"

exe:
	cd $(LIBDIR) && $(COMPILER) $(SRCDIR)/*.c $(CFLAGS) -I $(INCLUDE)
	cd $(BINDIR) && $(COMPILER) $(LIBDIR)/*.o -o $(BINFILE).exe

clean:
	rm $(LIBDIR)/*.o && rm $(BINDIR)/*
	echo "Deleted all object and executable files"

# Builder will call this to install the application before running.
install:
	echo "Installing is not supported"

# Builder uses this target to run your application.
run:
	cd bin/ && ./$(BINFILE)
