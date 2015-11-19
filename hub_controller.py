import sys
host_dict = {}
for new_host in sys.stdin:
	host_dict[new_host.split(" ")[0]] = new_host.split(" ")[1:]

for host in host_dict:
	for port in host_dict[host]:
		


print host_dict
