
Debian
====================
This directory contains files used to package adeptiod/adeptio-qt
for Debian-based Linux systems. If you compile adeptiod/adeptio-qt yourself, there are some useful files here.

## adeptio: URI support ##


adeptio-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install adeptio-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your adeptioqt binary to `/usr/bin`
and the `../../share/pixmaps/adeptio128.png` to `/usr/share/pixmaps`

adeptio-qt.protocol (KDE)

