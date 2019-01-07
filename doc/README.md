Adeptio Core
=====================

### Most up-to-date documentation

Can be found at: [adeptio wiki](http://wiki.adeptio.cc). You can find some usefull information here as well.

### Up-to-date building instructions

[https://wiki.adeptio.cc/books/building-the-wallet](https://wiki.adeptio.cc/books/building-the-wallet)

Setup
---------------------
[Adeptio Core](http://adeptio.cc) is the original Adeptio client and it builds the backbone of the network. However, it downloads and stores the entire history of Adeptio transactions; depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more. Thankfully you only have to do this once.

Running
---------------------
The following are some helpful notes on how to run Adeptio on your native platform.

### Unix

Unpack the files into a directory and run:

- adeptio-qt (GUI, 32-bit) or adeptiod (headless, 32-bit)
- adeptio-qt (GUI, 64-bit) or adeptiod (headless, 64-bit)

### Windows

Unpack the files into a directory, and then run adeptio-qt.exe.

### OSX

Drag Adeptio-qt to your applications folder, and then run Adeptio-qt.

### Need Help?

* See the documentation at the [Adeptio Wiki](https://wiki.adeptio.cc)
* Ask for help on [BitcoinTalk](https://bitcointalk.adeptio.cc)
* Join our Discord server [Discord Server](https://discord.gg/RBXjTBa)

Building
---------------------
The following are developer notes on how to build Adeptio on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [OSX Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)

License
---------------------
Distributed under the [MIT/X11 software license](http://www.opensource.org/licenses/mit-license.php).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](https://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
