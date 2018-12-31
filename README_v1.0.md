### Usage

<<<<<<< HEAD
![Alt text](https://explorer.adeptio.cc/images/adeptio.png)

[![Build Status](https://development.adeptio.cc/job/Adeptio-CI-master-Weekly-Build/badge/icon)](https://development.adeptio.cc/job/Adeptio-CI-master-Weekly-Build/)

# What is Adeptio?

Adeptio is a fair cryptocurrency and enables instant payments to anyone, anywhere in the world. Coin uses peer-to-peer technology to operate with no central authority. Adeptio Core combines the best features of different coins in order to create an excellent digital payment asset. [storADE](https://github.com/adeptio-project/adeptioStorade) service technology with valuable adeptio masternode functionality serves storage & streaming platform for every day usage.

For more information see:

https://adeptio.cc

# Development

The master branch is regularly built and tested. Other branches used for upcoming release or test. Although master is not guaranteed to be completely stable.

Continuous integration process can be found at:
http://development.adeptio.cc

# Building process

**compiling adeptio from git**

Use the autogen script to prepare the build environment.

    make clean (if necessary)
    ./autogen.sh
    ./configure
    make

**precompiled binaries**

Precompiled binaries are available at GitHub, see https://github.com/adeptio-project/adeptio/releases

**Dependencies for Ubuntu 16.04 LTS or equivalent**

    sudo add-apt-repository ppa:bitcoin/bitcoin
    sudo apt-get update
    sudo apt-get install libdb4.8-dev libdb4.8++-dev
    sudo apt-get install libboost-system1.58-dev libboost-system1.58.0
    sudo apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev  bsdmainutils software-properties-common libminiupnpc-dev libcrypto++-dev libboost-all-dev libboost-system-dev libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev libboost-filesystem-dev libboost-thread-dev libssl-dev libssl-dev software-properties-common unzip libzmq3-dev

**Dependencies for Ubuntu 18.04 LTS or equivalent**

    sudo add-apt-repository ppa:bitcoin/bitcoin
    sudo apt-get update
    sudo apt-get install libdb4.8-dev libdb4.8++-dev
    sudo apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev  bsdmainutils software-properties-common libminiupnpc-dev libcrypto++-dev libboost-all-dev libboost-system-dev libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev libboost-filesystem-dev libboost-thread-dev libssl-dev libssl-dev software-properties-common unzip libzmq3-dev
   
# Coin Specifications

![Alt text](https://adeptio.cc/icon/adeptio_icon(256).png)

• Premine: (#1 Block) 50,002 for 5 init MasterNodes*

• Algorithm: Hybrid - PoW/PoS

• PoW Algorithm: Quark

• PoW Blocks: 2 - 345600

• PoS Blocks: Starting from 345601 (after ~240 days)

• Block Time: 60 Seconds

• Block Size: 1MB

• Max. Coin supply: infinite

• Network Port: 9077

• RPC Port: 9078

• "storADE" Port: 9079

• Tor network: capable

• IPv6 network: capable

• PoW Ending: ~240 Days

• Masternodes: activated

• Masternode Requirements: 10 000 ADE

• Maturity: 100 Confirmations

• Prefix: ADE adresses start with the capital letter "A"

*Premine masternodes will be burnt after 1 year from init start.*
https://explorer.adeptio.cc/address/APxwmBBBBBBBBBBBBBBBBBBBBBBBCywtwz

# Reward Distribution
<table>
<tr><th>Block Height</th><th>Reward Amount</th><th>Circulating amount</th>
<tr><td>Block 2 - 86400</td><td>150 ADE</td><td>~12 960000 ADE</td>
<tr><td>Block 86401 - 151200</td><td>125 ADE</td><td>~21 059875 ADE</td>
<tr><td>Block 151201 - 302400</td><td>100 ADE</td><td>~36 179775 ADE</td><td>POW ends</td>
<tr><td>Block 302401 - 345600</td><td>75 ADE</td><td>~39 419 700 ADE</td><td>POS starts</td>
<tr><td>Block 345601 - 388800</td><td>50 ADE</td><td>~41 579 650 ADE</td>
<tr><td>Block 388801 - 475200</td><td>50 ADE</td><td>~45 899 600 ADE</td>
<tr><td>Block 475201 - 518400</td><td>50 ADE</td><td>~48 059 550 ADE</td>
<tr><td>Block 518401 - 561600</td><td>25 ADE</td><td>~49 139 525 ADE</td>
<tr><td>Block 561601 - 604800</td><td>10 ADE</td><td>~49 571 515 ADE</td>
<tr><td>Block 604801 - infinite</td><td>5 ADE</td><td>+ ~2.628M per year </td>
</table>

![Alt text](https://blog.adeptio.cc/wp-content/uploads/2018/11/68747470733a2f2f6578706c6f7265722e6164657074696f2e63632f696d616765732f6164657074696f5f7265776172645f6469737472692e706e67.png)

# Resources

[Adeptio Website](https://adeptio.cc/)

[Adeptio Blog](https://blog.adeptio.cc/)

[Adeptio Explorer](https://explorer.adeptio.cc/)

[Adeptio Explorer 2](https://blocks.adeptio.cc/)

[Adeptio Exchange](https://crex24.com/exchange/ADE-BTC)

[Adeptio Stats](https://stats.adeptio.cc/)

[Adeptio Official Public API](https://api.adeptio.cc/)

[Adeptio CI Development](https://development.adeptio.cc/)

[Adeptio Paper Wallet](https://paperwallet.adeptio.cc/)

# Community

[Adeptio Bitcointalk](https://bitcointalk.org/index.php?topic=4368475.0)

[Adeptio Discord](https://discord.gg/RBXjTBa)
=======
To build dependencies for the current arch+OS:

    make

To build for another arch/OS:
>>>>>>> rebrand_new_features

    make HOST=host-platform-triplet

For example:

    make HOST=x86_64-w64-mingw32 -j4

A prefix will be generated that's suitable for plugging into Bitcoin's
configure. In the above example, a dir named x86_64-w64-mingw32 will be
created. To use it for Bitcoin:

    ./configure --prefix=`pwd`/depends/x86_64-w64-mingw32

Common `host-platform-triplets` for cross compilation are:

- `i686-w64-mingw32` for Win32
- `x86_64-w64-mingw32` for Win64
- `x86_64-apple-darwin14` for macOS
- `arm-linux-gnueabihf` for Linux ARM 32 bit
- `aarch64-linux-gnu` for Linux ARM 64 bit
- `riscv32-linux-gnu` for Linux RISC-V 32 bit
- `riscv64-linux-gnu` for Linux RISC-V 64 bit

No other options are needed, the paths are automatically configured.

### Install the required dependencies: Ubuntu & Debian

#### For macOS cross compilation

    sudo apt-get install curl librsvg2-bin libtiff-tools bsdmainutils cmake imagemagick libcap-dev libz-dev libbz2-dev python-setuptools

#### For Win32/Win64 cross compilation

- see [build-windows.md](../doc/build-windows.md#cross-compilation-for-ubuntu-and-windows-subsystem-for-linux)

#### For linux (including i386, ARM) cross compilation

Common linux dependencies:

    sudo apt-get install make automake cmake curl g++-multilib libtool binutils-gold bsdmainutils pkg-config python3

For linux ARM cross compilation:

    sudo apt-get install g++-arm-linux-gnueabihf binutils-arm-linux-gnueabihf

For linux AARCH64 cross compilation:

    sudo apt-get install g++-aarch64-linux-gnu binutils-aarch64-linux-gnu

For linux RISC-V 64-bit cross compilation (there are no packages for 32-bit):

    sudo apt-get install g++-riscv64-linux-gnu binutils-riscv64-linux-gnu

RISC-V known issue: gcc-7.3.0 and gcc-7.3.1 result in a broken `test_pivx` executable (see https://github.com/bitcoin/bitcoin/pull/13543),
this is apparently fixed in gcc-8.1.0.

### Dependency Options
The following can be set when running make: make FOO=bar

    SOURCES_PATH: downloaded sources will be placed here
    BASE_CACHE: built packages will be placed here
    SDK_PATH: Path where sdk's can be found (used by macOS)
    FALLBACK_DOWNLOAD_PATH: If a source file can't be fetched, try here before giving up
    NO_QT: Don't download/build/cache qt and its dependencies
    NO_WALLET: Don't download/build/cache libs needed to enable the wallet
    NO_UPNP: Don't download/build/cache packages needed for enabling upnp
    DEBUG: disable some optimizations and enable more runtime checking
    HOST_ID_SALT: Optional salt to use when generating host package ids
    BUILD_ID_SALT: Optional salt to use when generating build package ids

If some packages are not built, for example `make NO_WALLET=1`, the appropriate
options will be passed to bitcoin's configure. In this case, `--disable-wallet`.

### Additional targets

    download: run 'make download' to fetch all sources without building them
    download-osx: run 'make download-osx' to fetch all sources needed for macOS builds
    download-win: run 'make download-win' to fetch all sources needed for win builds
    download-linux: run 'make download-linux' to fetch all sources needed for linux builds

### Other documentation

- [description.md](description.md): General description of the depends system
- [packages.md](packages.md): Steps for adding packages

