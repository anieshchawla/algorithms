-module(json_check).
-export([convert_from_Json/1,main/0]).

convert_from_Json(JsonData) ->
     {_,A} = mochijson2:decode(JsonData),
     %io:format("~s",[A]),
     Dpid = binary_to_list(proplists:get_value(<<"DPID">>,A)),
     Ingress = list_to_integer(binary_to_list(proplists:get_value(<<"Ingress">>,A))),
     Egress = list_to_integer(binary_to_list(proplists:get_value(<<"Egress">>,A))),
     {Dpid,Ingress,Egress}.

main()->
	Name =iolist_to_binary(mochijson2:encode({struct, [{"DPID",<<"123456">>}, {"Ingress",<<"20">>},{"Egress",<<"30">>}]})),
  %JsonData = lists:last(binary:split(Name,<<"\r\n">>,[global])),
  Output = convert_from_Json(Name),
	io:format("~s ~n",[Name]),
  %Output = mochijson2:decode(Name).
  io:format("~p ~n",[Output]).
