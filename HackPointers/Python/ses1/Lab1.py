import os 
os.system("echo Hello")
x = os.popen("ls")
x = x.read()
print(x)
