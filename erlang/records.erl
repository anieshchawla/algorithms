-module(records).
-compile(export_all).
 
-record(robot, {name,
type=industrial,
hobbies,
details=[]}).

-record(user, {id, name, group, age}).

first_robot() ->
#robot{name="Mechatron",
type=handmade,
details=["Moved by a small man inside"]}.

admin_panel(#user{name=Name, group=admin}) ->
Name ++ " is allowed!";
admin_panel(#user{name=Name}) ->
Name ++ " is not allowed".
 
%% can extend user without problem
adult_section(U = #user{}) when U#user.age >= 18 ->
%% Show stuff that can't be written in such a text
allowed;
adult_section(_) ->
%% redirect to sesame street site
forbidden.