# From Latin language // ădeptĭo - act of obtaining, attainment, achievement.

![Alt text](https://github.com/adeptio-project/adeptio/blob/master/logo/adeptio_loading.png)

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

![Alt text](https://explorer.adeptio.cc/images/adeptio_reward_distri.png)

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

[Adeptio FaceBook](https://www.facebook.com/AdeptioProject-1637877816511858)

[Adeptio Twitter](https://twitter.com/adeptioproject)

[Adeptio Gitter](https://gitter.im/adeptiocoin/Lobby?utm_source=share-link&utm_medium=link&utm_campaign=share-link)

[Adeptio Telegram](https://t.me/adeptiocoin)

[Adeptio Reddit](https://www.reddit.com/r/Adeptio/)

# Developers Funds

~~No premine was made*. There is only 0.5% dev fee from fixed blocks.~~

*Premine: (#1 Block) 50 002 ADE for five init MasterNodes required for succesful network start*

*Five premined masternodes will be burnt after 1 year from init start.*

# Why should I trust in adeptio-project?

Hybrid algorithm ensures the security of network and distributes the rewards among the PoW/PoS and masternodes

We don't own the majority of coin supply, because no premine was made

StorADE system functionality makes adeptio unique project

Long term support (probably no coin swap ever)

No Bounties (except for translations)

There was a fair start for everyone.

No Airdrops

No Presale

No ICO

# What's the difference between adeptio and other cryptocurrencies?

You should check our [whitepaper](https://github.com/adeptio-project/adeptio#further-information). Our long term goal is to use adeptio as a base core blockchain.

# Who is adeptio team?

Our core team consist of young members with passion for blockchain technology and fintech revolution.

# Acknowledgements

Credit goes to Bitcoin Core, Dash and Pivx for providing a basic platform for Adeptio to enhance and develop, in concert with a shared desire to support the adoption of a decentralised digital currency future for the masses.

# Code issues
Since we are a 100% open-source project we strongly prefer if you create a pull-request on Github in the proper repository with the necessary fix. Alternatively, If you would like to make a suggestion regarding a potential fix please send an email to development@adeptio.cc

# License

Adeptio is released under the terms of the MIT license. See [COPYING](https://raw.githubusercontent.com/adeptio-project/adeptio/master/COPYING) or for more information:

[https://opensource.org/licenses/MIT](URL)

# Further information

_For more information check out our whitepaper at [https://adeptio.cc/whitepaper.pdf](https://dev.adeptio.cc/adeptio_whitepaper_v1.0.0.1.pdf)_
