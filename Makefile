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
SHARE_DIR ?= $(PREFIX)/share
PROGRAM = alterlinux-i3-manager

all: 
	cmake -GNinja .
	ninja

clean: 
	rm CMakeCache.txt cmake_install.cmake && rm -r CMakeFiles

install: 
	cmake -GNinja .
	ninja
	mkdir   -p                            $(DESTDIR)$(SHARE_DIR)/$(PROGRAM)
	cp      -rf pic/                      $(DESTDIR)$(SHARE_DIR)/$(PROGRAM)
	cp      -rf polybar                   $(DESTDIR)$(SHARE_DIR)/$(PROGRAM)
	install -m 755 -p $(PROGRAM)          $(DESTDIR)$(PREFIX)/bin
	install -m 644 -p $(PROGRAM)_ja_JP.qm $(DESTDIR)$(SHARE_DIR)/$(PROGRAM)

uninstall: 
	rm -f  $(DESTDIR)$(PREFIX)/bin/$(PROGRAM)
	rm -rf $(DESTDIR)$(SHARE_DIR)/$(PROGRAM)
