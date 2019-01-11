# From Latin language // ădeptĭo - act of obtaining, attainment, achievement.

[![Build Status](https://development.adeptio.cc/job/Adeptio-CI-master-Weekly-Build/badge/icon)](https://development.adeptio.cc/job/Adeptio-CI-master-Weekly-Build/)
[![](https://img.shields.io/github/downloads/adeptio-project/adeptio/total.svg)](https://github.com/adeptio-project/adeptio/releases)
[![](https://img.shields.io/github/last-commit/adeptio-project/adeptio.svg)](https://github.com/adeptio-project/adeptio/commits/master)
[![](https://img.shields.io/github/release/adeptio-project/adeptio.svg)](https://github.com/adeptio-project/adeptio/releases)
[![](https://img.shields.io/website-up-down-green-red/https/adeptio.cc.svg?label=adeptio.cc)](https://adeptio.cc)
[![](https://img.shields.io/twitter/follow/adeptioproject.svg?label=Follow&style=social)](https://twitter.com/intent/user?screen_name=adeptioproject)

# What is Adeptio?

Adeptio is a fair cryptocurrency and enables instant payments to anyone, anywhere in the world. Coin uses peer-to-peer technology to operate with no central authority. Adeptio Core combines the best features of different coins in order to create an excellent digital payment asset.

[storADE](https://github.com/adeptio-project/adeptioStorade) service technology with valuable adeptio masternode functionality serves storage & streaming platform for every day usage.

![Alt text](https://github.com/adeptio-project/adeptio/raw/master/logo/1_shadow.png)

For more information see:

https://adeptio.cc

# Development

The master branch is regularly built and tested. Other branches used for upcoming release or test. Although master is not guaranteed to be completely stable.

Continuous integration process can be found at:
https://development.adeptio.cc

# Building process

Use the autogen script to prepare the build environment.

    ./autogen.sh
    ./configure
    make

More information how to build on specific distribution see at: https://wiki.adeptio.cc/books/building-the-wallet

**Precompiled binaries**

Available at GitHub, see https://github.com/adeptio-project/adeptio/releases

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

Burn addr: https://explorer.adeptio.cc/address/APxwmBBBBBBBBBBBBBBBBBBBBBBBCywtwz

# Reward Distribution
Masternode / Stakers / DevFund. Distribution ratio of 60% / 30% / 10% respectively.
<table>
<tr><th>Block Height</th><th>Reward Amount</th><th>Circulating amount</th><th>Development fees</th><th>Algo</th>
<tr><td>Block 2 - 86400</td><td>150 ADE</td><td>~12 960000 ADE</td></td><td>DevFee 0.5%</td><td>POW</td>
<tr><td>Block 86401 - 151200</td><td>125 ADE</td><td>~21 059875 ADE</td></td><td>DevFee 0%</td><td>POW</td>
<tr><td>Block 151201 - 302400</td><td>100 ADE</td><td>~36 179775 ADE</td></td><td>DevFee 0%</td><td>POW</td>
<tr><td>Block 302401 - 345600</td><td>75 ADE</td><td>~39 419 700 ADE</td><td>DevFee 0%</td><td>POW ends</td>
<tr><td>Block 345601 - 388800</td><td>50 ADE</td><td>~41 579 650 ADE</td><td>DevFee 0%</td><td>POS starts</td>
<tr><td>Block 388801 - 475200</td><td>50 ADE</td><td>~45 899 600 ADE</td><td>DevFee 7.5%</td><td>POS</td>
<tr><td>Block 475201 - 518400</td><td>50 ADE</td><td>~48 059 550 ADE</td><td>DevFee 7.5%</td><td>POS</td>
<tr><td>Block 518401 - 561600</td><td>25 ADE</td><td>~49 139 525 ADE</td><td>DevFee 7.5%</td><td>POS</td>
<tr><td>Block 561601 - 604800</td><td>10 ADE</td><td>~49 571 515 ADE</td><td>DevFee 7.5%</td><td>POS</td>
<tr><td>Block 604801 - 1209600</td><td>5 ADE</td><td>~52 595 510 ADE </td><td>DevFee 7.5%</td><td>POS</td>
<tr><td>Block 1209601 - 2419200</td><td>3 ADE</td><td>~56 224 307 ADE </td><td>DevFee 7.5%</td><td>POS</td>
<tr><td>Block 2419201 - 4838400</td><td>2 ADE</td><td>~61 062 705 ADE </td><td>DevFee 7.5%</td><td>POS</td>
<tr><td>Block 4838401 - infinite</td><td>1 ADE</td><td>+ ~0.518M per year </td><td>DevFee 7.5%</td><td>POS</td>
</table>

~3360 days or ~9.199 years to reach 13th reward phase (1 ADE) per block.

![Alt text](https://blog.adeptio.cc/wp-content/uploads/2018/11/68747470733a2f2f6578706c6f7265722e6164657074696f2e63632f696d616765732f6164657074696f5f7265776172645f6469737472692e706e67.png)

# Resources

[Adeptio Website](https://adeptio.cc/)

[Adeptio Blog](https://blog.adeptio.cc/)

[Adeptio Explorer](https://explorer.adeptio.cc/)

[Adeptio Explorer 2](https://blocks.adeptio.cc/)

[Adeptio Exchange](https://crex24.com/exchange/ADE-BTC)

[Adeptio Stats](https://stats.adeptio.cc/)

[Adeptio Wiki](https://wiki.adeptio.cc/)

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

*There is 7.5% dev fee from fixed blocks*

*Development Fee address: https://explorer.adeptio.cc/address/ASpLv9c3UTN6SZXYR29iW46xFGjHRRvPWf*

*Premine: (#1 Block) 50 002 ADE for five init MasterNodes required for succesful network start*

*Five premined masternodes will be burnt after 1 year from init start.*

# Why should I trust in adeptio-project?

Hybrid algorithm ensures the security of network and distributes the rewards among the PoW/PoS and masternodes

We don't own the majority of coin supply, because of no premine

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

_For more information check out our whitepaper at [https://adeptio.cc/whitepaper.pdf](https://adeptio.cc/adeptio_whitepaper_latest.pdf)_
