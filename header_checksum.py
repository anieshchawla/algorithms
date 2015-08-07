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
        _carry_over =_check_sum>>16
        while(_carry_over>0):
            _present_csum +=_carry_over
            _carry_over = _present_csum>>16
            _present_csum = hex(_present_csum)[2:]
            _present_csum = _present_csum[len(_present_csum)-4:]
            _present_csum=int(_present_csum,16)
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
        _checksum_tuple = self.calc_checksum(_header_in_hex)
        return _checksum_tuple