Setup hot masternode using all in one script
====================

Hot masternode meaning
---------------------
Hot masternode requires 10 000 ADE in your actual masternode wallet. This is less safer, but easier to setup and maintain.

System Requirements
---------------------
* Setup was tested only on Ubuntu 16.04 LTS Server. Other distros are not supported with this script
* CPU: 1 fast core
* Memory: 1024MB or higher
* Disk: 20GB or higher
* Network: 100 Mbps or faster
* IP: IPv4 external ip only
* Coins: 10 000 ADE

Setup
---------------------
**Warning!** Make sure the links are correct and belong to Adeptio project. Don't use third-party links in your setup.

Login with ssh to your virtual machine, server or computer. You can use regular user with sudo rights (safer) or root.

Copy this line and paste it to the terminal:

```cd ~/ && sudo apt-get install curl -y && bash <(curl -s https://raw.githubusercontent.com/adeptio-project/adeptio/master/scripts/setup_adeptio_hot_masternode_ipv4_latest.sh) | tee ~/adeptio_masternode_installation.log```

Follow instructions during setup. Installation can take up to ~30 minutes.
