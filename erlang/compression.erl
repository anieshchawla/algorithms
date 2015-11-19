
-module(compression).
-export([main/0,string_coding/4]).
string_coding(S,Msg,P,L) ->
case (P+L) =:= (string:len(Msg)) of
	true ->
	if L > 1 -> S++string:substr(Msg,P,1)++integer_to_list(L);
		true -> S++string:substr(Msg,P,1)
	end;
	false ->
	CompareString = string:substr(Msg,P,1),
	PresentString = string:substr(Msg,P+L,1),
	Result =string:equal(CompareString,PresentString), 
	if Result==true -> string_coding(S,Msg,P,L+1);
		true ->
			if L > 1 -> string_coding(S++string:substr(Msg,P,1)++integer_to_list(L),Msg,P+L,1);
				true -> string_coding(S++string:substr(Msg,P,1),Msg,P+1,1)
			end
	end
end.

main() ->
    Msg = io:get_line(""),
    Solution = string_coding([],Msg,1,1),
    io:format("~s",[Solution])
	.