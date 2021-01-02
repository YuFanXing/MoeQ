Language: **`English`** [`简体中文`](https://github.com/YuFanXing/MoeQ/blob/master/README_ZH.md)

# Brief Introduction

***MoeQ*** is *a QQ robot* based on *Android QQ 8.4.1*.

It is still a *semi-finished product* now. If you want a *ready-made robot* frame, please go to the next door [mirai](https://www.google.com).

Because of busy school, I can't spare time to continue updating this project on my own, so I opened sources.

**Wish you can make it better!**


# Achieved


## Protocol

1. Log in and sign out.

2. Get friends and groups list.

2. Receive some group messages and private messages.

3. Send part of group messages and private messages.

4. Draw group message.

5. Do some friend and group actions.

6. ...


## Plugin System

1. Enable and disable.

2. Right control.

3. [C++ sdk](https://github.com/YuFanXing/mqcppsdk).

4. ...


# Features Under Way

1. Some memory leak.
2. Support image message and voice message.
3. Fix bugs.
4. Update protocol version.
5. Plugin management.
6. Plugin store.
8. ...

# Files Usage

`./include` Include the head files of dependencies.

`./lib` Include the static link library of dependencies.

`./MoeQ` Include source code of this project.



`./MoeQ/MoeQ.cpp` The entrance of the program.

`./MoeQ/MainFrm.cpp` The main window of UI.

`./MoeQ/Android.cpp` `./MoeQ/Tim.cpp` The protocol of *QQ*.

`./MoeQ/PluginSystem.cpp` The plugins control system.

`./MoeQ/ExportFunction.cpp` The export functions to plugins.

`./MoeQ/Utils.cpp` Include encode, compress, algorithm and some tools.

`./MoeQ/Protobuf.cpp` `./MoeQ/JceStruct.cpp` `./MoeQ/Pack.cpp` Include some packing measures.

# Protocol

**If you want to help us improve or expand features, you should learn the following.**

But, you **CAN'T** add features like *send or receive red envelopes*.

### *Android QQ 8.4.1* Protocol

`./MoeQ/Android.cpp`

|               Function Name               |              Usage              |
| :---------------------------------------: | :-----------------------------: |
|          Android::Fun_Send_Sync           |   send a packet synchronously   |
|            Android::Fun_Handle            | handle server broadcast message |
|          Android::Fun_Life_Event          |        life cycle event         |
|     Android::Make_Body_Request_Packet     |     pack jce struct packet      |
|       Android::MessageSvc_PbGetMsg        |       get private message       |
| Android::Unpack_OnlinePush_PbPushGroupMsg |        get group message        |
| Android::Unpack_OnlinePush_PbPushTransMsg |    get group action message     |
|   Android::Unpack_MessageSvc_PushNotify   |       get private message       |

### *Tim 3.3.1* Protocol

`./MoeQ/Tim.cpp`

|           Function Name           |              Usage              |
| :-------------------------------: | :-----------------------------: |
|      Android::Fun_Send_Sync       |   send a packet synchronously   |
|        Android::Fun_Handle        | handle server broadcast message |
|      Android::Fun_Life_Event      |        life cycle event         |
| Android::Make_Body_Request_Packet |     pack jce struct packet      |

# Example

If you just want to use the protocol,  following is the simplest way of using the *Android* class.

```c++
#include "Android.h"

Android Sdk("861891778567", "460013521635791", (const byte*)"\x86\xA4\x45\xBF\x44\xA2\xC2\x87\x59\x76\x18\xF6\xF3\x6E\xB6\x8C", (const byte*)"\0\0\0\0\0\2", "XiaoMi", "MIX Alpha");
Sdk.QQ_Init("10001");
int state = Sdk.QQ_Login("Password");
if (state == LOGIN_SUCCESS)
    Sdk.QQ_Online();  //you log in successfully
```

# Dependencies

Thanks to the following projects for making this project greater!

1. ***[rapidjson](https://github.com/Tencent/rapidjson)***

2. ***miniblink***
3. ***[openssl](https://github.com/openssl/openssl)***
4. ***zlib***
5. ***[curl](https://github.com/curl/curl)***

**If it is not necessary,  please don't add more dependencies.**

