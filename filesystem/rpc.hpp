#ifndef _RPC_
#define _RPC_
#include "error.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>


class RPC{
public: 
	RPC();
	~RPC();
	int connect(const char* host, int port);
	void disconnect();
	int call(int inode_num,int flags);
private:
	int sock
};

#endif