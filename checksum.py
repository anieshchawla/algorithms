'''This is the file to calculating the ip header checksum it assumes that 2 bytes checksum value 
is (0,0) before it calculates the checksum and then outputs the resultant ip header'''
class csum_ip():
     def __init__(self,header_list):
        self.header_list = header_list
     def calc_checksum(self,header_hex):
        '''this function is the one which actually calculates the checksum'''
        _check_sum = 0
        header_hex = header_hex.split(",")
        for hex_byte in header_hex:
            _check_sum +=int(hex_byte,16)
        _present_csum = hex(_check_sum)[2:]
        _present_csum = _present_csum[len(_present_csum)-4:]
        _present_csum=int(_present_csum,16)
        print "csum before while ",_present_csum
        _carry_over =_check_sum>>16
        while(_carry_over>0):
            _present_csum +=_carry_over
            _carry_over = _present_csum>>16
            _present_csum = hex(_present_csum)[2:]
            _present_csum = _present_csum[len(_present_csum)-4:]
            _present_csum=int(_present_csum,16)
            print _present_csum
        _check_sum=_present_csum&0xFFFF ^ 0xFFFF #we are flipping the bits and then trimming it to 16bits values
        _check_sum= hex(_check_sum)[2:]
        _checksum1 = _check_sum[:len(_check_sum)-2]
        _checksum2=_check_sum[len(_check_sum)-2:]
        _checksum1=int(_checksum1,16)
        _checksum2=int(_checksum2,16)
        _checksum=(_checksum1,_checksum2)
        return _checksum

     def header_csum(self):
        header_list=self.header_list
        _header_in_hex=",".join(format(header_list[_iter-1],'02x')+ format(header_list[_iter],'02x') for _iter in xrange(1,(len(header_list)),2))
        print _header_in_hex
        _checksum_tuple = self.calc_checksum(_header_in_hex)
        return _checksum_tuple

length_of_ip_header = (69,) #in hex it is 45, 4 ---> 1st 4 bits of this represent version, next 4 bits represent
# => (45): 4--> version i.e. IPv4  and 
# 5 -->lenght of header , mininum is 5(RFC 791) which means 5x32=160bits = 20bytes of header
ecn_field = (0,) #this is set to 1 if you want explicit congestion notification
length_of_ip_data = (1,211)
packet_id = (236, 246)
flag_for_offset = (0,)
offset_field = (0,)
time_to_live = (64,)
protocol_type = (17,) #Protocol type 17=UDP
ip_header_check_sum = (0,0) #intializing it to (0,0) so that we can calucate the checksum and then add the value at this position, value should be(6, 153)
src_ip_field = (192, 68, 2, 1)
dest_ip_field = (192, 68, 3, 1)
#pkt = 69, 0, 1, 211, 236, 246, 0, 0, 64, 17, 6, 153, 192, 68, 2, 1, 192, 68, 3, 1
ip_header = length_of_ip_header+ecn_field+length_of_ip_data+packet_id+flag_for_offset+offset_field+time_to_live+protocol_type+ip_header_check_sum+src_ip_field+dest_ip_field
checksum=csum_ip(ip_header)
print checksum.header_csum()