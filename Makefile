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
	cmake -GNinja -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ .
	ninja

clean: 
	rm CMakeCache.txt cmake_install.cmake && rm -r CMakeFiles

install: 
	cmake -GNinja -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ .
	ninja
	install -Dm 755 $(PROGRAM)            $(DESTDIR)$(PREFIX)/bin/$(PROGRAM)
	install -Dm 644 $(PROGRAM)_ja_JP.qm   $(DESTDIR)$(SHARE_DIR)/$(PROGRAM)/$(PROGRAM)_ja_JP.qm
	install -Dm 644 $(PROGRAM).desktop    $(DESTDIR)$(SHARE_DIR)/applications/$(PROGRAM).desktop
	cp      -rf pic                       $(DESTDIR)$(SHARE_DIR)/$(PROGRAM)
	cp      -rf polybar                   $(DESTDIR)$(SHARE_DIR)/$(PROGRAM)
	cp      -rf rofi                      $(DESTDIR)$(SHARE_DIR)/$(PROGRAM)

uninstall: 
	rm -f  $(DESTDIR)$(PREFIX)/bin/$(PROGRAM)
	rm -f  $(DESTDIR)$(SHARE_DIR)/applications/$(PROGRAM).desktop
	rm -rf $(DESTDIR)$(SHARE_DIR)/$(PROGRAM)
