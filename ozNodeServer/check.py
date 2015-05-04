import sys
from sets import Set
dic=Set([]);
file = open('message.txt','r');
for line in file.readlines():
	lines = line.split();
	if lines[0]=='client':
		dic.add(int(lines[1]));
n = int(sys.argv[1])
for i in range (n):
	if i not in dic:
		print "client number ",i, " did not reply."
