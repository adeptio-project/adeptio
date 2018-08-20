Setup cold masternode using all in one script
====================

Cold masternode meaning
---------------------
Cold masternode requires 10 000 ADE in your cold wallet. This is more safer, but a bit harder to setup.

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

Installation can take up to ~60 minutes. Let's begin:

1. First of all you need to open your Cold Wallet with Graphical user interface. It can be Linux or Windows it doesn't matter. 

2. When wait for wallet sync' 100%.

![Alt text](https://explorer.adeptio.cc/images/doc/1.png)

3. Make sure you have **10 000** ADE or more in your wallet.

4. Click Tools > Debug Console

4. Type in to Console: ***getnewaddress***

![Alt text](https://explorer.adeptio.cc/images/doc/2.png)

5. **Copy new address** from the console output (this is your new wallet address).

6. Send exactly **10 000** ADE to this copied address. You can send it from GUI (if you want) or just use command to console: ***sendtoaddress ThisIsYourCopiedWalletAddress 10000***

![Alt text](https://explorer.adeptio.cc/images/doc/3.png)

7. You will get the output which should be the same if you type: ***masternode outputs***

![Alt text](https://explorer.adeptio.cc/images/doc/4.png)

8. Copy **"masternode outputs" content to notepad** (we will need it later on)

9. Typing to the console once again: ***masternode genkey***

![Alt text](https://explorer.adeptio.cc/images/doc/5.png)

10. This will output the masternode private key. **Copy this to notepad.**

11. Close the Cold Wallet. We need to edit the config file in adeptio content folder.

11a. For Linux open a file: ***~/.adeptio/adeptio.conf***

11b. For Windows open a file: ***C:\Users\{Your User Name}\AppData\Roaming\ADE\adeptio.conf***

12. Paste at the bottom and save the file:
***masternode=1
masternodeprivkey={PasteYourMasternodeGenkeyOutputHere}***

![Alt text](https://explorer.adeptio.cc/images/doc/6.png)

13. Open another file in the same 11a or 11b directory. File called: **masternode.conf**

14. We have and example bellow. Please keep in mind that "YourVirtualMachineOrComputerPublicIpAddr" is not your Cold Wallet IP addr, but your Ubuntu Server virtual machine IP addr. After example we will fill the data:


 #Example: mn1 127.0.0.2:9077 93HaYBVUCYjEMeeH1Y4sBGLALQZE1Yc1K64xiqgX37tGBDQL8Xg 2bcd3c84c84f87eaa86e4e56834c92927a07f9e18718810b92e0d0324456a67c 0
***YourMasternodeName YourVirtualMachineOrComputerPublicIpAddr:9077 YourMasternodePrivKeySavedFromNotePad YourMasternodeOutputContentSavedinNotepad 0 or 1***

![Alt text](https://explorer.adeptio.cc/images/doc/7.png)

15. Thats it with cold wallet. Save the file and close it. **Open cold wallet again.**

16. **Login with ssh to your virtual machine**, server or computer where is your Ubuntu 16.04 LTS Server. You can use regular user with sudo rights or root.

![Alt text](https://explorer.adeptio.cc/images/doc/8.png)

17. Copy this line and paste it to the terminal:

```cd ~/ && sudo apt-get install curl -y && bash <(curl -s https://raw.githubusercontent.com/adeptio-project/adeptio/master/scripts/setup_adeptio_cold_masternode_ipv4_v1.0.0.2.sh)```

![Alt text](https://explorer.adeptio.cc/images/doc/9.png)

18. **Follow instructions during setup.** When the setup will be finished try to start a masternode from Cold Wallet. Command to console: ***masternode start-alias YourMasterNodeName***

![Alt text](https://explorer.adeptio.cc/images/doc/10.png)

19. If everything was made **without mistakes** we should see your masternode in "All Masternodes" Tab within ~30 minutes.

20. **Well done!.**
