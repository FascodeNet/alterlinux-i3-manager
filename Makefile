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
PREFIX ?= /usr
share_dir ?= $(PREFIX)/share
PROGRAM = alterlinux-i3-manager

all: 
	cmake -GNinja .
	ninja

clean: 
	rm CMakeCache.txt cmake_install.cmake && rm -r CMakeFiles

install: 
	cmake -GNinja .
	ninja
	mkdir   -p          $(DESTDIR)$(share_dir)/$(PROGRAM)
	cp      -rf pic/    $(DESTDIR)$(share_dir)/$(PROGRAM)
	cp      -rf polybar $(DESTDIR)$(share_dir)/$(PROGRAM)
	install -m 755 -p $(PROGRAM)          $(DESTDIR)$(PREFIX)/bin
	install -m 644 -p $(PROGRAM)_ja_JP.qm $(DESTDIR)$(share_dir)/$(PROGRAM)

uninstall: 
	rm -f  $(DESTDIR)$(PREFIX)/bin/$(PROGRAM)
	rm -rf $(DESTDIR)$(share_dir)/$(PROGRAM)
