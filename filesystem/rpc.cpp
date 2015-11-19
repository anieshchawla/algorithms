#include "rpc.hpp"

using namespace std;
//struct hostent
//{
//  char **h_aliases;		/* Alias list.  */
//  int h_addrtype;		/* Host address type.  */
//  int h_length;			/* Length of address.  */
//  char **h_addr_list;		/* List of addresses from name server.  */
//#if defined __USE_MISC || defined __USE_GNU
//# define	h_addr	h_addr_list[0] /* Address, for backward compatibility.*/
//#endif
//};


/*struct sockaddr_in {
    short            sin_family;   // e.g. AF_INET
    unsigned short   sin_port;     // e.g. htons(3490)
    struct in_addr   sin_addr;     // see struct in_addr, below
    char             sin_zero[8];  // zero this if you want to
};*/

//htons = host to network short , this functions convert from your native byte order(big/little endian) to 
    //network byte order and back again

RPC::RPC(){}

RPC::~RPC(){}

RPC::connect(const char* host, int port){
	sock = (int)socket(AF_INET,SOCK_STREAM,0);
	if(sock < 0) return DISK_ERROR;
//hostent and gethostbyname are present in netdb.h file, refer it for more details
	struct hostent *hostent = gethostbyname(host);
	//resolve host
  	if (hostent == NULL)
    	return DISK_ERROR;

    //setting port
	struct sockaddr_in server;
	memset(&server,0,sizeof(server));
	peer.sin_family = AF_INET;
	memcpy(&server.sin_addr,hostent->h_addr,hostent->h_length);
	server.sin_port = htons((short)port)

	//connect
	if(connect(sock,(const struct sockaddr*)&server),sizeof(server) < 0 ){
		return CONNECTION_ERROR;
	}

}

RPC::call(int inode_num,int flags){
	if(sock < 0 ) return CONNECTION_ERROR;

}