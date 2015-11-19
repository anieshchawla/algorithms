#include "sane_fs_client.hpp"

using namespace std;

static const  
sane_fs::sane_fs_client()
{
	rpc->connect("localhost",SANE_FS_DEFAULT_PORT);
}

sane_fs::~sane_fs_client()
{
	rpc->disconnect();
}

/*
int sane_fs::getattr(const char *path, struct stat *stat_buf){
	//add for getting attribute
}*/

int
sane_fs::sane_fs_open(const char *path, struct fuse_file_info *fi){
	//need to implement a hash function to find the non overlapping values, let's say that function is hash_fun;
	//this hash_fun will give output as uint64_t, which will be used as file descriptor.
	string file_path(path);
	const uint64_t inode_num = hash_fun(path);
	struct inode* file_inode;
	file_inode->i_nonum = inode_num;
	file_inode->i_rpc = this->get_rpc();
	//define the mode in which you want to open the file - read, write, read+write etc - this is in fi->flags
	//send the request via RPC to the server
	fi->fh = NFS_SERVER(file_inode,fi);
	//if get the positive response then in fuse_file_info populate fh, otherwise return Disk_error
	return inode_num;
}

static struct fuse_operations sane_fs_oper{
	.open = sane_fs_open;
};


int main(int argc, char **argv){
	return fuse_main(argc,argv,&sane_fs_oper,NULL);
}