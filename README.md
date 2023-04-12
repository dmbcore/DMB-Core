Token Of Digital Money [DMB] 2023
===========================================================================================

http://dmbchain.one/

What is the Token Of Digital Money [DMB] Blockchain?
-----------------------------------------

### Overview
Token Of Digital Money is a blockchain project.

### Blockchain Technology
The Token Of Digital Money [DMB] Blockchain is an experimental smart contract platform that enables 
instant payments to anyone, anywhere in the world in a private, secure manner. 
Token Of Digital Money [DMB] uses peer-to-peer blockchain technology to operate
with no central authority: managing transactions, execution of contracts, and 
issuing money are carried out collectively by the network.

### Custom Difficulty Retarget Algorithm “VRX”
VRX is designed from the ground up to integrate properly with the Velocity parameter enforcement system to ensure users no longer receive orphan blocks.

### Velocity Block Constraint System
Ensuring Token Of Digital Money stays as secure and robust as possible, we have implemented what's known as the Velocity block constraint system. This system acts as a third and final check for both mined and peer-accepted blocks, ensuring that all parameters are strictly enforced.

### Demi-Nodes
Our network now operates by using "Demi-nodes" to help the wallet make informed decisions on how to treat a peer in the network or even other nodes that aren't trusted. Demi-nodes are a list of trusted nodes a user can define inside of the wallet. These user-defined trusted nodes then can be queried for specific data such as asking the Demi-node network wether or not a reorganization request from another peer is a valid one or something that should be rejected and then banned off the network to protect other peers. An adaptive self cleaning network as this continiously defends itself from any possible intrusion or attack while still keeping decentralization as the underlying focus by allowing users to define their own lists. This feature compliments the Velocity security system which goes beyond other blockchain's security methods to ensure no possibility of malformed blocks making it onto the chain even with something like a 51% attack.

### Wish (bmw512) Proof-of-Work Algorithm
Wish or bmw512 hashing algorithm is utilized for the Proof-of-Work function and also replaces much of the underlying codebase hashing functions as well that normally are SHA256. By doing so this codebase is able to be both exponentially lighter and more secure in comparison to reference implementations.

Specifications and General info
------------------
Token Of Digital Money uses 

	libsecp256k1
	libgmp
	Boost1.74, OR Boost1.6+
	Openssl1.02u, OR OpenSSL1.1.1q, OR OpenSSL3.0.5
	Berkeley DB 6.2.32
	QT5.15.2 (for GUI)


General Specs

	Name: 		 	  Token of Digital Money
	Max coin supply:          280,000,000 (280-million DMB)
	Premine Coin Count:       (15%) = 42 Million DMB
	Algorithm:                Wish (bmw512)
	Block Reward:             1.1 DMB (0.2-PoW/PoS, 0.6-Masternodes, 0.3-DevOps)
	Ticker:                   DMB
	Type:                     Proof of Stake (PoS) + Proof of Work (PoW) + Masternodes
	Peer port:                32623
	RPC port:                 32624
	Block Spacing:            1-minute
	Relayed Txn Depth:        5-blocks (sent or received Txn)
	Min. Staking Depth:       30-blocks (Relayed Txn)
	Mined Txn Depth:          20-blocks
	Masternode Collateral:	  50,000 DMB

	Masternodes help secure the Token Of Digital Money [DMB] network by making it
	more decentralized, providing a consensus for every transaction, and
	other extended features such as private messaging and so on.
	For providing these important services, Masternodes owners are
	rewarded a portion of each block.


BUILD LINUX
-----------
### Compiling Token Of Digital Money "SatoshiCore" daemon on Ubuntu 22.04 LTS (Jammy Jellyfish)
### Note: guide should be compatible with other Ubuntu versions from 14.04+

### Become poweruser
```
sudo -i
```
### CREATE SWAP FILE FOR DAEMON BUILD (if system has less than 2GB of RAM)
```
cd ~; sudo fallocate -l 3G /swapfile; ls -lh /swapfile; sudo chmod 600 /swapfile; ls -lh /swapfile; sudo mkswap /swapfile; sudo swapon /swapfile; sudo swapon --show; sudo cp /etc/fstab /etc/fstab.bak; echo '/swapfile none swap sw 0 0' | sudo tee -a /etc/fstab
```

### Dependencies install
```
cd ~; sudo apt-get install -y ntp git build-essential libssl-dev libdb-dev libdb++-dev libboost-all-dev libqrencode-dev libcurl4-openssl-dev curl libzip-dev; apt-get update -y; apt-get install -y git make automake build-essential libboost-all-dev; apt-get install -y yasm binutils libcurl4-openssl-dev openssl libssl-dev; sudo apt-get install -y libgmp-dev; sudo apt-get install -y libtool;
```

### Dependencies build and link
```
cd ~; wget http://download.oracle.com/berkeley-db/db-6.2.32.NC.tar.gz; tar zxf db-6.2.32.NC.tar.gz; cd db-6.2.32.NC/build_unix; ../dist/configure --enable-cxx --disable-shared; make; sudo make install; sudo ln -s /usr/local/BerkeleyDB.6.2/lib/libdb-6.2.so /usr/lib/libdb-6.2.so; sudo ln -s /usr/local/BerkeleyDB.6.2/lib/libdb_cxx-6.2.so /usr/lib/libdb_cxx-6.2.so; export BDB_INCLUDE_PATH="/usr/local/BerkeleyDB.6.2/include"; export BDB_LIB_PATH="/usr/local/BerkeleyDB.6.2/lib"
```

