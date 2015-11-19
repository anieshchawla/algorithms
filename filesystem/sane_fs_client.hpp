#ifndef SANE_FS_H
#define SANE_FS_H
#include <fuse.h>
#include <iostream>
#include <string.h>
#include <cstdio>
#include <fcntl.h>
#include <sys/types.h> //dev_t is defined in this

// Including the header files for definition of various parameters
#include "internal_functions.hpp"
#include "error.hpp"
#include "rpc.hpp"

#define SANE_FS_DEFAULT_PORT 2016

#ifndef __gid_t_defined
typedef __gid_t gid_t;
#define __gid_t_defined
#endif

#ifndef __uid_t_defined
typedef __uid_t uid_t;
#define __uid_t_defined
#endif

#ifndef __mode_t_defined
typedef __mode_t mode_t;
# define __mode_t_defined
#endif


//----------------------------------------------------------------------------------------
//defining a hash_fun for finding out the block_num/inode number, this might change later

uint64_t hash_fun(const char *path){
	return strlen(path);
}

//----------------------------------------------------------------------------------------
class sane_fs {

public:
	sane_fs_client();
	~sane_fs_client();
/*	int sane_fs_getattr(const char *path, struct stat *stat_buf);

	int sane_fs_readlink (const char *path, char *, size_t size);

	int sane_fs_mknod (const char *path, mode_t mode, dev_t rdev);

	int sane_fs_mkdir (const char *path, mode_t mode);

	int sane_fs_unlink (const char *path);

	int sane_fs_rmdir (const char *path);

	int sane_fs_symlink (const char *path, const char *name);

	int sane_fs_rename (const char *path, const char *name);

	int sane_fs_link (const char *path, const char *);

	int sane_fs_chmod (const char *path, mode_t mode);

	int sane_fs_chown (const char *path, uid_t uid, gid_t gid);

	int sane_fs_truncate (const char *path, off_t length);

	int sane_fs_utime (const char *path, struct utimbuf *);

*/	int sane_fs_open (const char *path, struct fuse_file_info *fi);
	const RPC * get_rpc(){return rpc};

	/*int sane_fs_read (const char *path, char *, size_t size, off_t length, struct fuse_file_info *fi);

	int sane_fs_write (const char *path, const char *, size_t size, off_t length,struct fuse_file_info *fi);

	int sane_fs_statfs (const char *path, struct statfs *stbuf);

	int sane_fs_flush (const char *path, struct fuse_file_info *fi);

	int sane_fs_release (const char *path, struct fuse_file_info *fi);

	int sane_fs_fsync (const char *path, int, struct fuse_file_info *fi);

	int sane_fs_setxattr (const char *path, const char *name, const char *value, size_t size, int flags);

	int sane_fs_getxattr (const char *path, const char *name, char *value, size_t size);

	int sane_fs_listxattr (const char *path, char *name, size_t size);

	int sane_fs_removexattr (const char *path, const char *name);
*/
private:
	//Volume m_vol;
	const RPC* rpc;

};


#endif