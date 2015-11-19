-module(function).
-compile(export_all).
 
sum(L)->sum(L,0).

sum([],Sum) -> Sum;
sum([H|T],Sum) -> sum(T,H+Sum).

reverse(L)->reverse(L,[]).
reverse([],Acc)->Acc;
reverse([H|T],Acc)->reverse(T,[H|Acc]).


whoa() ->
try
talk(),
_Knight = "None shall Pass!",
_Doubles = [N*2 || N <- lists:seq(1,100)],
throw(up),
_WillReturnThis = tequila
catch
Exception:Reason -> {caught, Exception, Reason}
end.

talk() -> io:format("blah blah").