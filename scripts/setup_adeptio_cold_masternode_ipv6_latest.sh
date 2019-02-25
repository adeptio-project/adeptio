#!/usr/bin/env bash

#:: Adeptio dev team
#:: Copyright // 2018-02-25
#:: Version: v2.1.0.0 heron
#:: Tested on Ubuntu 18.04 LTS Server Bionic & Ubuntu 16.04 LTS Server Xenial!

cat << "ADE"
           _____  ______        ___   __   _    _                                    _                    _____  ______ 
     /\   |  __ \|  ____|      |__ \ /_ | | |  | |                         _        | |             /\   |  __ \|  ____|
    /  \  | |  | | |__    __   __ ) | | | | |__| | ___ _ __ ___  _ __    _| |_   ___| |_ ___  _ __ /  \  | |  | | |__   
   / /\ \ | |  | |  __|   \ \ / // /  | | |  __  |/ _ \ '__/ _ \| '_ \  |_   _| / __| __/ _ \| '__/ /\ \ | |  | |  __|  
  / ____ \| |__| | |____   \ V // /_ _| | | |  | |  __/ | | (_) | | | |   |_|   \__ \ || (_) | | / ____ \| |__| | |____ 
 /_/    \_\_____/|______|   \_/|____(_)_| |_|  |_|\___|_|  \___/|_| |_|         |___/\__\___/|_|/_/    \_\_____/|______|
                                                                                                                        
                                                                                                                        
ADE

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

echo $(date)
echo ""
echo "©Copyright 2017-2019 Adeptio Developer Team"
echo -e "${GREEN}== adeptio v2.1.0.0 ==${NC}"
echo
echo "Good day. This is automated cold masternode setup for adeptio project. Auto installer was tested on specific environment. Don't try to install masternode with undocumented operating system!"
echo ""
echo "Installation content:"
echo "adeptio core v2.1.0.0 + latest storADE platform code"
echo
echo "Setup can be launched only once"
echo "Do you agree?"
echo -e "${GREEN}y${NC}/${RED}n"${NC}?
read agree
            if [ "$agree" != "y" ]; then
               echo "Sorry, we cannot continue" && exit 1
            fi
OS_version=$(cat /etc/lsb-release | grep -c bionic)
OS_version2=$(cat /etc/lsb-release | grep -c xenial)
            if [ "$OS_version" -ne "1" ]; then
                    echo ""
			echo -e "${RED}Looks like your OS version is not Ubuntu 18.04 Bionic //${GREEN} Maybe Ubuntu 16.04 Xenial? - Checking...${NC}"

                        if [ "$OS_version2" -eq "1" ]; then
                                echo ""
                        else
                                echo ""
                                echo -e "${RED}Looks like your OS version is not Ubuntu 16.04 Xenial or Ubuntu 18.04 Bionic${NC}" && exit 1
                        fi
            fi
sudo apt-get update -y
if [ $? -ne "0" ]; then echo -e "${RED}Cannot update ubuntu repos${NC}" && exit 1; fi
sudo apt-get install software-properties-common -y 1> /dev/null
if [ $? -ne "0" ]; then echo -e "${RED}Unable to install software-properties-common${NC}" && exit 1; fi
sudo add-apt-repository universe -y 1> /dev/null
if [ $? -ne "0" ]; then echo -e "${RED}Unable to add repository universe${NC}" && exit 1; fi
sudo apt-get install dnsutils jq curl -y 1> /dev/null
if [ $? -ne "0" ]; then echo -e "${RED}Unable to install dnsutils jq curl${NC}" && exit 1; fi
echo ""
wanipv6=$(curl -s 6.ipquail.com/ip)
if [ -z "${wanipv6}" ]; then
    echo -e "${RED}Sorry, we don't know your external IPv6 addr${NC}" && echo ""
    echo -e "${GREEN}Input your IPv6 addr manually:${NC}" && read wanipv6
fi
echo "Your external IPv6 is $wanipv6 y/n?"
read wan
            if [ "$wan" != "y" ]; then
               echo -e "${RED}Sorry, we don't know your external IPv6 addr${NC}" && exit 1
            fi
