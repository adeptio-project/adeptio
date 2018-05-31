#!/usr/bin/env bash

#:: Adeptio dev team
#:: Copyright // 2018-06-01
#:: Version: v1.0.0.1
#:: Tested on Ubuntu 16.04 LTS Server Xenial only!

echo "== adeptio v1.0.0.1 =="
echo
echo "Good day. This is automated hot masternode setup for adeptio coin. Auto installer was tested on specific environment. Don't try to install masternode with undocumented operating system!"
echo
echo "Do you agree? y/n"
read agree
            if [ "$agree" != "y" ]; then
               echo "Sorry, we cannot continue" && exit 1
            fi
wanip=$(/usr/bin/dig +short myip.opendns.com @resolver1.opendns.com)
echo "Your external IP is $wanip y/n?"
read wan
            if [ "$wan" != "y" ]; then
               echo "Sorry, we don't know your external IP" && exit 1
            fi
# Check if bitcoin repo exists //
repo=$(cat /etc/apt/sources.list | grep -c bitcoin)
            if [ "$repo" -ne "0" ]; then
                    echo ""
                    echo "Looks like you are trying to setup second time? You need a fresh installation!" && exit 1
            fi
sudo bash -c 'cat << EOF >> /etc/apt/sources.list
deb http://ppa.launchpad.net/bitcoin/bitcoin/ubuntu xenial main
EOF'
# Install dep. //
sudo apt-get update
sudo apt-get install libdb4.8-dev libdb4.8++-dev -y
sudo apt-get install libboost-system1.58-dev libboost-system1.58.0 -y
sudo apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev  bsdmainutils software-properties-common libminiupnpc-dev libdb++-dev libdb-dev libcrypto++-dev libboost-all-dev libboost-system-dev libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev libboost-filesystem-dev libboost-thread-dev libssl-dev libdb++-dev libssl-dev ufw git software-properties-common unzip libzmq3-dev ufw wget -y

# Download adeptio sources //
cd ~
rm -fr adeptio*.zip
wget https://github.com/adeptio-project/adeptio/releases/download/v1.0.0.1/adeptiod.zip

# Manage coin daemon and configuration //
unzip -o adeptio*.zip
echo ""
sudo cp -fr adeptio-cli adeptiod /usr/bin/
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
EOF

# Start adeptio daemon, wait for wallet creation and get the masterprivkey and addr where to send 10 000 ADE
/usr/bin/adeptiod --daemon &&
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
masternodeaddr=$(/usr/bin/adeptio-cli getnewaddress)
masternodeprivkey=$(/usr/bin/adeptio-cli masternode genkey)
echo ""
echo "Your masternode wallet addr is -: $masternodeaddr :- Send exactly 10 000 ADE to this address"
masternodeprivkey=$(/usr/bin/adeptio-cli masternode genkey)
/usr/bin/adeptio-cli stop &&
echo ""
echo "Shutting down daemon, reconfiguring adeptio.conf, adding masternodeprivkey and enabling masternode option"
echo "Give some time to shutdown wallet..."
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
maxconnections=125
masternode=1
masternodeaddr=$wanip:9077
externalip=$wanip
masternodeprivkey=$masternodeprivkey
EOF

# Firewall
sudo /usr/sbin/ufw limit ssh/tcp comment 'Rate limit for openssh serer'
sudo /usr/sbin/ufw allow 9077/tcp
sudo /usr/sbin/ufw --force enable

# Start daemon after reboot
crontab -l | { cat; echo "@reboot /usr/bin/adeptio --daemon"; } | crontab -

# Final start
echo "Masternode config done, starting daemon again"
/usr/bin/adeptiod --daemon
echo ""
echo "Setup completed. You have to wait 15 confirmations right now"
echo ""
echo "Setup summary:"
echo "Masternode Wallet Addr: $masternodeaddr"
echo "Masternode privkey: $masternodeprivkey"
echo "Your external IP: $wanip"
echo "" ; echo "Verifying blocks Please wait..."
sleep 120 &
PID=$!
i=1
sp="/-\|"
echo -n ' '
while [ -d /proc/$PID ]
do
  printf "\b${sp:i++%${#sp}:1}"
done
echo "You can check the status of masternode:"
echo "adeptio-cli masternode status"
