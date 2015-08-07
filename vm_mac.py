pkts_to_process = int(raw_input())
M_dict = dict()
MAXSIZE = 16
def add(key,value):
  if len(M_dict) == MAXSIZE:
    old = get_oldest_key() # returns the key to the oldest item
    del M_dict[old]
  M_dict[key] = value


def action_taken(port,dest_mac,src_mac):
	_srcmac = tuple([int(x,16) for x in src_mac.split(":")])
	_chk_multicast = _srcmac[0]&0x01 #masking the mac by taking the last bit only
	if(_chk_multicast == 1):
		'''since src_mac cannot be a mutlicast address thus we should drop this packet immediately'''
		print "drop"
	else:
		_destmac = tuple([int(x,16) for x in dest_mac.split(":")])
		_chk_multicast = _destmac[0]&0x01
		if(_chk_multicast == 1):
			'''src address is unique and dest_mac is mutlicast, thus flood the switch'''
			print "flood"
			add(src_mac,port)
		else:
			try:
				_port_to_forward = M_dict[dest_mac]
				if(_port_to_forward == port):
					print "drop"
				else:
					add(src_mac,port)
					print _port_to_forward
			except:
				print "flood"
				add(src_mac,port)

while(pkts_to_process > 0):
	port,dest_mac,src_mac = raw_input().split(" ")
	action_taken(port,dest_mac,src_mac)
	pkts_to_process -=1