# Check if bitcoin repo exists for Bionic //
[ -f /etc/apt/sources.list.d/bitcoin-ubuntu-bitcoin-bionic.list ]
            if [ "$?" -eq "0" ]; then
                    echo ""
                    echo "Looks like you are trying to setup second time? You need a fresh installation!" && exit 1
            fi
# Check if bitcoin repo exists for Xenial //
[ -f /etc/apt/sources.list.d/bitcoin-ubuntu-bitcoin-xenial.list ]
            if [ "$?" -eq "0" ]; then
                    echo ""
                    echo "Looks like you are trying to setup second time? You need a fresh installation!" && exit 1
            fi
if [ "$OS_version" -eq "1" ]; then
# Install dep. for Bionic //
        sudo add-apt-repository ppa:bitcoin/bitcoin -y
	if [ $? -ne "0" ]; then echo "Unable to add bitcoin dependencies" && exit 1; fi
        sudo apt-get update -y
	if [ $? -ne "0" ]; then echo "Cannot update ubuntu repos" && exit 1; fi
        sudo apt-get install -y libdb4.8-dev libdb4.8++-dev
	if [ $? -ne "0" ]; then echo "Unable to install libdb dependencies" && exit 1; fi
        sudo apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev  bsdmainutils software-properties-common libminiupnpc-dev libcrypto++-dev libboost-all-dev libboost-system-dev libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev libboost-filesystem-dev libboost-thread-dev libssl-dev libssl-dev software-properties-common unzip libzmq3-dev ufw wget git python-openssl libevent-dev dialog -y
	if [ $? -ne "0" ]; then echo "Unable to install major dependencies" && exit 1; fi
        else
        sudo add-apt-repository ppa:bitcoin/bitcoin -y
        if [ $? -ne "0" ]; then echo "Unable to add bitcoin dependencies" && exit 1; fi
        sudo apt-get update -y
        if [ $? -ne "0" ]; then echo "Cannot update ubuntu repos" && exit 1; fi
        sudo apt-get install libdb4.8-dev libdb4.8++-dev -y
        if [ $? -ne "0" ]; then echo "Unable to install libdb dependencies" && exit 1; fi
        sudo apt-get install libboost-system1.58-dev libboost-system1.58.0 -y
        if [ $? -ne "0" ]; then echo "Unable to install libboost dependencies" && exit 1; fi
        sudo apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev  bsdmainutils software-properties-common libminiupnpc-dev libcrypto++-dev libboost-all-dev libboost-system-dev libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev libboost-filesystem-dev libboost-thread-dev libssl-dev libssl-dev software-properties-common unzip libzmq3-dev ufw wget git python-openssl libevent-dev -y
        if [ $? -ne "0" ]; then echo "Unable to install major dependencies" && exit 1; fi
        fi
# Download adeptio sources //
echo ""
echo -e "${GREEN}1/10 Downloading adeptio sources...${NC}" 
echo ""
cd ~
rm -fr adeptio*.zip
            if [ "$OS_version" -eq "1" ]; then
                wget https://github.com/adeptio-project/adeptio/releases/download/v2.1.0.0/adeptiod-v2.1.0.0-linux64.zip
		if [ $? -ne "0" ]; then echo "Failed to download adeptiod binary" && exit 1; fi
            elif [ "$OS_version2" -eq "1" ]; then
                wget https://github.com/adeptio-project/adeptio/releases/download/v2.1.0.0/adeptiod-v2.1.0.0-linux64-legacy.zip
		if [ $? -ne "0" ]; then echo "Failed to download adeptiod binary" && exit 1; fi
            fi
# Manage coin daemon and configuration //
unzip -o adeptio*.zip
echo ""
sudo cp -fr adeptio-cli adeptiod /usr/bin/
rm -fr adeptio-cli adeptiod adeptio-tx
mkdir -p ~/.adeptio/
touch ~/.adeptio/adeptio.conf
cat << EOF > ~/.adeptio/adeptio.conf
rpcuser=adeptiouser
rpcpassword=$(head /dev/urandom | tr -dc A-Za-z0-9 | head -c 32 ; echo '')
rpcallow=127.0.0.1
server=1
listen=1
daemon=1
staking=1
bind=[$wanipv6]
EOF