### GitHub pull (Source Download)
```
cd ~; git clone https://github.com/dmbcore/DMB-Core TokenOfDigitalMoney
```

### Build TokenOfDigitalMoney daemon
```
cd ~; cd ~/TokenOfDigitalMoney/src; chmod a+x obj; chmod a+x leveldb/build_detect_platform; chmod a+x secp256k1; chmod a+x leveldb; chmod a+x ~/TokenOfDigitalMoney/src; chmod a+x ~/TokenOfDigitalMoney; make -f makefile.unix USE_UPNP=-; cd ~; cp -r ~/TokenOfDigitalMoney/src/TokenOfDigitalMoneyd /usr/local/bin/TokenOfDigitalMoneyd;
```

### Create config file (for daemon, DO NOT USE FOR QT)
```
cd ~; sudo ufw allow 32623/tcp; sudo ufw allow 32624/tcp; sudo ufw allow 22/tcp; sudo mkdir ~/.DMB; cat << "CONFIG" >> ~/.DMB/TokenOfDigitalMoney.conf
listen=1
server=1
daemon=1
deminodes=1
demimaxdepth=200
testnet=0
rpcuser=DMBrpcuser
rpcpassword=SomeCrazyVeryVerySecurePasswordHere
rpcport=32624
port=32623
rpcconnect=127.0.0.1
rpcallowip=127.0.0.1
addnode=172.104.177.206:32623
addnode=45.56.105.176:32623
CONFIG
chmod 700 ~/.DMB/TokenOfDigitalMoney.conf; chmod 700 ~/.DMB; ls -la ~/.DMB
```

### Run TokenOfDigitalMoney daemon
```
cd ~; TokenOfDigitalMoneyd; TokenOfDigitalMoneyd getinfo
```

### (Optional) Build TokenOfDigitalMoney-QT (GUI wallet) on Linux 

**All previous steps must be completed first.**
(If you recompiling some other time you don't have to repeat previous steps.)

Install Qt dependencies:
```
sudo apt-get install -y qtcreator qtbase5-dev qttools5-dev qttools5-dev-tools qt5-qmake cmake
```

Install extended dependencies:
```
sudo apt-get install -y autoconf autotools-dev pkg-config zlib1g-dev
```

Qt Dependencies build and link (1 of 2):
```
wget https://ppa.launchpadcontent.net/linuxuprising/libpng12/ubuntu/pool/main/libp/libpng/libpng_1.2.54.orig.tar.xz; tar Jxfv libpng_1.2.54.orig.tar.xz; cd ~/libpng-1.2.54; ./configure; make; sudo make install; cd ~; sudo ln -s /usr/local/lib/libpng12.so.0.54.0 /usr/lib/libpng12.so; sudo ln -s /usr/local/lib/libpng12.so.0.54.0 /usr/lib/libpng12.so.0
```
Qt Dependencies build and link (2 of 2):
```
wget https://fukuchi.org/works/qrencode/qrencode-4.0.2.tar.gz; tar zxfv qrencode-4.0.2.tar.gz; cd ~/qrencode-4.0.2; ./configure; make; sudo make install; sudo ldconfig
```

Ubuntu Legacy Patch (Ubuntu 18.04 and older)
```
sudo apt-get install -y libevent-dev
cp -r ~/TokenOfDigitalMoney/src/qt/forms/signverifymessagedialog.ui.legacy_qt ~/TokenOfDigitalMoney/src/qt/forms/signverifymessagedialog.ui
cp -r ~/TokenOfDigitalMoney/src/qt/forms/rpcconsolesettings.ui.legacy_qt ~/TokenOfDigitalMoney/src/qt/forms/rpcconsolesettings.ui
cp -r ~/TokenOfDigitalMoney/src/qt/forms/rpcconsole.ui.legacy_qt ~/TokenOfDigitalMoney/src/qt/forms/rpcconsole.ui
```

Build TokenOfDigitalMoney Qt
```
cd ~/TokenOfDigitalMoney; qmake -qt=qt5 USE_UPNP=-; make
```

### Troubleshooting
### for basic troubleshooting run the following commands when compiling:
### this is for minupnpc errors compiling

```
make clean -f makefile.unix USE_UPNP=-
make -f makefile.unix USE_UPNP=-
```
### Updating daemon in bin directory
```
cd ~; cp -r ~/TokenOfDigitalMoney/src/TokenOfDigitalMoneyd /usr/local/bin
```

License
-------

Token Of Digital Money [DMB] is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/SaltineChips/TokenOfDigitalMoney/Tags) are created
regularly to indicate new official, stable release versions of TokenOfDigitalMoney [DMB].

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

The developer [mailing list](https://lists.linuxfoundation.org/mailman/listinfo/bitcoin-dev)
should be used to discuss complicated or controversial changes before working
on a patch set.


Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](/doc/unit-tests.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`

There are also [regression and integration tests](/qa) of the RPC interface, written
in Python, that are run automatically on the build server.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.
