import socket

s = socket.socket()

s.bind(("0.0.0.0", 9000))

s.listen(1)

print("서버 대기중")

client, addr = s.accept()

data = client.recv(1024)

print(data.decode())