#Create adeptiocore.service
echo -e "${GREEN}2/10 Create adeptiocore.service for systemd${NC}"
echo ""
echo \
"[Unit]
Description=Adeptio Core Wallet daemon & service
After=network.target

[Service]
User=root
Type=forking
ExecStart=/usr/bin/adeptiod -daemon -pid=$(echo $HOME)/.adeptio/adeptiod.pid --datadir=$(echo $HOME)/.adeptio/
PIDFile=$(echo $HOME)/.adeptio/adeptiod.pid
ExecStop=/usr/bin/adeptio-cli stop
Restart=always
RestartSec=3600
TimeoutStopSec=60s
TimeoutStartSec=10s
StartLimitInterval=120s
StartLimitBurst=5

[Install]
WantedBy=default.target" | sudo tee /etc/systemd/system/adeptiocore.service

sudo chmod 664 /etc/systemd/system/adeptiocore.service

sudo systemctl enable adeptiocore

real_user=$(echo $USER) 

sudo chown -R $real_user:$real_user $(echo $HOME)/.adeptio/

# Check if user is root? If not create sudoers files to manage systemd services
echo ""
echo -e "${GREEN}3/10 Check if user is root? If not create sudoers files to manage systemd services${NC}"
if [ "$EUID" -ne 0 ]; then
sudo echo \
"%$real_user ALL= NOPASSWD: /bin/systemctl start adeptiocore
%$real_user ALL= NOPASSWD: /bin/systemctl stop adeptiocore
%$real_user ALL= NOPASSWD: /bin/systemctl restart adeptiocore
%$real_user ALL= NOPASSWD: /bin/systemctl start storADEserver
%$real_user ALL= NOPASSWD: /bin/systemctl stop storADEserver
%$real_user ALL= NOPASSWD: /bin/systemctl restart storADEserver" | sudo tee /tmp/$real_user
sudo mv /tmp/$(echo $real_user) /etc/sudoers.d/
fi

# Start adeptio daemon, wait for wallet creation //
sudo systemctl start adeptiocore &&
echo "" ; echo "Please wait for few minutes..."
sleep 120 &
PID=$!
i=1
sp="/-\|"
echo -n ' '
while [ -d /proc/$PID ]
do
  printf "\b${sp:i++%${#sp}:1}"
done
echo ""
sudo systemctl stop adeptiocore &&
echo ""
echo -e "Shutting down daemon, reconfiguring adeptio.conf, we want to know your cold wallet ${GREEN}masternodeprivkey${NC} (example: 7UwDGWAKNCAvyy9MFEnrf4JBBL2aVaDm2QzXqCQzAugULf7PUFD), please input now:"
echo""
read masternodeprivkey
privkey=$(echo $masternodeprivkey)
checkpriv_key=$(echo $masternodeprivkey | wc -c)
if [ "$checkpriv_key" -ne "52" ];
then
	echo ""
	echo "Looks like your $privkey is not correct, it should cointain 52 symbols, please paste it one more time"
	read masternodeprivkey
privkey=$(echo $masternodeprivkey)
checkpriv_key=$(echo $masternodeprivkey | wc -c)

if [ "$checkpriv_key" -ne "52" ];
then
        echo "Something wrong with masternodeprivkey, cannot continue" && exit 1
fi
fi
echo ""
echo "Give some time to shutdown the wallet..."
echo ""
sleep 60 &
PID=$!
i=1
sp="/-\|"
echo -n ' '
while [ -d /proc/$PID ]
do
  printf "\b${sp:i++%${#sp}:1}"
done
cat << EOF > ~/.adeptio/adeptio.conf
rpcuser=adeptiouser
rpcpassword=$(head /dev/urandom | tr -dc A-Za-z0-9 | head -c 32 ; echo '')
rpcallow=127.0.0.1
server=1
listen=1
daemon=1
staking=1
maxconnections=256
masternode=1
bind=[$wanipv6]
masternodeaddr=[$wanipv6]:9077
externalip=[$wanipv6]
masternodeprivkey=$privkey
enablezeromint=0
EOF

