include param.mk

DEST=/home/luc/libs
VERSION=1.0

INCLUDES=/home/luc/includes
INCFILE=$(NAME).hpp
INCSDIR=$(INCLUDES)/$(NAME)

PCFILE=$(NAME).pc
PCDIR=/usr/lib/pkgconfig

all : $(LIB)

$(LIB) :
	cd src && make

clean :
	cd src && make clean

rec : clean $(LIB)

install : $(LIB)
	@cp -v $(LIB) $(DEST)
	@mkdir $(INCSDIR)
	@cp -v $(INCFILE) $(INCLUDES)
	@cp -v `ls src/*.hpp --ignore=$(INCFILE)` $(INCSDIR)
	@cp -v $(PCFILE) $(PCDIR)

uninstall : $(LIBS)
	@touch $(DEST)/$(LIB) $(INCLUDES)/$(INCFILE) $(PCDIR)/$(PCFILE) $(INCSDIR)
	@rm -v $(DEST)/$(LIB) $(INCLUDES)/$(INCFILE)
	@rm -rv $(INCSDIR)
	@rm -v $(PCDIR)/$(PCFILE)

mr-proper : uninstall clean

reinstall : uninstall rec install

doc :
	cd doc && doxygen Doxyfile
	firefox doc/html/index.html > /dev/null 2>&1 &

clear-doc :
	rm -rf doc/html
	rm -rf doc/man
	rm -rf doc/latex

.PHONY: doc

