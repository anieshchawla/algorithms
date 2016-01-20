# Enter your code here. Read input from STDIN. Print output to STDOUT
n,m = map(int,raw_input().split())
input_array = map(int,raw_input().split())
happiness = map(int,raw_input().split())
sadness = map(int,raw_input().split())
input_array.sort()
happiness.sort()
sadness.sort()
h=0
s=0
ans=0
for i in range(n):
    if(input_array[i] == happiness[h]):
        ans+=1
        h++
    elif(input_array[i] == sadness[s]):
        ans-=1
        s++
    else:
        while(input_array[i]!= happiness[h]) or input
        
 