# Firewall //
echo -e "${GREEN}4/10 Update firewall rules${NC}"
echo ""
sudo /usr/sbin/ufw limit ssh/tcp comment 'Rate limit for openssh server' 
sudo /usr/sbin/ufw allow 9077/tcp comment 'Adeptio Wallet daemon'
sudo /usr/sbin/ufw allow 9079/tcp comment 'Adeptio storADEserver protocol TCP'
sudo /usr/sbin/ufw allow 9079/udp comment 'Adeptio storADEserver protocol UDP'
sudo /usr/sbin/ufw --force enable
echo ""

#Create storADEserver service for systemd
echo -e "${GREEN}5/10 Create storADEserver service for systemd${NC}"
echo ""
sudo echo \
"[Unit]
Description=Adeptio storADEserver daemon for encrypted file storage
After=network.target

[Service]
User=$USER
Type=simple
WorkingDirectory=$HOME/adeptioStorade
ExecStart=$(which python) $HOME/adeptioStorade/storADEserver.py
Restart=always
RestartSec=3600

[Install]
WantedBy=default.target" | sudo tee /etc/systemd/system/storADEserver.service

sudo chmod 664 /etc/systemd/system/storADEserver.service

# Download storADEserver files from Github;
echo ""
echo -e "${GREEN}6/10 Downloading storADEserver files from Github...${NC}"
echo ""
cd ~/
git clone https://github.com/adeptio-project/adeptioStorade.git

sudo systemctl enable storADEserver.service
sudo systemctl start storADEserver.service
sudo systemctl daemon-reload

cd ~/adeptioStorade
sudo chmod +x ~/adeptioStorade/storADEserver-updater.sh
sudo chown -R $real_user:$real_user ~/adeptioStorade/
sudo chown -R $real_user:$real_user ~/adeptioStorade/.git/

# Start daemon after reboot // Systemd take care of this;
echo -e "${GREEN}7/10 Create auto updater for storADEserver${NC}"
echo ""
echo \
"[Unit]
Description=storADEupdater.service
 
[Service]
Type=oneshot
WorkingDirectory=$HOME/adeptioStorade
ExecStart=$HOME/adeptioStorade/storADEserver-updater.sh
PrivateTmp=true

[Install]
WantedBy=timers.target" | sudo tee /etc/systemd/system/storADEupdater.service

echo ""
echo -e "${GREEN}8/10 Create timer for storADEupdater service${NC}"
echo ""
echo \
"[Unit]
Description=Run storADEupdater unit daily @ 00:00:00 (UTC)
 
[Timer]
OnCalendar=*-*-* 00:00:00
Unit=storADEupdater.service
Persistent=true
 
[Install]
WantedBy=timers.target" | sudo tee /etc/systemd/system/storADEupdater.timer

echo ""
echo -e "${GREEN}9/10 Adjusting systemd services please wait...${NC}"
echo ""

sudo chmod 664 /etc/systemd/system/storADEupdater.service
sudo chmod 664 /etc/systemd/system/storADEupdater.timer

sudo systemctl start storADEupdater.service
sudo systemctl start storADEupdater.timer
sudo systemctl enable storADEupdater.service
sudo systemctl enable storADEupdater.timer

# Final start
echo ""
echo -e "${GREEN}10/10 Masternode config done, storADE platform installed - starting adeptiocore again${NC}"
echo ""
sudo systemctl start adeptiocore
echo -e "${RED}The blockchain is syncing from scratch. You have to wait few hours to sync all the blocks!${NC}"
echo ""
echo "Setup summary:"
echo "Masternode privkey: $privkey"
echo "Your external IPv6 addr: $wanipv6"
echo "Installation log: ~/adeptio_masternode_installation.log"
echo "storADE datadir: "$(echo $HOME/adeptioStorade/)"" 
echo "Adeptio Core datadir: "$(echo $HOME/.adeptio/)""
echo ""
echo "In order to start a masternode from Cold Wallet check your current block with explorer block by typing in the terminal:"
echo -e "${GREEN}adeptio-cli getinfo | grep blocks${NC}"
echo "https://explorer.adeptio.cc/api/getblockcount"
echo ""
echo "Please start a masternode from Cold Wallet if explorer.adeptio.cc block matches with yours."
echo "Overall setup completed successfully"
echo -e "Need additional help? Please visit adeptio Discord channel: ${GREEN}https://discord.adeptio.cc${NC}"
echo ""
echo -e "${GREEN}©2018-2019 powered by adeptio-project${NC}"
