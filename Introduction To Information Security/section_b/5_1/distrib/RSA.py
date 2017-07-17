import random
import base64

def fastExpMod(base, index, mod):
	result = 1
	while index != 0:
		if index & 1 == 1:
			result = (result * base) % mod
		index >>= 1
		base = (base * base) % mod
	return result

def PrimeTest(n):
	q = n - 1
	k = 0
	while q % 2 == 0:
		k += 1
		q /= 2
	a = random.randint(2, n-2)
	if fastExpMod(a, q, n) == 1:
		return "inconclusive"
	for j in range(0, k):
		if fastExpMod(a, (2**j)*q, n) == n - 1:
			return "inconclusive"
	return "composite"

def FindPrime(halfkeyLength):
	while True:
		n = random.randint(0, 1<<halfkeyLength)
		if n % 2 != 0:
			found = True
			for i in range(0, 10):
				if PrimeTest(n) == "composite":
					found = False
					break
			if found:
				return n
	
def extendedGCD(a, b):
	if b == 0:
		return (1, 0, a)
	x1 = 1
	y1 = 0
	x2 = 0
	y2 = 1
	while b != 0:
		q = a / b
		r = a % b
		a = b
		b = r
		x = x1 - q*x2
		x1 = x2
		x2 = x
		y = y1 - q*y2
		y1 = y2
		y2 = y
	return (x1, y1, a)
	#a*xi+b*yi=ri

def computeD(fn, e):
	(x, y, r) = extendedGCD(fn, e)
	if(y < 0):
		return fn + y
	return y
	
def selectE(fn, halfkeyLength):
	while True:
		e = random.randint(0, 1<<halfkeyLength)
		(x, y, r) = extendedGCD(e, fn)
		if r == 1:
			return e
			
def encryption(M, e, n):
	return fastExpMod(M, e, n)
	
def decryption(C, d, n):
	return fastExpMod(C, d, n)

p = 205023009136450173084188261524390005311
q = 300941700773930581581777121246681821097
e = 65537
n = p * q
fn = (p - 1) * (q - 1)
d = computeD(fn, e)
c = 0x16a8344aeb9a2d1cd449e22acd976a1a712a51982ba0151355394a841f5e13b
m = decryption(c, d, n)
print hex(m)
answer = []
while m != 0:
	answer.append(chr(m&0xFF))
	m >>= 8
result = "".join(answer[::-1])
print result