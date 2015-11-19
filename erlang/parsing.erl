-module(parsing).
 -export([for_each_line_in_file/3,main/0]).
%-export([main/0]).
%-record(switch, {ingress, egress}).
%ets:new(switch_ieports,[named_table,set,public,{keypos,#switch.ieports}]).
for_each_line_in_file(Name,DPID,Mode) ->
    {ok, Device} = file:open(Name, Mode),
    for_each_line(DPID,Device).
 
for_each_line(DPID,Device) ->
    case io:get_line(Device, '') of
        eof  -> file:close(Device), {1,8};
        Line ->
        		[NwDPID,Ingr,Egr] = string:tokens(Line,","),
        		case DPID of
        			NwDPID -> Ingress = list_to_integer(Ingr),
        					[Egrs] = string:tokens(Egr,"\n"),
        					Egress = list_to_integer(Egrs),
        					{Ingress,Egress};
        			_ -> for_each_line(DPID,Device)
        		end
    end.

main()->
	Name = ["halogen_sfc.conf"],
	{Ingress,Egress} = for_each_line_in_file(Name,"00:00:00:00:50:f3:e3:17",[read]),
	io:format("~p ~p",[Ingress,Egress]).