'''
take an input string
reverse the string
original -> "Test, is running today!"
return   -> "today! running is Test,"
'''

def mysplit(a):
	alen = len(a)
	start, stop = 0, alen - 1
	startb = False
	stopb = False

	if (not a[start].isalpha()):
		start += 1
		startb = True
	if (not a[stop].isalpha()):
		stop -= 1
		stopb = True
	#while (not a[start].isalpha()): start = start + 1
	#while (not a[stop].isalpha()): stop  -= 1
	#return (start, stop)
	if (startb):
		astart = a[0:start]
		print (astart)
	else:
		astart = ""
	if (stopb):
		astop = a[stop+1:alen]
		print (astop)
	else:
		astop = ""

	am = a[start:stop+1]
	return (astart, am, astop)

def myswap(a, b):
	ast, am, astop = mysplit(a)
	bst, bm, bstop = mysplit(b)
	return (ast+bm+astop, bst+am+bstop)

def rS(inputstr):
	inputsplit = inputstr.split(" ")
	startidx, endidx = 0, len(inputsplit)-1
	while (startidx < endidx):
		inputsplit[startidx], inputsplit[endidx] = myswap(inputsplit[startidx], inputsplit[endidx])
		startidx += 1
		endidx   -= 1
	print (" ".join(inputsplit))

def reverseString(inputstr):
	inputsplit = inputstr.split(" ")
#print(inputsplit)
	startidx, endidx = 0, len(inputsplit)-1
	while (startidx < endidx):
		inputsplit[startidx], inputsplit[endidx] = inputsplit[endidx], inputsplit[startidx]
		startidx += 1
		endidx   -= 1
	print (" ".join(inputsplit))

reverseString("Test, is running today!")
#rs() rotuine should keep the punctuation symbols as is
rS("Test, is running today!")
