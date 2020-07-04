# ---------------------------------------------
#  Alter Linux i3 manager
#  Makefile
#
#  Watasuke
#  Twitter: @Watasuke102
#  Email  : Watasuke102@gmail.com
#
#  (c) 2020 Fascode Network.
# ---------------------------------------------

PROGRAM = alterlinux-i3-manager

all: 
	cmake -GNinja .
	ninja

clean: 
	rm CMakeCache.txt cmake_install.cmake && rm -r CMakeFiles

install: 
	cmake -GNinja .
	ninja
	mkdir   -p          /usr/share/$(PROGRAM)
	cp      -rf pic/    /usr/share/$(PROGRAM)
	cp      -rf polybar /usr/share/$(PROGRAM)
	install -m 755 -p $(PROGRAM)          /usr/bin
	install -m 644 -p $(PROGRAM)_ja_JP.qm /usr/share/$(PROGRAM)

uninstall: 
	rm -f  /usr/bin/$(PROGRAM)
	rm -rf /usr/share/$(PROGRAM)