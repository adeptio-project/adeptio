##HyperSend Technical Information

HyperSend has been integrated into the Core Daemon in two ways:
* "push" notifications (ZMQ and `-hypersendnotify` cmd-line/config option);
* RPC commands.

####ZMQ

When a "Transaction Lock" occurs the hash of the related transaction is broadcasted through ZMQ using both the `zmqpubrawtxlock` and `zmqpubhashtxlock` channels.

* `zmqpubrawtxlock`: publishes the raw transaction when locked via HyperSend
* `zmqpubhashtxlock`: publishes the transaction hash when locked via HyperSend

This mechanism has been integrated into Bitcore-Node-ADE which allows for notification to be broadcast through Insight API in one of two ways:
* WebSocket: [https://github.com/ADE-Project/insight-api-adeptio#web-socket-api](https://github.com/ADE-Project/insight-api-adeptio#web-socket-api) 
* API: [https://github.com/ADE-Project/insight-api-adeptio#hypersend-transactions](https://github.com/ADE-Project/insight-api-adeptio#hypersend-transactions) 

####Command line option

When a wallet HyperSend transaction is successfully locked a shell command provided in this option is executed (`%s` in `<cmd>` is replaced by TxID):

```
-hypersendnotify=<cmd>
```

####RPC

Details pertaining to an observed "Transaction Lock" can also be retrieved through RPC, it’s important however to understand the underlying mechanism.

By default, the Adeptio Core daemon will launch using the following constant:

```
static const int DEFAULT_HYPERSEND_DEPTH = 5;
```

This value can be overridden by passing the following argument to the Adeptio Core daemon:

```
-hypersenddepth=<n>
```

The key thing to understand is that this value indicates the number of "confirmations" a successful Transaction Lock represents. When Wallet RPC commands are performed (such as `listsinceblock`) this attribute is taken into account when returning information about the transaction. The value in `confirmations` field you see through RPC is showing the number of `"Blockchain Confirmations" + "HyperSend Depth"` (assuming the funds were sent via HyperSend).

There is also a field named `bcconfirmations`. The value in this field represents the total number of `"Blockchain Confirmations"` for a given transaction without taking into account whether it was HyperSend or not.

**Examples**
* HyperSend transaction just occurred:
    * confirmations: 5
    * bcconfirmations: 0
* HyperSend transaction received one confirmation from blockchain:
    * confirmations: 6
    * bcconfirmations: 1
* non-HyperSend transaction just occurred:
    * confirmations: 0
    * bcconfirmations: 0
* non-HyperSend transaction received one confirmation from blockchain:
    * confirmations: 1
    * bcconfirmations: 1
