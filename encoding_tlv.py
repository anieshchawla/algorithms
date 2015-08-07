'''This is the code for encoding the packet into TLV form for sending NDN packets via controller'''
class TLV():
        def splitN(self,string,N):
                _string_reverse = string[::-1]
                _string_tok_rev= [_string_reverse[start:start+N] for start in range(0,len(string),N)]
                _string_tok=map(lambda x: x[::-1],_string_tok_rev)
                _string_tok = _string_tok[::-1]
                return _string_tok

        def encoding(self):
                '''This one encodes the packet in TLV format and then sends back the updated packet and since
                we are only working with sending the interest packets, thus the type is 5'''
                if(self.type == "Interest"):
                        _msg_type = 5
                elif(self.type=="Name"):
                        _msg_type = 7 #_msg_type = 8 means name component
                else:
                        _msg_type=8
                _length_of_msg = len(self.msg)
                _length_pkt_type = _length_of_msg
                _length_pkt_tuple = (_length_of_msg,)
                _pkt_tlv = (_msg_type,)
                if(_length_of_msg >= 0xff-2): #if the value is greater than 253 then we need next two octest to store the value
                        if(_length_of_msg >= 0xffff): #if the value is large that it cannot be stored in next 2 bytes then we will use 4 bytes 
                                if(_length_of_msg>=0xffffffff):
                                        #if the value is larger and cannot be stored in 4 bytes,we will need 8bytes of space to store the length of data
                                        _length_pkt_type = (0xff,)
                                else:
                                        _length_pkt_type = (0xff-1,)
                        else:
                                _length_pkt_type = (0xff-2,)
                        _hex_string_of_length = hex(_length_of_msg)[2:]
                        _split_hex_of_msg = self.splitN(_hex_string_of_length,2)
                        _tuple_of_msg = tuple([int(_tuple,16) for _tuple in _split_hex_of_msg])
                        _length_pkt_tuple=_length_pkt_type+_tuple_of_msg
                _pkt_tlv_encoded = _pkt_tlv+_length_pkt_tuple+self.msg
                return _pkt_tlv_encoded

        def __init__(self,msg,type_of_pkt):
                self.msg = msg
                self.type=type_of_pkt

class packet_format():
        def __init__(self,msg):
                self.msg = msg.split("/")
        def wire_encode(self):
                '''This function creates a TLV packet inside a TLV packet'''
                _msg_type = 7 #msg type = 7 means Name component according to NDN standards
                _msg_encoded = ()
                for _name in self.msg:
                        _name_in_acii = ()
                        for _char in _name:
                                _name_in_acii+=(ord(_char),)
                        _msg_encoded+=TLV(_name_in_acii,"NameComponent").encoding()
                _len_of_wire_encode = len(_msg_encoded)
                _final_msg = (_msg_type,_len_of_wire_encode)+_msg_encoded
                return _final_msg

class packet_encode_split():
        def __init__(self,msg):
                self.msg=msg.split("/")
        def encode(self):
                _msg_encoded=()
                for _name in self.msg:
                        _name_in_acii=()
                        for _char in _name:
                                _name_in_acii+=(ord(_char),)
                        _msg_encoded+=TLV(_name_in_acii,"NameComponent").encoding()
                return _msg_encoded

class packet_encode_full():
        def __init__(self,msg):
                self.msg=msg
        def encode(self):
                _msg_encoded=()
                _name_in_acii=()
                for _char in self.msg:
                        _name_in_acii+=(ord(_char),)
                _msg_encoded+=TLV(_name_in_acii,"NameComponent").encoding()
                return _msg_encoded

#raw_data =  (5, 253, 1, 178, 7, 253, 1, 164, 8, 3, 110, 100, 110, 8, 4, 78, 76, 83, 82, 8, 9, 97, 100, 118, 101, 114, 116, 105, 115, 101, 8, 12, 47, 101, 100, 117, 47, 115, 97, 110, 99, 116, 117, 109, 8, 9, 49, 48, 46, 49, 48, 46, 49, 46, 51, 8, 22, 7, 20, 8, 5, 112, 97, 112, 117, 97, 8, 3, 110, 101, 119, 8, 6, 103, 117, 105, 110, 101, 97, 8, 8, 0, 0, 1, 77, 251, 241, 50, 47, 8, 8, 25, 82, 220, 131, 48, 103, 39, 205)

