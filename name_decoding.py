class ndn_pkt_received():
	def __init__(self,ndn_ethernet_tuple):
		self.ndn_ethernet = ndn_ethernet_tuple
	def len_of_pkt(self,position):
		eth_offset = 0
		hex_string =''
		if(self.ndn_ethernet[position]<253):
		        eth_offset=0
		        hex_string=hex(self.ndn_ethernet[position])
		elif(self.ndn_ethernet[position]==253):
		        eth_offset=2
		elif(self.ndn_ethernet[position]==254):
		        eth_offset=4
		elif(self.ndn_ethernet[position]==255):
		        eth_offset=8
		for _iter in range(eth_offset):
			hex_string+=hex(self.ndn_ethernet[position+_iter+1])[2:]
		return int(hex_string,16),eth_offset

	def get_interest_name(self):
	   if self.ndn_ethernet[0]==5:
	   	_position = 1
	   	length_pkt,_interest_offset = self.len_of_pkt(_position)
	   	name =''
	   	_position +=_interest_offset+1
		while (_position < length_pkt):
			if(self.ndn_ethernet[_position]==8):
				_position+=1
				length_of_name,_name_offset = self.len_of_pkt(_position)

				_position+=_name_offset
				if(self.ndn_ethernet[_position+1] == 7):
					pass
				else:
					if(length_of_name>0):
						name+="/"
					for _val in range(_position+1, _position+length_of_name+1):
						print name, _val
						name+=str(unichr(self.ndn_ethernet[_val]))
					_position+=length_of_name
			_position+=1
		return name
#pkt = ndn_pkt_received([5, 253, 1, 179, 7, 253, 1, 165, 8, 3, 110, 100, 110, 8, 4, 78, 76, 83, 82, 8, 9, 97, 100, 118, 101, 114, 116, 105, 115, 101, 8, 12, 47, 101, 100, 117, 47, 115, 97, 110, 99, 116, 117, 109, 8, 10, 49, 57, 50, 46, 54, 56, 46, 50, 46, 49, 8, 22, 7, 20, 8, 5, 112, 97, 112, 117, 97, 8, 3, 110, 101, 119, 8, 6, 103, 117, 105, 110, 101, 97, 8, 8, 0, 0, 1, 78, 36, 204, 226, 103, 8, 8, 122, 189, 109, 206, 59, 20, 181, 176, 8, 63, 22, 61, 27, 1, 1, 28, 56, 7, 54, 8, 9, 108, 111, 99, 97, 108, 104, 111, 115, 116, 8, 8, 111, 112, 101, 114, 97, 116, 111, 114, 8, 3, 75, 69, 89, 8, 17, 107, 115, 107, 45, 49, 52, 51, 53, 48, 52, 54, 57, 50, 50, 48, 51, 51, 8, 7, 73, 68, 45, 67, 69, 82, 84, 8, 253, 1, 4, 23, 253, 1, 0, 1, 30, 46, 85, 158, 133, 11, 201, 76, 162, 22, 104, 156, 145, 58, 38, 15, 56, 123, 118, 155, 166, 64, 96, 224, 241, 141, 181, 29, 158, 213, 179, 148, 100, 167, 7, 150, 85, 5, 242, 124, 110, 13, 90, 137, 163, 249, 87, 226, 155, 212, 126, 205, 23, 227, 91, 146, 213, 120, 253, 161, 100, 219, 119, 47, 104, 128, 233, 117, 201, 0, 225, 138, 102, 216, 234, 160, 180, 41, 202, 228, 28, 28, 77, 211, 16, 161, 125, 82, 29, 44, 57, 134, 2, 78, 97, 228, 139, 99, 14, 59, 140, 27, 85, 75, 118, 76, 96, 52, 109, 93, 150, 253, 78, 2, 75, 148, 94, 212, 159, 248, 124, 199, 60, 85, 67, 24, 7, 174, 165, 34, 240, 137, 47, 176, 157, 147, 128, 31, 46, 228, 213, 81, 202, 123, 94, 246, 226, 34, 242, 212, 190, 150, 42, 113, 95, 66, 5, 129, 185, 36, 24, 136, 205, 211, 69, 137, 178, 233, 191, 122, 28, 146, 45, 118, 52, 34, 148, 54, 240, 16, 56, 250, 3, 75, 173, 48, 128, 48, 135, 74, 215, 102, 53, 39, 89, 30, 194, 110, 94, 135, 60, 185, 250, 24, 159, 75, 97, 211, 194, 102, 88, 132, 231, 251, 205, 32, 242, 29, 65, 173, 16, 23, 244, 253, 37, 188, 108, 202, 99, 58, 40, 184, 46, 164, 106, 21, 113, 56, 94, 238, 151, 2, 121, 225, 117, 79, 28, 235, 7, 37, 139, 43, 153, 60, 29, 9, 2, 18, 0, 10, 4, 12, 34, 215, 221])
#print pkt.get_interest_name()