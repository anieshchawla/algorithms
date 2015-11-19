-module(kitchen).
-compile(export_all).
start(FoodList) ->

spawn(?MODULE, fridge2, [FoodList]).

fridge2(FoodList) ->
	receive
		{From, {store, Food}} ->
			From ! {self(), ok},
			io:format("hellyeah we are inside it ~n"),
			fridge2([Food|FoodList]);
		{From, {take, Food}} ->
			case lists:member(Food, FoodList) of
				true ->
					From ! {self(), {ok, Food}},
					fridge2(lists:delete(Food, FoodList));		
				false ->
					From ! {self(), not_found},
					fridge2(FoodList)
			end;
	terminate ->
		ok
end.
store(Pid, Food) ->
	Pid ! {self(), {store, Food}},
	receive
		{Pid, Msg} -> Msg
	after 1000 ->
		timeout
	end.
 
take(Pid, Food) ->
	Pid ! {self(), {take, Food}},
	receive
	{Pid, Msg} -> Msg
	after 1000 ->
		thissucks
	end.