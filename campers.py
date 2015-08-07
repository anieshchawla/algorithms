array_of_players = [1]*(2*1000000+1)
N,K = map(int, raw_input().split(" "))
snipers = list(map(int,raw_input().split(" ")))
count_players = K
for _index in snipers:
    array_of_players[_index-1]=0
    array_of_players[_index]=0
    if _index >= 2:
        array_of_players[_index-2]=0
players=0
prev_index=-1
last_zero = 0
while (players < N):
    if(array_of_players[players]==0 and last_zero == 0):
        if players != 0:
            difference = players - prev_index
        else:
            difference = 0
        if(difference == 1):
            count_players+=1
        else:
            count_players+=int(difference/2)
        prev_index = players
        last_zero = 1
    elif(players == N-1):
        difference = players - prev_index
        if(array_of_players[players] != 0):
            if(difference%2==0):
                count_players+=int(difference/2)
            else:
                count_players+=int(difference/2)+1

    else:
        if array_of_players[players]!=0:
            last_zero = 0
        else:
            prev_index = players

    players+=1
    
print (count_players)
