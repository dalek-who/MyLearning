import socket
import time
import hashlib

def hex_md5(str):
	m = hashlib.md5()
	m.update(str.decode("hex"))
	return m.hexdigest()

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(("139.59.99.159",9000))
i = 0
m = hashlib.md5()
while i < 500:
	print i
	time.sleep(0.2)
	data = client.recv(4096)
	while len(data) < 35:
		time.sleep(0.2)
		data += client.recv(4096)
	print data
	line1 = 0
	line2 = 0
	for x in xrange(0,len(data)):
		if data[x] == '\n':
			line1 = line2
			line2 = x
	str1 = data[line1+1:line2]
	print str1
	str2 = hex_md5(str1)
	print str2
	str2 += '\n'
	client.send(str2)
	i = i + 1
time.sleep(1)
data = client.recv(4096)
print data
client.close()