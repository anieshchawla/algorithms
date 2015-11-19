#ifndef _INTERNAL_FUNCTIONS
#define _INTERNAL_FUNCTIONS
#include <fuse.h>
#include <iostream>
#include <string.h>
#include <cstdio>
#include <fcntl.h>
#include <sys/types.h>

#include "rpc.h"
struct inode
{
	uint64_t i_nonum;
	RPC *i_rpc;
};


const nfs_server * NFS_SERVER(const char* command,const struct inode *file_node, struct fuse_file_info *fi){
	file_node->i_rpc->call(file_node->i_nonum,fi->flags)

}
#endif