import time
import socket

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(("127.0.0.1", 5100));

fp=open('data','rb')

data='  '
i=0
while len(data)>0:
	i+=1
	print 'read',i
	data=fp.read(517)
	s.sendall(data)
	time.sleep(0.05)